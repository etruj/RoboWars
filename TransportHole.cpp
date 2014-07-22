#include "TransportHole.h"
#include "Parameters.h"

TransportHole::TransportHole()
{
    //ctor
}
TransportHole::TransportHole(int Arow, int Acol, Arena *ArgArenaPtr){
   displayChar='*';
   posRow=Arow;
   posCol=Acol;
   cellArenaPtr= ArgArenaPtr;
   animatedThisTurn=false;}
TransportHole::~TransportHole()
{
    //dtor
}
void TransportHole::Animate()
{

}
