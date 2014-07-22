#ifndef TRANSPORTHOLE_H
#define TRANSPORTHOLE_H

#include "BlackHole.h"


class TransportHole : public BlackHole
{
    public:
        TransportHole();
        TransportHole(int Arow, int Acol, Arena *ArgArenaPtr);
        void Animate();
        virtual ~TransportHole();
    protected:
    private:
};

#endif // TRANSPORTHOLE_H
