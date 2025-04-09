#ifndef GRAPH_H
#define GRAPH_H

#include "DynamicArray.h"

class Graph {
private:
    struct Edge {
        int to;
        double weight;
    };

    struct Node {
        char name[30]; //Instead of string since the assignment explicitly said that we have to implement our own data structures
        DynamicArray<Edge> edges;
    };

    DynamicArray<Node> nodes;

public:
    Graph();

    void addNode(const char* cityName);
    void addEdge(int fromIndex, int toIndex, double weight);
    void display() const;
};

#endif
