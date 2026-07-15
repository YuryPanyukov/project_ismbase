#ifndef NODE_H
#define NODE_H

#include "../include/point.h"


class Node{
    private:
        Point coord;
    public:
        Node(Point coord): coord(coord) {}
        ~Node() {}

        double getX();
        double getY();
};

#endif