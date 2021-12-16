/********************************************************************************
** Form generated from reading UI file 'formregister.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMREGISTER_H
#define UI_FORMREGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormRegister
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButtonSend;

    void setupUi(QWidget *FormRegister)
    {
        if (FormRegister->objectName().isEmpty())
            FormRegister->setObjectName(QString::fromUtf8("FormRegister"));
        FormRegister->resize(400, 300);
        horizontalLayout = new QHBoxLayout(FormRegister);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FormRegister);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(FormRegister);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButtonSend = new QPushButton(FormRegister);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));

        horizontalLayout->addWidget(pushButtonSend);


        retranslateUi(FormRegister);

        QMetaObject::connectSlotsByName(FormRegister);
    } // setupUi

    void retranslateUi(QWidget *FormRegister)
    {
        FormRegister->setWindowTitle(QCoreApplication::translate("FormRegister", "Form", nullptr));
        label->setText(QCoreApplication::translate("FormRegister", "\320\235\320\270\320\272:", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("FormRegister", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormRegister: public Ui_FormRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMREGISTER_H
