#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    char line[1024];
    int retval;
    QFile file;
    file.setFileName("/root/frank/music/list.txt");
     file.open(QFile::ReadOnly);
    do{
        retval=file.readLine(line,1024);
        if(retval<=0)break;
        line[retval-1] = '\0';
        list<<line;
        qDebug()<<line;
     }while(retval!=-1);

    file.close();

}

Widget::~Widget()
{
    delete ui;
    delete qprocess;
}

void Widget::on_play_clicked()
{
    qprocess=new QProcess;
    QStringList arg;
    arg<<"mplayer"<<"-slave"<<"-quiet"<<"/root/frank/music/Brendan James - Let It Rain.mp3";
    qprocess->start("mplayer",arg);
}


