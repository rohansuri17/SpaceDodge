#ifndef Player_H
#define Player_H

#include <QColor>
#include <QGraphicsItem>
#include "Board.h"

class Player : public QObject, public QGraphicsItem {

    Q_OBJECT

public:
    Player();
    Player(QColor color, const int x, const int y);  // constructor

    int get_x() const { return x_; }  // inline member function
    int get_y() const { return y_; }  // inline member function
    void set_width(int width);
    void set_height(int height);
    void set_color(QColor c);
    bool isColliding(Board *b);
    void keyPressEvent(QKeyEvent *event) override;


    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    int get_width() { return width_; };

private:
  int x_;
  int y_;
  QColor color_;

  // all our Players will be 10 wide and tall (they are circles)
 int width_ = 0;
 int height_ = 0;
 int score_ = 0;
 //SquareType square_= SquareType::Player;

  // if you declare the operator as a friend, then it isn't
  // part of the object
  // friend will let this method access the private fields
  friend bool operator==(const Player &first, const Player &other);
};  // class Player



#endif // Player_H
