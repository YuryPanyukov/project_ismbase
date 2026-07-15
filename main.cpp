// main.cpp
#include "mathutils.h"
#include <iostream>
#include "include/point.h"
#include "include/node.h"
#include "include/grid.h"

int main() {
    std::cout << "Add: " << add(5, 3) << std::endl;

    Point p(1, 2);
    std::cout << "getX: " << p.getX() << ", getY: " << p.getY() << std::endl;

    Node node(p);
    std::cout << "getX: " << node.getX() << std::endl;
    



    Grid grid;
    grid.getInformation();

    return 0;
}
