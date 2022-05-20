#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QFileInfo>
#include <QMessageBox>
#include <QListWidget>
#include <QDebug>
#include <QRandomGenerator>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QVideoWidget>
#include <QVBoxLayout>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool eventFilter(QObject *watched, QEvent *event);//事件过滤器
    void dragEnterEvent(QDragEnterEvent *event);//拖拽事件
    void dropEvent(QDropEvent *event);//放下时间
    void PlayVedio(QString);//播放视频
    void keyPressEvent(QKeyEvent *event);   //键盘按下事件
    void keyReleaseEvent(QKeyEvent *event); //键盘松开事件
    QString getNextAudioOrVedio();//获取下一个播放的内容
    QString getLastAudioOrVedio();//获取上一个播放的内容
    QString getListItemFileAddress(QListWidgetItem *item);//获取列表项中的地址
    void SetCurrentListItemColor(QColor q);
    void SaveLocalCache();
    void LoadLocalCache();
    void PlayAudioAndVedio(QString file);

private slots:
    void on_PlayButton_clicked();//播放按钮槽函数
    void on_timer_timeout();//计时器槽函数
    void on_FullScreenButton_clicked();//全屏按钮槽函数
    void on_PlayListButton_clicked();//播放列表槽函数
    void on_ListWidget_itemDoubleClicked(QListWidgetItem *item);//播放列表项槽函数
    void on_ModeButton_clicked();//模式按钮槽函数

    void on_NextVedioButton_clicked();

    void on_LastVedioButton_clicked();

    void on_SpeadButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* FunctionWidgetTimer;
    int PlaySeqence = 1;
    int PlayOrStopTag = 0;
    int PlayRate = 1;
    int CurrentAudioOrVedio = 0;
    QMediaPlayer *player = new QMediaPlayer;  //用于解析视频流的媒体播放器
    QVideoWidget *videowidget = new QVideoWidget;  //用于播放视频
    QVBoxLayout *layout = new QVBoxLayout;  //用于指定视频播放的位置
    QAudioOutput *audioOutput = new QAudioOutput; // chooses the default audio routing
};
#endif // MAINWINDOW_H
