#include "../include/edge.h"
#include "../include/cell.h"
#include "../include/grid.h"
#include <math.h>

int Cell::getNodeNum(int idxNode) const{
    if (idxNode < 0 || idxNode >= edgeNums.size()){
        return -1;
    }

    int numEdge = edgeNums[idxNode];
    const Edge& edge = grid->getEdge(abs(numEdge));

    if (numEdge > 0){
        return edge.getFirstNumNode();
    } else {
        return edge.getSecondNumNode();
    }
}