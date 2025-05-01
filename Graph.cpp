#include "Graph.h"
#include <cstring>
#include <iostream>

void Graph::addNode(const char* cityName) {
    // Check if the node already exists
    if (getIndexByName(cityName) != -1) return;

    Node newNode;
    // Ensure the name is correctly copied into the array with a null-terminator
    strncpy(newNode.name, cityName, sizeof(newNode.name) - 1);
    newNode.name[sizeof(newNode.name) - 1] = '\0';
    nodes.push_back(newNode);  // Use DynamicArray's push_back
}

int Graph::getIndexByName(const char* cityName) const {
    for (int i = 0; i < nodes.get_size(); ++i) {
        if (strcmp(nodes[i].name, cityName) == 0) {
            return i;
        }
    }
    return -1;
}

void Graph::addEdge(const char* fromCity, const char* toCity, double weight) {
    int from = getIndexByName(fromCity);
    int to = getIndexByName(toCity);

    if (from == -1 || to == -1) {
        std::cout << "One or both cities not found.\n";
        return;
    }

    if (from == to) {
        std::cout << "Cannot add an edge to the same city.\n";
        return;
    }

    // Check if the edge already exists
    for (int i = 0; i < nodes[from].edges.get_size(); ++i) {
        if (nodes[from].edges[i].to == to) {
            std::cout << "Edge already exists.\n";
            return;
        }
    }

    // Add the edges in both directions (undirected graph)
    Edge e1 = {to, weight};
    Edge e2 = {from, weight};

    nodes[from].edges.push_back(e1);  // Add edge to the source city
    nodes[to].edges.push_back(e2);    // Add edge to the destination city
}

void Graph::display() const {
    for (int i = 0; i < nodes.get_size(); i++) {
        std::cout << nodes[i].name << " -> ";
        for (int j = 0; j < nodes[i].edges.get_size(); j++) {
            int to = nodes[i].edges[j].to;
            std::cout << "(" << nodes[to].name << ", " << nodes[i].edges[j].weight << " km) ";
        }
        std::cout << "\n";
    }
}

int Graph::getSize() const {
    return nodes.get_size();  // Use DynamicArray's getSize
}

const char* Graph::getCityName(int index) const {
    return nodes[index].name;
}

const DynamicArray<Graph::Edge>& Graph::getEdges(int index) const {
    return nodes[index].edges;
}

int Graph::getCityIndex(const char* name) const {
    return getIndexByName(name);
}
