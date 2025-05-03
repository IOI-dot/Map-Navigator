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
    void deleteEdge(std::string city1, std::string city2);
    void deleteCity(std::string cityName);
    int getSize() const;
    std::string getCityName(int index) const;
    //Updated
    //int Graph::getIndexByNameIgnoreCase(std::string cityName) const;
    int getIndexByNameIgnoreCase(std::string cityName) const;
    const DynamicArray<Edge>& getEdges(int index) const;
    int getCityIndex(std::string name) const;
};

#endif
