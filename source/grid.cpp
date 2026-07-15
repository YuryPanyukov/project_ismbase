#include <iostream>
#include "../include/point.h"
#include "../include/node.h"
#include "../include/grid.h"

Grid::Grid(){
    nodes.assign(0, Node(Point()));
    edges.assign(0, Edge(Node(Point()), Node(Point())));
    cells.assign(0, Cell());
}

void Grid::createGrid(std::vector<SNode> nodes, std::vector<SCell> cells) {

}

void Grid::getInformation() {
    std::cout << "Amount nodes = "<< nodes.size() << std::endl;
    std::cout << "Amount edges = "<< edges.size() << std::endl;
    std::cout << "Amount cells = "<< cells.size() << std::endl;
}