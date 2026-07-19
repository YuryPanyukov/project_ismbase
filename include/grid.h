#ifndef GRID_H
#define GRID_H

#include <vector>
#include "../include/cell.h"
#include "../include/node.h"
#include "../include/edge.h"
#include "../include/point.h"

struct SNode{
    Point coord;
    Point vec;

    SNode(Point coord, Point vec=Point(0, 0)): coord(coord), vec(vec) {}
};

struct SEdge{
    int firstNodeNum;
    int secondNodeNum;

    int firstCellNum = -1;
    int secondCellNum = -1;
    

    SEdge(int firstNodeNum, int secondNodeNum, int firstCellNum, int secondCellNum = -1): 
    firstNodeNum(firstNodeNum), secondNodeNum(secondNodeNum), firstCellNum(firstCellNum), secondCellNum(secondCellNum) {}
};

struct SCell{
    std::vector<int> numNodes;

    SCell(std::vector<int> numNodes): numNodes(numNodes) {}
};


class Grid{
    private:
        std::vector<Cell> cells;
        std::vector<Node> nodes;
        std::vector<Edge> edges;
    public:
        Grid();
        ~Grid() {}

        void createGrid(std::vector<SNode> nodes, std::vector<SCell> cells);
        void getInformation();
};

#endif