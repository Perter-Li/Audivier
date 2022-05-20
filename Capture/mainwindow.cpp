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
    v_info = new Video("D:\\Data\\QT\\tutorial\\QtMultimedia\\MediaTest3\\Divergence.mp4");
    m_pVideoWidget->resize(ui->label_screen->size());  //把视频输出图像的大小重新调整为label的大小
    layout->addWidget(m_pVideoWidget);  //指定视频播放的界面位置
    ui->label_screen->setLayout(layout);
    m_pMediaPlayer->setVideoOutput(m_pVideoWidget);  //设置视频输出附加到媒体播放器
    m_pMediaPlayer->setAudioOutput(audioOutput);  //设置音频输出附加到媒体播放器
    play_state = true;
//    m_pMediaPlayer->play();
    connect(m_pMediaPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(getduration(qint64)));
    connect(m_pMediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(getposition(qint64)));
    v_info->getInfo();

//    //基于FFmpeg提取视频信息
//    AVFormatContext* format_ctx = avformat_alloc_context();
//    const char* url = "Divergence.mp4";
//    int ret = -1;
//    AVDictionary* dict = nullptr;
//    av_dict_set(&dict, "max_delay", "100", 0);
//    ret = avformat_open_input(&format_ctx, url, nullptr, &dict);
//    if (ret != 0) {
//        fprintf(stderr, "fail to open url: %s, return value: %d\n", url, ret);
//    }

//    fprintf(stdout, "dictionary count: %d\n", av_dict_count(format_ctx->metadata));
//    AVDictionaryEntry* entry = nullptr;
//    while ((entry = av_dict_get(format_ctx->metadata, "", entry, AV_DICT_IGNORE_SUFFIX))) {
//        fprintf(stdout, "key: %s, value: %s\n", entry->key, entry->value);
//        qDebug() << entry->key << entry->value;
//    }
//    avformat_free_context(format_ctx);
//    av_dict_free(&dict);

//    //借助析构函数来释放自源
//    AudioInfoGuard guard;

//    //打开输入流并读取头
//    //流要使用avformat_close_input关闭
//    //成功时返回=0
//    int result=avformat_open_input(&guard.formatCtx, url, NULL, NULL);
//    if (result!=0||guard.formatCtx==NULL){
////        return false;
//    }

//    //读取文件获取流信息，把它存入AVFormatContext中
//    //正常时返回>=0
//    if (avformat_find_stream_info(guard.formatCtx, NULL) < 0) {
////        return false;
//    }

//    //获取元信息，曲名，歌手等
//    AVDictionaryEntry *tag = NULL;
//    while (tag = av_dict_get(guard.formatCtx->metadata, "", tag, AV_DICT_IGNORE_SUFFIX))
//    {
//        qDebug()<<tag->key<<tag->value;
//    }

//    qDebug()<<"filepath"<<url;
//    //时长
//    //duration/AV_TIME_BASE单位为秒
//    qDebug()<<"duration"<<guard.formatCtx->duration/(AV_TIME_BASE/1000.0)<<"ms";
//    //文件格式，如wav
//    qDebug()<<"format"<<guard.formatCtx->iformat->name<<":"<<guard.formatCtx->iformat->long_name;
//    //这是容器的比特率
//    qDebug()<<"bit rate"<<guard.formatCtx->bit_rate<<"bps";
//    qDebug()<<"n stream"<<guard.formatCtx->nb_streams;

//    for (unsigned int i = 0; i < guard.formatCtx->nb_streams; i++)
//    {
//        //AVStream是存储每一个视频/音频流信息的结构体
//        AVStream *in_stream = guard.formatCtx->streams[i];

//        //类型为音频
//        if(in_stream->codecpar->codec_type == AVMEDIA_TYPE_AUDIO){
//            //查找具有匹配编解码器ID的已注册解码器
//            //失败返回NULL
//            guard.codec = avcodec_find_decoder(in_stream->codecpar->codec_id);
//            if(guard.codec==NULL){
////                return false;
//            }

//            //分配AVCodecContext并将其字段设置为默认值
//            //需要使用avcodec_free_context释放生成的对象
//            //如果失败，则返回默认填充或者 NULL
//            guard.codecCtx = avcodec_alloc_context3(guard.codec);
//            if(guard.codecCtx==NULL){
////                return false;
//            }

//            //根据编码器填充上下文参数
//            //事实上codecpar包含了大部分解码器相关的信息，这里是直接从AVCodecParameters复制到AVCodecContext
//            //成功时返回值>=0
//            if(avcodec_parameters_to_context(guard.codecCtx, in_stream->codecpar)<0){
////                return false;
//            }

//            //某些AVCodecContext字段的访问器，已弃用
//            //av_codec_set_pkt_timebase(codec_ctx, in_stream->time_base);

//            //打开解码器
//            //使用给定的AVCodec初始化AVCodecContext
//            //在之前必须使用avcodec_alloc_context3()分配上下文
//            //成功时返回值=0
//            if(avcodec_open2(guard.codecCtx, guard.codec, nullptr)!=0){
////                return false;
//            }

//            //采样率
//            qDebug()<<"sample rate"<<guard.codecCtx->sample_rate;
//            //通道数
//            qDebug()<<"channels"<<guard.codecCtx->channels;
//            //采样精度（暂时没找到获取采样精度的接口，用fmt来算的有些对不上）
//            //in_stream->codec->sample_fmt枚举AVSampleFormat表示数据存储格式，如16位无符号
//            //av_get_bytes_per_sample返回AVSampleFormat对应的字节大小
//            qDebug()<<"sample bit"<<guard.codecCtx->sample_fmt<<":"<<(av_get_bytes_per_sample(guard.codecCtx->sample_fmt)<<3);
//            //音频的比特率
//            qDebug()<<"bit rate"<<guard.codecCtx->bit_rate;
//            //编码，如pcm
//            qDebug()<<"codec name"<<guard.codec->name<<":"<<guard.codec->long_name;
////            return true;
//        }
////    }
////    #else
//        else
//        //新的版本这种获取方式已弃用
//        AVStream *in_stream = guard.formatCtx->streams[i];
//        AVCodecContext *avctx=in_stream->codec;
//        if (avctx->codec_type == AVMEDIA_TYPE_VIDEO){
//            //视频信息略
//        }else if (avctx->codec_type == AVMEDIA_TYPE_AUDIO){
//            //音频信息
//            qDebug()<<"sample rate"<<in_stream->codec->sample_rate;
//            qDebug()<<"channels"<<in_stream->codec->channels;
//            //in_stream->codec->sample_fmt枚举AVSampleFormat表示数据存储格式，如16位无符号
//            //av_get_bytes_per_sample返回AVSampleFormat对应的字节大小
//            qDebug()<<"sample bit"<<in_stream->codec->sample_fmt<<":"<<(av_get_bytes_per_sample(in_stream->codec->sample_fmt)<<3);

//            AVCodec *codec=avcodec_find_decoder(avctx->codec_id);
//            if(codec==NULL){
////                return;
//            }
//            qDebug()<<"codec name"<<codec->name<<":"<<codec->long_name;
////            return true;
//        }
//    }
//    #endif

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
    m_pMediaPlayer->setSource(QUrl::fromLocalFile("V.mp3"));  //载入视频文件
    a_info = new Audio("D:\\Data\\QT\\tutorial\\QtMultimedia\\MediaTest3\\V.mp3");
    play_state = true;
    m_pMediaPlayer->setAudioOutput(audioOutput);  //设置音频输出附加到媒体播放器
    m_pMediaPlayer->play();
    connect(m_pMediaPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(getduration(qint64)));
    connect(m_pMediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(getposition(qint64)));
    a_info->getInfo();
    ui->label_screen->setPixmap(QPixmap::fromImage(a_info->getCover()));

    //基于FFmpeg提取音频信息
//    AVFormatContext* format_ctx = avformat_alloc_context();
//    const char* url = "V.mp3";
//    int ret = -1;
//    AVDictionary* dict = nullptr;
//    av_dict_set(&dict, "max_delay", "100", 0);
//    ret = avformat_open_input(&format_ctx, url, nullptr, &dict);
//    if (ret != 0) {
//        fprintf(stderr, "fail to open url: %s, return value: %d\n", url, ret);
//    }

////    fprintf(stdout, "dictionary count: %d\n", av_dict_count(format_ctx->metadata));
//    AVDictionaryEntry* entry = nullptr;
//    while ((entry = av_dict_get(format_ctx->metadata, "", entry, AV_DICT_IGNORE_SUFFIX))) {
//        fprintf(stdout, "key: %s, value: %s\n", entry->key, entry->value);
//        qDebug() << entry->key << entry->value;
//    }
////    avformat_free_context(format_ctx);
//    av_dict_free(&dict);

//    QPixmap pix_img("music.jpeg");
//    ui->label_screen->setPixmap(pix_img);
//    //基于FFmpeg提取封面图片
//    for (int i = 0; i < format_ctx->nb_streams; i++){
//       if (format_ctx->streams[i]->disposition & AV_DISPOSITION_ATTACHED_PIC) {
//           AVPacket pkt = format_ctx->streams[i]->attached_pic;
//           //使用QImage读取完整图片数据（注意，图片数据是为解析的文件数据，需要用QImage::fromdata来解析读取）
//           QImage img = QImage::fromData((uchar*)pkt.data, pkt.size);
//           ui->label_screen->setPixmap(QPixmap::fromImage(img));
//           qDebug() << "here";
//           break;
//       }
//   }
//    avformat_free_context(format_ctx);
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

void MainWindow::on_foward_button_clicked()
{
    int frame = 5;
    if(play_state == true)
    {
        m_pMediaPlayer->pause();
        play_state = false;
    }
    //
    qDebug() << "duration: " << this->m_pMediaPlayer->duration();
//    this->m_pMediaPlayer->playbackState();
    qDebug() << "current: " << this->m_pMediaPlayer->position();
    qDebug() << "num_frames: " << this->v_info->nb_frames;
    qDebug() << "current + 1 / num_frames" << (qint64)(this->m_pMediaPlayer->position() + 1 / (float)this->v_info->nb_frames * (float)this->m_pMediaPlayer->duration());
    //
    qint64 move = (qint64)(this->m_pMediaPlayer->position() + 1 / (float)this->v_info->nb_frames * (float)this->m_pMediaPlayer->duration());
    m_pMediaPlayer->setPosition(move);
}


void MainWindow::on_back_button_clicked()
{
    int frame = -5;
    if(play_state == true)
    {
        m_pMediaPlayer->pause();
        play_state = false;
    }
    //
    qDebug() << "duration: " << this->m_pMediaPlayer->duration();
//    this->m_pMediaPlayer->playbackState();
    qDebug() << "current: " << this->m_pMediaPlayer->position();
    qDebug() << "num_frames: " << this->v_info->nb_frames;
    qDebug() << "current + 1 / num_frames" << (qint64)(this->m_pMediaPlayer->position() + 1 / (float)this->v_info->nb_frames * (float)this->m_pMediaPlayer->duration());
    //
    qint64 move = (qint64)(this->m_pMediaPlayer->position() + 1 / (float)this->v_info->nb_frames * (float)this->m_pMediaPlayer->duration());
    m_pMediaPlayer->setPosition(move);
}


void MainWindow::on_previewSlider_sliderPressed()
{
    qDebug() << "Slider position: " << this->ui->previewSlider->value();    // 按百分比显示
    this->preview_frame_time = (int)((float)this->ui->previewSlider->value() / 100.0 * (float)this->m_pMediaPlayer->duration() / 1000.0);
    qDebug() << "preview_frame_time: " << this->preview_frame_time;
//    qDebug() << "(float)this->ui->previewSlider->value() / 100.0: " << (float)this->ui->previewSlider->value() / 100.0;
//    qDebug() << "(float)this->m_pMediaPlayer->duration(): " << (float)this->m_pMediaPlayer->duration();
}

void MainWindow::on_getView_button_clicked()
{
    const char*file_path = "D:\\Data\\QT\\tutorial\\QtMultimedia\\MediaTest3\\Divergence.mp4";

    int ret = -1, index = 0, image_size = -1;
    int videoStream = -1, got_picture = -1, numBytes= -1;
    uint8_t *out_buffer = NULL;

    AVFormatContext *pFormatCtx = NULL;
    AVCodecContext *pCodecCtx = NULL;
    AVCodec *pCodec = NULL;
    AVPacket *packet = NULL;
    AVFrame *pFrame = NULL, *pFrameRGB = NULL;
    struct SwsContext *img_convert_ctx = NULL;

    av_register_all();
    pFormatCtx = avformat_alloc_context();
    if(NULL == pFormatCtx){
        qDebug() << "avformat_alloc_context() failed.";
    }

    // 1. 打开视频文件;
    ret = avformat_open_input(&pFormatCtx, file_path, NULL, NULL);
    if(ret < 0){
        qDebug() << "avformat_open_input() failed.";
    }

    // 2. 读取视频文件信息;
    ret = avformat_find_stream_info(pFormatCtx, NULL);
    if (ret < 0) {
        qDebug() << "avformat_find_stream_info() failed.";
    }

    // 3. 获取视频流
    for (int i = 0; i < pFormatCtx->nb_streams; i++) {
        if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoStream = i;
        }
    }
    if (videoStream == -1) {
        qDebug() << "coun't find a video stream.";
    }

    // 4. 根据上面得到的视频流类型打开对应的解码器
    pCodecCtx = pFormatCtx->streams[videoStream]->codec;
    pCodec = avcodec_find_decoder(pCodecCtx->codec_id);
    if (pCodec == NULL) {
        qDebug() <<"Decoder not found.";
    }
    if (avcodec_open2(pCodecCtx, pCodec, NULL) < 0) {
        qDebug() <<"Ddecoder couldn't open.";
    }

    // 5. 分配并初始化一个视频packet
    image_size = pCodecCtx->width * pCodecCtx->height;
    packet = (AVPacket *) malloc(sizeof(AVPacket)); //分配一个packet
    if(!packet){
        qDebug() <<"malloc() failed.";
    }
    ret = av_new_packet(packet, image_size);
    if(ret < 0){
        qDebug() <<"av_new_packet() failed.";
    }

    // 6. 分配两个frame分别存放yuv和rgb数据
    pFrame = av_frame_alloc();
    pFrameRGB = av_frame_alloc();
    if(!pFrame || !pFrameRGB){
        qDebug() <<"pFrame:" << pFrame
               <<", pFrameRGB:" << pFrameRGB
              <<" av_frame_alloc() failed";
    }

    // 7. 分配一个struct SwsContext结构体, 填充源图像和目标图像信息(为接下来的转换做准备)
    img_convert_ctx = sws_getContext(pCodecCtx->width, pCodecCtx->height,
                pCodecCtx->pix_fmt, pCodecCtx->width, pCodecCtx->height,
                AV_PIX_FMT_RGB24, SWS_BICUBIC, NULL, NULL, NULL);

    // 8. pFrameRGB和out_buffer都是已经申请到的一段内存, 会将pFrameRGB的数据按RGB24格式自动"关联(转换并放置)"到out_buffer。
    numBytes = avpicture_get_size(AV_PIX_FMT_RGB24, pCodecCtx->width,pCodecCtx->height);
    out_buffer = (uint8_t *) av_malloc(numBytes * sizeof(uint8_t));
    ret = avpicture_fill((AVPicture *) pFrameRGB, out_buffer, AV_PIX_FMT_RGB24,
                pCodecCtx->width, pCodecCtx->height);
    if (!img_convert_ctx || numBytes<0 || !out_buffer || ret<0) {
        qDebug() <<"img_convert_ctx:" << img_convert_ctx
               <<", numBytes:" << numBytes
              <<", out_buffer:" << out_buffer
             <<", ret:" <<ret;
    }

    // 9. 按时间寻找需要的帧
    ret = av_seek_frame(pFormatCtx, -1, this->preview_frame_time * AV_TIME_BASE, AVSEEK_FLAG_BACKWARD); // this->preview_frame_time，单位为s，即为预览图所在时间点

    while(1){
        if (av_read_frame(pFormatCtx, packet) < 0) {
            break;
        }

        if (packet->stream_index == videoStream) {
            ret = avcodec_decode_video2(pCodecCtx, pFrame, &got_picture,packet);
            if (ret < 0) {
                qDebug() << "decode error.";
            }
        }

        if (got_picture) {
            if(pFrame->key_frame == 1)  // 提取关键帧
            {
                sws_scale(img_convert_ctx,
                        (uint8_t const * const *) pFrame->data,
                        pFrame->linesize, 0, pCodecCtx->height, pFrameRGB->data,
                        pFrameRGB->linesize);

                // 将提取的关键帧显示到label_preview上
                QImage image(pFrameRGB->data[0], pCodecCtx->width, pCodecCtx->height, pFrameRGB->linesize[0], QImage::Format_RGB888);
                ui->label_preview->setPixmap(QPixmap::fromImage(image));
                ui->label_preview->setScaledContents(true);
            }
        }

        index++;
        if(index > 100){
            break;
        }
    }
}
