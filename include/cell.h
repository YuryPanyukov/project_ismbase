#ifndef CELL_H
#define CELL_H

#include <vector>
#include "../include/point.h"

class Grid;

class Cell{
    private:
        double Rho;
        double T;
        Point u;
        std::vector<int> edgeNums;
        Grid* grid;
    public:
        Cell() {}
        Cell(std::vector<int> edgeNums, Grid* grid): edgeNums(edgeNums), grid(grid) {}
        ~Cell() {}

        int amountEdges() const { return edgeNums.size(); }
        int getEdgeNum(int idxEdge) const { return edgeNums[idxEdge]; }
        int getNodeNum(int idxNode) const;
};

#endif