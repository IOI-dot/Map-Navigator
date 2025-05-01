#ifndef GRAPH_H
#define GRAPH_H

#include "Dynamic_Array.h"
#include <string>

class Graph {
private:
    struct Edge {
        int to;
        double weight;
    };

    struct Node {
        std::string name;
        DynamicArray<Edge> edges;  // Store edges using DynamicArray
    };

    DynamicArray<Node> nodes;  // Store nodes using DynamicArray

    int getIndexByName(std::string cityName) const;

public:
    void addNode(std::string cityName);
    void addEdge(std::string fromCity, std::string toCity, double weight);
    void display() const;

    int getSize() const;
    std::string getCityName(int index) const;
    const DynamicArray<Edge>& getEdges(int index) const;
    int getCityIndex(std::string name) const;
};

#endif
