#ifndef Enemy_H
#define Enemy_H
#include <QColor>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QtWidgets>
#include <QObject>
class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        Enemy( int Enemy_x, int Enemy_y,int Enemy_width,int Enemy_length); //constructor
        int GetEnemyLength();
        void SetEnemyLength(int);
        int GetEnemyWidth();
        void SetEnemyWidth(int);
        int GetEnemyX();
        void SetEnemyX(int);
        int GetEnemyY();
        void SetEnemyY(int);
        bool GetAliveStatus();
        void SetAliveStatus(bool);
        QColor GetColor();
        void SetColor(QColor c);
        QRectF boundingRect() const override;
        QPainterPath shape() const override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;



    signals:

    private:
        int Enemy_length_;
        int Enemy_width_;
        int Enemy_x_;
        int Enemy_y_;
        bool alive_;
        QColor color_;
        bool isalive_prev_;
        QColor color_prev_;
};



















#endif
