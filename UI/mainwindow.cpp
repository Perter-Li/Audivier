#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTime>

extern "C"{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/imgutils.h>
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setAcceptDrops(true);// 设置之后才能拖拽文件到窗口

    ui->VideoScreenLabel->setMouseTracking(1);//播放标签设置鼠标追踪
    ui->PlayListWidget->setMouseTracking(1);//播放列表设置鼠标追踪
    ui->VideoScreenLabel->installEventFilter(this);//播放标签设置事件过滤器

    ui->PlayListWidget->setVisible(0);

    FunctionWidgetTimer=new QTimer(this);//定义功能栏定时器
    FunctionWidgetTimer->setInterval(5000);//设置间隔为5s
    connect(FunctionWidgetTimer,SIGNAL(timeout()),this,SLOT(on_timer_timeout()));//关联定时器与定时器槽函数

    LoadLocalCache();//载入数据

}

void Delay(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PlayButton_clicked()
{
    if(PlayOrStopTag==0)
    {
        PlayOrStopTag=1;
        ui->PlayButton->setIcon(QIcon(":/images/Stop.png"));
        //PlayAudioAndVedio("D:\\jijidown\\JiJiDown\\Download\\lemon_chinese.mp3");
        player->play();
    }
    else if(PlayOrStopTag==1)
    {
        PlayOrStopTag=0;
        ui->PlayButton->setIcon(QIcon(":/images/Play.png"));
        player->pause();
    }
}

//全屏按钮
void MainWindow::on_FullScreenButton_clicked()
{
    if(this->isFullScreen()==0)//如果当前不是全屏
    {
        ui->FunctionWidget->setVisible(0);//功能栏隐藏
        this->setWindowFlags(Qt::FramelessWindowHint);//最小化、窗口化、退出按钮隐藏
        this->showFullScreen();//当前窗口全屏
        ui->PlayListWidget->setVisible(0);
    }
    else//如果当前是全屏
    {
        ui->FunctionWidget->setVisible(1);//功能栏出现
        FunctionWidgetTimer->stop();//计时器停止即使，避免功能栏被隐藏
        this->setWindowFlags(Qt::Window);//最小化、窗口化、退出按钮出现
        this->showNormal();//恢复正常尺寸
    }
}


//播放标签事件过滤
bool MainWindow::eventFilter(QObject* obj,QEvent *ev)
{
    if(obj==ui->VideoScreenLabel)//如果鼠标的移动进入了播放标签
    {
        if(ev->type()==QEvent::MouseMove&&this->isFullScreen()==1)//如果鼠标在动且处于全屏模式
        {
            ui->FunctionWidget->setVisible(1);//功能栏出现
            FunctionWidgetTimer->stop();//定时器重新计时
            FunctionWidgetTimer->start();
            return 1;
        }
    }
    return QWidget::eventFilter(obj,ev);
}

//计时器槽函数
void MainWindow::on_timer_timeout()//计时器时间到
{
    ui->FunctionWidget->setVisible(0);//隐藏功能栏
    ui->PlayListWidget->setVisible(0);//隐藏播放列表
    FunctionWidgetTimer->stop();//停止计时
}

//显示播放列表按钮槽函数
void MainWindow::on_PlayListButton_clicked()
{
    if(ui->PlayListWidget->isVisible()==0)
    {
        ui->PlayListWidget->setVisible(1);
    }
    else
    {
        ui->PlayListWidget->setVisible(0);
    }
}

//拖拽事件
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    // 创建可接受文件类型列表
    QStringList acceptedFileTypes;
    acceptedFileTypes<<"mp4"<<"avi"<<"flv"<<"mp3"<<"flac";

    // 拖拽事件触发  且 判断只拖拽了一个文件
    if( event->mimeData()->hasUrls() && event->mimeData()->urls().count() == 1 )
    {
        // 取到拖拽文件中的第一个  并转换成文件
        QFileInfo file(event->mimeData()->urls().at(0).toLocalFile());
        // 查看文件后缀名  是否在列表acceptedFileTypes中
        if(acceptedFileTypes.contains(file.suffix().toLower()))
        {
            // 让程序 同意将这个文件 读入
            event->acceptProposedAction();
        }
        else
        {
            QMessageBox::critical(this, tr("错误"), tr("读入文件类型非法"));
        }
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    // 程序同意将文件加载，  下一步 读取文件
    QFileInfo file(event->mimeData()->urls().at(0).toLocalFile());

    QString AbsPath=file.absoluteFilePath();//获取绝对路径
    QString FileName=file.fileName();//获取文件名
    QString temp=FileName+"\t"+AbsPath;

    QListWidgetItem* item=new QListWidgetItem(temp);
    ui->ListWidget->addItem(item);//添加列表项
    CurrentAudioOrVedio=ui->ListWidget->count()-1;//设置指针

    SaveLocalCache();
}

//播放视频
void MainWindow::PlayVedio(QString file)
{
    if(file==" ")//单曲播放中，下一个为空
    {
        return;
    }

    AVFormatContext    *pFormatCtx;
    int                i, videoindex;
    AVCodecContext    *pCodecCtx;
    AVCodec            *pCodec;
    AVFrame    *pFrame, *pFrameRGB;
    unsigned char *out_buffer;
    AVPacket *packet;
    int ret, got_picture;
    struct SwsContext *img_convert_ctx;

    int l=file.length();
    char* filepath;
    filepath=new char[l];
    for(int i=0;i<l;i++)
    {
        filepath[i]=file[i].toLatin1();
    }
    filepath[l]='\0';

    QFileInfo f(file);
    if(f.isFile()==0)
    {
        QMessageBox::critical(this, tr("错误"), tr("文件不存在"));
        return;
    }

    //初始化编解码库
//    av_register_all();//创建AVFormatContext对象，与码流相关的结构。
    pFormatCtx = avformat_alloc_context();
    //初始化pFormatCtx结构
    if (avformat_open_input(&pFormatCtx, filepath, NULL, NULL) != 0){
        printf("Couldn't open input stream.\n");
        return ;
    }
    //获取音视频流数据信息
    if (avformat_find_stream_info(pFormatCtx, NULL) < 0){
        printf("Couldn't find stream information.\n");
        return ;
    }
    videoindex = -1;
    //nb_streams视音频流的个数，这里当查找到视频流时就中断了。
    for (i = 0; i < pFormatCtx->nb_streams; i++)
        if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO){
            videoindex = i;
            break;
    }
    if (videoindex == -1){
        printf("Didn't find a video stream.\n");
        return ;
    }
    //获取视频流编码结构
    pCodecCtx = pFormatCtx->streams[videoindex]->codec;
    //查找解码器
    pCodec = avcodec_find_decoder(pCodecCtx->codec_id);
    if (pCodec == NULL){
        printf("Codec not found.\n");
        return ;
    }
    //用于初始化pCodecCtx结构
    if (avcodec_open2(pCodecCtx, pCodec, NULL) < 0){
        printf("Could not open codec.\n");
        return ;
    }
    //创建帧结构，此函数仅分配基本结构空间，图像数据空间需通过av_malloc分配
    pFrame = av_frame_alloc();
    pFrameRGB = av_frame_alloc();
    //创建动态内存,创建存储图像数据的空间
    //av_image_get_buffer_size获取一帧图像需要的大小
    out_buffer = (unsigned char *)av_malloc(av_image_get_buffer_size(AV_PIX_FMT_RGB32, pCodecCtx->width, pCodecCtx->height, 1));
    av_image_fill_arrays(pFrameRGB->data, pFrameRGB->linesize, out_buffer,
        AV_PIX_FMT_RGB32, pCodecCtx->width, pCodecCtx->height, 1);

    packet = (AVPacket *)av_malloc(sizeof(AVPacket));
    //Output Info-----------------------------
    printf("--------------- File Information ----------------\n");
    //此函数打印输入或输出的详细信息
    av_dump_format(pFormatCtx, 0, filepath, 0);
    printf("-------------------------------------------------\n");
    //初始化img_convert_ctx结构
    img_convert_ctx = sws_getContext(pCodecCtx->width, pCodecCtx->height, pCodecCtx->pix_fmt,
        pCodecCtx->width, pCodecCtx->height, AV_PIX_FMT_RGB32, SWS_BICUBIC, NULL, NULL, NULL);
    //av_read_frame读取一帧未解码的数据
    while (av_read_frame(pFormatCtx, packet) >= 0){
        //如果是视频数据
        if (packet->stream_index == videoindex){
            //解码一帧视频数据
            ret = avcodec_decode_video2(pCodecCtx, pFrame, &got_picture, packet);
            if (ret < 0){
                printf("Decode Error.\n");
                return ;
            }
            if (got_picture){
                sws_scale(img_convert_ctx, (const unsigned char* const*)pFrame->data, pFrame->linesize, 0, pCodecCtx->height,
                    pFrameRGB->data, pFrameRGB->linesize);
                QImage img((uchar*)pFrameRGB->data[0],pCodecCtx->width,pCodecCtx->height,QImage::Format_RGB32);
                ui->VideoScreenLabel->setPixmap(QPixmap::fromImage(img));
                Delay(40/PlayRate);
            }
        }
        av_free_packet(packet);
    }
    sws_freeContext(img_convert_ctx);
    av_frame_free(&pFrameRGB);
    av_frame_free(&pFrame);
    avcodec_close(pCodecCtx);
    avformat_close_input(&pFormatCtx);
    QString NextAudioOrVedio=getNextAudioOrVedio();
    PlayVedio(NextAudioOrVedio);
}

void MainWindow::PlayAudioAndVedio(QString file)
{
    player->stop();
    if(file==" ")//单曲播放中，下一个为空
    {
        return;
    }

    int l=file.length();
    char* filepath;
    filepath=new char[l];
    for(int i=0;i<l;i++)
    {
        filepath[i]=file[i].toLatin1();
    }
    filepath[l]='\0';

    QFileInfo f(file);
    if(f.isFile()==0)
    {
        QMessageBox::critical(this, tr("错误"), tr("文件不存在"));
        return;
    }

    player->setSource(QUrl::fromLocalFile(filepath));  //打开音视频流文件
    videowidget->resize(ui->VideoScreenLabel->size());  //把视频输出图像的大小重新调整为label的大小
    //指定视频播放的位置
    layout->addWidget(videowidget);
    ui->VideoScreenLabel->setLayout(layout);

    player->setVideoOutput(videowidget);  //设置视频输出附加到媒体播放器
    player->setAudioOutput(audioOutput);
    player->play();  //开始播放视频
    qDebug()<<"123";
    //QString NextAudioOrVedio=getNextAudioOrVedio();
    //PlayAudioAndVedio(NextAudioOrVedio);
}

//列表项选中播放槽函数
void MainWindow::on_ListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    SetCurrentListItemColor(QColor(255,255,255));
    CurrentAudioOrVedio=ui->ListWidget->currentRow();
    SetCurrentListItemColor(QColor(255,182,193));
    PlayAudioAndVedio(getListItemFileAddress(item));
}


void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key_Delete)
    {
       if(ui->ListWidget->currentRow()==CurrentAudioOrVedio)//如果想要删除的是当前视频，提示错误并返回
       {
           QMessageBox::critical(NULL, "错误", "当前正在播放的音视频无法从播放列表被删除！", QMessageBox::Yes, QMessageBox::Yes);
           return;
       }
       else if(ui->ListWidget->currentRow()<CurrentAudioOrVedio)//如果要删除的是当前音视频之前的，那么指针-1
       {
           CurrentAudioOrVedio--;
       }
       else if(ui->ListWidget->currentRow()>CurrentAudioOrVedio)//如果要删除的是当前音视频之后的，不进行操作
       {

       }
       QListWidgetItem* i = ui->ListWidget->currentItem();
       delete i;
       SaveLocalCache();
       return;
    }
    else if(ev->modifiers()==Qt::ControlModifier && ev->key()==Qt::Key_F)//全屏
    {
        qDebug()<<"F";
        on_FullScreenButton_clicked();
    }
    else if(ev->modifiers()==Qt::ControlModifier && ev->key()==Qt::Key_Left)//上一首
    {
        qDebug()<<"left";
        QString NextAudioOrVedio=getLastAudioOrVedio();
        PlayAudioAndVedio(NextAudioOrVedio);
    }
    else if(ev->modifiers()==Qt::ControlModifier && ev->key()==Qt::Key_Right)//下一首
    {
        qDebug()<<"right";
        QString NextAudioOrVedio=getNextAudioOrVedio();
        PlayAudioAndVedio(NextAudioOrVedio);
    }

    QWidget::keyPressEvent(ev);
}


void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    QWidget::keyReleaseEvent(ev);
}

//模式按钮点击事件
void MainWindow::on_ModeButton_clicked()
{
    if(PlaySeqence==1)
    {
        PlaySeqence++;
        ui->ModeButton->setText("顺序播放");
        ui->ModeButton->setIcon(QIcon(":/images/PlayInOrder.png"));
        ui->ModeButton->setIconSize(QSize(17,16));
    }
    else if(PlaySeqence==2)
    {
        PlaySeqence++;
        ui->ModeButton->setText("随机播放");
        ui->ModeButton->setIcon(QIcon(":/images\\PlayRandom.png"));
        ui->ModeButton->setIconSize(QSize(17,16));
    }
    else if(PlaySeqence==3)
    {
        PlaySeqence++;
        ui->ModeButton->setText("单曲循环");
        ui->ModeButton->setIcon(QIcon(":/images\\PlaySingleCycle.png"));
        ui->ModeButton->setIconSize(QSize(17,16));
    }
    else
    {
        PlaySeqence=1;
        ui->ModeButton->setText("单曲播放");
        ui->ModeButton->setIcon(QIcon(":/images\\PlaySingle.png"));
        ui->ModeButton->setIconSize(QSize(17,16));
    }
}

//获取列表项对应的地址
QString MainWindow::getListItemFileAddress(QListWidgetItem *item)
{
    QStringList SplitList=item->text().split("\t");
    return SplitList[1];
}

//索引到下一个音视频的地址
QString MainWindow::getNextAudioOrVedio()
{
    if(CurrentAudioOrVedio==-1)return "";//如果没有任何音视频可以播放，直接返回
    int PlayListLength=ui->ListWidget->count();
    if(PlaySeqence==1)
    {
        return " ";
    }
    else if(PlaySeqence==2)
    {
        SetCurrentListItemColor(QColor(255,255,255));
        CurrentAudioOrVedio=(CurrentAudioOrVedio+1)%PlayListLength;//循环
        SetCurrentListItemColor(QColor(255,182,193));
        return getListItemFileAddress(ui->ListWidget->item(CurrentAudioOrVedio));//获取指针对应的列表项对应的地址
    }
    else if(PlaySeqence==3)
    {
        int TempRandNum=QRandomGenerator::global()->bounded(PlayListLength);
        SetCurrentListItemColor(QColor(255,255,255));
        CurrentAudioOrVedio=(CurrentAudioOrVedio+TempRandNum)%PlayListLength;//让下一个音视频被选中
        SetCurrentListItemColor(QColor(255,182,193));
        return getListItemFileAddress(ui->ListWidget->item(CurrentAudioOrVedio));
    }
    else if(PlaySeqence==4)
    {
        return getListItemFileAddress(ui->ListWidget->item(CurrentAudioOrVedio));
    }
}

QString MainWindow::getLastAudioOrVedio()
{
    if(CurrentAudioOrVedio==-1)return "";//如果没有任何音视频可以播放，直接返回
    int PlayListLength=ui->ListWidget->count();
    if(PlaySeqence==1)
    {
        return " ";
    }
    else if(PlaySeqence==2)
    {
        SetCurrentListItemColor(QColor(255,255,255));
        CurrentAudioOrVedio=(CurrentAudioOrVedio+PlayListLength-1)%PlayListLength;//循环
        SetCurrentListItemColor(QColor(255,182,193));
        return getListItemFileAddress(ui->ListWidget->item(CurrentAudioOrVedio));//获取指针对应的列表项对应的地址
    }
    else if(PlaySeqence==3)
    {
        SetCurrentListItemColor(QColor(255,255,255));
        int TempRandNum=QRandomGenerator::global()->bounded(PlayListLength);
        CurrentAudioOrVedio=(CurrentAudioOrVedio+TempRandNum)%PlayListLength;//让下一个音视频被选中
        SetCurrentListItemColor(QColor(255,182,193));
        return getListItemFileAddress(ui->ListWidget->item(CurrentAudioOrVedio));
    }
    else if(PlaySeqence==4)
    {
        return getListItemFileAddress(ui->ListWidget->item(CurrentAudioOrVedio));
    }
}

//“下一个”按钮槽函数
void MainWindow::on_NextVedioButton_clicked()
{
    QString NextAudioOrVedio=getNextAudioOrVedio();
    PlayAudioAndVedio(NextAudioOrVedio);
}

//"上一个"按钮槽函数
void MainWindow::on_LastVedioButton_clicked()
{
    QString NextAudioOrVedio=getLastAudioOrVedio();
    PlayAudioAndVedio(NextAudioOrVedio);
}

void MainWindow::SetCurrentListItemColor(QColor q)
{
    ui->ListWidget->item(CurrentAudioOrVedio)->setBackground(q);
}

void MainWindow::SaveLocalCache()
{
    QFile* myfile=new QFile("./Cache.txt");//创建一个输出文件的文档
    if (myfile->open(QFile::WriteOnly|QIODevice::Truncate))//注意WriteOnly是往文本中写入的时候用，ReadOnly是在读文本中内容的时候用，Truncate表示将原来文件中的内容清空
    {
        QTextStream out(myfile);
        for(int i=0;i<ui->ListWidget->count();i++)
        {
            out<<ui->ListWidget->item(i)->text()<<"\n";
        }
        out<<"EOF";
    }
    myfile->close();
}

void MainWindow::LoadLocalCache()
{
    QFile* myfile=new QFile("./Cache.txt");//创建一个输出文件的文档
    if (myfile->open(QFile::ReadOnly|QIODevice::Text))
    {
        QTextStream out(myfile);
        while(1)
        {
            QString tempstr;
            tempstr=out.readLine();
                if(tempstr=="EOF")
                {
                    break;
                }
            ui->ListWidget->addItem(tempstr);
        }
    }
    myfile->close();
}


void MainWindow::on_SpeadButton_clicked()
{
    /*if(PlayRate==1)
    {
        PlayRate=2;
        ui->SpeadButton->setText("2x");
    }
    else if(PlayRate==2)
    {
        PlayRate=4;
        ui->SpeadButton->setText("4x");
    }
    else if(PlayRate==4)
    {
        PlayRate=8;
        ui->SpeadButton->setText("8x");
    }
    else if(PlayRate==8)
    {
        PlayRate=1;
        ui->SpeadButton->setText("1x");
    }*/
}

