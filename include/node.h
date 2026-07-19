#ifndef NODE_H
#define NODE_H

#include <vector>
#include "../include/point.h"


class Node{
    private:
        Point coord;
        std::vector<int> edgeNums;
    public:
        Node(Point coord): coord(coord) {}
        ~Node() {}

        Point getCoord();
        double getX();

        void getInformation();
};

#endif