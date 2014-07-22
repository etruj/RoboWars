#include "PreyRobot.h"
#include "Parameters.h"

PreyRobot::PreyRobot()
{
    //ctor
}
PreyRobot::PreyRobot(int Arow, int Acol, Arena *ArgArenaPtr){
       displayChar='r';
       timeToBreed=Parameters::TIME_TO_BREED_PREY;
       posRow=Arow;
       posCol=Acol;
       cellArenaPtr= ArgArenaPtr;
       animatedThisTurn=false;}

void PreyRobot::Animate()
{
    timeToBreed--;
    if (timeToBreed<=0)
    {
        animatedThisTurn=Breed('r');
        if(animatedThisTurn)
            {timeToBreed=Parameters::TIME_TO_BREED_PREY;}
    }
    if (!animatedThisTurn)
        {animatedThisTurn=Move();}
}
bool PreyRobot::Breed(char RobotType)
{
    UpdateNeighbors();
    unsigned loopCount=0, ndex_rnd;
    bool didBreed=false;

    int tempCell2[2];

    ndex_rnd=rand()%4;
    for (loopCount=0;loopCount<4;loopCount++)
    {
        switch((ndex_rnd+loopCount)%4)
        {
            case 0:
            {

                if (neighborN==' ')
                {
                    tempCell2[0]=cell_rowNorth;
                    tempCell2[1]=posCol;
                    cellArenaPtr->Spawn(tempCell2, RobotType);
                    didBreed=true;
                    break;
                }
            }
            case 1:
            {

                if (neighborE==' ')
                {
                    tempCell2[0]=posRow;
                    tempCell2[1]=cell_colEast;
                    cellArenaPtr->Spawn(tempCell2, RobotType);
                    didBreed=true;
                    break;
                }
            }
            case 2:
            {
                if (neighborS==' ')
                {
                    tempCell2[0]=cell_rowSouth;
                    tempCell2[1]=posCol;
                    cellArenaPtr->Spawn(tempCell2, RobotType);
                    didBreed=true;
                    break;
                }
            }
            case 3:
            {
                if (neighborW==' ')
                {
                    tempCell2[0]=posRow;
                    tempCell2[1]=cell_colWest;
                    cellArenaPtr->Spawn(tempCell2, RobotType);
                    didBreed=true;
                    break;
                }
            }
            default:break;
        }
        if (didBreed){break;}
        loopCount++;
    }
    return didBreed;
}
bool PreyRobot::Move()
{
    UpdateNeighbors();
    unsigned loopCount=0, ndex_rnd;
    bool moved=false;

    int tempCell1[2];
    int tempCell2[2];

    ndex_rnd=rand()%4;
    for (loopCount=0;loopCount<4;loopCount++)
    {
        switch((ndex_rnd+loopCount)%4)
        {
            case 0:
            {

                if (neighborN==' ')
                {
                    tempCell1[0]=posRow;
                    tempCell1[1]=posCol;
                    tempCell2[0]=cell_rowNorth;
                    tempCell2[1]=posCol;
                    cellArenaPtr->swapCells(tempCell1, tempCell2);
                    moved=true;
                    break;
                }
            }
            case 1:
            {

                if (neighborE==' ')
                {
                    tempCell1[0]=posRow;
                    tempCell1[1]=posCol;
                    tempCell2[0]=posRow;
                    tempCell2[1]=cell_colEast;
                    cellArenaPtr->swapCells(tempCell1, tempCell2);
                    moved=true;
                    break;
                }
            }
            case 2:
            {
                if (neighborS==' ')
                {
                    tempCell1[0]=posRow;
                    tempCell1[1]=posCol;
                    tempCell2[0]=cell_rowSouth;
                    tempCell2[1]=posCol;
                    cellArenaPtr->swapCells(tempCell1, tempCell2);
                    moved=true;
                    break;
                }
            }
            case 3:
            {
                if (neighborW==' ')
                {
                    tempCell1[0]=posRow;
                    tempCell1[1]=posCol;
                    tempCell2[0]=posRow;
                    tempCell2[1]=cell_colWest;
                    cellArenaPtr->swapCells(tempCell1, tempCell2);
                    moved=true;
                    break;
                }
            }
            default:break;
        }
        if (moved){break;}
        loopCount++;
    }
    return moved;
}
PreyRobot::~PreyRobot()
{
    //dtor
}
