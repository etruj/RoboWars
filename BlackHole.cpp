#include "BlackHole.h"
#include "Parameters.h"

BlackHole::BlackHole()
{
    //ctor
}
BlackHole::BlackHole(int Arow, int Acol, Arena *ArgArenaPtr){
   displayChar='O';
   posRow=Arow;
   posCol=Acol;
   cellArenaPtr= ArgArenaPtr;
   animatedThisTurn=false;}
BlackHole::~BlackHole()
{
    //dtor
}
void BlackHole::Animate()
{
    UpdateNeighbors();
    animatedThisTurn= KillRobot();
}
bool BlackHole::KillRobot()
{
    UpdateNeighbors();
    unsigned ndex_rnd;
    bool didKill=false;

    int tempCell2[2];

    ndex_rnd=rand()%8;

    switch((ndex_rnd))
    {
        case 0:
        {

            if (neighborN=='r'||neighborN=='P')
            {
                tempCell2[0]=cell_rowNorth;
                tempCell2[1]=posCol;
                cellArenaPtr->Kill(tempCell2);
                didKill=true;
                break;
            }
        }
        case 1:
        {

            if (neighborE=='r'||neighborE=='P')
            {
                tempCell2[0]=posRow;
                tempCell2[1]=cell_colEast;
                cellArenaPtr->Kill(tempCell2);
                didKill=true;
                break;
            }
        }
        case 2:
        {
            if (neighborS=='r'||neighborS=='P')
            {
                tempCell2[0]=cell_rowSouth;
                tempCell2[1]=posCol;
                cellArenaPtr->Kill(tempCell2);
                didKill=true;
                break;
            }
        }
        case 3:
        {
            if (neighborW=='r'||neighborW=='P')
            {
                tempCell2[0]=posRow;
                tempCell2[1]=cell_colWest;
                cellArenaPtr->Kill(tempCell2);
                didKill=true;
                break;
            }
        }
        default:break;
    }
    return didKill;
}
