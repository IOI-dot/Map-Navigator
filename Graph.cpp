#include <iostream>
#include <cstring>
#include "Graph.h"

//fix
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

    // Add edge from fromIndex to toIndex
    Edge e1;
    e1.to = toIndex;
    e1.weight = weight;
    nodes[fromIndex].edges.push_back(e1);
}

void Graph::display() const {
    for (int i = 0; i < nodes.getSize(); i++) {
        std::cout << nodes[i].name << " -> ";

        for (int j = 0; j < nodes[i].edges.getSize(); j++) {
            int to = nodes[i].edges[j].to;
            double weight = nodes[i].edges[j].weight;

            if (to >= 0 && to < nodes.getSize()) {
                std::cout << "(" << nodes[to].name << ", " << weight << " km) ";
            } else {
                std::cout << "(Invalid node index: " << to << ") ";
            }
        }

        std::cout << std::endl;
    }
}

