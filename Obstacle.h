#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Cell.h"


class Obstacle : public Cell
{
    public:
        Obstacle();
        Obstacle(int Arow, int Acol, Arena *ArgArenaPtr);
        virtual ~Obstacle();
    protected:
    private:
};

#endif // OBSTACLE_H
