#include "Board.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QtWidgets>
#include <QTimer>
//Overloaded Constructor that takes in Board x, y, width, and length value
Board::Board(int Board_x, int Board_y,int Board_width,int Board_length)
{
    int random = qrand() % 100;
    QColor color(255, 255, 255);
    if(random < 15)
    {
        alive_ = true;
    }
    else
    {
        alive_ = false;
    }
    color_ = color;
    Board_length_ = Board_length;
    Board_width_ = Board_width;
    Board_x_ = Board_x*Board_width;
    Board_y_ = Board_y*Board_length;
}
/**
Returns a Board length

@param none
@return a Board length
*/
int Board::GetBoardLength()
{
    return Board_length_;

}
/**
Returns None

@param length of a Board
@return None
*/
void Board::SetBoardLength(int Board_length)
{
    Board_length_ = Board_length;

}
/**
Returns width of a Board

@param None
@return the width of a Board
*/
int Board::GetBoardWidth()
{
    return Board_width_;
}
/**
Returns None

@param width of a Board
@return None
*/
void Board::SetBoardWidth(int Board_width)
{
    Board_width_ = Board_width;

}
/**
Returns x value of Board

@param None
@return x value of Board
*/
int Board::GetBoardX()
{
    return Board_x_;

}
/**
Returns None

@param x value of Board
@return None
*/
void Board::SetBoardX(int Board_x)
{
    Board_x_ = Board_x;


}
/**
Returns y value of Board

@param None
@return y value of Board
*/
int Board::GetBoardY()
{
    return Board_y_;

}
/**
Returns None

@param y value of Board
@return None
*/
void Board::SetBoardY(int Board_y)
{
    Board_y_ = Board_y;

}
/**
Returns alive status of Board

@param None
@return true if Board is alive and false if not
*/
bool Board::GetAliveStatus()
{
    return alive_;

}
/**
Returns None

@param alive status of Board
@return None
*/
void Board::SetAliveStatus(bool status)
{
    alive_ = status;

}
/**
Returns Color of Board

@param None
@return Color of Board QColor object
*/
QColor Board::GetColor()
{
    return color_;

}
/**
Returns None

@param Color of Board QColor object
@return None
*/
void Board::SetColor(QColor c)
{
    color_ = c;
}
/**
Returns QRectF object

@param None
@return QRectF object
*/
QRectF Board::boundingRect() const
{
    return QRectF(Board_x_, Board_y_, Board_width_, Board_length_);

}
//Event

/**
Returns QPainerPath object

@param None
@return QPainterPath object
*/
QPainterPath Board::shape() const
{
    QPainterPath path;
    path.addRect(Board_x_,Board_y_,Board_width_,Board_length_);
    return path;

}
/**
Returns None

@param QRectF object, QStyleOptionGraphicsItem,QWidget
@return None
*/
void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    Q_UNUSED(widget) //should not have a semi colon
    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_));

    painter->drawRect(QRect(Board_x_, Board_y_,Board_width_,Board_length_));
    painter->setBrush(b);
    if(alive_==true)
    {
        painter->drawPixmap(Board_x_,Board_y_, Board_width_,Board_length_,QPixmap("/Users/rohansuri17/Downloads/Unknown.png"));
    }

}
