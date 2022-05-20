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

//using namespace libZPlay;

struct AudioInfo{
public:
    AudioInfo(QString title, QString author, QString audio_bit_rate,
              QString audio_codec, QString channel_count, QString album_title):
        title(title), author(author), audio_bit_rate(audio_bit_rate),
        audio_codec(audio_codec), channel_count(channel_count), album_title(album_title)
    {

    };
    QString getInfo(){
        QString info = "Title: " + title
                + "\nAuthor: " + author
                + "\nAudioBitRate: " + audio_bit_rate
                + "\nAudioCodec: " + audio_codec
                + "\nChannelCount: " + channel_count
                + "\nAlbumTitle: " + album_title;
        return info;
    };
    QString title = "UnKnown";
    QString author = "UnKnown";
    QString audio_bit_rate = "UnKnown";  //码率
    QString audio_codec = "UnKnown";  //编码格式
    QString channel_count = "UnKnown";  //声道数
    QString album_title = "UnKnown";  //专辑信息
};

struct VideoInfo{
public:
    VideoInfo(QString title, QString author, QString video_bit_rate,
              QString video_frame_rate, QString video_codec, QString resolution):
        title(title), author(author), video_bit_rate(video_bit_rate),
        video_frame_rate(video_frame_rate), video_codec(video_codec),
        resolution(resolution)
    {

    };
    QString getInfo(){
        QString info = "Title: " + title
                + "\nAuthor: " + author
                + "\nVideoBitRate: " + video_bit_rate
                + "\nVideoFrameRate: " + video_frame_rate
                + "\nVideoCodec: " + video_codec
                + "\nResolution: " + resolution;
        return info;
    };
    QString title = "UnKnown";
    QString author = "UnKnown";
    QString video_bit_rate = "UnKnown";  //码率
    QString video_frame_rate = "UnKnown";  //帧率
    QString video_codec = "UnKnown";  //编码格式
    QString resolution = "UnKnown";  //分辨率
};

//https://doc.qt.io/qt-5/qmediametadata.html

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

private:
    Ui::MainWindow *ui;
    QStringList         m_strlist;          //文件名列表
    QMediaPlayer*       m_pMediaPlayer;     //播放器
    QVideoWidget*       m_pVideoWidget;     //播放窗口
    QVBoxLayout *layout = new QVBoxLayout;  //用于指定视频播放的位置
    QAudioOutput *audioOutput = new QAudioOutput; // chooses the default audio routing
//    QMediaPlaylist*     m_MediaPlaylist;    //播放列表
//    QMediaPlayer::State m_state;            //播放状态
    int m_hour;                             //视频总时长
    int m_min;                           //分钟
    int m_sec;                           //秒
    bool m_sliderstate;                     //滑块是否被选中的状态
    int m_slider_crtval;                    //滑块当前值
    bool play_state;                         //是否正在播放
};
#endif // MAINWINDOW_H
