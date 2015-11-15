#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <unistd.h>
#include "main.h"

void colorBox(int x, int y, int color);
void run();
int driver(int argc, char **argv);
ant* ant;
grid* grid;
QGraphicsScene     *scene;
QGraphicsRectItem  *rect;
QGraphicsView      *view;

int main(int argc, char **argv){
    driver(argc, argv);
    for(int i = 0; i < 10; i++)
        run();
}

int driver(int argc, char **argv){
    QApplication app(argc, argv);

    scene = new QGraphicsScene();
    rect  = new QGraphicsRectItem();
    view  = new QGraphicsView(scene);
    view->setFixedSize(800,600);
    view->fitInView(scene->itemsBoundingRect());
    ant = new ant::ant(SIZE/20, SIZE/20);
    grid = new grid::grid(SIZE/10);
    rect->setRect(SIZE/2, SIZE/2, 10, 10);
    rect->setBrush(* new QBrush(Qt::black));
    scene->addItem(rect);
    scene->setSceneRect(0, 0, SIZE, SIZE);
    view->show();


    for (int i = 0; i <= SIZE; i +=10){
        scene->addLine(i, 0, i, SIZE, QPen(Qt::black));
        scene->addLine(0, i, SIZE, i, QPen(Qt::black));
    }

   return app.exec();
}

void run(){
    int oldX = ant->getX();
    int oldY = ant->getY();
    int color = grid->getColor(oldX, oldY);
    ant->move(color);
    colorBox(oldX*10, oldY*10, color);
    int newX = ant->getX();
    int newY = ant->getY();
    rect->setRect(newX*10, newY*10, 10, 10);
    grid->changeColor(oldX, oldY);
    scene->update();
}

void colorBox(int x, int y, int color){
    switch (color){
        case WHITE:
            scene->addLine(x, y+1, x+10, y+1, QPen(Qt::blue));
            scene->addLine(x, y+2, x+10, y+2, QPen(Qt::blue));
            scene->addLine(x, y+3, x+10, y+3, QPen(Qt::blue));
            scene->addLine(x, y+4, x+10, y+4, QPen(Qt::blue));
            scene->addLine(x, y+5, x+10, y+5, QPen(Qt::blue));
            scene->addLine(x, y+6, x+10, y+6, QPen(Qt::blue));
            scene->addLine(x, y+7, x+10, y+7, QPen(Qt::blue));
            scene->addLine(x, y+8, x+10, y+8, QPen(Qt::blue));
            scene->addLine(x, y+9, x+10, y+9, QPen(Qt::blue));
            break;
        case BLUE:
            scene->addLine(x, y+1, x+10, y+1, QPen(Qt::white));
            scene->addLine(x, y+2, x+10, y+2, QPen(Qt::white));
            scene->addLine(x, y+3, x+10, y+3, QPen(Qt::white));
            scene->addLine(x, y+4, x+10, y+4, QPen(Qt::white));
            scene->addLine(x, y+5, x+10, y+5, QPen(Qt::white));
            scene->addLine(x, y+6, x+10, y+6, QPen(Qt::white));
            scene->addLine(x, y+7, x+10, y+7, QPen(Qt::white));
            scene->addLine(x, y+8, x+10, y+8, QPen(Qt::white));
            scene->addLine(x, y+9, x+10, y+9, QPen(Qt::white));
            break;
    }
}
