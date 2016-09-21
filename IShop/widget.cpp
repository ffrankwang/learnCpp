#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->volume->setMaximum(100);
    show_List();
    cur_Num=0;

}

Widget::~Widget()
{
    delete ui;
    delete qprocess;
}

void Widget::play(){
    QPixmap pix;
    if(play_status==0){
    qprocess=new QProcess(this);
    connect(qprocess, SIGNAL(finished(int)), this, SLOT(proc_finished(int)));
    WId id=ui->video_label->winId();
    QStringList args;
    QString str=QString::number(id);
    args<<"-slave"<<"-quiet"<<"-zoom"<<"-wid"<<str<<"/root/frank/music/"+list[cur_Num];
    qprocess->start("mplayer",args);
    //当前已经播放，将按钮切换为暂停
    //设置为暂停按钮
    pix.load(":/images/icon/pause.png");
    icon.addPixmap(pix);
    ui->play->setIcon(icon);
    play_status=1;

    }else if(play_status==1){
        qprocess->write("pause\n");
        //设置为播放按钮
        pix.load(":/images/icon/start.png");
        icon.addPixmap(pix);
        ui->play->setIcon(icon);
        play_status=2;//2表示当前为暂停状态

    }else if(play_status==2){
        //设置为暂停按钮
        qprocess->write("pause\n");
        pix.load(":/images/icon/pause.png");
        icon.addPixmap(pix);
        ui->play->setIcon(icon);
        play_status=1;
    }
}
void Widget::on_play_clicked()
{
    play();
}



void Widget::on_stop_clicked()
{    QPixmap pix1;
    if(play_status==1||play_status==2){
        qprocess->write("quit\n");
        qprocess->waitForFinished();
        delete qprocess;
        //设置为播放按钮
        pix1.load("/root/frank/git/learnCpp/IShop/icon/start.png");
        icon.addPixmap(pix1);
        ui->play->setStyleSheet("border-image: url(:/images/icon/start.png);");
        ui->play->setIcon(icon);
        play_status=0;
     }
}

void Widget::on_backward_clicked()
{
    if(play_status==1){
        qprocess->write("pausing_keep seek -3 0\n");
     }
}

void Widget::on_forward_clicked()
{
    if(play_status==1){
        qprocess->write("pausing_keep seek +3 0\n");
     }
}
void Widget::show_List(){
    char line[1024];
    int retval;
    QFile file;
    file.setFileName("/root/frank/music/list.txt");
     file.open(QFile::ReadOnly);
     while((retval=file.readLine(line,1024))>0){
        line[retval-1] = '\0';
        list<<line;
        qDebug()<<line;
     }

    file.close();
    play_status=0;//设置褪初始状态，0表示未播放
}
void Widget::proc_finished(int){
    disconnect(qprocess, SIGNAL(finished(int)), this, SLOT(proc_finished(int)));//断开slot函数建立连接
    delete qprocess;
    play_status=0;
    cur_Num++;
    play();
}
void Widget::on_next_clicked()
{
    disconnect(qprocess, SIGNAL(finished(int)), this, SLOT(proc_finished(int)));//断开slot函数建立连接
    if(play_status==0){
        return;
    }
    if(play_status==1||play_status==2){
        if(cur_Num==list.size()-1)cur_Num=0;
        on_stop_clicked();
        cur_Num++;
        play();
    }
}

void Widget::on_preivous_clicked()
{
    disconnect(qprocess, SIGNAL(finished(int)), this, SLOT(proc_finished(int)));//断开slot函数建立连接
    if(play_status==0)return;
    if(play_status==1||play_status==2){
        if(cur_Num==0)cur_Num=1;
        on_stop_clicked();
        cur_Num--;
        play();
}

}

void Widget::on_volume_valueChanged(int value)
{       if(ui->volume->isSliderDown()) return;
        char buf[100];
        sprintf(buf,"volume %d 1\n",value);
        qprocess->write(buf);

}

void Widget::on_volume_sliderReleased()
{
    if(play_status==2||play_status==0)return;
    int value=ui->volume->value();
    char buf[100];
    sprintf(buf,"volume %d 1\n",value);
    qprocess->write(buf);
}

void Widget::on_monitor_clicked()
{
    thread = new VideoThread(this);
    connect(thread,SIGNAL(recv_image_slot(char *img, int len)),this,SLOT(recv_image_slot(char *img, int len)));
    thread->start();

}
void Widget::recv_image_slot(char *img, int len){
    QPixmap pix;
    pix.loadFromData((uchar *)img, len);
    ui->monitorLabel->setPixmap(pix);
    delete []img; //释放内存
}
