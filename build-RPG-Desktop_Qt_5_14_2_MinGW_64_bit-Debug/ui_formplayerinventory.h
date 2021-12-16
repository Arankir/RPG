/********************************************************************************
** Form generated from reading UI file 'formplayerinventory.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPLAYERINVENTORY_H
#define UI_FORMPLAYERINVENTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormPlayerInventory
{
public:
    QGridLayout *gridLayout;
    QLabel *labelBelt;
    QLabel *labelPants;
    QLabel *labelAccessories3;
    QLabel *labelHand2;
    QLabel *labelBoots;
    QLabel *labelAccessories1;
    QLabel *labelAccessories2;
    QLabel *labelChest;
    QLabel *labelHelm;
    QLabel *labelHand1;
    QLabel *labelGloves;
    QLabel *labelAccessories4;

    void setupUi(QWidget *FormPlayerInventory)
    {
        if (FormPlayerInventory->objectName().isEmpty())
            FormPlayerInventory->setObjectName(QString::fromUtf8("FormPlayerInventory"));
        FormPlayerInventory->resize(434, 513);
        gridLayout = new QGridLayout(FormPlayerInventory);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelBelt = new QLabel(FormPlayerInventory);
        labelBelt->setObjectName(QString::fromUtf8("labelBelt"));

        gridLayout->addWidget(labelBelt, 3, 1, 1, 1);

        labelPants = new QLabel(FormPlayerInventory);
        labelPants->setObjectName(QString::fromUtf8("labelPants"));

        gridLayout->addWidget(labelPants, 4, 1, 1, 1);

        labelAccessories3 = new QLabel(FormPlayerInventory);
        labelAccessories3->setObjectName(QString::fromUtf8("labelAccessories3"));

        gridLayout->addWidget(labelAccessories3, 4, 2, 1, 1);

        labelHand2 = new QLabel(FormPlayerInventory);
        labelHand2->setObjectName(QString::fromUtf8("labelHand2"));

        gridLayout->addWidget(labelHand2, 3, 2, 1, 1);

        labelBoots = new QLabel(FormPlayerInventory);
        labelBoots->setObjectName(QString::fromUtf8("labelBoots"));

        gridLayout->addWidget(labelBoots, 5, 1, 1, 1);

        labelAccessories1 = new QLabel(FormPlayerInventory);
        labelAccessories1->setObjectName(QString::fromUtf8("labelAccessories1"));

        gridLayout->addWidget(labelAccessories1, 4, 0, 1, 1);

        labelAccessories2 = new QLabel(FormPlayerInventory);
        labelAccessories2->setObjectName(QString::fromUtf8("labelAccessories2"));

        gridLayout->addWidget(labelAccessories2, 5, 0, 1, 1);

        labelChest = new QLabel(FormPlayerInventory);
        labelChest->setObjectName(QString::fromUtf8("labelChest"));

        gridLayout->addWidget(labelChest, 2, 1, 1, 1);

        labelHelm = new QLabel(FormPlayerInventory);
        labelHelm->setObjectName(QString::fromUtf8("labelHelm"));

        gridLayout->addWidget(labelHelm, 0, 1, 1, 1);

        labelHand1 = new QLabel(FormPlayerInventory);
        labelHand1->setObjectName(QString::fromUtf8("labelHand1"));

        gridLayout->addWidget(labelHand1, 2, 0, 1, 1);

        labelGloves = new QLabel(FormPlayerInventory);
        labelGloves->setObjectName(QString::fromUtf8("labelGloves"));

        gridLayout->addWidget(labelGloves, 3, 0, 1, 1);

        labelAccessories4 = new QLabel(FormPlayerInventory);
        labelAccessories4->setObjectName(QString::fromUtf8("labelAccessories4"));

        gridLayout->addWidget(labelAccessories4, 5, 2, 1, 1);


        retranslateUi(FormPlayerInventory);

        QMetaObject::connectSlotsByName(FormPlayerInventory);
    } // setupUi

    void retranslateUi(QWidget *FormPlayerInventory)
    {
        FormPlayerInventory->setWindowTitle(QCoreApplication::translate("FormPlayerInventory", "Form", nullptr));
        labelBelt->setText(QCoreApplication::translate("FormPlayerInventory", "\320\237\320\276\321\217\321\201", nullptr));
        labelPants->setText(QCoreApplication::translate("FormPlayerInventory", "\320\250\321\202\320\260\320\275\321\213", nullptr));
        labelAccessories3->setText(QCoreApplication::translate("FormPlayerInventory", "\320\220\320\272\321\201\320\265\321\201\321\201\321\203\320\260\321\2003", nullptr));
        labelHand2->setText(QCoreApplication::translate("FormPlayerInventory", "\320\240\321\203\320\272\320\2602", nullptr));
        labelBoots->setText(QCoreApplication::translate("FormPlayerInventory", "\320\221\320\276\321\202\320\270\320\275\320\272\320\270", nullptr));
        labelAccessories1->setText(QCoreApplication::translate("FormPlayerInventory", "\320\220\320\272\321\201\320\265\321\201\321\201\321\203\320\260\321\2001", nullptr));
        labelAccessories2->setText(QCoreApplication::translate("FormPlayerInventory", "\320\220\320\272\321\201\320\265\321\201\321\201\321\203\320\260\321\2002", nullptr));
        labelChest->setText(QCoreApplication::translate("FormPlayerInventory", "\320\242\320\265\320\273\320\276", nullptr));
        labelHelm->setText(QCoreApplication::translate("FormPlayerInventory", "\320\223\320\276\320\273\320\276\320\262\320\260", nullptr));
        labelHand1->setText(QCoreApplication::translate("FormPlayerInventory", "\320\240\321\203\320\272\320\2601", nullptr));
        labelGloves->setText(QCoreApplication::translate("FormPlayerInventory", "\320\237\320\265\321\200\321\207\320\260\321\202\320\272\320\270", nullptr));
        labelAccessories4->setText(QCoreApplication::translate("FormPlayerInventory", "\320\220\320\272\321\201\320\265\321\201\321\201\321\203\320\260\321\2004", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormPlayerInventory: public Ui_FormPlayerInventory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPLAYERINVENTORY_H
