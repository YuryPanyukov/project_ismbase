#ifndef EDGE_H
#define EDGE_H

#include "../include/node.h"


class Edge{
    private:
        Node first;
        Node second;

        int frstNumCell = -1;
        int scndNumCell = -1;
    public:
        Edge(Node first, Node second, int frstNumCell, int scndNumCell):
           first(first), second(second), frstNumCell(frstNumCell), scndNumCell(scndNumCell) {}
        ~Edge() {}

        double getX();
        double getY();
};

#endif