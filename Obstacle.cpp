#include "Obstacle.h"
#include "Parameters.h"

Obstacle::Obstacle()
{
    //ctor
}
Obstacle::Obstacle(int Arow, int Acol, Arena *ArgArenaPtr){
   displayChar='#';
   posRow=Arow;
   posCol=Acol;
   cellArenaPtr= ArgArenaPtr;}
Obstacle::~Obstacle()
{
    //dtor
}
