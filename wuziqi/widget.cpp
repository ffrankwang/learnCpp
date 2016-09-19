#include "widget.h"
#include "ui_widget.h"
#include "QPen"
#include "QPainter"
#include "QPoint"
#include "QBrush"
#include "QMouseEvent"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_PaintOutsidePaintEvent);
    color=0;//0表示黑色
    for(int i=0;i<21;i++){
        for(int j=0;j<21;j++){
            a[i][j]=2;
        }
    }
   // memset(a,2,sizeof(a));//2表示没有下子
}

Widget::~Widget()
{
    delete ui;
}
void Widget:: paintEvent(QPaintEvent *)
{
    QPen pen;
    QPainter painter(this);
   pen.setColor(Qt::black);
   painter.setPen(pen);
   for(int i=1;i<=21;i++){
       painter.drawLine(30,i*30,630,i*30);
   }
   for(int i=1;i<=21;i++){
       painter.drawLine(i*30,30,i*30,630);
   }

}
void Widget:: mousePressEvent(QMouseEvent* e){
    int row,col;
    row=((e->y()-30+15)/30);
    col=((e->x()-30+15)/30);
    if(!(a[row][col]==2))return;//判断是否下过子
    a[row][col]=color;//0表示黑色,1表示白色，2表示示下
    if(!(e->x()>=15&&e->x()<=645&&e->y()>=15&&e->y()<=630))return;//判断边界
    QPainter painter(this);
    QBrush brush;
    if(color==0)
         brush.setColor(Qt::black);
    else
         {
        QPen pen;
        pen.setColor(Qt::white);
        painter.setPen(pen);
        brush.setColor(Qt::white);
    }
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    QPoint center;
    center.setX(((e->x()+15+30)/30)*30-30);
    center.setY(((e->y()+15+30)/30)*30-30);
    painter.drawEllipse(center,14,14);
    color=!color;
    ui->label_2->setText("x,y"+QString::number(col+1)+","+QString::number(row+1));
       if(judgeWin(row,col)==true&&a[row][col]==0)
       ui->label->setText("Black WIN!");
       if(judgeWin(row,col)==true&&a[row][col]==1)
       ui->label->setText("White WIN!");
}
bool Widget:: judgeWin(int row,int col){
    int count=0;
    int r,c;
    r=row,c=col;
    //右下
    for(int i=0;i<4;i++){
        if(a[row][col]==a[++row][++col])
            count++;
    }

    if(count==4) return true;
    count=0;
    row=r,col=c;
    //左上
    for(int i=0;i<4&&row>=0&&col>=0;i++){
        if(a[row][col]==a[--row][--col])
            count++;
    }
    if(count==4) return true;
      count=0;
      row=r,col=c;
    //横右
    for(int i=0;i<4&&col<21;i++){
        if(a[row][col]==a[row][++col])
            count++;
    }
    if(count==4) return true;
      count=0;
      row=r,col=c;
    //竖上
    for(int i=0;i<4&&col>=0;i++){
        if(a[row][col]==a[row][--col])
            count++;
    }
    if(count==4) return true;
    count=0;
    row=r,col=c;
    //竖下
    for(int i=0;i<4&&row<21;i++){
        if(a[row][col]==a[++row][col])
            count++;
    }
    if(count==4) return true;
      row=r,col=c;
      count=0;
    //横左
    for(int i=0;i<4&&row>=0;i++){
        if(a[row][col]==a[--row][col])
            count++;
    }
    if(count==4) return true;
      row=r,col=c;
      count=0;
    //左下
    for(int i=0;i<4&&row>=0&&col<21;i++){
        if(a[row][col]==a[--row][++col])
            count++;
    }
    if(count==4) return true;
      row=r,col=c;
      count=0;
    //右上
    for(int i=0;i<4&&row<21&&col>=0;i++){
        if(a[row][col]==a[++row][--col])
            count++;
    }
    if(count==4) return true;
      row=r,col=c;
      count=0;
      //判断特殊的在中间的四种情况:左斜
       for(int i=0;i<2&&row<21&&col<21;i++){
          if(a[row][col]==a[++row][++col])
              count++;
           else return false;//防止出现1黑2黑3黑4黑5白6黑，下第四个子会判断黑赢
      }
        row=r,col=c;//重置坐标
      for(int i=0;i<2&&row>=0&&col>=0;i++){
          if(a[row][col]==a[--row][--col])
              count++;
          else return false;
         if(count=4) return true;
      }
        row=r,col=c;
        count=0;

        //判断特殊的在中间的四种情况:右斜
         for(int i=0;i<2&&row>=0&&col<21;i++){
            if(a[row][col]==a[--row][++col])
                count++;
             else return false;
        }
          row=r,col=c;
        for(int i=0;i<2&&row<21&col>=0;i++){
            if(a[row][col]==a[++row][--col])
                count++;
             else return false;
            if(count=4) return true;
        }
          row=r,col=c;
          count=0;

          //判断特殊的在中间的四种情况:横
           for(int i=0;i<2&&row<21;i++){
              if(a[row][col]==a[++row][col])
                  count++;
               else return false;
          }
            row=r,col=c;
          for(int i=0;i<2&&row>=0;i++){
              if(a[row][col]==a[--row][col])
                  count++;
             else return false;
             if(count=4) return true;
          }
            row=r,col=c;
            count=0;

            //判断特殊的在中间的四种情况:竖
             for(int i=0;i<2&&col>=0;i++){
                if(a[row][col]==a[row][--col])
                    count++;
                 else return false;
            }
              row=r,col=c;
            for(int i=0;i<2&&col<21;i++){
                if(a[row][col]==a[row][++col])
                    count++;
                else return false;
                if(count=4) return true;
            }
              row=r,col=c;
              count=0;
      return false;
}
