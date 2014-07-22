#include "Predator.h"
#include "Parameters.h"

Predator::Predator()
{
    //ctor
}
Predator::Predator(int Arow, int Acol, Arena *ArgArenaPtr)
{
       displayChar='P';
       timeToEat=Parameters::TIME_TO_EAT;
       timeToBreed=Parameters::TIME_TO_BREED_PREDATOR;
       posRow=Arow;
       posCol=Acol;
       cellArenaPtr= ArgArenaPtr;
       animatedThisTurn=false;
}
Predator::~Predator()
{
    //dtor
}
void Predator::Animate()
{
    timeToBreed--;
    timeToEat--;
    if (timeToEat<=0)
    {
        int thisPosition[2]={posRow,posCol};
        cellArenaPtr->Kill(thisPosition);
    }
    else
    {
        if (!animatedThisTurn)
        {
            if(timeToEat<=Parameters::PREDATOR_AGGRESSIVENESS)
            {
                animatedThisTurn=Eat();
                if (animatedThisTurn)
                {
                    timeToEat=Parameters::TIME_TO_EAT;
                }
            }
            if (!animatedThisTurn)
            {
                if (timeToBreed<=0)
                {
                    animatedThisTurn=Breed('P');
                    if(animatedThisTurn)
                        {timeToBreed=Parameters::TIME_TO_BREED_PREDATOR;}
                }
            }
            if (!animatedThisTurn)
                {animatedThisTurn=Move();
                animatedThisTurn=true;}
        }
    }
}

bool Predator::Eat()
{
    UpdateNeighbors();
    unsigned loopCount=0, ndex_rnd;
    bool didEat=false;

    int tempCell2[2];

    ndex_rnd=rand()%4;
    for (loopCount=0;loopCount<4;loopCount++)
    {
        switch((ndex_rnd+loopCount)%4)
        {
            case 0:
            {

                if (neighborN=='r')
                {
                    tempCell2[0]=cell_rowNorth;
                    tempCell2[1]=posCol;
                    cellArenaPtr->Kill(tempCell2);
                    didEat=true;
                    break;
                }
            }
            case 1:
            {

                if (neighborE=='r')
                {
                    tempCell2[0]=posRow;
                    tempCell2[1]=cell_colEast;
                    cellArenaPtr->Kill(tempCell2);
                    didEat=true;
                    break;
                }
            }
            case 2:
            {
                if (neighborS=='r')
                {
                    tempCell2[0]=cell_rowSouth;
                    tempCell2[1]=posCol;
                    cellArenaPtr->Kill(tempCell2);
                    didEat=true;
                    break;
                }
            }
            case 3:
            {
                if (neighborW=='r')
                {
                    tempCell2[0]=posRow;
                    tempCell2[1]=cell_colWest;
                    cellArenaPtr->Kill(tempCell2);
                    didEat=true;
                    break;
                }
            }
            default:break;
        }
        if (didEat){break;}
        loopCount++;
    }
    return didEat;

}
