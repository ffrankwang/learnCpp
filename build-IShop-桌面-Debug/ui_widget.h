/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Tue Sep 20 10:37:04 2016
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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *play;
    QPushButton *pause;
    QPushButton *forward;
    QPushButton *stop;
    QPushButton *volume;
    QSlider *verticalSlider;

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
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 500, 500));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(198, 255, 112);"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(520, 80, 270, 500));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));
        play = new QPushButton(Widget);
        play->setObjectName(QString::fromUtf8("play"));
        play->setGeometry(QRect(20, 510, 30, 30));
        play->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icon/start.png);"));
        pause = new QPushButton(Widget);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setGeometry(QRect(60, 510, 30, 30));
        pause->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icon/pause.png);"));
        forward = new QPushButton(Widget);
        forward->setObjectName(QString::fromUtf8("forward"));
        forward->setGeometry(QRect(100, 510, 30, 30));
        forward->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icon/forward.png);"));
        stop = new QPushButton(Widget);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setGeometry(QRect(140, 510, 30, 30));
        stop->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icon/stop.png);"));
        volume = new QPushButton(Widget);
        volume->setObjectName(QString::fromUtf8("volume"));
        volume->setGeometry(QRect(180, 510, 30, 30));
        volume->setStyleSheet(QString::fromUtf8("border-image: url(:/images/icon/sound.png);"));
        verticalSlider = new QSlider(Widget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(220, 410, 20, 131));
        verticalSlider->setOrientation(Qt::Vertical);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "                                                          ads", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "                                                       video", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "            \344\277\203\351\224\200\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        play->setText(QString());
        pause->setText(QString());
        forward->setText(QString());
        stop->setText(QString());
        volume->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
