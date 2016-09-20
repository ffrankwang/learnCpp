/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Tue Sep 20 16:31:58 2016
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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *video_label;
    QLabel *label_3;
    QPushButton *play;
    QPushButton *forward;
    QPushButton *stop;
    QPushButton *next;
    QPushButton *backward;
    QPushButton *preivous;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(219, 255, 196);"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 5, 800, 30));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(130, 195, 255);"));
        video_label = new QLabel(Widget);
        video_label->setObjectName(QString::fromUtf8("video_label"));
        video_label->setGeometry(QRect(10, 35, 581, 333));
        video_label->setStyleSheet(QString::fromUtf8("background-color: rgb(198, 255, 112);"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(595, 35, 200, 500));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));
        play = new QPushButton(Widget);
        play->setObjectName(QString::fromUtf8("play"));
        play->setGeometry(QRect(100, 370, 32, 32));
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

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "                                                          ads", 0, QApplication::UnicodeUTF8));
        video_label->setText(QApplication::translate("Widget", "                                                       video", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "            \344\277\203\351\224\200\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        play->setText(QString());
        forward->setText(QString());
        stop->setText(QString());
        next->setText(QString());
        backward->setText(QString());
        preivous->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
