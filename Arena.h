#ifndef ARENA_H
#define ARENA_H
#include "Cell.h"

class Cell;

struct cellCoords
{
    unsigned int strRow;
    unsigned int strCol;
};
class Arena
{
    friend class Cell;
    public:
        Arena();
        ~Arena();
        Arena(int aRows, int aCols);
        unsigned int GetColums(){return cols;}
        unsigned int GetRows(){return rows;}
        void swapCells(int rc1[2], int rc2[2]);
        void DisplayArena();
        void AnimateArena();
        char ReturnCellType(int aRow, int aCol);
        bool Spawn(int rc1[2], char a_RobotType);
        bool Kill(int rc1[2]);
        void CreateArrayOfCoords();
        void RandomizeArrayOfCoords();

    protected:
    private:
        Cell ***iPtr;
        unsigned int rows;
        unsigned int cols;
        cellCoords *ArrayOfCoords;
};

#endif // ARENA_H
