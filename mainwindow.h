#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <vector>
#include "Board.h"
#include "point.h"
//#include "Population.h"
#include "Player.h"
#include <list>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void CreateGrid();
    void Move();
    bool CreateRandomAliveStatus();

private slots:
    void on_Step_clicked();

    void on_pushButton_clicked();

    void on_Stop_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *Board_;
    QGraphicsScene *population_graph_;
    QGraphicsView *population_view_;
    QGraphicsView * Board_view_;
    double speed_ = 1.0;
    int population_ = 0;
    int turn_ = 0;
    std::vector<Board*> row;
    Board *Board_Matrix_[10][20];
    //std::vector<CellInfo> cell_states_;
    int counts_[10][20];
    QTimer *timer_;
    int alive_counter_=0;
    int population_back_count_=0;
    bool stop = false;
    //Player *p = new Player();
    //Point *p;
};
#endif // MAINWINDOW_H
