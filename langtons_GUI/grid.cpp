#include "grid.h"

grid::grid(int size){
    int** grid = new int*[size];
    for(int i = 0; i < size; i++)
        grid[i] = new int[size];
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            grid[i][j] = WHITE;
    this->_grid = grid;
}

grid::~grid(){
    if(this->_grid)
        free(this->_grid);
}

void grid::changeColor(int x, int y){
    int color = this->_grid[y][x];
    switch(color){
        case WHITE:
            this->_grid[y][x] = BLUE;
            break;
        case BLUE:
            this->_grid[y][x] = WHITE;
            break;
    }
}


int grid::getColor(int x, int y){
    return this->_grid[y][x];
}
