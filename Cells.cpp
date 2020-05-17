#include "Cells.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QtWidgets>
#include <QTimer>
//Overloaded Constructor that takes in cells x, y, width, and length value
Cells::Cells(int cell_x, int cell_y,int cell_width,int cell_length)
{
    int random = qrand() % 100;
    QColor color(255, 255, 255);
    if(random < 20)
    {
        //color.setRgb(242, 19, 131);

        alive_ = true;
    }
    else
    {
        //color.setRgb(255, 255, 255);
        alive_ = false;
    }
    color_ = color;
    cell_length_ = cell_length;
    cell_width_ = cell_width;
    cell_x_ = cell_x*cell_width;
    cell_y_ = cell_y*cell_length;
}
/**
Returns a cells length

@param none
@return a cells length
*/
int Cells::GetCellLength()
{
    return cell_length_;

}
/**
Returns None

@param length of a cell
@return None
*/
void Cells::SetCellLength(int cell_length)
{
    cell_length_ = cell_length;

}
/**
Returns width of a cell

@param None
@return the width of a cell
*/
int Cells::GetCellWidth()
{
    return cell_width_;
}
/**
Returns None

@param width of a cell
@return None
*/
void Cells::SetCellWidth(int cell_width)
{
    cell_width_ = cell_width;

}
/**
Returns x value of cell

@param None
@return x value of cell
*/
int Cells::GetCellX()
{
    return cell_x_;

}
/**
Returns None

@param x value of cell
@return None
*/
void Cells::SetCellX(int cell_x)
{
    cell_x_ = cell_x;


}
/**
Returns y value of cell

@param None
@return y value of cell
*/
int Cells::GetCellY()
{
    return cell_y_;

}
/**
Returns None

@param y value of cell
@return None
*/
void Cells::SetCellY(int cell_y)
{
    cell_y_ = cell_y;

}
/**
Returns alive status of cell

@param None
@return true if cell is alive and false if not
*/
bool Cells::GetAliveStatus()
{
    return alive_;

}
/**
Returns None

@param alive status of cell
@return None
*/
void Cells::SetAliveStatus(bool status)
{
    alive_ = status;

}
/**
Returns Color of cell

@param None
@return Color of cell QColor object
*/
QColor Cells::GetColor()
{
    return color_;

}
/**
Returns None

@param Color of cell QColor object
@return None
*/
void Cells::SetColor(QColor c)
{
    color_ = c;
}
/**
Returns QRectF object

@param None
@return QRectF object
*/
QRectF Cells::boundingRect() const
{
    return QRectF(cell_x_, cell_y_, cell_width_, cell_length_);

}
//Event

/**
Returns QPainerPath object

@param None
@return QPainterPath object
*/
QPainterPath Cells::shape() const
{
    QPainterPath path;
    path.addRect(cell_x_,cell_y_,cell_width_,cell_length_);
    return path;

}
/**
Returns None

@param QRectF object, QStyleOptionGraphicsItem,QWidget
@return None
*/
void Cells::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    Q_UNUSED(widget) //should not have a semi colon
    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_));

    painter->drawRect(QRect(cell_x_, cell_y_,cell_width_,cell_length_));
    painter->setBrush(b);
    if(alive_==true)
    {
        painter->drawPixmap(cell_x_,cell_y_, cell_width_,cell_length_,QPixmap("/Users/rohansuri17/Downloads/Unknown.png"));
    }

}
