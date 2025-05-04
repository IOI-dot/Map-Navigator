#ifndef GRAPH_H
#define GRAPH_H

#include "Dynamic_Array.h"
#include <QString>

class Edge {
public:
    int to;
    double weight;
};

class Node {
public:
    QString name;
    DynamicArray<Edge> edges;  // Store edges using DynamicArray
};

class Graph {
private:


    DynamicArray<Node> nodes;  // Store nodes using DynamicArray


public:
    void addNode(QString cityName);
    void addEdge(QString fromCity, QString toCity, double weight);
    void display() const;
    void deleteEdge(QString city1, QString city2);
    void deleteCity(QString cityName);
    int getSize() const;
    QString getCityName(int index) const;
    int getIndexByName(QString cityName) const;
    int getIndexByNameIgnoreCase(QString cityName) const;
    const DynamicArray<Edge>& getEdges(int index) const;
    int getCityIndex(QString name) const;
    bool edgeExists(QString city1, QString city2) const;
};

#endif
