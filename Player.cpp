#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>
#include <QDebug>
#include<QKeyEvent>
#include <QList>
#include "Player.h"
#include "Board.h"
#include <QGraphicsItem>

Player::Player()
{

}
/**
  Creates a new Player object with coordinates x and y
  @param x int x coordinate
  @param y int y coordinate
*/
Player::Player(QColor color, const int x, const int y) {
  this->color_ = color;
  x_ = x;
  y_ = y;
}
/**
Returns none

@param width
@return none
sets width to width given
*/

void Player::set_width(int width)
{
    width_ = width;

}
/**
Returns none

@param none
@return none
sets height to argument given
*/
void Player::set_height(int height)
{
    height_ = height;
}
void Player::set_color(QColor c)
{
    color_ = c;

}
bool Player::isColliding(Board *b)
{
   QList<QGraphicsItem*> colliding_items = collidingItems();
   for(int i = 0 , n = colliding_items.size(); i < n; i++)
   {
       if(typeid(*(colliding_items[i]))==typeid(Board) && b->GetAliveStatus()==true)
       {
           return true;


       }
   }
   return false;


}
/**
Returns None
@param QKeyEvent Pointer object
@return none
Moves our enemy left and right a square with the arrow keys

*/
void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        setPos(x()-width_,y());
    }
    if(event->key() == Qt::Key_Right)
    {
        setPos(x()+width_,y());
    }

}

/**
Returns QRectF object

@param None
@return QRectF object
*/
QRectF Player::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}
/**
Returns QPainerPath object

@param None
@return QPainterPath object
*/
QPainterPath Player::shape() const
{
    QPainterPath path;
    path.addEllipse(x_, y_, width_, width_);
    return path;
}

/**
Returns None

@param QRectF object, QStyleOptionGraphicsItem,QWidget
@return None
*/
void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);


    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_));

    painter->setBrush(b);
    painter->drawPixmap(x_,y_,width_,width_,QPixmap("/Users/rohansuri17/Downloads/planet.png"));
}



/**
  Makes it so the == operator will have the behavior that you
  expect when comparing Players.
  You can overload pretty much any operator in c++
  @param first Player left hand side of the expression
  @param other Player right hand side of the expression
*/
bool operator==(const Player &first, const Player &other) {
  return first.x_ == other.x_ && first.y_ == other.y_;
}
