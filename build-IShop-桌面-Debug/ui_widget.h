/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Sat Sep 24 18:55:02 2016
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *adlabel;
    QLabel *video_label;
    QLabel *left_label;
    QPushButton *play;
    QPushButton *forward;
    QPushButton *stop;
    QPushButton *next;
    QPushButton *backward;
    QPushButton *preivous;
    QSlider *volume;
    QPushButton *monitor;
    QLabel *monitorLabel;
    QPushButton *sound;
    QSlider *progress;
    QPushButton *full_screen;
    QLabel *left_label_2;
    QLabel *music_info_label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(219, 255, 196);"));
        adlabel = new QLabel(Widget);
        adlabel->setObjectName(QString::fromUtf8("adlabel"));
        adlabel->setGeometry(QRect(0, 0, 800, 30));
        adlabel->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 160, 255);"));
        video_label = new QLabel(Widget);
        video_label->setObjectName(QString::fromUtf8("video_label"));
        video_label->setGeometry(QRect(0, 30, 600, 340));
        video_label->setAutoFillBackground(false);
        video_label->setStyleSheet(QString::fromUtf8("background-image: url(:/images/icon/background.jpg);"));
        video_label->setPixmap(QPixmap(QString::fromUtf8(":/images/icon/In Time_3262251001518004.jpg")));
        video_label->setScaledContents(true);
        left_label = new QLabel(Widget);
        left_label->setObjectName(QString::fromUtf8("left_label"));
        left_label->setGeometry(QRect(600, 179, 200, 421));
        left_label->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));
        play = new QPushButton(Widget);
        play->setObjectName(QString::fromUtf8("play"));
        play->setGeometry(QRect(100, 370, 32, 32));
        play->setMouseTracking(false);
        play->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icon/start.png);\n"
"selection-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        play->setIcon(icon);
        play->setIconSize(QSize(32, 32));
        play->setShortcut(QString::fromUtf8(""));
        play->setCheckable(false);
        forward = new QPushButton(Widget);
        forward->setObjectName(QString::fromUtf8("forward"));
        forward->setGeometry(QRect(140, 370, 32, 32));
        forward->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icon/forward.png);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/icon/forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        forward->setIcon(icon1);
        forward->setIconSize(QSize(32, 32));
        stop = new QPushButton(Widget);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setGeometry(QRect(220, 370, 32, 32));
        stop->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icon/stop.png);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/icon/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        stop->setIcon(icon2);
        stop->setIconSize(QSize(32, 32));
        next = new QPushButton(Widget);
        next->setObjectName(QString::fromUtf8("next"));
        next->setGeometry(QRect(180, 370, 32, 32));
        next->setMouseTracking(false);
        next->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icon/sound.png);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/icon/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        next->setIcon(icon3);
        next->setIconSize(QSize(32, 32));
        backward = new QPushButton(Widget);
        backward->setObjectName(QString::fromUtf8("backward"));
        backward->setGeometry(QRect(60, 370, 32, 32));
        backward->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icon/backward.png);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/icon/backward.png"), QSize(), QIcon::Normal, QIcon::Off);
        backward->setIcon(icon4);
        backward->setIconSize(QSize(32, 32));
        preivous = new QPushButton(Widget);
        preivous->setObjectName(QString::fromUtf8("preivous"));
        preivous->setGeometry(QRect(20, 370, 32, 32));
        preivous->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icon/previous.png);\n"
"background-image: url(:/images/icon/previous.png);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/icon/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        preivous->setIcon(icon5);
        preivous->setIconSize(QSize(32, 32));
        volume = new QSlider(Widget);
        volume->setObjectName(QString::fromUtf8("volume"));
        volume->setGeometry(QRect(300, 375, 121, 19));
        volume->setOrientation(Qt::Horizontal);
        monitor = new QPushButton(Widget);
        monitor->setObjectName(QString::fromUtf8("monitor"));
        monitor->setGeometry(QRect(530, 370, 32, 32));
        monitor->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icon/monitor.png);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/icon/monitor.png"), QSize(), QIcon::Normal, QIcon::Off);
        monitor->setIcon(icon6);
        monitor->setIconSize(QSize(32, 32));
        monitorLabel = new QLabel(Widget);
        monitorLabel->setObjectName(QString::fromUtf8("monitorLabel"));
        monitorLabel->setGeometry(QRect(600, 30, 200, 150));
        monitorLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 127);"));
        sound = new QPushButton(Widget);
        sound->setObjectName(QString::fromUtf8("sound"));
        sound->setGeometry(QRect(260, 370, 32, 32));
        sound->setMouseTracking(false);
        sound->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icon/stop.png);"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/icon/sound.png"), QSize(), QIcon::Normal, QIcon::Off);
        sound->setIcon(icon7);
        sound->setIconSize(QSize(32, 32));
        progress = new QSlider(Widget);
        progress->setObjectName(QString::fromUtf8("progress"));
        progress->setGeometry(QRect(0, 360, 600, 10));
        progress->setOrientation(Qt::Horizontal);
        full_screen = new QPushButton(Widget);
        full_screen->setObjectName(QString::fromUtf8("full_screen"));
        full_screen->setGeometry(QRect(570, 370, 32, 32));
        full_screen->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icon/full_screen.png);"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/icon/full_screen.png"), QSize(), QIcon::Normal, QIcon::Off);
        full_screen->setIcon(icon8);
        full_screen->setIconSize(QSize(32, 32));
        left_label_2 = new QLabel(Widget);
        left_label_2->setObjectName(QString::fromUtf8("left_label_2"));
        left_label_2->setGeometry(QRect(0, 400, 601, 231));
        left_label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));
        music_info_label = new QLabel(Widget);
        music_info_label->setObjectName(QString::fromUtf8("music_info_label"));
        music_info_label->setGeometry(QRect(440, 372, 81, 20));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        adlabel->setText(QString());
        video_label->setText(QString());
        left_label->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">\345\271\277\345\221\212\345\225\206\345\223\201\345\210\227\350\241\250</span></p><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#ff0000;\">\345\244\247\347\231\275\345\205\224\345\245\266\347\263\226 \347\211\271\344\273\267\344\274\230\346\203\240</span></p><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#ff0000;\">\344\271\214\351\276\231\350\214\266 3\345\205\203</span></p><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#ff0000;\">\344\270\212\345\245\275\344\275\263\346\260\264\346\236\234\347\263\226 4\345\205\203</span></p><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#ff0000;\">\351\224\241\345\261\261\347\211\271\351\273\204 7\345\205\203</span></p><p><br/></p><p><br/></p><p><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
        play->setText(QString());
        forward->setText(QString());
        stop->setText(QString());
        next->setText(QString());
        backward->setText(QString());
        preivous->setText(QString());
        monitor->setText(QString());
        monitorLabel->setText(QApplication::translate("Widget", "             \350\247\206\351\242\221\347\233\221\346\216\247\345\214\272\345\237\237", 0, QApplication::UnicodeUTF8));
        sound->setText(QString());
        full_screen->setText(QString());
        left_label_2->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">\345\271\277\345\221\212\345\225\206\345\223\201\345\210\227\350\241\250</span></p><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#ff0000;\">\345\244\247\347\231\275\345\205\224\345\245\266\347\263\226 \347\211\271\344\273\267\344\274\230\346\203\240</span></p><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#ff0000;\">\344\271\214\351\276\231\350\214\266 3\345\205\203</span></p><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#ff0000;\">\344\270\212\345\245\275\344\275\263\346\260\264\346\236\234\347\263\226 4\345\205\203</span></p><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#ff0000;\">\351\224\241\345\261\261\347\211\271\351\273\204 7\345\205\203</span></p><p><br/></p><p><br/></p><p><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
        music_info_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
