#include <iostream>
#include "Graph.h"

Graph::Graph() {
    // No dynamic allocation required here, DynamicArray handles this issue
}

void Graph::addNode(const char* cityName) {
    Node newNode;
    int i = 0;
    for (; i < sizeof(newNode.name) - 1 && cityName[i] != '\0'; i++) {
        newNode.name[i] = cityName[i];
    }
    newNode.name[i] = '\0';

    nodes.push_back(newNode);
}

void Graph::addEdge(int fromIndex, int toIndex, double weight) {
    if (fromIndex < 0 || fromIndex >= nodes.getSize() ||
        toIndex < 0 || toIndex >= nodes.getSize()) {
        std::cout << "Invalid node index\n";
        return;
        }

    Edge e;
    e.to = toIndex;
    e.weight = weight;
    nodes[fromIndex].edges.push_back(e);
}

void Graph::display() const {
    for (int i = 0; i < nodes.getSize(); i++) {
        std::cout << nodes[i].name << " -> ";
        for (int j = 0; j < nodes[i].edges.getSize(); j++) {
            int to = nodes[i].edges[j].to;
            double weight = nodes[i].edges[j].weight;
            std::cout << "(" << nodes[to].name << ", " << weight << " km) ";
        }
        std::cout << std::endl;
    }
}
