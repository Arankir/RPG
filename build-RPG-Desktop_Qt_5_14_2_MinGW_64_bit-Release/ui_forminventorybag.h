/********************************************************************************
** Form generated from reading UI file 'forminventorybag.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMINVENTORYBAG_H
#define UI_FORMINVENTORYBAG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormInventoryBag
{
public:
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *FormInventoryBag)
    {
        if (FormInventoryBag->objectName().isEmpty())
            FormInventoryBag->setObjectName(QString::fromUtf8("FormInventoryBag"));
        FormInventoryBag->resize(400, 300);
        verticalLayout = new QVBoxLayout(FormInventoryBag);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(FormInventoryBag);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(graphicsView);


        retranslateUi(FormInventoryBag);

        QMetaObject::connectSlotsByName(FormInventoryBag);
    } // setupUi

    void retranslateUi(QWidget *FormInventoryBag)
    {
        FormInventoryBag->setWindowTitle(QCoreApplication::translate("FormInventoryBag", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormInventoryBag: public Ui_FormInventoryBag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMINVENTORYBAG_H
