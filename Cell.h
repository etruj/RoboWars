#ifndef CELL_H
#define CELL_H
#include "Arena.h"

class Arena;
class Cell
{
    friend class Arena;
    public:
        Cell();
        Cell(int Arow, int Acol, Arena *ArgArenaPtr);
        virtual ~Cell();
        virtual void Animate();
        void setAnimatedThisTurn(){animatedThisTurn=true;}
        void resetAnimatedTHisTurn(){animatedThisTurn=false;}
        bool getAnimatedThisTurn(){return animatedThisTurn;}

        bool Move();
        void Eat();
        void Breed();
        void Encounter();
        void setRowCol(int Arow, int Acol);
        void UpdateNeighbors();
        char DisplayCell(){return displayChar;}
        int GetRow(){return posRow;}
        int GetCol(){return posCol;}
    protected:
        unsigned int timeToEat;
        unsigned int timeToBreed;
        bool animatedThisTurn;
        int posRow;
        int posCol;
        unsigned int cell_rowNorth;
        unsigned int cell_rowSouth;
        unsigned int cell_colEast;
        unsigned int cell_colWest;
        char displayChar;
        char neighborN;
        char neighborE;
        char neighborS;
        char neighborW;
        Arena *cellArenaPtr;
};

#endif // CELL_H
