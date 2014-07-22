#ifndef PREYROBOT_H
#define PREYROBOT_H

#include "Cell.h"
#include "Arena.h"


#include <iostream>
#include <stdlib.h>
#include <stdio.h>



class PreyRobot : public Cell
{
    public:
        PreyRobot();
        PreyRobot(int Arow, int Acol, Arena *ArgArenaPtr);
        void Animate();
        bool Breed(char RobotType);
        bool Move();
        virtual ~PreyRobot();
    protected:
    private:
};

#endif // PREYROBOT_H
