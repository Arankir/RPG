/********************************************************************************
** Form generated from reading UI file 'formplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPLAYER_H
#define UI_FORMPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "playerWidgets/forminventorybag.h"
#include "playerWidgets/formplayerinventory.h"
#include "playerWidgets/formplayerstats.h"

QT_BEGIN_NAMESPACE

class Ui_FormPlayer
{
public:
    QHBoxLayout *horizontalLayout;
    FormPlayerStats *stats;
    FormPlayerInventory *inventory;
    QVBoxLayout *verticalLayout;
    FormInventoryBag *bag;
    QPushButton *pushButtonAddItem;

    void setupUi(QWidget *FormPlayer)
    {
        if (FormPlayer->objectName().isEmpty())
            FormPlayer->setObjectName(QString::fromUtf8("FormPlayer"));
        FormPlayer->resize(482, 344);
        horizontalLayout = new QHBoxLayout(FormPlayer);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        stats = new FormPlayerStats(FormPlayer);
        stats->setObjectName(QString::fromUtf8("stats"));

        horizontalLayout->addWidget(stats);

        inventory = new FormPlayerInventory(FormPlayer);
        inventory->setObjectName(QString::fromUtf8("inventory"));

        horizontalLayout->addWidget(inventory);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        bag = new FormInventoryBag(FormPlayer);
        bag->setObjectName(QString::fromUtf8("bag"));

        verticalLayout->addWidget(bag);

        pushButtonAddItem = new QPushButton(FormPlayer);
        pushButtonAddItem->setObjectName(QString::fromUtf8("pushButtonAddItem"));

        verticalLayout->addWidget(pushButtonAddItem);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(FormPlayer);

        QMetaObject::connectSlotsByName(FormPlayer);
    } // setupUi

    void retranslateUi(QWidget *FormPlayer)
    {
        FormPlayer->setWindowTitle(QCoreApplication::translate("FormPlayer", "Form", nullptr));
        pushButtonAddItem->setText(QCoreApplication::translate("FormPlayer", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\321\200\320\265\320\264\320\274\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormPlayer: public Ui_FormPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPLAYER_H
