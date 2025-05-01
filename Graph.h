#ifndef GRAPH_H
#define GRAPH_H

#include "Dynamic_Array.h"

class Graph {
private:
    struct Edge {
        int to;
        double weight;
    };

    struct Node {
        char name[30];
        DynamicArray<Edge> edges;  // Store edges using DynamicArray
    };

    DynamicArray<Node> nodes;  // Store nodes using DynamicArray

    int getIndexByName(const char* cityName) const;

public:
    void addNode(const char* cityName);
    void addEdge(const char* fromCity, const char* toCity, double weight);
    void display() const;

    int getSize() const;
    const char* getCityName(int index) const;
    const DynamicArray<Edge>& getEdges(int index) const;
    int getCityIndex(const char* name) const;
};

#endif
