#ifndef CELL_H
#define CELL_H

#include "../include/point.h"


class Cell{
    private:
        double Rho;
        double T;
        Point u;
    public:
        Cell() {}
        ~Cell() {}
};

#endif