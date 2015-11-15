#include "ant.h"

ant::ant(int x, int y) {
    this->x = x;
    this->y = y;
    this->facing = SOUTH;
}

int ant::getX(){
    return this->x;
}

int ant::getY(){
    return this->y;
}

void ant::move(int current_color){
    switch(current_color){
        case WHITE:
            switch(this->facing){
                case NORTH:
                    this->x += 1;
                    this->facing = EAST;
                    break;
                case EAST:
                    this->y += 1;
                    this->facing = SOUTH;
                    break;
                case SOUTH:
                    this->x -= 1;
                    this->facing = WEST;
                    break;
                case WEST:
                    this->y -= 1;
                    this->facing = NORTH;
                    break;
            }
        break;
        case BLUE:
            switch(this->facing){
                case NORTH:
                    this->x -= 1;
                    this->facing = WEST;
                    break;
                case EAST:
                    this->y -= 1;
                    this->facing = NORTH;
                    break;
                case SOUTH:
                    this->x += 1;
                    this->facing = EAST;
                    break;
                case WEST:
                    this->y += 1;
                    this->facing = SOUTH;
                    break;
                }
        break;
    }
}

