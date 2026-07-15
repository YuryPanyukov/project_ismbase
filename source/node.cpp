#include <iostream>
#include "../include/node.h"

Point Node::getCoord(){
    return coord;
}

double Node::getX(){
    return coord.getX();
}

void Node::getInformation(){
    std::cout << "Node.x = " << std::endl;
}