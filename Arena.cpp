#include "Arena.h"
#include "Cell.h"
#include "Parameters.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Predator.h"
#include "Obstacle.h"
#include "TransportHole.h"



using namespace std;

Arena::Arena()
{
    //ctor
}

Arena::~Arena()
{
    unsigned int r,c;
      for (r=0;r<rows;r++)
      {
          for(c=0;c<cols;c++)
          {
              delete iPtr[r][c];
          }
      }
      for (r=0;r<rows;r++)
      {
          delete iPtr[r];
      }
      delete iPtr;
}

Arena::Arena(int aRows, int aCols)
{
  unsigned int r,c;
  rows = aRows;
  cols = aCols;

  CreateArrayOfCoords();
  RandomizeArrayOfCoords();

  unsigned int rnd;

  iPtr= new Cell**[rows];

  for (r=0;r<rows;r++)
  {
      iPtr[r] = new Cell*[cols];
      for(c=0;c<cols;c++)
      {
          //iPtr[r][c] = new Cell(r,c,this); //temporary delete for live

          //uncomment following code for live

          rnd=rand()%100;
          if (rnd<Parameters::PERCENT_PREDATOR)
          {
              iPtr[r][c] = new Predator(r,c,this);
          }
          else if(rnd<(Parameters::PERCENT_PREDATOR+Parameters::PERCENT_PREY))
          {
              iPtr[r][c] = new PreyRobot(r,c,this);
          }
          else if(rnd<(Parameters::PERCENT_PREDATOR+Parameters::PERCENT_PREY+Parameters::PERCENT_OBSTACLES))
          {
              iPtr[r][c] = new Obstacle(r,c,this);
          }
           else if(rnd<(Parameters::PERCENT_PREDATOR+Parameters::PERCENT_PREY+Parameters::PERCENT_OBSTACLES+Parameters::PERCENT_TRANSPORTHOLES))
          {
              iPtr[r][c] = new TransportHole(r,c,this);
          }
          else if(rnd<(Parameters::PERCENT_PREDATOR+Parameters::PERCENT_PREY+Parameters::PERCENT_OBSTACLES+Parameters::PERCENT_TRANSPORTHOLES+Parameters::PERCENT_BLACKHOLES))
          {
              iPtr[r][c] = new BlackHole(r,c,this);
          }
          else{iPtr[r][c] = new Cell(r,c,this);}
      }
  }
}

bool Arena::Kill(int rc1[2])
{
    delete iPtr[rc1[0]][rc1[1]];
    iPtr[rc1[0]][rc1[1]]=new Cell(rc1[0],rc1[1],this);
    return true;
}

bool Arena::Spawn(int rc1[2], char a_RobotType)
{
    delete iPtr[rc1[0]][rc1[1]];
    if(a_RobotType=='r')
        {iPtr[rc1[0]][rc1[1]]=new PreyRobot(rc1[0],rc1[1],this);}
    else if(a_RobotType=='P')
        {iPtr[rc1[0]][rc1[1]]=new Predator(rc1[0],rc1[1],this);}
    else{iPtr[rc1[0]][rc1[1]]=new Cell(rc1[0],rc1[1],this);}
    return true;
}

void Arena::swapCells(int rc1[2], int rc2[2])//takes 2 int arrays as parameters denoting two vectors {row,col}
{
  Cell *tmpCell;

  tmpCell=iPtr[rc1[0]][rc1[1]]; //tmp points to cell1

  iPtr[rc1[0]][rc1[1]]=iPtr[rc2[0]][rc2[1]];

  iPtr[rc2[0]][rc2[1]]=tmpCell;
  iPtr[rc2[0]][rc2[1]]->setRowCol(rc2[0],rc2[1]);
  iPtr[rc1[0]][rc1[1]]->setRowCol(rc1[0],rc1[1]);
}

void Arena::DisplayArena()
{
  unsigned int r,c;
  for (r=0;r<rows;r++)
  {
      for(c=0;c<cols;c++)
      {
          cout <<iPtr[r][c]->DisplayCell();
      }
      cout<<endl;
  }
}

void Arena::AnimateArena()
{
    unsigned int r,c;

    for (unsigned int ndex=0;ndex<rows*cols;ndex++)
    {
        iPtr[ArrayOfCoords[ndex].strRow][ArrayOfCoords[ndex].strCol]->Animate();
    }

    for (r=0;r<rows;r++)
    {
      for(c=0;c<cols;c++)
      {
          iPtr[r][c]->resetAnimatedTHisTurn();
      }
    }
    RandomizeArrayOfCoords();
}

char Arena::ReturnCellType(int aRow, int aCol)
{
    return iPtr[aRow][aCol]->DisplayCell();
}


void Arena::CreateArrayOfCoords()
{
    unsigned int ndex1=0;
    unsigned int r,c;

    ArrayOfCoords = new cellCoords[rows*cols];

    //initiate array
    for (r=0;r<rows;r++)
      {
          for(c=0;c<cols;c++)
          {
              ArrayOfCoords[ndex1].strRow=r;
              ArrayOfCoords[ndex1].strCol=c;
              ndex1++;
          }
      }
}

void Arena::RandomizeArrayOfCoords()
{
    unsigned int ndex1=0,ndex2=0;
    unsigned int tmpRow,tmpCol;

      //randomize array
      for(unsigned int i=0;i<cols*rows*3;i++)
      {
          ndex1=rand()%cols*rows;
          ndex2=rand()%cols*rows;

          tmpRow=ArrayOfCoords[ndex1].strRow;
          tmpCol=ArrayOfCoords[ndex1].strCol;

          ArrayOfCoords[ndex1].strRow=ArrayOfCoords[ndex2].strRow;
          ArrayOfCoords[ndex1].strCol=ArrayOfCoords[ndex2].strCol;

          ArrayOfCoords[ndex2].strRow=tmpRow;
          ArrayOfCoords[ndex2].strCol=tmpCol;
      }

}





