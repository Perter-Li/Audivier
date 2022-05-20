/********************************************************************************
** Form generated from reading UI file 'setwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETWINDOW_H
#define UI_SETWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <changebuttoncolor.h>

QT_BEGIN_NAMESPACE

class Ui_SetWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    ChangeButtonColor *toolButton;
    ChangeButtonColor *toolButton_2;
    ChangeButtonColor *toolButton_3;

    void setupUi(QWidget *SetWindow)
    {
        if (SetWindow->objectName().isEmpty())
            SetWindow->setObjectName(QString::fromUtf8("SetWindow"));
        SetWindow->setWindowModality(Qt::ApplicationModal);
        SetWindow->resize(33, 97);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SetWindow->sizePolicy().hasHeightForWidth());
        SetWindow->setSizePolicy(sizePolicy);
        SetWindow->setMouseTracking(true);
        SetWindow->setFocusPolicy(Qt::StrongFocus);
        SetWindow->setStyleSheet(QString::fromUtf8("border:1px solid black"));
        verticalLayout_2 = new QVBoxLayout(SetWindow);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        widget = new QWidget(SetWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMouseTracking(true);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        toolButton = new ChangeButtonColor(widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy1);
        toolButton->setMouseTracking(true);
        toolButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/1x.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);

        verticalLayout->addWidget(toolButton);

        toolButton_2 = new ChangeButtonColor(widget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        sizePolicy1.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy1);
        toolButton_2->setMouseTracking(true);
        toolButton_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/OneFrame.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);

        verticalLayout->addWidget(toolButton_2);

        toolButton_3 = new ChangeButtonColor(widget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        sizePolicy1.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy1);
        toolButton_3->setMouseTracking(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/Set.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);

        verticalLayout->addWidget(toolButton_3);


        verticalLayout_2->addWidget(widget);


        retranslateUi(SetWindow);

        QMetaObject::connectSlotsByName(SetWindow);
    } // setupUi

    void retranslateUi(QWidget *SetWindow)
    {
        SetWindow->setWindowTitle(QCoreApplication::translate("SetWindow", "Form", nullptr));
        toolButton->setText(QString());
        toolButton_2->setText(QString());
        toolButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SetWindow: public Ui_SetWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETWINDOW_H
