/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *labelIP;
    QPushButton *pushButtonCopyIP;
    QLabel *label_4;
    QSpinBox *spinBoxPort;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonCreateGame;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEditServerIP;
    QPushButton *pushButtonConnectToGame;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(254, 169);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        labelIP = new QLabel(centralwidget);
        labelIP->setObjectName(QString::fromUtf8("labelIP"));
        labelIP->setStyleSheet(QString::fromUtf8("color: rgb(80, 255, 106);"));

        horizontalLayout_3->addWidget(labelIP);

        pushButtonCopyIP = new QPushButton(centralwidget);
        pushButtonCopyIP->setObjectName(QString::fromUtf8("pushButtonCopyIP"));

        horizontalLayout_3->addWidget(pushButtonCopyIP);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        spinBoxPort = new QSpinBox(centralwidget);
        spinBoxPort->setObjectName(QString::fromUtf8("spinBoxPort"));
        spinBoxPort->setMaximum(999999);
        spinBoxPort->setValue(25565);

        horizontalLayout_3->addWidget(spinBoxPort);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        pushButtonCreateGame = new QPushButton(centralwidget);
        pushButtonCreateGame->setObjectName(QString::fromUtf8("pushButtonCreateGame"));

        verticalLayout->addWidget(pushButtonCreateGame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEditServerIP = new QLineEdit(centralwidget);
        lineEditServerIP->setObjectName(QString::fromUtf8("lineEditServerIP"));

        horizontalLayout->addWidget(lineEditServerIP);


        verticalLayout->addLayout(horizontalLayout);

        pushButtonConnectToGame = new QPushButton(centralwidget);
        pushButtonConnectToGame->setObjectName(QString::fromUtf8("pushButtonConnectToGame"));

        verticalLayout->addWidget(pushButtonConnectToGame);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 254, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\222\320\260\321\210 IP:", nullptr));
        labelIP->setText(QString());
        pushButtonCopyIP->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\200\321\202:", nullptr));
        pushButtonCreateGame->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\270\320\263\321\200\321\203", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217 \320\272 IP", nullptr));
        lineEditServerIP->setInputMask(QCoreApplication::translate("MainWindow", "000.000.000.000;_", nullptr));
        lineEditServerIP->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        pushButtonConnectToGame->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\321\201\320\276\320\265\320\264\320\270\320\275\320\270\321\202\321\214\321\201\321\217 \320\272 \320\270\320\263\321\200\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
