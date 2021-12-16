#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonTest_clicked();

    void on_pushButtonCopyIP_clicked();

    void on_pushButtonCreateGame_clicked();

    void on_pushButtonConnectToGame_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
