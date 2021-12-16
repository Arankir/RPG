/********************************************************************************
** Form generated from reading UI file 'formcreateinventoryitem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCREATEINVENTORYITEM_H
#define UI_FORMCREATEINVENTORYITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCreateInventoryItem
{
public:
    QFormLayout *formLayout;
    QLabel *labelImage;
    QPushButton *pushButtonLoadImage;
    QLabel *labelType;
    QComboBox *comboBoxType;
    QLabel *labelWidth;
    QSpinBox *spinBoxWidth;
    QLabel *labelHeight;
    QSpinBox *spinBoxHeight;
    QLabel *labelHP;
    QSpinBox *spinBoxHpMax;
    QLabel *labelMP;
    QSpinBox *spinBoxMpMax;
    QLabel *labelArmor;
    QSpinBox *spinBoxArmor;
    QLabel *labelStrength;
    QSpinBox *spinBoxStrength;
    QLabel *labelAgility;
    QSpinBox *spinBoxAgility;
    QLabel *labelntelligence;
    QSpinBox *spinBoxIntelligence;
    QLabel *labelStamina;
    QSpinBox *spinBoxStamina;
    QLabel *labelCloseCombat;
    QSpinBox *spinBoxCloseCombat;
    QLabel *labelAccuracy;
    QSpinBox *spinBoxAccuracy;
    QLabel *labelMovement;
    QSpinBox *spinBoxMovement;
    QLabel *labelDodge;
    QSpinBox *spinBoxDodge;
    QPushButton *pushButtonSave;
    QLabel *labelName;
    QLineEdit *lineEditName;

    void setupUi(QWidget *FormCreateInventoryItem)
    {
        if (FormCreateInventoryItem->objectName().isEmpty())
            FormCreateInventoryItem->setObjectName(QString::fromUtf8("FormCreateInventoryItem"));
        FormCreateInventoryItem->resize(176, 471);
        formLayout = new QFormLayout(FormCreateInventoryItem);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelImage = new QLabel(FormCreateInventoryItem);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelImage);

        pushButtonLoadImage = new QPushButton(FormCreateInventoryItem);
        pushButtonLoadImage->setObjectName(QString::fromUtf8("pushButtonLoadImage"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonLoadImage->sizePolicy().hasHeightForWidth());
        pushButtonLoadImage->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::FieldRole, pushButtonLoadImage);

        labelType = new QLabel(FormCreateInventoryItem);
        labelType->setObjectName(QString::fromUtf8("labelType"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelType);

        comboBoxType = new QComboBox(FormCreateInventoryItem);
        comboBoxType->setObjectName(QString::fromUtf8("comboBoxType"));
        sizePolicy.setHeightForWidth(comboBoxType->sizePolicy().hasHeightForWidth());
        comboBoxType->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBoxType);

        labelWidth = new QLabel(FormCreateInventoryItem);
        labelWidth->setObjectName(QString::fromUtf8("labelWidth"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelWidth);

        spinBoxWidth = new QSpinBox(FormCreateInventoryItem);
        spinBoxWidth->setObjectName(QString::fromUtf8("spinBoxWidth"));
        sizePolicy.setHeightForWidth(spinBoxWidth->sizePolicy().hasHeightForWidth());
        spinBoxWidth->setSizePolicy(sizePolicy);
        spinBoxWidth->setMinimum(1);
        spinBoxWidth->setMaximum(10);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBoxWidth);

        labelHeight = new QLabel(FormCreateInventoryItem);
        labelHeight->setObjectName(QString::fromUtf8("labelHeight"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelHeight);

        spinBoxHeight = new QSpinBox(FormCreateInventoryItem);
        spinBoxHeight->setObjectName(QString::fromUtf8("spinBoxHeight"));
        sizePolicy.setHeightForWidth(spinBoxHeight->sizePolicy().hasHeightForWidth());
        spinBoxHeight->setSizePolicy(sizePolicy);
        spinBoxHeight->setMinimum(1);
        spinBoxHeight->setMaximum(10);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBoxHeight);

        labelHP = new QLabel(FormCreateInventoryItem);
        labelHP->setObjectName(QString::fromUtf8("labelHP"));

        formLayout->setWidget(5, QFormLayout::LabelRole, labelHP);

        spinBoxHpMax = new QSpinBox(FormCreateInventoryItem);
        spinBoxHpMax->setObjectName(QString::fromUtf8("spinBoxHpMax"));
        sizePolicy.setHeightForWidth(spinBoxHpMax->sizePolicy().hasHeightForWidth());
        spinBoxHpMax->setSizePolicy(sizePolicy);
        spinBoxHpMax->setMinimum(-999);
        spinBoxHpMax->setMaximum(999);
        spinBoxHpMax->setValue(0);

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBoxHpMax);

        labelMP = new QLabel(FormCreateInventoryItem);
        labelMP->setObjectName(QString::fromUtf8("labelMP"));

        formLayout->setWidget(6, QFormLayout::LabelRole, labelMP);

        spinBoxMpMax = new QSpinBox(FormCreateInventoryItem);
        spinBoxMpMax->setObjectName(QString::fromUtf8("spinBoxMpMax"));
        sizePolicy.setHeightForWidth(spinBoxMpMax->sizePolicy().hasHeightForWidth());
        spinBoxMpMax->setSizePolicy(sizePolicy);
        spinBoxMpMax->setMinimum(-999);
        spinBoxMpMax->setMaximum(999);

        formLayout->setWidget(6, QFormLayout::FieldRole, spinBoxMpMax);

        labelArmor = new QLabel(FormCreateInventoryItem);
        labelArmor->setObjectName(QString::fromUtf8("labelArmor"));

        formLayout->setWidget(7, QFormLayout::LabelRole, labelArmor);

        spinBoxArmor = new QSpinBox(FormCreateInventoryItem);
        spinBoxArmor->setObjectName(QString::fromUtf8("spinBoxArmor"));
        sizePolicy.setHeightForWidth(spinBoxArmor->sizePolicy().hasHeightForWidth());
        spinBoxArmor->setSizePolicy(sizePolicy);
        spinBoxArmor->setMinimum(-999);
        spinBoxArmor->setMaximum(999);
        spinBoxArmor->setValue(0);

        formLayout->setWidget(7, QFormLayout::FieldRole, spinBoxArmor);

        labelStrength = new QLabel(FormCreateInventoryItem);
        labelStrength->setObjectName(QString::fromUtf8("labelStrength"));

        formLayout->setWidget(8, QFormLayout::LabelRole, labelStrength);

        spinBoxStrength = new QSpinBox(FormCreateInventoryItem);
        spinBoxStrength->setObjectName(QString::fromUtf8("spinBoxStrength"));
        sizePolicy.setHeightForWidth(spinBoxStrength->sizePolicy().hasHeightForWidth());
        spinBoxStrength->setSizePolicy(sizePolicy);
        spinBoxStrength->setMinimum(-999);
        spinBoxStrength->setMaximum(999);
        spinBoxStrength->setValue(0);

        formLayout->setWidget(8, QFormLayout::FieldRole, spinBoxStrength);

        labelAgility = new QLabel(FormCreateInventoryItem);
        labelAgility->setObjectName(QString::fromUtf8("labelAgility"));

        formLayout->setWidget(9, QFormLayout::LabelRole, labelAgility);

        spinBoxAgility = new QSpinBox(FormCreateInventoryItem);
        spinBoxAgility->setObjectName(QString::fromUtf8("spinBoxAgility"));
        sizePolicy.setHeightForWidth(spinBoxAgility->sizePolicy().hasHeightForWidth());
        spinBoxAgility->setSizePolicy(sizePolicy);
        spinBoxAgility->setMinimum(-999);
        spinBoxAgility->setMaximum(999);
        spinBoxAgility->setValue(0);

        formLayout->setWidget(9, QFormLayout::FieldRole, spinBoxAgility);

        labelntelligence = new QLabel(FormCreateInventoryItem);
        labelntelligence->setObjectName(QString::fromUtf8("labelntelligence"));

        formLayout->setWidget(10, QFormLayout::LabelRole, labelntelligence);

        spinBoxIntelligence = new QSpinBox(FormCreateInventoryItem);
        spinBoxIntelligence->setObjectName(QString::fromUtf8("spinBoxIntelligence"));
        sizePolicy.setHeightForWidth(spinBoxIntelligence->sizePolicy().hasHeightForWidth());
        spinBoxIntelligence->setSizePolicy(sizePolicy);
        spinBoxIntelligence->setMinimum(-999);
        spinBoxIntelligence->setMaximum(999);
        spinBoxIntelligence->setValue(0);

        formLayout->setWidget(10, QFormLayout::FieldRole, spinBoxIntelligence);

        labelStamina = new QLabel(FormCreateInventoryItem);
        labelStamina->setObjectName(QString::fromUtf8("labelStamina"));

        formLayout->setWidget(11, QFormLayout::LabelRole, labelStamina);

        spinBoxStamina = new QSpinBox(FormCreateInventoryItem);
        spinBoxStamina->setObjectName(QString::fromUtf8("spinBoxStamina"));
        sizePolicy.setHeightForWidth(spinBoxStamina->sizePolicy().hasHeightForWidth());
        spinBoxStamina->setSizePolicy(sizePolicy);
        spinBoxStamina->setMinimum(-999);
        spinBoxStamina->setMaximum(999);
        spinBoxStamina->setValue(0);

        formLayout->setWidget(11, QFormLayout::FieldRole, spinBoxStamina);

        labelCloseCombat = new QLabel(FormCreateInventoryItem);
        labelCloseCombat->setObjectName(QString::fromUtf8("labelCloseCombat"));

        formLayout->setWidget(12, QFormLayout::LabelRole, labelCloseCombat);

        spinBoxCloseCombat = new QSpinBox(FormCreateInventoryItem);
        spinBoxCloseCombat->setObjectName(QString::fromUtf8("spinBoxCloseCombat"));
        sizePolicy.setHeightForWidth(spinBoxCloseCombat->sizePolicy().hasHeightForWidth());
        spinBoxCloseCombat->setSizePolicy(sizePolicy);
        spinBoxCloseCombat->setMinimum(-999);
        spinBoxCloseCombat->setMaximum(999);
        spinBoxCloseCombat->setValue(0);

        formLayout->setWidget(12, QFormLayout::FieldRole, spinBoxCloseCombat);

        labelAccuracy = new QLabel(FormCreateInventoryItem);
        labelAccuracy->setObjectName(QString::fromUtf8("labelAccuracy"));

        formLayout->setWidget(13, QFormLayout::LabelRole, labelAccuracy);

        spinBoxAccuracy = new QSpinBox(FormCreateInventoryItem);
        spinBoxAccuracy->setObjectName(QString::fromUtf8("spinBoxAccuracy"));
        sizePolicy.setHeightForWidth(spinBoxAccuracy->sizePolicy().hasHeightForWidth());
        spinBoxAccuracy->setSizePolicy(sizePolicy);
        spinBoxAccuracy->setMinimum(-999);
        spinBoxAccuracy->setMaximum(999);
        spinBoxAccuracy->setValue(0);

        formLayout->setWidget(13, QFormLayout::FieldRole, spinBoxAccuracy);

        labelMovement = new QLabel(FormCreateInventoryItem);
        labelMovement->setObjectName(QString::fromUtf8("labelMovement"));

        formLayout->setWidget(14, QFormLayout::LabelRole, labelMovement);

        spinBoxMovement = new QSpinBox(FormCreateInventoryItem);
        spinBoxMovement->setObjectName(QString::fromUtf8("spinBoxMovement"));
        sizePolicy.setHeightForWidth(spinBoxMovement->sizePolicy().hasHeightForWidth());
        spinBoxMovement->setSizePolicy(sizePolicy);
        spinBoxMovement->setMinimum(-999);
        spinBoxMovement->setMaximum(999);
        spinBoxMovement->setValue(0);

        formLayout->setWidget(14, QFormLayout::FieldRole, spinBoxMovement);

        labelDodge = new QLabel(FormCreateInventoryItem);
        labelDodge->setObjectName(QString::fromUtf8("labelDodge"));

        formLayout->setWidget(15, QFormLayout::LabelRole, labelDodge);

        spinBoxDodge = new QSpinBox(FormCreateInventoryItem);
        spinBoxDodge->setObjectName(QString::fromUtf8("spinBoxDodge"));
        sizePolicy.setHeightForWidth(spinBoxDodge->sizePolicy().hasHeightForWidth());
        spinBoxDodge->setSizePolicy(sizePolicy);
        spinBoxDodge->setMinimum(-999);
        spinBoxDodge->setMaximum(999);
        spinBoxDodge->setValue(0);

        formLayout->setWidget(15, QFormLayout::FieldRole, spinBoxDodge);

        pushButtonSave = new QPushButton(FormCreateInventoryItem);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));

        formLayout->setWidget(16, QFormLayout::SpanningRole, pushButtonSave);

        labelName = new QLabel(FormCreateInventoryItem);
        labelName->setObjectName(QString::fromUtf8("labelName"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelName);

        lineEditName = new QLineEdit(FormCreateInventoryItem);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditName);


        retranslateUi(FormCreateInventoryItem);

        QMetaObject::connectSlotsByName(FormCreateInventoryItem);
    } // setupUi

    void retranslateUi(QWidget *FormCreateInventoryItem)
    {
        FormCreateInventoryItem->setWindowTitle(QCoreApplication::translate("FormCreateInventoryItem", "Form", nullptr));
        labelImage->setText(QString());
        pushButtonLoadImage->setText(QCoreApplication::translate("FormCreateInventoryItem", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        labelType->setText(QCoreApplication::translate("FormCreateInventoryItem", "\320\242\320\270\320\277", nullptr));
        labelWidth->setText(QCoreApplication::translate("FormCreateInventoryItem", "\320\224\320\273\320\270\320\275\320\260", nullptr));
        labelHeight->setText(QCoreApplication::translate("FormCreateInventoryItem", "\320\222\321\213\321\201\320\276\321\202\320\260", nullptr));
        labelHP->setText(QCoreApplication::translate("FormCreateInventoryItem", "\320\245\320\237", nullptr));
        labelMP->setText(QCoreApplication::translate("FormCreateInventoryItem", "\320\234\320\260\320\275\320\260", nullptr));
        labelArmor->setText(QCoreApplication::translate("FormCreateInventoryItem", "\320\221\321\200\320\276\320\275\321\217", nullptr));
        labelStrength->setText(QCoreApplication::translate("FormCreateInventoryItem", "\320\241\320\270\320\273\320\260", nullptr));
        labelAgility->setText(QCoreApplication::translate("FormCreateInventoryItem", "\320\233\320\276\320\262\320\272\320\276\321\201\321\202\321\214", nullptr));
        labelntelligence->setText(QCoreApplication::translate("FormCreateInventoryItem", "\320\230\320\275\321\202\320\265\320\273\320\273\320\265\320\272\321\202", nullptr));
        labelStamina->setText(QCoreApplication::translate("FormCreateInventoryItem", "\320\222\321\213\320\275\320\276\321\201\320\273\320\270\320\262\320\276\321\201\321\202\321\214", nullptr));
        labelCloseCombat->setText(QCoreApplication::translate("FormCreateInventoryItem", "\320\221\320\273\320\270\320\266\320\275\320\270\320\271 \320\261\320\276\320\271", nullptr));
        labelAccuracy->setText(QCoreApplication::translate("FormCreateInventoryItem", "\320\234\320\265\321\202\320\272\320\276\321\201\321\202\321\214", nullptr));
        labelMovement->setText(QCoreApplication::translate("FormCreateInventoryItem", "\320\224\320\262\320\270\320\266\320\265\320\275\320\270\320\265", nullptr));
        labelDodge->setText(QCoreApplication::translate("FormCreateInventoryItem", "\320\243\320\272\320\273\320\276\320\275\320\265\320\275\320\270\320\265", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("FormCreateInventoryItem", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 \321\204\320\260\320\271\320\273", nullptr));
        labelName->setText(QCoreApplication::translate("FormCreateInventoryItem", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCreateInventoryItem: public Ui_FormCreateInventoryItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCREATEINVENTORYITEM_H
