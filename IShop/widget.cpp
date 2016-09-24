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
    pos=1;
    mute=false;
    adStr="国庆大酬宾，开业五周年，打折促销，全场半价，错过今年在等一年";
    connect(&timer,SIGNAL(timeout()),this,SLOT(timer_slot()));
    timer.start(800);

    connect(&play_timer,SIGNAL(timeout()),this,SLOT(play_timer_slot()));


}

Widget::~Widget()
{
    delete ui;
}

void Widget::play(){
    QPixmap pix;
    if(play_status==0){
    proc=new QProcess(this);
    connect(proc, SIGNAL(finished(int)), this, SLOT(proc_finished(int)));//与进程结束信号建立连接
    connect(proc,SIGNAL(readyReadStandardOutput()),this,SLOT(proc_read_proc_slot()));//读取proc 返回的信息
    play_timer.start(800);
    WId id=ui->video_label->winId();
    QStringList args;
    QString str=QString::number(id);
    if(list[cur_Num].contains("mp3")){
        pix.load(":/images/icon/background.jpg");
        ui->video_label->setPixmap(pix);
        ui->video_label->setText("\t\t正在播放:"+list[cur_Num].mid(0,list[cur_Num].length()-4));
    }
    args<<"-slave"<<"-quiet"<<"-zoom"<<"-wid"<<str<<"/root/frank/music/"+list[cur_Num];
    proc->start("mplayer",args);


    //当前已经播放，将按钮切换为暂停
    //设置为暂停按钮
    pix.load(":/images/icon/pause.png");
    icon.addPixmap(pix);
    ui->play->setIcon(icon);
    play_status=1;
    play_timer.start(100);

    }else if(play_status==1){
        proc->write("pause\n");
        //设置为播放按钮
        pix.load(":/images/icon/start.png");
        icon.addPixmap(pix);
        ui->play->setIcon(icon);
        play_status=2;//2表示当前为暂停状态

    }else if(play_status==2){
        //设置为暂停按钮
        proc->write("pause\n");
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
        proc->write("quit\n");
        proc->waitForFinished();
        play_timer.stop();//停掉监控进度的定时器
        delete proc;
        //设置为播放按钮
        pix1.load(":images/icon/start.png");
        icon.addPixmap(pix1);
        ui->play->setStyleSheet("border-image: url(:/images/icon/start.png);");
        ui->play->setIcon(icon);
        play_status=0;
     }
}

void Widget::on_backward_clicked()
{
    if(play_status==1){
        proc->write("pausing_keep seek -3 0\n");
     }
}

void Widget::on_forward_clicked()
{
    if(play_status==1){
        proc->write("pausing_keep seek +3 0\n");
     }
}
void Widget::show_List(){
    char line[1024];
    int retval;
    QFile file;
    file.setFileName("/root/frank/music/list.txt");
     file.open(QFile::ReadOnly);
     qDebug()<<"===============MusicList=====================";
     while((retval=file.readLine(line,1024))>0){
        line[retval-1] = '\0';
        list<<line;
        qDebug()<<line;
     }
    qDebug()<<"============================================";
    file.close();
    play_status=0;//设置褪初始状态，0表示未播放
}
void Widget::proc_finished(int){
    disconnect(proc, SIGNAL(finished(int)), this, SLOT(proc_finished(int)));//断开slot函数建立连接
    play_timer.stop();
    delete proc;
    play_status=0;
    cur_Num++;
    play();
}
void Widget::on_next_clicked()
{

    if(play_status==0){
        return;
    }
     disconnect(proc, SIGNAL(finished(int)), this, SLOT(proc_finished(int)));//断开slot函数建立连接
    if(play_status==1||play_status==2){
        if(cur_Num==list.size()-1)cur_Num=0;
        on_stop_clicked();
        cur_Num++;
        play();
    }
}

void Widget::on_preivous_clicked()
{

    if(play_status==0)return;
    disconnect(proc, SIGNAL(finished(int)), this, SLOT(proc_finished(int)));//断开slot函数建立连接
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
        proc->write(buf);

}

void Widget::on_volume_sliderReleased()
{
    if(play_status==2||play_status==0)return;
    int value=ui->volume->value();
    char buf[100];
    sprintf(buf,"volume %d 1\n",value);
    proc->write(buf);
}

void Widget::on_monitor_clicked()
{
    thread = new VideoThread(this);
    connect(thread,SIGNAL(recv_image(char*,int)),this,SLOT(recv_image_slot(char *, int)));
    thread->start();

}
//接收图片的槽函数
void Widget::recv_image_slot(char *img, int len){
    QPixmap pix;
    pix.loadFromData((uchar *)img, len);
    ui->monitorLabel->setPixmap(pix);
    delete []img; //释放内存
}
void Widget::timer_slot()
{
    int len;
    QString str="                                             ";
    len=str.length();
    if(pos<len){
        str=str.mid(0,str.length()-pos);
        str=str+adStr.mid(0,pos);
        pos=pos+1;
       // qDebug()<<str;
    }else{
        str=adStr.mid(pos-len,len);
        pos=pos+1;
    }
    ui->adlabel->setText(str);

    if(str.length()<=1){
        pos=1;
    }
}
void Widget::play_timer_slot(){
    if(play_status== 1){

        proc->write("get_percent_pos \n");
        proc->write("get_time_length \n");
        proc->write("get_time_pos \n");
    }

}
void Widget::proc_read_proc_slot(){
    char buf[1024];
       char *p;
       int pos;
   while(
       proc->canReadLine()){
       proc->readLine(buf,1024);
       if(strncmp("ANS_PERCENT_POSITION",buf,20) == 0){
            p = strchr(buf,'=');
            pos = atoi(p+1);
            ui->progress->setValue(pos);
            //qDebug()<<"pos"<<pos;
       }
       if(strncmp("ANS_LENGTH",buf,10) == 0){//获取每首歌的时间
            p = strchr(buf,'=');
            pos = atof(p+1);
           //qDebug()<<"length"<<pos;
           music_len = pos;//传给全局变量
       }
       if(strncmp("ANS_TIME_POSITION",buf,17) == 0){//获取每首歌的时间
            p = strchr(buf,'=');
            pos = atoi(p+1);
           //qDebug()<<"length"<<pos;
           cur_music_time = pos;//传给全局变量
           QString minute=QString::number(cur_music_time/60);
           QString second=QString::number(cur_music_time%60);
           QString a_minute=QString::number(music_len/60);
           QString a_second=QString::number(music_len%60);
               if(second.length()<2||a_second.length()<2){
                   if(second.length()==1&&a_second.length()==2)ui->music_info_label->setText(minute+":"+second+"/"+a_minute+":0"+a_second);
                   if(a_second.length()==2&&second.length()==1)ui->music_info_label->setText(minute+":0"+second+"/"+a_minute+":"+a_second);
                   if(a_second.length()==1&&second.length()==1)ui->music_info_label->setText(minute+":0"+second+"/"+a_minute+":0"+a_second);
           }else{
               ui->music_info_label->setText(minute+":"+second+"/"+a_minute+":"+a_second);
               }
       }
   }

}

void Widget::on_progress_sliderMoved(int position)
{
    if(play_status!=1)return;
    play_timer.stop();
    char buf[100];
    sprintf(buf,"seek %d 2\n",position*music_len/100);
    proc->write(buf);
   // qDebug()<<"buf:"<<buf;
    ui->progress->setValue(position);
    play_timer.start();

}

void Widget::on_full_screen_clicked()
{
     QString reg="mp4";
     if(play_status!=1)return;
     if(!list[cur_Num].contains(reg))return;
     if (!isFullScreen()) {
             m_windowFlags = windowFlags() & (Qt::Window);
             m_geometry = geometry();
             ui->video_label->setWindowFlags((windowFlags() | Qt::Window));
              proc->write("vo_fullscreen \n");
              ui->video_label->show();
             // From Phonon::VideoWidget
     #ifdef Q_WS_X11
            ui->video_label-> show();
            ui->video_label-> raise();
            ui->video_label-> setWindowState(windowState() | Qt::WindowFullScreen);
     #else
            ui->video_label->setWindowState(windowState() | Qt::WindowFullScreen);
            ui->video_label->show();
     #endif
         } else {
             ui->video_label->setWindowFlags((windowFlags() ^ (Qt::Window)) | m_windowFlags);
             ui->video_label-> setWindowState(windowState() & ~Qt::WindowFullScreen);
             ui->video_label->setGeometry(m_geometry);
             ui->video_label->show();
         }

}
void Widget::mouseDoubleClickEvent(QMouseEvent *e) {
    on_full_screen_clicked();
  QWidget::mouseDoubleClickEvent(e);
}

void Widget::on_sound_clicked()
{
       QPixmap pix;
    if(play_status!=1)return;
    if(mute)
    {
        proc->write("mute 0\n");
        mute=!mute;
        pix.load(":/images/icon/sound.png");
        icon.addPixmap(pix);
        ui->sound->setIcon(icon);
    }
    else{
        proc->write("mute 1\n");
        mute=!mute;
        pix.load(":/images/icon/mute.png");
        icon.addPixmap(pix);
        ui->sound->setIcon(icon);
    }
}
