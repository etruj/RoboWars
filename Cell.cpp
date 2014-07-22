#include "Cell.h"
#include "Arena.h"
#include <iostream>
#include "Parameters.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

Cell::Cell()
{
    //def ctor
    displayChar=' ';
}
Cell::~Cell()
{
    //dtor
}
Cell::Cell(int Arow, int Acol, Arena *ArgArenaPtr)
{
   displayChar=' ';
   animatedThisTurn=false;
   posRow=Arow;
   posCol=Acol;
   cellArenaPtr= ArgArenaPtr;
}
void Cell::UpdateNeighbors()
{
    unsigned int numArenaRows=cellArenaPtr->GetRows();
    unsigned int numArenaCols=cellArenaPtr->GetColums();
    unsigned int rowAbove, rowBelow, colLeft, colRight;

    //set rows
    if(posRow==0)
    {
        rowAbove=numArenaRows-1;
        rowBelow=1;
    }
    else if(posRow==(numArenaRows-1))
    {
        rowBelow=0;
        rowAbove=numArenaRows-2;
    }
    else
    {
        rowAbove=posRow-1;
        rowBelow=posRow+1;
    }

    //set columns
    if(posCol==0)
    {
        colLeft=numArenaCols-1;
        colRight=1;
    }
    else if(posCol==(numArenaCols-1))
    {
        colLeft=numArenaCols-2;
        colRight=0;
    }
    else
    {
        colLeft=posCol-1;
        colRight=posCol+1;
    }
    neighborN=cellArenaPtr->ReturnCellType(rowAbove, posCol);
    neighborE=cellArenaPtr->ReturnCellType(posRow, colRight);
    neighborS=cellArenaPtr->ReturnCellType(rowBelow, posCol);
    neighborW=cellArenaPtr->ReturnCellType(posRow, colLeft);
    cell_colWest=colLeft;
    cell_colEast=colRight;
    cell_rowNorth=rowAbove;
    cell_rowSouth=rowBelow;
}

void Cell::setRowCol(int Arow, int Acol)
{
   posRow=Arow;
   posCol=Acol;
}
void Cell::Animate(){}
