/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <changebuttoncolor.h>
#include <mylistwidget.h>
#include <playerslider.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_6;
    QWidget *MainWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *AudioWidget;
    QVBoxLayout *verticalLayout_5;
    QWidget *AudioShowWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_6;
    QLabel *AudioInfoLabel;
    QListWidget *LRCWidget;
    QLabel *AlbumCoverLabel;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *WaveLabel;
    QLabel *VideoScreenLabel;
    QWidget *FunctionWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *ProcessWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *CurrentTimeLabel;
    PlayerSlider *ProgressSlider;
    QLabel *TotalTimeLabel;
    QWidget *ButtonWidget;
    QHBoxLayout *horizontalLayout_5;
    QWidget *ModeWidget;
    QHBoxLayout *horizontalLayout_4;
    ChangeButtonColor *ModeButton;
    ChangeButtonColor *VoiceButton;
    ChangeButtonColor *SetButton;
    QSpacerItem *horizontalSpacer;
    QWidget *PlayWidget;
    QHBoxLayout *horizontalLayout;
    ChangeButtonColor *LastVedioButton;
    ChangeButtonColor *PlayButton;
    ChangeButtonColor *NextVedioButton;
    QSpacerItem *horizontalSpacer_2;
    QWidget *ControlWidget;
    QHBoxLayout *horizontalLayout_2;
    ChangeButtonColor *FullScreenButton;
    ChangeButtonColor *AddButton;
    ChangeButtonColor *PlayListButton;
    QWidget *PlayListWidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *ScrollArea;
    QWidget *ScrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    MyListWidget *ListWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(847, 580);
        MainWindow->setMouseTracking(true);
        MainWindow->setFocusPolicy(Qt::StrongFocus);
        MainWindow->setIconSize(QSize(40, 40));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMouseTracking(true);
        centralwidget->setFocusPolicy(Qt::StrongFocus);
        horizontalLayout_6 = new QHBoxLayout(centralwidget);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        MainWidget = new QWidget(centralwidget);
        MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->setMouseTracking(true);
        MainWidget->setFocusPolicy(Qt::StrongFocus);
        verticalLayout_2 = new QVBoxLayout(MainWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        AudioWidget = new QWidget(MainWidget);
        AudioWidget->setObjectName(QString::fromUtf8("AudioWidget"));
        AudioWidget->setMouseTracking(true);
        verticalLayout_5 = new QVBoxLayout(AudioWidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        AudioShowWidget = new QWidget(AudioWidget);
        AudioShowWidget->setObjectName(QString::fromUtf8("AudioShowWidget"));
        AudioShowWidget->setMouseTracking(true);
        gridLayout = new QGridLayout(AudioShowWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 11, 0, 11);
        verticalSpacer = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 3, 1, 1);

        widget = new QWidget(AudioShowWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_6 = new QVBoxLayout(widget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        AudioInfoLabel = new QLabel(widget);
        AudioInfoLabel->setObjectName(QString::fromUtf8("AudioInfoLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AudioInfoLabel->sizePolicy().hasHeightForWidth());
        AudioInfoLabel->setSizePolicy(sizePolicy);
        AudioInfoLabel->setStyleSheet(QString::fromUtf8(""));
        AudioInfoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(AudioInfoLabel);

        LRCWidget = new QListWidget(widget);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(LRCWidget);
        __qlistwidgetitem->setTextAlignment(Qt::AlignCenter);
        LRCWidget->setObjectName(QString::fromUtf8("LRCWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LRCWidget->sizePolicy().hasHeightForWidth());
        LRCWidget->setSizePolicy(sizePolicy1);
        LRCWidget->setMouseTracking(true);
        LRCWidget->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"font: 700 9pt \"Microsoft YaHei UI\";"));
        LRCWidget->setFrameShape(QFrame::NoFrame);

        verticalLayout_6->addWidget(LRCWidget);


        gridLayout->addWidget(widget, 1, 3, 1, 1);

        AlbumCoverLabel = new QLabel(AudioShowWidget);
        AlbumCoverLabel->setObjectName(QString::fromUtf8("AlbumCoverLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(AlbumCoverLabel->sizePolicy().hasHeightForWidth());
        AlbumCoverLabel->setSizePolicy(sizePolicy2);
        AlbumCoverLabel->setMouseTracking(true);
        AlbumCoverLabel->setFrameShape(QFrame::WinPanel);

        gridLayout->addWidget(AlbumCoverLabel, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 4, 1, 1);


        verticalLayout_5->addWidget(AudioShowWidget);

        WaveLabel = new QLabel(AudioWidget);
        WaveLabel->setObjectName(QString::fromUtf8("WaveLabel"));
        WaveLabel->setFrameShape(QFrame::WinPanel);

        verticalLayout_5->addWidget(WaveLabel);


        verticalLayout_2->addWidget(AudioWidget);

        VideoScreenLabel = new QLabel(MainWidget);
        VideoScreenLabel->setObjectName(QString::fromUtf8("VideoScreenLabel"));
        VideoScreenLabel->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(VideoScreenLabel->sizePolicy().hasHeightForWidth());
        VideoScreenLabel->setSizePolicy(sizePolicy3);
        VideoScreenLabel->setMouseTracking(true);
        VideoScreenLabel->setFocusPolicy(Qt::StrongFocus);
        VideoScreenLabel->setFrameShape(QFrame::WinPanel);
        VideoScreenLabel->setFrameShadow(QFrame::Plain);
        VideoScreenLabel->setLineWidth(1);
        VideoScreenLabel->setAlignment(Qt::AlignCenter);
        VideoScreenLabel->setMargin(0);

        verticalLayout_2->addWidget(VideoScreenLabel);

        FunctionWidget = new QWidget(MainWidget);
        FunctionWidget->setObjectName(QString::fromUtf8("FunctionWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(FunctionWidget->sizePolicy().hasHeightForWidth());
        FunctionWidget->setSizePolicy(sizePolicy4);
        FunctionWidget->setMouseTracking(true);
        verticalLayout_3 = new QVBoxLayout(FunctionWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        ProcessWidget = new QWidget(FunctionWidget);
        ProcessWidget->setObjectName(QString::fromUtf8("ProcessWidget"));
        sizePolicy4.setHeightForWidth(ProcessWidget->sizePolicy().hasHeightForWidth());
        ProcessWidget->setSizePolicy(sizePolicy4);
        horizontalLayout_3 = new QHBoxLayout(ProcessWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(5, -1, 5, 0);
        CurrentTimeLabel = new QLabel(ProcessWidget);
        CurrentTimeLabel->setObjectName(QString::fromUtf8("CurrentTimeLabel"));

        horizontalLayout_3->addWidget(CurrentTimeLabel);

        ProgressSlider = new PlayerSlider(ProcessWidget);
        ProgressSlider->setObjectName(QString::fromUtf8("ProgressSlider"));
        ProgressSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(ProgressSlider);

        TotalTimeLabel = new QLabel(ProcessWidget);
        TotalTimeLabel->setObjectName(QString::fromUtf8("TotalTimeLabel"));

        horizontalLayout_3->addWidget(TotalTimeLabel);


        verticalLayout_3->addWidget(ProcessWidget);

        ButtonWidget = new QWidget(FunctionWidget);
        ButtonWidget->setObjectName(QString::fromUtf8("ButtonWidget"));
        sizePolicy4.setHeightForWidth(ButtonWidget->sizePolicy().hasHeightForWidth());
        ButtonWidget->setSizePolicy(sizePolicy4);
        ButtonWidget->setMouseTracking(true);
        horizontalLayout_5 = new QHBoxLayout(ButtonWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(5, 0, 5, 0);
        ModeWidget = new QWidget(ButtonWidget);
        ModeWidget->setObjectName(QString::fromUtf8("ModeWidget"));
        sizePolicy2.setHeightForWidth(ModeWidget->sizePolicy().hasHeightForWidth());
        ModeWidget->setSizePolicy(sizePolicy2);
        ModeWidget->setMouseTracking(true);
        horizontalLayout_4 = new QHBoxLayout(ModeWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, -1, -1, -1);
        ModeButton = new ChangeButtonColor(ModeWidget);
        ModeButton->setObjectName(QString::fromUtf8("ModeButton"));
        ModeButton->setMouseTracking(true);
        ModeButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/PlaySingle.png"), QSize(), QIcon::Normal, QIcon::Off);
        ModeButton->setIcon(icon);

        horizontalLayout_4->addWidget(ModeButton);

        VoiceButton = new ChangeButtonColor(ModeWidget);
        VoiceButton->setObjectName(QString::fromUtf8("VoiceButton"));
        VoiceButton->setMouseTracking(true);
        VoiceButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/Voice.png"), QSize(), QIcon::Normal, QIcon::Off);
        VoiceButton->setIcon(icon1);

        horizontalLayout_4->addWidget(VoiceButton);

        SetButton = new ChangeButtonColor(ModeWidget);
        SetButton->setObjectName(QString::fromUtf8("SetButton"));
        SetButton->setMouseTracking(true);
        SetButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/Set.png"), QSize(), QIcon::Normal, QIcon::Off);
        SetButton->setIcon(icon2);

        horizontalLayout_4->addWidget(SetButton);


        horizontalLayout_5->addWidget(ModeWidget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        PlayWidget = new QWidget(ButtonWidget);
        PlayWidget->setObjectName(QString::fromUtf8("PlayWidget"));
        sizePolicy2.setHeightForWidth(PlayWidget->sizePolicy().hasHeightForWidth());
        PlayWidget->setSizePolicy(sizePolicy2);
        PlayWidget->setMouseTracking(true);
        horizontalLayout = new QHBoxLayout(PlayWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LastVedioButton = new ChangeButtonColor(PlayWidget);
        LastVedioButton->setObjectName(QString::fromUtf8("LastVedioButton"));
        LastVedioButton->setMouseTracking(true);
        LastVedioButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/Next.png"), QSize(), QIcon::Normal, QIcon::Off);
        LastVedioButton->setIcon(icon3);

        horizontalLayout->addWidget(LastVedioButton);

        PlayButton = new ChangeButtonColor(PlayWidget);
        PlayButton->setObjectName(QString::fromUtf8("PlayButton"));
        PlayButton->setMouseTracking(true);
        PlayButton->setStyleSheet(QString::fromUtf8("background-color: rgba(128, 128, 128, 0);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/Play.png"), QSize(), QIcon::Normal, QIcon::Off);
        PlayButton->setIcon(icon4);
        PlayButton->setCheckable(false);
        PlayButton->setPopupMode(QToolButton::DelayedPopup);

        horizontalLayout->addWidget(PlayButton);

        NextVedioButton = new ChangeButtonColor(PlayWidget);
        NextVedioButton->setObjectName(QString::fromUtf8("NextVedioButton"));
        NextVedioButton->setMouseTracking(true);
        NextVedioButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/Last.png"), QSize(), QIcon::Normal, QIcon::Off);
        NextVedioButton->setIcon(icon5);

        horizontalLayout->addWidget(NextVedioButton);


        horizontalLayout_5->addWidget(PlayWidget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        ControlWidget = new QWidget(ButtonWidget);
        ControlWidget->setObjectName(QString::fromUtf8("ControlWidget"));
        sizePolicy2.setHeightForWidth(ControlWidget->sizePolicy().hasHeightForWidth());
        ControlWidget->setSizePolicy(sizePolicy2);
        ControlWidget->setMouseTracking(true);
        horizontalLayout_2 = new QHBoxLayout(ControlWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 0, -1);
        FullScreenButton = new ChangeButtonColor(ControlWidget);
        FullScreenButton->setObjectName(QString::fromUtf8("FullScreenButton"));
        FullScreenButton->setMouseTracking(true);
        FullScreenButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/FullScreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        FullScreenButton->setIcon(icon6);

        horizontalLayout_2->addWidget(FullScreenButton);

        AddButton = new ChangeButtonColor(ControlWidget);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setMouseTracking(true);
        AddButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/Plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddButton->setIcon(icon7);

        horizontalLayout_2->addWidget(AddButton);

        PlayListButton = new ChangeButtonColor(ControlWidget);
        PlayListButton->setObjectName(QString::fromUtf8("PlayListButton"));
        PlayListButton->setMouseTracking(true);
        PlayListButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/PlayList.png"), QSize(), QIcon::Normal, QIcon::Off);
        PlayListButton->setIcon(icon8);

        horizontalLayout_2->addWidget(PlayListButton);


        horizontalLayout_5->addWidget(ControlWidget);


        verticalLayout_3->addWidget(ButtonWidget);


        verticalLayout_2->addWidget(FunctionWidget);


        horizontalLayout_6->addWidget(MainWidget);

        PlayListWidget = new QWidget(centralwidget);
        PlayListWidget->setObjectName(QString::fromUtf8("PlayListWidget"));
        PlayListWidget->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(PlayListWidget->sizePolicy().hasHeightForWidth());
        PlayListWidget->setSizePolicy(sizePolicy5);
        PlayListWidget->setMouseTracking(true);
        verticalLayout = new QVBoxLayout(PlayListWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, 0);
        ScrollArea = new QScrollArea(PlayListWidget);
        ScrollArea->setObjectName(QString::fromUtf8("ScrollArea"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(ScrollArea->sizePolicy().hasHeightForWidth());
        ScrollArea->setSizePolicy(sizePolicy6);
        ScrollArea->setMouseTracking(true);
        ScrollArea->setFrameShape(QFrame::WinPanel);
        ScrollArea->setFrameShadow(QFrame::Plain);
        ScrollArea->setWidgetResizable(true);
        ScrollAreaWidgetContents = new QWidget();
        ScrollAreaWidgetContents->setObjectName(QString::fromUtf8("ScrollAreaWidgetContents"));
        ScrollAreaWidgetContents->setGeometry(QRect(0, 0, 278, 554));
        ScrollAreaWidgetContents->setMouseTracking(true);
        verticalLayout_4 = new QVBoxLayout(ScrollAreaWidgetContents);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        ListWidget = new MyListWidget(ScrollAreaWidgetContents);
        ListWidget->setObjectName(QString::fromUtf8("ListWidget"));
        sizePolicy.setHeightForWidth(ListWidget->sizePolicy().hasHeightForWidth());
        ListWidget->setSizePolicy(sizePolicy);
        ListWidget->setMinimumSize(QSize(100, 0));
        ListWidget->setMouseTracking(true);
        ListWidget->setFocusPolicy(Qt::StrongFocus);
        ListWidget->setFrameShape(QFrame::HLine);
        ListWidget->setDragDropMode(QAbstractItemView::InternalMove);
        ListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        ListWidget->setMovement(QListView::Free);

        verticalLayout_4->addWidget(ListWidget);

        ScrollArea->setWidget(ScrollAreaWidgetContents);

        verticalLayout->addWidget(ScrollArea);


        horizontalLayout_6->addWidget(PlayListWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        AudioInfoLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p style='line-height:30%'>\346\255\214\345\220\215</p><p style='line-height:30%'>\346\255\214\346\211\213</p><p style='line-height:30%'>\344\270\223\350\276\221</p></body></html>", nullptr));

        const bool __sortingEnabled = LRCWidget->isSortingEnabled();
        LRCWidget->setSortingEnabled(false);
        LRCWidget->setSortingEnabled(__sortingEnabled);

        AlbumCoverLabel->setText(QCoreApplication::translate("MainWindow", "\344\270\223\350\276\221\345\260\201\351\235\242", nullptr));
        WaveLabel->setText(QCoreApplication::translate("MainWindow", "\346\263\242\345\275\242\345\233\276", nullptr));
        VideoScreenLabel->setText(QString());
        CurrentTimeLabel->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        TotalTimeLabel->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        ModeButton->setText(QCoreApplication::translate("MainWindow", "\345\215\225\346\233\262\346\222\255\346\224\276", nullptr));
        VoiceButton->setText(QCoreApplication::translate("MainWindow", "\351\237\263\351\207\217", nullptr));
        SetButton->setText(QString());
        LastVedioButton->setText(QCoreApplication::translate("MainWindow", "\344\270\212", nullptr));
        PlayButton->setText(QString());
        NextVedioButton->setText(QCoreApplication::translate("MainWindow", "\344\270\213", nullptr));
        FullScreenButton->setText(QCoreApplication::translate("MainWindow", "\345\205\250\345\261\217", nullptr));
        AddButton->setText(QString());
        PlayListButton->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
