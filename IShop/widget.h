#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qprocess.h>
#include <qfile.h>
#include "QString"
#include <qdebug.h>
#include <qstringlist.h>
#include <qpixmap.h>
#include <qicon.h>
#include"videothread.h"
#include "ssocket.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void on_play_clicked();


    void on_stop_clicked();

    void on_backward_clicked();

    void on_forward_clicked();

    void on_next_clicked();

    void on_preivous_clicked();

    void proc_finished(int);

    void on_volume_valueChanged(int value);

    void on_volume_sliderReleased();


    void on_monitor_clicked();
    void recv_image_slot(char *, int );
private:
    Ui::Widget *ui;
    QProcess *qprocess;
    QStringList list;
    int play_status;
    int cur_Num;
    QIcon icon;
    void play();
    void show_List();
    VideoThread *thread;
};

#endif // WIDGET_H
