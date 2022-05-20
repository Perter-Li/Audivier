/********************************************************************************
** Form generated from reading UI file 'setvolume.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETVOLUME_H
#define UI_SETVOLUME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <changebuttoncolor.h>

QT_BEGIN_NAMESPACE

class Ui_SetVolume
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSlider *verticalSlider;
    ChangeButtonColor *toolButton;

    void setupUi(QWidget *SetVolume)
    {
        if (SetVolume->objectName().isEmpty())
            SetVolume->setObjectName(QString::fromUtf8("SetVolume"));
        SetVolume->setWindowModality(Qt::ApplicationModal);
        SetVolume->resize(33, 124);
        SetVolume->setStyleSheet(QString::fromUtf8("border:1px solid black"));
        verticalLayout_2 = new QVBoxLayout(SetVolume);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        widget = new QWidget(SetVolume);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        verticalSlider = new QSlider(widget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalSlider->sizePolicy().hasHeightForWidth());
        verticalSlider->setSizePolicy(sizePolicy);
        verticalSlider->setStyleSheet(QString::fromUtf8("border:0px solid black"));
        verticalSlider->setMaximum(100);
        verticalSlider->setValue(100);
        verticalSlider->setOrientation(Qt::Vertical);

        verticalLayout->addWidget(verticalSlider);

        toolButton = new ChangeButtonColor(widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/Voice.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);

        verticalLayout->addWidget(toolButton);


        verticalLayout_2->addWidget(widget);


        retranslateUi(SetVolume);

        QMetaObject::connectSlotsByName(SetVolume);
    } // setupUi

    void retranslateUi(QWidget *SetVolume)
    {
        SetVolume->setWindowTitle(QCoreApplication::translate("SetVolume", "Form", nullptr));
        toolButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SetVolume: public Ui_SetVolume {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETVOLUME_H
