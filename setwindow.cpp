#include "setwindow.h"
#include "ui_setwindow.h"

SetWindow::SetWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetWindow)
{
    ui->setupUi(this);
}

SetWindow::~SetWindow()
{
    delete ui;
}

void SetWindow::on_toolButton_clicked()
{

}


void SetWindow::on_toolButton_3_clicked()
{
    this->close();
}


void SetWindow::on_toolButton_2_clicked()
{
    if(this->frame==1)
    {
        this->frame=5;
        ui->toolButton_2->setIcon(QIcon(":/images/FiveFrame.png"));
    }
    else if(this->frame==5)
    {
        this->frame=1;
        ui->toolButton_2->setIcon(QIcon(":/images/OneFrame.png"));
    }
    emit FrameSignal(this->frame);
}
