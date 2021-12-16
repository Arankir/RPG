/********************************************************************************
** Form generated from reading UI file 'formchat.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCHAT_H
#define UI_FORMCHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormChat
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEditMessages;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEditMessage;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;

    void setupUi(QWidget *FormChat)
    {
        if (FormChat->objectName().isEmpty())
            FormChat->setObjectName(QString::fromUtf8("FormChat"));
        FormChat->resize(632, 636);
        verticalLayout = new QVBoxLayout(FormChat);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textEditMessages = new QTextEdit(FormChat);
        textEditMessages->setObjectName(QString::fromUtf8("textEditMessages"));
        textEditMessages->setReadOnly(true);

        verticalLayout_2->addWidget(textEditMessages);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineEditMessage = new QLineEdit(FormChat);
        lineEditMessage->setObjectName(QString::fromUtf8("lineEditMessage"));

        horizontalLayout_4->addWidget(lineEditMessage);

        pushButton = new QPushButton(FormChat);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FormChat);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(FormChat);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(9);
        spinBox->setValue(6);

        horizontalLayout->addWidget(spinBox);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(FormChat);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBox_2 = new QSpinBox(FormChat);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMaximum(9);
        spinBox_2->setValue(1);

        horizontalLayout_2->addWidget(spinBox_2);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(FormChat);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(FormChat);

        QMetaObject::connectSlotsByName(FormChat);
    } // setupUi

    void retranslateUi(QWidget *FormChat)
    {
        FormChat->setWindowTitle(QCoreApplication::translate("FormChat", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("FormChat", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("FormChat", "\320\223\321\200\320\260\320\275\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("FormChat", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FormChat", "\320\221\321\200\320\276\321\201\320\270\321\202\321\214 \320\272\321\203\320\261\320\270\320\272(\320\270)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormChat: public Ui_FormChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCHAT_H
