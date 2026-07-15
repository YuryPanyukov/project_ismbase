#ifndef EDGE_H
#define EDGE_H

#include "../include/node.h"


class Edge{
    private:
        Node first;
        Node second;
    public:
        Edge(Node first, Node second): first(first), second(second) {}
        ~Edge() {}

        double getX();
        double getY();
};

#endif