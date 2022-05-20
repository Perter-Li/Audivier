#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pMediaPlayer = new QMediaPlayer;
    m_pVideoWidget = new QVideoWidget(ui->label_screen);

//    qDebug() << m_pMediaPlayer->staticMetaObject.Title;

    m_sliderstate = false;
    connect(ui->progress_slider, &PlayerSlider::mousepress, [=](int val){
        m_sliderstate = true;
        play_state = false;
        m_pMediaPlayer->pause();
        qDebug() << "progress slider pressed by mouse" << val;
    });
    connect(ui->progress_slider, &PlayerSlider::mouserelease, [=](int val){
        m_sliderstate = false;
        m_pMediaPlayer->setPosition(val*1000);
        ui->progress_slider->setValue(val*1000);
        play_state = true;
        m_pMediaPlayer->play();
        qint64 playtime = m_pMediaPlayer->position();
        qDebug() << "progress slider released by mouse" << val;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_load_button_clicked()
{
    // 载入视频
    m_pMediaPlayer->setSource(QUrl::fromLocalFile("Divergence.mp4"));  //载入视频文件
    m_pVideoWidget->resize(ui->label_screen->size());  //把视频输出图像的大小重新调整为label的大小
    layout->addWidget(m_pVideoWidget);  //指定视频播放的界面位置
    ui->label_screen->setLayout(layout);
    m_pMediaPlayer->setVideoOutput(m_pVideoWidget);  //设置视频输出附加到媒体播放器
    m_pMediaPlayer->setAudioOutput(audioOutput);  //设置音频输出附加到媒体播放器
    play_state = true;
//    m_pMediaPlayer->play();
    connect(m_pMediaPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(getduration(qint64)));
    connect(m_pMediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(getposition(qint64)));

    //基于FFmpeg提取视频信息
    AVFormatContext* format_ctx = avformat_alloc_context();
    const char* url = "Divergence.mp4";
    int ret = -1;
    AVDictionary* dict = nullptr;
    av_dict_set(&dict, "max_delay", "100", 0);
    ret = avformat_open_input(&format_ctx, url, nullptr, &dict);
    if (ret != 0) {
        fprintf(stderr, "fail to open url: %s, return value: %d\n", url, ret);
    }

    fprintf(stdout, "dictionary count: %d\n", av_dict_count(format_ctx->metadata));
    AVDictionaryEntry* entry = nullptr;
    while ((entry = av_dict_get(format_ctx->metadata, "", entry, AV_DICT_IGNORE_SUFFIX))) {
        fprintf(stdout, "key: %s, value: %s\n", entry->key, entry->value);
        qDebug() << entry->key << entry->value;
    }
    avformat_free_context(format_ctx);
    av_dict_free(&dict);


    //尝试用metaData()读取音视频信息，失败
    //qDebug() << m_pMediaPlayer->metaData().stringValue(QMediaMetaData::VideoCodec);

    //尝试用ZPlay读取音频信息，失败
    //    char *location = "Sea, You & Me.flac";//要读取的文件的地址。
    //    std::string location = "Divergence.mp4";
    //    ZPlay* file = CreateZPlay();//创建类实例file
    //    if(file == 0)
    //    {
    //        printf("创建libzplay ID3类实例失败！\n");
    //        system("pause");
    //    }
    //    TID3InfoEx id3_info;
    //    if(file->LoadFileID3Ex(location.c_str(), sfAutodetect, &id3_info, 1)) //加载file的ID3v2标签信息
    //    {
    //        printf("标题 Title:               %s\n", id3_info.Title);
    //        printf("参与创作的艺术家 Artist:  %s\n", id3_info.Artist);
    //        printf("唱片集 Album:             %s\n", id3_info.Album);
    //        printf("年 Year:                  %s\n\n", id3_info.Year);
    //        printf("备注 Comment:             %s\n\n", id3_info.Comment);
    //        printf("流派 Genre:               %s\n", id3_info.Genre);
    //        printf("#（编号） Track:          %s\n", id3_info.TrackNum);
    //        printf("唱片集艺术家 Artist1:     %s\n", id3_info.AlbumArtist );
    //        printf("作曲者 Composer:          %s\n", id3_info.Composer );
    //        printf("Original:                 %s\n", id3_info.OriginalArtist );
    //        printf("Copyright:                %s\n", id3_info.Copyright );
    //        printf("URL:                      %s\n", id3_info.URL );
    //        printf("编码人员 Encoder:         %s\n", id3_info.Encoder );
    //        printf("发布者 Publisher:         %s\n", id3_info.Publisher );
    //        printf("BPM:                      %u\n", id3_info.BPM);
    //        printf("封面图片类型 MIME:        %s\n", id3_info.Picture.MIMEType);
    //        printf("TYPE:                     %u\n", id3_info.Picture.PictureType);
    //        printf("Desc:                     %s\n", id3_info.Picture.Description);
    //        printf("文件大小:                 %u\n", id3_info.Picture.PictureDataSize);
    //        file->DrawBitmapToHWND(NULL, 0, 0, 0, 0, id3_info.Picture.hBitmap);//打印封面图片
    //    }
    //    else
    //        printf("无法加载文件ID3标签信息\n");
    //    system("pause");
}

void MainWindow::on_music_button_clicked()
{
    //载入音乐
    m_pMediaPlayer->setSource(QUrl::fromLocalFile("Skyfall.mp3"));  //载入视频文件
    play_state = true;
    m_pMediaPlayer->setAudioOutput(audioOutput);  //设置音频输出附加到媒体播放器
    m_pMediaPlayer->play();
    connect(m_pMediaPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(getduration(qint64)));
    connect(m_pMediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(getposition(qint64)));

    //基于FFmpeg提取音频信息
    AVFormatContext* format_ctx = avformat_alloc_context();
    const char* url = "V.mp3";
    int ret = -1;
    AVDictionary* dict = nullptr;
    av_dict_set(&dict, "max_delay", "100", 0);
    ret = avformat_open_input(&format_ctx, url, nullptr, &dict);
    if (ret != 0) {
        fprintf(stderr, "fail to open url: %s, return value: %d\n", url, ret);
    }

//    fprintf(stdout, "dictionary count: %d\n", av_dict_count(format_ctx->metadata));
    AVDictionaryEntry* entry = nullptr;
    while ((entry = av_dict_get(format_ctx->metadata, "", entry, AV_DICT_IGNORE_SUFFIX))) {
        fprintf(stdout, "key: %s, value: %s\n", entry->key, entry->value);
        qDebug() << entry->key << entry->value;
    }
//    avformat_free_context(format_ctx);
    av_dict_free(&dict);

    QPixmap pix_img("music.jpeg");
    ui->label_screen->setPixmap(pix_img);
    //基于FFmpeg提取封面图片
    for (int i = 0; i < format_ctx->nb_streams; i++){
       if (format_ctx->streams[i]->disposition & AV_DISPOSITION_ATTACHED_PIC) {
           AVPacket pkt = format_ctx->streams[i]->attached_pic;
           //使用QImage读取完整图片数据（注意，图片数据是为解析的文件数据，需要用QImage::fromdata来解析读取）
           QImage img = QImage::fromData((uchar*)pkt.data, pkt.size);
           ui->label_screen->setPixmap(QPixmap::fromImage(img));
           qDebug() << "here";
           break;
       }
   }
    avformat_free_context(format_ctx);
}

void MainWindow::on_start_button_clicked()
{
    if(play_state == true)
    {
        m_pMediaPlayer->pause();
        play_state = false;
    }
    else
    {
        m_pMediaPlayer->play();
        play_state = true;
    }
}

void MainWindow::getduration(qint64 playtime)
{
    if(!m_sliderstate)
    {
        playtime = m_pMediaPlayer->duration();
        setget_Alltime(playtime);
    }
}

void MainWindow::setget_Alltime(qint64 playtime)
{
    playtime /= 1000;
    ui->progress_slider->setMinimum(0);
    ui->progress_slider->setMaximum(playtime);

    m_hour = playtime / 3600;
    m_min = (playtime - m_hour * 3600) / 60;
    m_sec = playtime - m_hour * 3600 - m_min * 60;
    qDebug() << "duration: " << m_hour << " " << m_min << " " << m_sec;
    QString str = QString("%1:%2:%3").arg(m_hour).arg(m_min).arg(m_sec);
    ui->label_allT->setText(str);
}

void MainWindow::getposition(qint64 playtime)
{
    if(!m_sliderstate)
    {
        playtime = m_pMediaPlayer->position();
        setget_currenttime(playtime);
    }
}

void MainWindow::setget_currenttime(qint64 playtime)
{
    playtime /= 1000;
    settimeslider(playtime);
    int h = playtime / 3600;
    int m = (playtime - h * 3600) / 60;
    int s = playtime - h * 3600 - m * 60;
//    qDebug() << "current: " << m_hour << " " << m_min << " " << m_sec;
    QString str = QString("%1:%2:%3").arg(h).arg(m).arg(s);
    ui->label_currentT->setText(str);
}

void MainWindow::settimeslider(qint64 playtime)
{
    if(!m_sliderstate)
        ui->progress_slider->setValue(playtime);
}

void MainWindow::on_Info_button_clicked()
{

}

void MainWindow::on_volume_slider_valueChanged(int value)
{
    qDebug() << (float)(value)/100;
    audioOutput->setVolume((float)(value)/100);
    ui->label_volume->setText(QString("音量:%1").arg(value));
}
