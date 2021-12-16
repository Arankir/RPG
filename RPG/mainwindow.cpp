#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkInterface>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QUrlQuery>
#include <QJsonObject>
#include <QJsonDocument>
#include <QEventLoop>
#include <QClipboard>
#include <QDebug>
#include <QMessageBox>
#include "class/network/server.h"
#include "class/network/client.h"
#include "formgame.h"
#include <QFile>

QHostAddress getIP() {
    QNetworkAccessManager networkManager;

    QUrl url("https://api.ipify.org");
    //the query used to add the parameter "format=json" to the request
    QUrlQuery query;
    query.addQueryItem("format", "json");
    //set the query on the url
    url.setQuery(query);

    //make a *get* request using the above url
    QNetworkReply* reply = networkManager.get(QNetworkRequest(url));

    QEventLoop loop;

    QObject::connect(&networkManager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QObject::disconnect(&networkManager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);

    QHostAddress ip;

    if(reply->error() != QNetworkReply::NoError) {
        //failure
        qDebug() << "error: " << reply->error();
    } else { //success
        //parse the json reply to extract the IP address
        QJsonObject jsonObject = QJsonDocument::fromJson(reply->readAll()).object();
        ip.setAddress(jsonObject["ip"].toString());
        //do whatever you want with the ip
        qDebug() << "external ip: " << ip;
    }
    //delete reply later to prevent memory leak
    reply->deleteLater();
    return ip;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile qssFile(":/style.qss");
    qssFile.open(QFile::ReadOnly);
    QString qss = qssFile.readAll();
    qApp->setStyleSheet(qss);
    qssFile.close();

    ui->labelIP->setText(getIP().toString());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButtonTest_clicked() {

}

void MainWindow::on_pushButtonCopyIP_clicked() {
    QApplication::clipboard()->setText(ui->labelIP->text());
}

void MainWindow::on_pushButtonCreateGame_clicked() {
    MyServer *server = new MyServer();
    connect(server, &MyServer::s_started, this, [=](bool started) {
        if (started) {
            FormGame *game = new FormGame(server, this);
            game->show();
            this->hide();
        } else {
            QMessageBox::warning(this, tr("Ошибка!"), tr("Не удалось запустить сервер!"));
        }
    });
    server->start(ui->spinBoxPort->value());
}

void MainWindow::on_pushButtonConnectToGame_clicked() {
    MyClient *client = new MyClient();
    QObject::connect(client, &QTcpSocket::hostFound, this, [&](){
        qDebug() << "host finded";
    });
    QObject::connect(client, &QTcpSocket::connected, this, [&](){
        FormGame *game = new FormGame(client, this);
        game->show();
        this->hide();
        qDebug() << "connect finished";
    });
    client->connect(QHostAddress(ui->lineEditServerIP->text()), ui->spinBoxPort->value());
}
