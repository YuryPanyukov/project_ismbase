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
};

struct SCell{
    std::vector<int> numNodes;
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