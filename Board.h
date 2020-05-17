#ifndef Board_H
#define Board_H
#include <QColor>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QtWidgets>
#include <QObject>

enum class SquareType {Player, Enemy, Planet, Sun, Empty};
//std::string SquareTypeStringify(SquareType sq);


class Board : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        Board( int Board_x, int Board_y,int Board_width,int Board_length); //constructor
        int GetBoardLength();
        void SetBoardLength(int);
        int GetBoardWidth();
        void SetBoardWidth(int);
        int GetBoardX();
        void SetBoardX(int);
        int GetBoardY();
        void SetBoardY(int);
        bool GetAliveStatus();
        void SetAliveStatus(bool);
        QColor GetColor();
        void SetColor(QColor c);
        SquareType get_square_value();
        void SetSquareValue(SquareType value);
        QRectF boundingRect() const override;
        QPainterPath shape() const override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;



    signals:

    private:
        int Board_length_;
        int Board_width_;
        int Board_x_;
        int Board_y_;
        bool alive_;
        QColor color_;
        bool isalive_prev_;
        QColor color_prev_;
        SquareType square_;//= SquareType::Empty;
};



















#endif
