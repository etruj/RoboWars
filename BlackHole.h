#ifndef BLACKHOLE_H
#define BLACKHOLE_H

#include "Predator.h"


class BlackHole : public Predator
{
    public:
        BlackHole();
        virtual ~BlackHole();
        BlackHole(int Arow, int Acol, Arena *ArgArenaPtr);
        void Animate();
        bool KillRobot();
    protected:
    private:
};

#endif // BLACKHOLE_H
