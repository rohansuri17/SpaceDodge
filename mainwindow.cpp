#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Board.h"
#include "Player.h"
//#include "Population.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <vector>
#include <QFloat16>
#include <QGraphicsEllipseItem>
/**
Homework 5
Rohan Suri
This is the final project for CSCI 3010. I made a game called dodge where you and any amount of players will compete to dodge black holes and gain points through planets and suns.
You are the manned flying saucer that moves with the arrow keys and the player with the most points wins. Good luck!
*/

//Default Constructor for Main Window
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    CreateGrid();
    timer_=new QTimer();
    connect(timer_, SIGNAL(timeout()), this, SLOT(on_pushButton_clicked()));
    //CreatePopulationGraph();

}
//destructor
MainWindow::~MainWindow()
{

    delete ui;
}
/**
Returns None

@param None
@return None
Creates the initial game board with player object(flying saucer) and enemies(black holes)
*/
void MainWindow::CreateGrid()
{

    ui->setupUi(this);
    turn_=0;
    QColor color(255, 0, 0);
    Board_ = new QGraphicsScene;
    Board_view_ = ui->Grid;
    Board_view_->setScene(Board_);
    Board_view_->setSceneRect(0,0,Board_view_->frameSize().width(),Board_view_->frameSize().height());

    qsrand(time(0));

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            Board * item = new Board(j, i, Board_view_->frameSize().width()/5, Board_view_->frameSize().height()/4);
            Board_Matrix_[i][j] = item;
            if(i==3)
            {
                Board_Matrix_[i][j]->SetAliveStatus(false);


            }
            Board_->addItem(Board_Matrix_[i][j]);
            population_++;
        }
    }
    QColor color2(255,255,255);
    Player *p = new Player(color2, Board_view_->frameSize().width()/2-((Board_view_->frameSize().width()/5)/2),  Board_view_->frameSize().height()/2+((Board_view_->frameSize().width()/5)));
    p->set_color(color2);
    p->setX(Board_view_->frameSize().width()/2-((Board_view_->frameSize().width()/5)/2));
    p->setY(Board_view_->frameSize().height()/2+((Board_view_->frameSize().width()/5)));
    p->set_width(Board_view_->frameSize().width()/5);
    p->set_height(Board_view_->frameSize().height()/4);
    p->setZValue(1);
    Board_->addItem(p);
    p->setFlag(QGraphicsItem::ItemIsFocusable);
    p->setFocus();
    ui->Grid->repaint();
    Board_->update();
}

/**
Returns None

@param None
@return None
Accounts for all logic when the board moves(2d array shift down algorithm)
*/
void MainWindow::Move()
{
    QColor color(0,255,0);
    for(int i = 2; i >= 0 ; i--)
    {

        for(int j = 0; j < 5; j++)
        {
            Board_Matrix_[i+1][j]->SetAliveStatus(Board_Matrix_[i][j]->GetAliveStatus());
            Board_Matrix_[i][j]->SetAliveStatus(CreateRandomAliveStatus());
        }
    }
    Board_->update();
    //p->isColliding();
}
/**
Return bool
@param None
@return bool status of enemy alive or not
Randomly decides if a cell on the board has an enemy(alive true) or not(alive false)
*/
bool MainWindow::CreateRandomAliveStatus()
{
    int random = qrand() % 100;
    bool alive;
    QColor color(255, 0, 0);
    if(random < 15)
    {
        alive = true;
    }
    else
    {
        alive = false;
    }
    return alive;

}
//Slot when step button is clicked
void MainWindow::on_Step_clicked()
{
    Move();
}

//Slot when start button is clicked
void MainWindow::on_pushButton_clicked()
{
    Move();
    timer_->start(750);
}
//slot when stop is clicked
void MainWindow::on_Stop_clicked()
{
    timer_->stop();
}
