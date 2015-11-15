#ifndef ANT_H
#define ANT_H
#include "main.h"

#define NORTH 0
#define EAST  1
#define SOUTH 2
#define WEST  3

class ant {
private:
    int facing, x, y;
public:
    ant(int x, int y);
    int getX();
    int getY();
    void move(int current_color);
};

#endif // ANT_H
