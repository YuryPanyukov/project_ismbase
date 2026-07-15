#ifndef GRID_H
#define GRID_H

#include <vector>
#include "../include/cell.h"
#include "../include/node.h"
#include "../include/edge.h"
#include "../include/point.h"


class Grid{
    private:
        std::vector<Node> cells;
        std::vector<Node> nodes;
        std::vector<Edge> edges;
    public:
        Grid() {}
        ~Grid() {}
};

#endif