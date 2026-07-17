#include <iostream>
#include <map>
#include <vector>

#include "../include/point.h"
#include "../include/node.h"
#include "../include/grid.h"

Grid::Grid(){
    nodes.assign(0, Node(Point()));
    edges.assign(0, Edge(Node(Point()), Node(Point())));
    cells.assign(0, Cell());
}

void Grid::createGrid(std::vector<SNode> nodes, std::vector<SCell> cells) {

    // std::vector<std::pair<int, int> > numNodeEdges;
    std::vector<SEdge> edges;
    edges.push_back(SEdge(0, 0));
    std::map<std::pair<int, int>, int> numNodeEdges;

    for (int i = 0; i < cells.size(); i++) {
        std::vector<int>& numNodes = cells[i].numNodes;

        for (int j = 0; j < numNodes.size(); j++) {
            int firstNum = numNodes[j];
            int secondNum = numNodes[(j + 1) % numNodes.size()];
            int edgeNum = numNodeEdges.count(std::make_pair(firstNum, secondNum));
            if (edgeNum == 0){
                edgeNum = numNodeEdges.count(std::make_pair(secondNum, firstNum));
                if (edgeNum == 0){
                    edges.push_back(SEdge(firstNum, secondNum));
                    numNodeEdges[std::make_pair(firstNum, secondNum)] = edges.size();
                    edgeNum = edges.size();
                }
            }
        }
    }

    std::cout << "Amount snodes = "<< nodes.size() << std::endl;
    std::cout << "Amount sedges = "<< edges.size() << std::endl;
    std::cout << "Amount scells = "<< cells.size() << std::endl;
}

void Grid::getInformation() {
    std::cout << "Amount nodes = "<< nodes.size() << std::endl;
    std::cout << "Amount edges = "<< edges.size() << std::endl;
    std::cout << "Amount cells = "<< cells.size() << std::endl;
}