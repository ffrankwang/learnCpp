#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qprocess.h>
#include <qfile.h>
#include <qstring.h>
#include <qdebug.h>
#include <qstringlist.h>

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


private:
    Ui::Widget *ui;
    QProcess *qprocess;
    QStringList list;
};

#endif // WIDGET_H
