/********************************************************************************
** Form generated from reading UI file 'formplayerserverstats.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPLAYERSERVERSTATS_H
#define UI_FORMPLAYERSERVERSTATS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormPlayerStats
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QProgressBar *progressBarHp;
    QLabel *label_2;
    QProgressBar *progressBarMp;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_6;
    QSpinBox *spinBox_7;
    QSpinBox *spinBox_8;
    QSpinBox *spinBox_9;

    void setupUi(QWidget *FormPlayerServerStats)
    {
        if (FormPlayerServerStats->objectName().isEmpty())
            FormPlayerServerStats->setObjectName(QString::fromUtf8("FormPlayerServerStats"));
        FormPlayerServerStats->resize(166, 282);
        formLayout = new QFormLayout(FormPlayerServerStats);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(FormPlayerServerStats);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        progressBarHp = new QProgressBar(FormPlayerServerStats);
        progressBarHp->setObjectName(QString::fromUtf8("progressBarHp"));
        progressBarHp->setValue(24);

        formLayout->setWidget(0, QFormLayout::FieldRole, progressBarHp);

        label_2 = new QLabel(FormPlayerServerStats);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        progressBarMp = new QProgressBar(FormPlayerServerStats);
        progressBarMp->setObjectName(QString::fromUtf8("progressBarMp"));
        progressBarMp->setValue(24);

        formLayout->setWidget(1, QFormLayout::FieldRole, progressBarMp);

        label_3 = new QLabel(FormPlayerServerStats);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(FormPlayerServerStats);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(FormPlayerServerStats);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(FormPlayerServerStats);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(FormPlayerServerStats);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        label_19 = new QLabel(FormPlayerServerStats);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_19);

        label_20 = new QLabel(FormPlayerServerStats);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_20);

        label_21 = new QLabel(FormPlayerServerStats);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_21);

        label_22 = new QLabel(FormPlayerServerStats);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_22);

        spinBox = new QSpinBox(FormPlayerServerStats);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox);

        spinBox_2 = new QSpinBox(FormPlayerServerStats);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBox_2);

        spinBox_3 = new QSpinBox(FormPlayerServerStats);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBox_3);

        spinBox_4 = new QSpinBox(FormPlayerServerStats);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBox_4);

        spinBox_5 = new QSpinBox(FormPlayerServerStats);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));

        formLayout->setWidget(6, QFormLayout::FieldRole, spinBox_5);

        spinBox_6 = new QSpinBox(FormPlayerServerStats);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));

        formLayout->setWidget(7, QFormLayout::FieldRole, spinBox_6);

        spinBox_7 = new QSpinBox(FormPlayerServerStats);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));

        formLayout->setWidget(8, QFormLayout::FieldRole, spinBox_7);

        spinBox_8 = new QSpinBox(FormPlayerServerStats);
        spinBox_8->setObjectName(QString::fromUtf8("spinBox_8"));

        formLayout->setWidget(9, QFormLayout::FieldRole, spinBox_8);

        spinBox_9 = new QSpinBox(FormPlayerServerStats);
        spinBox_9->setObjectName(QString::fromUtf8("spinBox_9"));

        formLayout->setWidget(10, QFormLayout::FieldRole, spinBox_9);


        retranslateUi(FormPlayerServerStats);

        QMetaObject::connectSlotsByName(FormPlayerServerStats);
    } // setupUi

    void retranslateUi(QWidget *FormPlayerServerStats)
    {
        FormPlayerServerStats->setWindowTitle(QCoreApplication::translate("FormPlayerServerStats", "Form", nullptr));
        label->setText(QCoreApplication::translate("FormPlayerServerStats", "\320\245\320\237", nullptr));
        label_2->setText(QCoreApplication::translate("FormPlayerServerStats", "\320\234\320\260\320\275\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("FormPlayerServerStats", "\320\241\320\270\320\273\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("FormPlayerServerStats", "\320\233\320\276\320\262\320\272\320\276\321\201\321\202\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("FormPlayerServerStats", "\320\230\320\275\321\202\320\265\320\273\320\273\320\265\320\272\321\202", nullptr));
        label_6->setText(QCoreApplication::translate("FormPlayerServerStats", "\320\243\320\264\320\260\321\207\320\260", nullptr));
        label_7->setText(QCoreApplication::translate("FormPlayerServerStats", "\320\222\321\213\320\265\320\261\320\276\320\275\321\213", nullptr));
        label_19->setText(QCoreApplication::translate("FormPlayerServerStats", "\320\220\321\202\320\260\320\272\320\260", nullptr));
        label_20->setText(QCoreApplication::translate("FormPlayerServerStats", "\320\227\320\260\321\211\320\270\321\202\320\260", nullptr));
        label_21->setText(QCoreApplication::translate("FormPlayerServerStats", "\320\234.\320\220\321\202\320\260\320\272\320\260", nullptr));
        label_22->setText(QCoreApplication::translate("FormPlayerServerStats", "\320\234.\320\227\320\260\321\211\320\270\321\202\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormPlayerStats: public Ui_FormPlayerStats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPLAYERSERVERSTATS_H
