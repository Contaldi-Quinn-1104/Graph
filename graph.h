//Name: Quinn Joseph Contaldi
//Date: 4/26/2023
//the Graph data structure h file and prototypes
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include "graph_interface.h"

#ifndef GRAPH
#define GRAPH
using namespace std;

template<class LabelType>
class Graph: public GraphInterface <LabelType> 
{
    private:
        int Matrix [MAX][MAX] = {-1};
    public:
        Graph();
        int getNumVertices() const;
        int getNumEdges() const;
        bool add(LabelType start, LabelType end, int edgeWeight);
        bool remove(LabelType start, LabelType end);
        int getEdgeWeight(LabelType start, LabelType end) const;
        void depthFirstTraversal(LabelType start, void visit(LabelType&));
        void breadthFirstTraversal(LabelType start, void visit(LabelType&));
};
#include "graph.cpp"
#endif
