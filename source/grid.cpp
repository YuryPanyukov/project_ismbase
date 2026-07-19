#include <iostream>
#include <map>
#include <vector>

#include "../include/point.h"
#include "../include/node.h"
#include "../include/grid.h"

Grid::Grid(){
    nodes.assign(0, Node(Point()));
    edges.assign(0, Edge(Node(Point()), Node(Point()), -1, -1));
    cells.assign(0, Cell());
}

void Grid::createGrid(std::vector<SNode> inputNodes, std::vector<SCell> inputCells) {

    for (int i = 0; i < inputNodes.size(); i++) {
        nodes.push_back(Node(inputNodes[i].coord));
    }

    std::vector<SEdge> inputEdges(1, SEdge(0, 0, -1, -1));
    
    // Две вершины образуют ребро
    std::map<std::pair<int, int>, int> numNodeEdges;
    std::vector<std::vector<int>> numNodeCells(inputNodes.size());

    for (int numCell = 0; numCell < inputCells.size(); numCell++) {
        std::vector<int>& numNodes = inputCells[numCell].numNodes;

        std::vector<int> edgeNums;
        for (int idxNode = 0; idxNode < numNodes.size(); idxNode++) {
            int firstNodeNum = numNodes[idxNode];
            int secondNodeNum = numNodes[(idxNode + 1) % numNodes.size()];
            numNodeCells[firstNodeNum].push_back(numCell);
            int edgeNum = numNodeEdges.count(std::make_pair(firstNodeNum, secondNodeNum));
            bool flagFindEdge = true;
            if (edgeNum == 0){
                edgeNum = -1*numNodeEdges.count(std::make_pair(secondNodeNum, firstNodeNum));
                if (edgeNum == 0){
                    flagFindEdge = false;
                    inputEdges.push_back(SEdge(firstNodeNum, secondNodeNum, numCell, -1));
                    numNodeEdges[std::make_pair(firstNodeNum, secondNodeNum)] = inputEdges.size();
                    edgeNum = edges.size();
                }
            }
            if (!flagFindEdge){
                inputEdges[edgeNum].secondCellNum = numCell;
            }
            edgeNums.push_back(edgeNum);
        }
        cells.push_back(Cell(edgeNums));
    }

    for (int i = 0; i<inputEdges.size(); i++){
        int firstNodeNum = inputEdges[i].firstNodeNum;
        int secondNodeNum = inputEdges[i].secondNodeNum;
        int firstCellNum = inputEdges[i].firstCellNum;
        int secondCellNum = inputEdges[i].secondCellNum;
        edges.push_back(Edge(nodes[firstNodeNum], nodes[secondNodeNum], firstCellNum, secondCellNum));
    }

    for (int numNode = 0; numNode < numNodeCells.size(); numNode++){
        std::vector<int> adjCells;
        std::vector<int>& numCells = numNodeCells[numNode];
        
    }

    std::cout << "Amount inputNodes = "<< inputNodes.size() << std::endl;    
    std::cout << "Amount inputCells = "<< inputCells.size() << std::endl;
}

void Grid::getInformation() {
    std::cout << "Amount nodes = "<< nodes.size() << std::endl;
    std::cout << "Amount edges = "<< edges.size() << std::endl;
    std::cout << "Amount cells = "<< cells.size() << std::endl;
}