/********************************************************************************
** Form generated from reading UI file 'formplayerminiature.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPLAYERMINIATURE_H
#define UI_FORMPLAYERMINIATURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "class/widgets/progressbarexp.h"
#include "class/widgets/progressbarhp.h"
#include "class/widgets/progressbarmp.h"

QT_BEGIN_NAMESPACE

class Ui_FormPlayerMiniature
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *labelAvatar;
    QLabel *labelNick;
    QVBoxLayout *verticalLayout;
    ProgressBarHp *progressBarHp;
    ProgressBarMp *progressBarMp;
    ProgressBarExp *progressBarExp;
    QPushButton *pushButtonKick;

    void setupUi(QWidget *FormPlayerMiniature)
    {
        if (FormPlayerMiniature->objectName().isEmpty())
            FormPlayerMiniature->setObjectName(QString::fromUtf8("FormPlayerMiniature"));
        FormPlayerMiniature->resize(167, 87);
        horizontalLayout = new QHBoxLayout(FormPlayerMiniature);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelAvatar = new QLabel(FormPlayerMiniature);
        labelAvatar->setObjectName(QString::fromUtf8("labelAvatar"));

        horizontalLayout->addWidget(labelAvatar);

        labelNick = new QLabel(FormPlayerMiniature);
        labelNick->setObjectName(QString::fromUtf8("labelNick"));
        labelNick->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font-weight: 700;"));

        horizontalLayout->addWidget(labelNick);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        progressBarHp = new ProgressBarHp(FormPlayerMiniature);
        progressBarHp->setObjectName(QString::fromUtf8("progressBarHp"));
        progressBarHp->setMaximumSize(QSize(16777215, 20));
        progressBarHp->setValue(24);

        verticalLayout->addWidget(progressBarHp);

        progressBarMp = new ProgressBarMp(FormPlayerMiniature);
        progressBarMp->setObjectName(QString::fromUtf8("progressBarMp"));
        progressBarMp->setMaximumSize(QSize(16777215, 20));
        progressBarMp->setValue(24);

        verticalLayout->addWidget(progressBarMp);

        progressBarExp = new ProgressBarExp(FormPlayerMiniature);
        progressBarExp->setObjectName(QString::fromUtf8("progressBarExp"));
        progressBarExp->setMaximumSize(QSize(16777215, 15));
        progressBarExp->setMaximum(1000);
        progressBarExp->setValue(24);

        verticalLayout->addWidget(progressBarExp);


        horizontalLayout->addLayout(verticalLayout);

        pushButtonKick = new QPushButton(FormPlayerMiniature);
        pushButtonKick->setObjectName(QString::fromUtf8("pushButtonKick"));

        horizontalLayout->addWidget(pushButtonKick);


        retranslateUi(FormPlayerMiniature);

        QMetaObject::connectSlotsByName(FormPlayerMiniature);
    } // setupUi

    void retranslateUi(QWidget *FormPlayerMiniature)
    {
        FormPlayerMiniature->setWindowTitle(QCoreApplication::translate("FormPlayerMiniature", "Form", nullptr));
        labelAvatar->setText(QString());
        labelNick->setText(QString());
        progressBarHp->setFormat(QCoreApplication::translate("FormPlayerMiniature", "%v/%m", nullptr));
        progressBarMp->setFormat(QCoreApplication::translate("FormPlayerMiniature", "%v/%m", nullptr));
        pushButtonKick->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormPlayerMiniature: public Ui_FormPlayerMiniature {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPLAYERMINIATURE_H
