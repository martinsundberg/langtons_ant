#ifndef GRID_H
#define GRID_H
#include <stdlib.h>
#include "main.h"


class grid {
private:
    int** _grid;
public:
    grid(int size);
    ~grid();
    void changeColor(int x, int y);
    int getColor(int x, int y);
};

#endif // GRID_H
