#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include "Dynamic_Array.h"

class Graph {
private:
    struct Edge {
        int to;
        double weight;

    };

    struct Node {
        char name[30];
        DynamicArray<Edge> edges;
    };

    DynamicArray<Node> nodes;

public:
    void addNode(const char* cityName);
    void addEdge(int fromIndex, int toIndex, double weight);
    void display() const;

};

#endif
