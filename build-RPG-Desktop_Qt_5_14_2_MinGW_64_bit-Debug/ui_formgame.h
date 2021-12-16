/********************************************************************************
** Form generated from reading UI file 'formgame.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMGAME_H
#define UI_FORMGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "GMWidgets/formcreateinventoryitem.h"
#include "gameWidgets/formchat.h"

QT_BEGIN_NAMESPACE

class Ui_FormGame
{
public:
    FormChat *chat;
    QListWidget *listWidgetPlayers;
    FormCreateInventoryItem *widget;
    QPushButton *pushButtonTest;

    void setupUi(QWidget *FormGame)
    {
        if (FormGame->objectName().isEmpty())
            FormGame->setObjectName(QString::fromUtf8("FormGame"));
        FormGame->resize(1177, 879);
        chat = new FormChat(FormGame);
        chat->setObjectName(QString::fromUtf8("chat"));
        chat->setGeometry(QRect(10, 580, 451, 291));
        listWidgetPlayers = new QListWidget(FormGame);
        listWidgetPlayers->setObjectName(QString::fromUtf8("listWidgetPlayers"));
        listWidgetPlayers->setGeometry(QRect(10, 10, 221, 561));
        widget = new FormCreateInventoryItem(FormGame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(240, 10, 331, 521));
        pushButtonTest = new QPushButton(FormGame);
        pushButtonTest->setObjectName(QString::fromUtf8("pushButtonTest"));
        pushButtonTest->setGeometry(QRect(850, 710, 80, 21));

        retranslateUi(FormGame);

        QMetaObject::connectSlotsByName(FormGame);
    } // setupUi

    void retranslateUi(QWidget *FormGame)
    {
        FormGame->setWindowTitle(QCoreApplication::translate("FormGame", "Form", nullptr));
        pushButtonTest->setText(QCoreApplication::translate("FormGame", "\320\242\320\265\321\201\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormGame: public Ui_FormGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGAME_H
