#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>  //播放器
#include <QVideoWidget>  //播放窗口
//#include <QMediaPlaylist>//播放列表
#include <QString>
#include <QFileDialog>//文件窗口
#include <QDebug>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QListWidgetItem>
#include <QAudioOutput>
#include <QVBoxLayout>
#include <QMediaMetaData>
#include <QPixmap>

// libzplay
//#include "stdafx.h"
#include <stdio.h>
#include <string>

//using namespace libZPlay;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

extern "C" {
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libavutil/imgutils.h"
#include "libavutil/log.h"
//#include "libzplay.h"
}

//https://doc.qt.io/qt-5/qmediametadata.html

//Media有关的类声明
struct AudioInfoGuard {
    //格式化I/O上下文
    AVFormatContext *formatCtx = NULL;
    //解码器
    AVCodec *codec = NULL;
    //解码器上下文
    AVCodecContext *codecCtx = NULL;

    ~AudioInfoGuard() {
        if(codecCtx){
            avcodec_free_context(&codecCtx);
        }
        if(formatCtx){
            avformat_close_input(&formatCtx);
            avformat_free_context(formatCtx);
        }
    }
};

class MediaTime
{
public:
    MediaTime():sec((qint64(0))),
        min((qint64(0))),
        hrs((qint64(0))){};
    MediaTime(qint64 play_time);
    ~MediaTime(){};
    QString getTime();
    void setTime(qint64 play_time);
    qint64 sec;
    qint64 min;
    qint64 hrs;

private:
};

class Media
{
public:
    Media(const char* path);
    ~Media(){};
    QString path;
    MediaTime duration;
    MediaTime current_T;

protected:
};

class Video : public Media
{
public:
    Video(const char* path);
    ~Video(){};
    QString getInfo();
    QString name;
    QString bit_rate;
    QString frame_rate;
    int nb_frames;
    QString codec;
    QString resolution;

protected:
};

class Audio : public Media
{
public:
    Audio(const char* path);
    ~Audio(){};
    QString getInfo();
    QImage getCover();
    QString name;
    QString bit_rate;
    int channel_count;
    QString codec;
    QString album;
    QString artist;
    QImage cover;

protected:
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setget_Alltime(qint64 playtime);//获取视频时长并设置到标签
    void setget_currenttime(qint64 playtime);//获取当时播放位置并设置
    void settimeslider(qint64 playtime);//设置进度条
    ~MainWindow();
//    ZPlay* player;

protected:
//    void resizeEvent(QResizeEvent *event);
//    void keyPressEvent(QKeyEvent* e);
//    void mousePressEvent(QMouseEvent* e);
//    void mouseDoubleClickEvent(QMouseEvent *e);

private slots:
    void on_start_button_clicked();
    void getduration(qint64 playtime);   //获取时间改变信号
    void getposition(qint64 playtime);

    void on_load_button_clicked();

    void on_Info_button_clicked();

    void on_music_button_clicked();

    void on_volume_slider_valueChanged(int value);

    void on_foward_button_clicked();

    void on_back_button_clicked();

    void on_previewSlider_sliderPressed();

    void on_getView_button_clicked();

private:
    Ui::MainWindow *ui;
    QStringList         m_strlist;          //文件名列表
    QMediaPlayer*       m_pMediaPlayer;     //播放器
    QVideoWidget*       m_pVideoWidget;     //播放窗口
    QVBoxLayout *layout = new QVBoxLayout;  //用于指定视频播放的位置
    QAudioOutput *audioOutput = new QAudioOutput; // chooses the default audio routing
    Video *v_info;
    Audio *a_info;
//    QMediaPlaylist*     m_MediaPlaylist;    //播放列表
//    QMediaPlayer::State m_state;            //播放状态
    int m_hour;                             //视频总时长
    int m_min;                           //分钟
    int m_sec;                           //秒
    bool m_sliderstate;                     //滑块是否被选中的状态
    int m_slider_crtval;                    //滑块当前值
    bool play_state;                         //是否正在播放
    int preview_frame_time;
};
#endif // MAINWINDOW_H

