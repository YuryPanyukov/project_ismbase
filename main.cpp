// main.cpp
#include "mathutils.h"
#include <iostream>
#include "include/point.h"
#include "include/node.h"
#include "include/grid.h"

Grid newGrid(){
    Point A(0.0, 0.0);

    double height = 1.0;
    double width = 1.0;
    int amountIntervalsWidth = 10;
    int amountIntervalsHeight = 10;
    double h = 0.1;

    std::vector<Point> points;
    for (int i=0; i<amountIntervalsWidth; i++){
        for (int j=0; j<amountIntervalsHeight; j++){
            Point newPoint(A.getX() + i*h, A.getY() + j*h);
            points.push_back(newPoint);
        }
    }

    std::vector<SNode> nodes;
    for (int i=0; i<points.size(); i++){
        SNode newNode(points[i]);
        nodes.push_back(newNode);
    }

    std::vector<SCell> cells;
    for (int i=0; i<amountIntervalsWidth - 1; i++){
        for (int j=0; j<amountIntervalsHeight - 1; j++){
            std::vector<int> numNodes;
            numNodes.push_back(i*amountIntervalsHeight + j);                
            numNodes.push_back(i*amountIntervalsHeight + j + 1);
            numNodes.push_back((i+1)*amountIntervalsHeight + j);
            numNodes.push_back((i+1)*amountIntervalsHeight + j + 1);
            cells.push_back(SCell(numNodes));
        }
    }

    Grid grid;
    grid.createGrid(nodes, cells);

    return grid;
}

int main() {
    std::cout << "Add: " << add(5, 3) << std::endl;

    Point p(1, 2);
    std::cout << "getX: " << p.getX() << ", getY: " << p.getY() << std::endl;

    Node node(p);
    std::cout << "getX: " << node.getX() << std::endl;


    Grid grid = newGrid();
    grid.getInformation();

    return 0;
}
