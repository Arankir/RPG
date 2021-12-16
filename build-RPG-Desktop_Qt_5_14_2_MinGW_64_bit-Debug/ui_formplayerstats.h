/********************************************************************************
** Form generated from reading UI file 'formplayerstats.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPLAYERSTATS_H
#define UI_FORMPLAYERSTATS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormPlayerStats
{
public:
    QFormLayout *formLayout;
    QLabel *labelAvatar;
    QPushButton *pushButtonLoadAvatar;
    QLabel *labelHP;
    QHBoxLayout *horizontalLayout;
    QLabel *labelStatHP;
    QSpinBox *spinBoxHpNow;
    QLabel *labelHPSlashGM;
    QSpinBox *spinBoxHpMax;
    QLabel *labelMP;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelStatMP;
    QSpinBox *spinBoxMpNow;
    QLabel *labelMPSlashGM;
    QSpinBox *spinBoxMpMax;
    QLabel *labelLvl;
    QHBoxLayout *horizontalLayout_11;
    QLabel *labelStatLvl;
    QSpinBox *spinBoxLvl;
    QLabel *labelExp;
    QHBoxLayout *horizontalLayout_13;
    QLabel *labelStatExp;
    QSpinBox *spinBoxExp;
    QLabel *labelArmor;
    QHBoxLayout *horizontalLayout_12;
    QLabel *labelStatArmor;
    QSpinBox *spinBoxArmor;
    QLabel *labelStrength;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelStatStrength;
    QPushButton *pushButtonAddStrength;
    QSpinBox *spinBoxStrength;
    QLabel *labelAgility;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelStatAgility;
    QPushButton *pushButtonAddAgility;
    QSpinBox *spinBoxAgility;
    QLabel *labelntelligence;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelStatIntelligence;
    QPushButton *pushButtonAddIntelegence;
    QSpinBox *spinBoxIntelligence;
    QLabel *labelStamina;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelStatStamina;
    QPushButton *pushButtonAddStamina;
    QSpinBox *spinBoxStamina;
    QLabel *labelCloseCombat;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelStatCloseCombat;
    QSpinBox *spinBoxCloseCombat;
    QLabel *labelAccuracy;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelStatAccuracy;
    QSpinBox *spinBoxAccuracy;
    QLabel *labelMovement;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelStatMovement;
    QSpinBox *spinBoxMovement;
    QLabel *labelDodge;
    QHBoxLayout *horizontalLayout_10;
    QLabel *labelStatDodge;
    QSpinBox *spinBoxDodge;
    QLabel *label;
    QHBoxLayout *horizontalLayout_14;
    QLabel *labelStatPoints;
    QSpinBox *spinBoxPoints;
    QPushButton *pushButtonApply;

    void setupUi(QWidget *FormPlayerStats)
    {
        if (FormPlayerStats->objectName().isEmpty())
            FormPlayerStats->setObjectName(QString::fromUtf8("FormPlayerStats"));
        FormPlayerStats->resize(225, 500);
        formLayout = new QFormLayout(FormPlayerStats);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelAvatar = new QLabel(FormPlayerStats);
        labelAvatar->setObjectName(QString::fromUtf8("labelAvatar"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelAvatar);

        pushButtonLoadAvatar = new QPushButton(FormPlayerStats);
        pushButtonLoadAvatar->setObjectName(QString::fromUtf8("pushButtonLoadAvatar"));

        formLayout->setWidget(0, QFormLayout::FieldRole, pushButtonLoadAvatar);

        labelHP = new QLabel(FormPlayerStats);
        labelHP->setObjectName(QString::fromUtf8("labelHP"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelHP);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelStatHP = new QLabel(FormPlayerStats);
        labelStatHP->setObjectName(QString::fromUtf8("labelStatHP"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelStatHP->sizePolicy().hasHeightForWidth());
        labelStatHP->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(labelStatHP);

        spinBoxHpNow = new QSpinBox(FormPlayerStats);
        spinBoxHpNow->setObjectName(QString::fromUtf8("spinBoxHpNow"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBoxHpNow->sizePolicy().hasHeightForWidth());
        spinBoxHpNow->setSizePolicy(sizePolicy1);
        spinBoxHpNow->setMinimum(-10);
        spinBoxHpNow->setMaximum(999);

        horizontalLayout->addWidget(spinBoxHpNow);

        labelHPSlashGM = new QLabel(FormPlayerStats);
        labelHPSlashGM->setObjectName(QString::fromUtf8("labelHPSlashGM"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelHPSlashGM->sizePolicy().hasHeightForWidth());
        labelHPSlashGM->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(labelHPSlashGM);

        spinBoxHpMax = new QSpinBox(FormPlayerStats);
        spinBoxHpMax->setObjectName(QString::fromUtf8("spinBoxHpMax"));
        sizePolicy1.setHeightForWidth(spinBoxHpMax->sizePolicy().hasHeightForWidth());
        spinBoxHpMax->setSizePolicy(sizePolicy1);
        spinBoxHpMax->setMinimum(1);
        spinBoxHpMax->setMaximum(999);

        horizontalLayout->addWidget(spinBoxHpMax);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout);

        labelMP = new QLabel(FormPlayerStats);
        labelMP->setObjectName(QString::fromUtf8("labelMP"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelMP);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelStatMP = new QLabel(FormPlayerStats);
        labelStatMP->setObjectName(QString::fromUtf8("labelStatMP"));
        sizePolicy.setHeightForWidth(labelStatMP->sizePolicy().hasHeightForWidth());
        labelStatMP->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(labelStatMP);

        spinBoxMpNow = new QSpinBox(FormPlayerStats);
        spinBoxMpNow->setObjectName(QString::fromUtf8("spinBoxMpNow"));
        sizePolicy1.setHeightForWidth(spinBoxMpNow->sizePolicy().hasHeightForWidth());
        spinBoxMpNow->setSizePolicy(sizePolicy1);
        spinBoxMpNow->setMinimum(-10);
        spinBoxMpNow->setMaximum(999);

        horizontalLayout_2->addWidget(spinBoxMpNow);

        labelMPSlashGM = new QLabel(FormPlayerStats);
        labelMPSlashGM->setObjectName(QString::fromUtf8("labelMPSlashGM"));
        sizePolicy2.setHeightForWidth(labelMPSlashGM->sizePolicy().hasHeightForWidth());
        labelMPSlashGM->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(labelMPSlashGM);

        spinBoxMpMax = new QSpinBox(FormPlayerStats);
        spinBoxMpMax->setObjectName(QString::fromUtf8("spinBoxMpMax"));
        sizePolicy1.setHeightForWidth(spinBoxMpMax->sizePolicy().hasHeightForWidth());
        spinBoxMpMax->setSizePolicy(sizePolicy1);
        spinBoxMpMax->setMaximum(999);

        horizontalLayout_2->addWidget(spinBoxMpMax);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_2);

        labelLvl = new QLabel(FormPlayerStats);
        labelLvl->setObjectName(QString::fromUtf8("labelLvl"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelLvl);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        labelStatLvl = new QLabel(FormPlayerStats);
        labelStatLvl->setObjectName(QString::fromUtf8("labelStatLvl"));
        sizePolicy.setHeightForWidth(labelStatLvl->sizePolicy().hasHeightForWidth());
        labelStatLvl->setSizePolicy(sizePolicy);

        horizontalLayout_11->addWidget(labelStatLvl);

        spinBoxLvl = new QSpinBox(FormPlayerStats);
        spinBoxLvl->setObjectName(QString::fromUtf8("spinBoxLvl"));
        sizePolicy1.setHeightForWidth(spinBoxLvl->sizePolicy().hasHeightForWidth());
        spinBoxLvl->setSizePolicy(sizePolicy1);
        spinBoxLvl->setMaximum(999);
        spinBoxLvl->setValue(1);

        horizontalLayout_11->addWidget(spinBoxLvl);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_11);

        labelExp = new QLabel(FormPlayerStats);
        labelExp->setObjectName(QString::fromUtf8("labelExp"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelExp);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        labelStatExp = new QLabel(FormPlayerStats);
        labelStatExp->setObjectName(QString::fromUtf8("labelStatExp"));
        sizePolicy.setHeightForWidth(labelStatExp->sizePolicy().hasHeightForWidth());
        labelStatExp->setSizePolicy(sizePolicy);

        horizontalLayout_13->addWidget(labelStatExp);

        spinBoxExp = new QSpinBox(FormPlayerStats);
        spinBoxExp->setObjectName(QString::fromUtf8("spinBoxExp"));
        sizePolicy1.setHeightForWidth(spinBoxExp->sizePolicy().hasHeightForWidth());
        spinBoxExp->setSizePolicy(sizePolicy1);
        spinBoxExp->setMaximum(999999);

        horizontalLayout_13->addWidget(spinBoxExp);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_13);

        labelArmor = new QLabel(FormPlayerStats);
        labelArmor->setObjectName(QString::fromUtf8("labelArmor"));

        formLayout->setWidget(5, QFormLayout::LabelRole, labelArmor);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        labelStatArmor = new QLabel(FormPlayerStats);
        labelStatArmor->setObjectName(QString::fromUtf8("labelStatArmor"));
        sizePolicy.setHeightForWidth(labelStatArmor->sizePolicy().hasHeightForWidth());
        labelStatArmor->setSizePolicy(sizePolicy);

        horizontalLayout_12->addWidget(labelStatArmor);

        spinBoxArmor = new QSpinBox(FormPlayerStats);
        spinBoxArmor->setObjectName(QString::fromUtf8("spinBoxArmor"));
        sizePolicy1.setHeightForWidth(spinBoxArmor->sizePolicy().hasHeightForWidth());
        spinBoxArmor->setSizePolicy(sizePolicy1);
        spinBoxArmor->setMaximum(999);
        spinBoxArmor->setValue(1);

        horizontalLayout_12->addWidget(spinBoxArmor);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayout_12);

        labelStrength = new QLabel(FormPlayerStats);
        labelStrength->setObjectName(QString::fromUtf8("labelStrength"));

        formLayout->setWidget(6, QFormLayout::LabelRole, labelStrength);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelStatStrength = new QLabel(FormPlayerStats);
        labelStatStrength->setObjectName(QString::fromUtf8("labelStatStrength"));
        sizePolicy.setHeightForWidth(labelStatStrength->sizePolicy().hasHeightForWidth());
        labelStatStrength->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(labelStatStrength);

        pushButtonAddStrength = new QPushButton(FormPlayerStats);
        pushButtonAddStrength->setObjectName(QString::fromUtf8("pushButtonAddStrength"));
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButtonAddStrength->sizePolicy().hasHeightForWidth());
        pushButtonAddStrength->setSizePolicy(sizePolicy3);
        pushButtonAddStrength->setMinimumSize(QSize(21, 21));

        horizontalLayout_3->addWidget(pushButtonAddStrength);

        spinBoxStrength = new QSpinBox(FormPlayerStats);
        spinBoxStrength->setObjectName(QString::fromUtf8("spinBoxStrength"));
        sizePolicy1.setHeightForWidth(spinBoxStrength->sizePolicy().hasHeightForWidth());
        spinBoxStrength->setSizePolicy(sizePolicy1);
        spinBoxStrength->setMaximum(999);
        spinBoxStrength->setValue(1);

        horizontalLayout_3->addWidget(spinBoxStrength);


        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayout_3);

        labelAgility = new QLabel(FormPlayerStats);
        labelAgility->setObjectName(QString::fromUtf8("labelAgility"));

        formLayout->setWidget(7, QFormLayout::LabelRole, labelAgility);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelStatAgility = new QLabel(FormPlayerStats);
        labelStatAgility->setObjectName(QString::fromUtf8("labelStatAgility"));
        sizePolicy.setHeightForWidth(labelStatAgility->sizePolicy().hasHeightForWidth());
        labelStatAgility->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(labelStatAgility);

        pushButtonAddAgility = new QPushButton(FormPlayerStats);
        pushButtonAddAgility->setObjectName(QString::fromUtf8("pushButtonAddAgility"));
        sizePolicy3.setHeightForWidth(pushButtonAddAgility->sizePolicy().hasHeightForWidth());
        pushButtonAddAgility->setSizePolicy(sizePolicy3);
        pushButtonAddAgility->setMinimumSize(QSize(21, 21));

        horizontalLayout_4->addWidget(pushButtonAddAgility);

        spinBoxAgility = new QSpinBox(FormPlayerStats);
        spinBoxAgility->setObjectName(QString::fromUtf8("spinBoxAgility"));
        sizePolicy1.setHeightForWidth(spinBoxAgility->sizePolicy().hasHeightForWidth());
        spinBoxAgility->setSizePolicy(sizePolicy1);
        spinBoxAgility->setMaximum(999);
        spinBoxAgility->setValue(1);

        horizontalLayout_4->addWidget(spinBoxAgility);


        formLayout->setLayout(7, QFormLayout::FieldRole, horizontalLayout_4);

        labelntelligence = new QLabel(FormPlayerStats);
        labelntelligence->setObjectName(QString::fromUtf8("labelntelligence"));

        formLayout->setWidget(8, QFormLayout::LabelRole, labelntelligence);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelStatIntelligence = new QLabel(FormPlayerStats);
        labelStatIntelligence->setObjectName(QString::fromUtf8("labelStatIntelligence"));
        sizePolicy.setHeightForWidth(labelStatIntelligence->sizePolicy().hasHeightForWidth());
        labelStatIntelligence->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(labelStatIntelligence);

        pushButtonAddIntelegence = new QPushButton(FormPlayerStats);
        pushButtonAddIntelegence->setObjectName(QString::fromUtf8("pushButtonAddIntelegence"));
        sizePolicy3.setHeightForWidth(pushButtonAddIntelegence->sizePolicy().hasHeightForWidth());
        pushButtonAddIntelegence->setSizePolicy(sizePolicy3);
        pushButtonAddIntelegence->setMinimumSize(QSize(21, 21));

        horizontalLayout_5->addWidget(pushButtonAddIntelegence);

        spinBoxIntelligence = new QSpinBox(FormPlayerStats);
        spinBoxIntelligence->setObjectName(QString::fromUtf8("spinBoxIntelligence"));
        sizePolicy1.setHeightForWidth(spinBoxIntelligence->sizePolicy().hasHeightForWidth());
        spinBoxIntelligence->setSizePolicy(sizePolicy1);
        spinBoxIntelligence->setMaximum(999);
        spinBoxIntelligence->setValue(1);

        horizontalLayout_5->addWidget(spinBoxIntelligence);


        formLayout->setLayout(8, QFormLayout::FieldRole, horizontalLayout_5);

        labelStamina = new QLabel(FormPlayerStats);
        labelStamina->setObjectName(QString::fromUtf8("labelStamina"));

        formLayout->setWidget(9, QFormLayout::LabelRole, labelStamina);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        labelStatStamina = new QLabel(FormPlayerStats);
        labelStatStamina->setObjectName(QString::fromUtf8("labelStatStamina"));
        sizePolicy.setHeightForWidth(labelStatStamina->sizePolicy().hasHeightForWidth());
        labelStatStamina->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(labelStatStamina);

        pushButtonAddStamina = new QPushButton(FormPlayerStats);
        pushButtonAddStamina->setObjectName(QString::fromUtf8("pushButtonAddStamina"));
        sizePolicy3.setHeightForWidth(pushButtonAddStamina->sizePolicy().hasHeightForWidth());
        pushButtonAddStamina->setSizePolicy(sizePolicy3);
        pushButtonAddStamina->setMinimumSize(QSize(21, 21));

        horizontalLayout_6->addWidget(pushButtonAddStamina);

        spinBoxStamina = new QSpinBox(FormPlayerStats);
        spinBoxStamina->setObjectName(QString::fromUtf8("spinBoxStamina"));
        sizePolicy1.setHeightForWidth(spinBoxStamina->sizePolicy().hasHeightForWidth());
        spinBoxStamina->setSizePolicy(sizePolicy1);
        spinBoxStamina->setMaximum(999);
        spinBoxStamina->setValue(1);

        horizontalLayout_6->addWidget(spinBoxStamina);


        formLayout->setLayout(9, QFormLayout::FieldRole, horizontalLayout_6);

        labelCloseCombat = new QLabel(FormPlayerStats);
        labelCloseCombat->setObjectName(QString::fromUtf8("labelCloseCombat"));

        formLayout->setWidget(10, QFormLayout::LabelRole, labelCloseCombat);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        labelStatCloseCombat = new QLabel(FormPlayerStats);
        labelStatCloseCombat->setObjectName(QString::fromUtf8("labelStatCloseCombat"));
        sizePolicy.setHeightForWidth(labelStatCloseCombat->sizePolicy().hasHeightForWidth());
        labelStatCloseCombat->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(labelStatCloseCombat);

        spinBoxCloseCombat = new QSpinBox(FormPlayerStats);
        spinBoxCloseCombat->setObjectName(QString::fromUtf8("spinBoxCloseCombat"));
        sizePolicy1.setHeightForWidth(spinBoxCloseCombat->sizePolicy().hasHeightForWidth());
        spinBoxCloseCombat->setSizePolicy(sizePolicy1);
        spinBoxCloseCombat->setMaximum(999);
        spinBoxCloseCombat->setValue(1);

        horizontalLayout_7->addWidget(spinBoxCloseCombat);


        formLayout->setLayout(10, QFormLayout::FieldRole, horizontalLayout_7);

        labelAccuracy = new QLabel(FormPlayerStats);
        labelAccuracy->setObjectName(QString::fromUtf8("labelAccuracy"));

        formLayout->setWidget(11, QFormLayout::LabelRole, labelAccuracy);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        labelStatAccuracy = new QLabel(FormPlayerStats);
        labelStatAccuracy->setObjectName(QString::fromUtf8("labelStatAccuracy"));
        sizePolicy.setHeightForWidth(labelStatAccuracy->sizePolicy().hasHeightForWidth());
        labelStatAccuracy->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(labelStatAccuracy);

        spinBoxAccuracy = new QSpinBox(FormPlayerStats);
        spinBoxAccuracy->setObjectName(QString::fromUtf8("spinBoxAccuracy"));
        sizePolicy1.setHeightForWidth(spinBoxAccuracy->sizePolicy().hasHeightForWidth());
        spinBoxAccuracy->setSizePolicy(sizePolicy1);
        spinBoxAccuracy->setMaximum(999);
        spinBoxAccuracy->setValue(1);

        horizontalLayout_8->addWidget(spinBoxAccuracy);


        formLayout->setLayout(11, QFormLayout::FieldRole, horizontalLayout_8);

        labelMovement = new QLabel(FormPlayerStats);
        labelMovement->setObjectName(QString::fromUtf8("labelMovement"));

        formLayout->setWidget(12, QFormLayout::LabelRole, labelMovement);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        labelStatMovement = new QLabel(FormPlayerStats);
        labelStatMovement->setObjectName(QString::fromUtf8("labelStatMovement"));
        sizePolicy.setHeightForWidth(labelStatMovement->sizePolicy().hasHeightForWidth());
        labelStatMovement->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(labelStatMovement);

        spinBoxMovement = new QSpinBox(FormPlayerStats);
        spinBoxMovement->setObjectName(QString::fromUtf8("spinBoxMovement"));
        sizePolicy1.setHeightForWidth(spinBoxMovement->sizePolicy().hasHeightForWidth());
        spinBoxMovement->setSizePolicy(sizePolicy1);
        spinBoxMovement->setMaximum(999);
        spinBoxMovement->setValue(1);

        horizontalLayout_9->addWidget(spinBoxMovement);


        formLayout->setLayout(12, QFormLayout::FieldRole, horizontalLayout_9);

        labelDodge = new QLabel(FormPlayerStats);
        labelDodge->setObjectName(QString::fromUtf8("labelDodge"));

        formLayout->setWidget(13, QFormLayout::LabelRole, labelDodge);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        labelStatDodge = new QLabel(FormPlayerStats);
        labelStatDodge->setObjectName(QString::fromUtf8("labelStatDodge"));
        sizePolicy.setHeightForWidth(labelStatDodge->sizePolicy().hasHeightForWidth());
        labelStatDodge->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(labelStatDodge);

        spinBoxDodge = new QSpinBox(FormPlayerStats);
        spinBoxDodge->setObjectName(QString::fromUtf8("spinBoxDodge"));
        sizePolicy1.setHeightForWidth(spinBoxDodge->sizePolicy().hasHeightForWidth());
        spinBoxDodge->setSizePolicy(sizePolicy1);
        spinBoxDodge->setMaximum(999);
        spinBoxDodge->setValue(1);

        horizontalLayout_10->addWidget(spinBoxDodge);


        formLayout->setLayout(13, QFormLayout::FieldRole, horizontalLayout_10);

        label = new QLabel(FormPlayerStats);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(14, QFormLayout::LabelRole, label);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        labelStatPoints = new QLabel(FormPlayerStats);
        labelStatPoints->setObjectName(QString::fromUtf8("labelStatPoints"));

        horizontalLayout_14->addWidget(labelStatPoints);

        spinBoxPoints = new QSpinBox(FormPlayerStats);
        spinBoxPoints->setObjectName(QString::fromUtf8("spinBoxPoints"));
        sizePolicy1.setHeightForWidth(spinBoxPoints->sizePolicy().hasHeightForWidth());
        spinBoxPoints->setSizePolicy(sizePolicy1);

        horizontalLayout_14->addWidget(spinBoxPoints);


        formLayout->setLayout(14, QFormLayout::FieldRole, horizontalLayout_14);

        pushButtonApply = new QPushButton(FormPlayerStats);
        pushButtonApply->setObjectName(QString::fromUtf8("pushButtonApply"));

        formLayout->setWidget(15, QFormLayout::SpanningRole, pushButtonApply);


        retranslateUi(FormPlayerStats);

        QMetaObject::connectSlotsByName(FormPlayerStats);
    } // setupUi

    void retranslateUi(QWidget *FormPlayerStats)
    {
        FormPlayerStats->setWindowTitle(QCoreApplication::translate("FormPlayerStats", "Form", nullptr));
        labelAvatar->setText(QString());
        pushButtonLoadAvatar->setText(QCoreApplication::translate("FormPlayerStats", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        labelHP->setText(QCoreApplication::translate("FormPlayerStats", "\320\245\320\237", nullptr));
        labelStatHP->setText(QCoreApplication::translate("FormPlayerStats", "1", nullptr));
        labelHPSlashGM->setText(QCoreApplication::translate("FormPlayerStats", "/", nullptr));
        labelMP->setText(QCoreApplication::translate("FormPlayerStats", "\320\234\320\260\320\275\320\260", nullptr));
        labelStatMP->setText(QCoreApplication::translate("FormPlayerStats", "1", nullptr));
        labelMPSlashGM->setText(QCoreApplication::translate("FormPlayerStats", "/", nullptr));
        labelLvl->setText(QCoreApplication::translate("FormPlayerStats", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214", nullptr));
        labelStatLvl->setText(QCoreApplication::translate("FormPlayerStats", "1", nullptr));
        labelExp->setText(QCoreApplication::translate("FormPlayerStats", "\320\236\320\277\321\213\321\202", nullptr));
        labelStatExp->setText(QCoreApplication::translate("FormPlayerStats", "0", nullptr));
        labelArmor->setText(QCoreApplication::translate("FormPlayerStats", "\320\221\321\200\320\276\320\275\321\217", nullptr));
        labelStatArmor->setText(QCoreApplication::translate("FormPlayerStats", "1", nullptr));
        labelStrength->setText(QCoreApplication::translate("FormPlayerStats", "\320\241\320\270\320\273\320\260", nullptr));
        labelStatStrength->setText(QCoreApplication::translate("FormPlayerStats", "1", nullptr));
        pushButtonAddStrength->setText(QCoreApplication::translate("FormPlayerStats", "+", nullptr));
        labelAgility->setText(QCoreApplication::translate("FormPlayerStats", "\320\233\320\276\320\262\320\272\320\276\321\201\321\202\321\214", nullptr));
        labelStatAgility->setText(QCoreApplication::translate("FormPlayerStats", "1", nullptr));
        pushButtonAddAgility->setText(QCoreApplication::translate("FormPlayerStats", "+", nullptr));
        labelntelligence->setText(QCoreApplication::translate("FormPlayerStats", "\320\230\320\275\321\202\320\265\320\273\320\273\320\265\320\272\321\202", nullptr));
        labelStatIntelligence->setText(QCoreApplication::translate("FormPlayerStats", "1", nullptr));
        pushButtonAddIntelegence->setText(QCoreApplication::translate("FormPlayerStats", "+", nullptr));
        labelStamina->setText(QCoreApplication::translate("FormPlayerStats", "\320\222\321\213\320\275\320\276\321\201\320\273\320\270\320\262\320\276\321\201\321\202\321\214", nullptr));
        labelStatStamina->setText(QCoreApplication::translate("FormPlayerStats", "1", nullptr));
        pushButtonAddStamina->setText(QCoreApplication::translate("FormPlayerStats", "+", nullptr));
        labelCloseCombat->setText(QCoreApplication::translate("FormPlayerStats", "\320\221\320\273\320\270\320\266\320\275\320\270\320\271 \320\261\320\276\320\271", nullptr));
        labelStatCloseCombat->setText(QCoreApplication::translate("FormPlayerStats", "1", nullptr));
        labelAccuracy->setText(QCoreApplication::translate("FormPlayerStats", "\320\234\320\265\321\202\320\272\320\276\321\201\321\202\321\214", nullptr));
        labelStatAccuracy->setText(QCoreApplication::translate("FormPlayerStats", "1", nullptr));
        labelMovement->setText(QCoreApplication::translate("FormPlayerStats", "\320\224\320\262\320\270\320\266\320\265\320\275\320\270\320\265", nullptr));
        labelStatMovement->setText(QCoreApplication::translate("FormPlayerStats", "1", nullptr));
        labelDodge->setText(QCoreApplication::translate("FormPlayerStats", "\320\243\320\272\320\273\320\276\320\275\320\265\320\275\320\270\320\265", nullptr));
        labelStatDodge->setText(QCoreApplication::translate("FormPlayerStats", "1", nullptr));
        label->setText(QCoreApplication::translate("FormPlayerStats", "\320\241\320\262\320\276\320\261\320\276\320\264\320\275\321\213\320\265 \320\276\321\207\320\272\320\270", nullptr));
        labelStatPoints->setText(QCoreApplication::translate("FormPlayerStats", "1", nullptr));
        pushButtonApply->setText(QCoreApplication::translate("FormPlayerStats", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormPlayerStats: public Ui_FormPlayerStats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPLAYERSTATS_H
