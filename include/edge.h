#ifndef EDGE_H
#define EDGE_H


class Edge{
    private:
        int firstNumNode = -1;
        int secondNumNode = -1;

        int frstNumCell = -1;
        int scndNumCell = -1;
    public:
        Edge(int firstNumNode, int secondNumNode, int frstNumCell, int scndNumCell):
           firstNumNode(firstNumNode), secondNumNode(secondNumNode), frstNumCell(frstNumCell), scndNumCell(scndNumCell) {}
        ~Edge() {}

        int getFirstNumNode() const { return firstNumNode; }
        int getSecondNumNode() const { return secondNumNode; }
};

#endif