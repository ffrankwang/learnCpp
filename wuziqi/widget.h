#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent( QPaintEvent * e);
    void mousePressEvent(QMouseEvent* e);
private:
    Ui::Widget *ui;
    int color;
    int a[21][21];
    bool judgeWin(int row,int col);


};
#endif // WIDGET_H
