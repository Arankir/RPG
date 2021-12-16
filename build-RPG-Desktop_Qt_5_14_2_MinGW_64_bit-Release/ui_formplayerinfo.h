/********************************************************************************
** Form generated from reading UI file 'formplayerinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPLAYERINFO_H
#define UI_FORMPLAYERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include "gameWidgets/formplayerinventory.h"
#include "gameWidgets/formplayerstats.h"

QT_BEGIN_NAMESPACE

class Ui_FormPlayerInfo
{
public:
    QHBoxLayout *horizontalLayout;
    FormPlayerInventory *widget;
    FormPlayerStats *widget_2;

    void setupUi(QWidget *FormPlayerInfo)
    {
        if (FormPlayerInfo->objectName().isEmpty())
            FormPlayerInfo->setObjectName(QString::fromUtf8("FormPlayerInfo"));
        FormPlayerInfo->resize(558, 390);
        horizontalLayout = new QHBoxLayout(FormPlayerInfo);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new FormPlayerInventory(FormPlayerInfo);
        widget->setObjectName(QString::fromUtf8("widget"));

        horizontalLayout->addWidget(widget);

        widget_2 = new FormPlayerStats(FormPlayerInfo);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        horizontalLayout->addWidget(widget_2);


        retranslateUi(FormPlayerInfo);

        QMetaObject::connectSlotsByName(FormPlayerInfo);
    } // setupUi

    void retranslateUi(QWidget *FormPlayerInfo)
    {
        FormPlayerInfo->setWindowTitle(QCoreApplication::translate("FormPlayerInfo", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormPlayerInfo: public Ui_FormPlayerInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPLAYERINFO_H
