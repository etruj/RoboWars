#ifndef PREDATOR_H
#define PREDATOR_H

#include "PreyRobot.h"


class Predator : public PreyRobot
{
    public:
        Predator();
         Predator(int Arow, int Acol, Arena *ArgArenaPtr);
        virtual ~Predator();
        void Animate();
        bool Eat();
    protected:
    private:
};

#endif // PREDATOR_H
