#ifndef CELL_H
#define CELL_H

#include <vector>
#include "../include/point.h"


class Cell{
    private:
        double Rho;
        double T;
        Point u;
        std::vector<int> edgeNums;
    public:
        Cell() {}
        Cell(std::vector<int> edgeNums): edgeNums(edgeNums) {}
        ~Cell() {}
};

#endif