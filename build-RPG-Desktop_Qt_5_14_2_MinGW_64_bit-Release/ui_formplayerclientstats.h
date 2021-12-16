/********************************************************************************
** Form generated from reading UI file 'formplayerclientstats.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPLAYERCLIENTSTATS_H
#define UI_FORMPLAYERCLIENTSTATS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormPlayerClientStats
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QProgressBar *progressBarHp;
    QLabel *label_2;
    QProgressBar *progressBarMp;
    QLabel *label_3;
    QLabel *label_10;
    QLabel *label_4;
    QLabel *label_11;
    QLabel *label_5;
    QLabel *label_12;
    QLabel *label_6;
    QLabel *label_13;
    QLabel *label_7;
    QLabel *label_14;
    QLabel *label_19;
    QLabel *label_23;
    QLabel *label_20;
    QLabel *label_24;
    QLabel *label_21;
    QLabel *label_25;
    QLabel *label_22;
    QLabel *label_26;

    void setupUi(QWidget *FormPlayerClientStats)
    {
        if (FormPlayerClientStats->objectName().isEmpty())
            FormPlayerClientStats->setObjectName(QString::fromUtf8("FormPlayerClientStats"));
        FormPlayerClientStats->resize(210, 276);
        formLayout = new QFormLayout(FormPlayerClientStats);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(FormPlayerClientStats);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        progressBarHp = new QProgressBar(FormPlayerClientStats);
        progressBarHp->setObjectName(QString::fromUtf8("progressBarHp"));
        progressBarHp->setValue(24);

        formLayout->setWidget(0, QFormLayout::FieldRole, progressBarHp);

        label_2 = new QLabel(FormPlayerClientStats);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        progressBarMp = new QProgressBar(FormPlayerClientStats);
        progressBarMp->setObjectName(QString::fromUtf8("progressBarMp"));
        progressBarMp->setValue(24);

        formLayout->setWidget(1, QFormLayout::FieldRole, progressBarMp);

        label_3 = new QLabel(FormPlayerClientStats);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_10 = new QLabel(FormPlayerClientStats);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_10);

        label_4 = new QLabel(FormPlayerClientStats);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_11 = new QLabel(FormPlayerClientStats);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout->setWidget(3, QFormLayout::FieldRole, label_11);

        label_5 = new QLabel(FormPlayerClientStats);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_12 = new QLabel(FormPlayerClientStats);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout->setWidget(4, QFormLayout::FieldRole, label_12);

        label_6 = new QLabel(FormPlayerClientStats);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        label_13 = new QLabel(FormPlayerClientStats);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout->setWidget(5, QFormLayout::FieldRole, label_13);

        label_7 = new QLabel(FormPlayerClientStats);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        label_14 = new QLabel(FormPlayerClientStats);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout->setWidget(6, QFormLayout::FieldRole, label_14);

        label_19 = new QLabel(FormPlayerClientStats);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_19);

        label_23 = new QLabel(FormPlayerClientStats);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        formLayout->setWidget(7, QFormLayout::FieldRole, label_23);

        label_20 = new QLabel(FormPlayerClientStats);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_20);

        label_24 = new QLabel(FormPlayerClientStats);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        formLayout->setWidget(8, QFormLayout::FieldRole, label_24);

        label_21 = new QLabel(FormPlayerClientStats);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_21);

        label_25 = new QLabel(FormPlayerClientStats);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        formLayout->setWidget(9, QFormLayout::FieldRole, label_25);

        label_22 = new QLabel(FormPlayerClientStats);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_22);

        label_26 = new QLabel(FormPlayerClientStats);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        formLayout->setWidget(10, QFormLayout::FieldRole, label_26);


        retranslateUi(FormPlayerClientStats);

        QMetaObject::connectSlotsByName(FormPlayerClientStats);
    } // setupUi

    void retranslateUi(QWidget *FormPlayerClientStats)
    {
        FormPlayerClientStats->setWindowTitle(QCoreApplication::translate("FormPlayerClientStats", "Form", nullptr));
        label->setText(QCoreApplication::translate("FormPlayerClientStats", "\320\245\320\237", nullptr));
        label_2->setText(QCoreApplication::translate("FormPlayerClientStats", "\320\234\320\260\320\275\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("FormPlayerClientStats", "\320\241\320\270\320\273\320\260", nullptr));
        label_10->setText(QCoreApplication::translate("FormPlayerClientStats", "0", nullptr));
        label_4->setText(QCoreApplication::translate("FormPlayerClientStats", "\320\233\320\276\320\262\320\272\320\276\321\201\321\202\321\214", nullptr));
        label_11->setText(QCoreApplication::translate("FormPlayerClientStats", "0", nullptr));
        label_5->setText(QCoreApplication::translate("FormPlayerClientStats", "\320\230\320\275\321\202\320\265\320\273\320\273\320\265\320\272\321\202", nullptr));
        label_12->setText(QCoreApplication::translate("FormPlayerClientStats", "0", nullptr));
        label_6->setText(QCoreApplication::translate("FormPlayerClientStats", "\320\243\320\264\320\260\321\207\320\260", nullptr));
        label_13->setText(QCoreApplication::translate("FormPlayerClientStats", "0", nullptr));
        label_7->setText(QCoreApplication::translate("FormPlayerClientStats", "\320\222\321\213\320\265\320\261\320\276\320\275\321\213", nullptr));
        label_14->setText(QCoreApplication::translate("FormPlayerClientStats", "0", nullptr));
        label_19->setText(QCoreApplication::translate("FormPlayerClientStats", "\320\220\321\202\320\260\320\272\320\260", nullptr));
        label_23->setText(QCoreApplication::translate("FormPlayerClientStats", "0", nullptr));
        label_20->setText(QCoreApplication::translate("FormPlayerClientStats", "\320\227\320\260\321\211\320\270\321\202\320\260", nullptr));
        label_24->setText(QCoreApplication::translate("FormPlayerClientStats", "0", nullptr));
        label_21->setText(QCoreApplication::translate("FormPlayerClientStats", "\320\234.\320\220\321\202\320\260\320\272\320\260", nullptr));
        label_25->setText(QCoreApplication::translate("FormPlayerClientStats", "0", nullptr));
        label_22->setText(QCoreApplication::translate("FormPlayerClientStats", "\320\234.\320\227\320\260\321\211\320\270\321\202\320\260", nullptr));
        label_26->setText(QCoreApplication::translate("FormPlayerClientStats", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormPlayerClientStats: public Ui_FormPlayerClientStats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPLAYERCLIENTSTATS_H
