#include "Graph.h"
#include <cstring>
#include <iostream>

void Graph::addNode(std::string cityName) {
    // Check if the node already exists
    if (getIndexByName(cityName) != -1) return;

    Node newNode(cityName);
    nodes.push_back(newNode);  // Use DynamicArray's push_back
}

// Returns the index of the given city.
int Graph::getIndexByName(std::string cityName) const {
    for (int i = 0; i < nodes.get_size(); ++i) {
        if (nodes[i].name == cityName) {
            return i;
        }
    }
    return -1;
}

void Graph::addEdge(std::string fromCity, std::string toCity, double weight) {
    int from = getIndexByNameIgnoreCase(fromCity);
    int to = getIndexByNameIgnoreCase(toCity);

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
    std:: cout << "Direct path of " << weight << " kilometers between " << fromCity << " and " << toCity << " added successfully!" << std::endl << std::endl;
}

// Prints out all the edges and their weights.
void Graph::display() const {
    for (int i = 0; i < nodes.get_size(); i++) {
        std::cout << std::endl << nodes[i].name << std::endl;
        for (int j = 0; j < nodes[i].edges.get_size(); j++) {
            int to = nodes[i].edges[j].to;
            std::cout << "  -> " << nodes[to].name << " (distance: " << nodes[i].edges[j].weight << " km)" << std::endl;
        }
    }

    std::cout << std::endl;
}


int Graph::getSize() const {
    return nodes.get_size();  // Use DynamicArray's getSize
}

std::string Graph::getCityName(int index) const {
    return nodes[index].name;
}

const DynamicArray<Edge>& Graph::getEdges(int index) const {
    return nodes[index].edges;
}

int Graph::getCityIndex(std::string name) const {
    return getIndexByName(name);
}
//Updated
int Graph::getIndexByNameIgnoreCase(std::string cityName) const {
	for (int i = 0; i < nodes.get_size(); ++i) {
		if (nodes[i].name.size() != cityName.size()) continue;
		bool match = true;
		for (size_t j = 0; j < cityName.size(); ++j) {
			if (tolower(nodes[i].name[j]) != tolower(cityName[j])) {
				match = false;
				break;
			}
		}
		if (match) return i;
	}
	return -1;
}


void Graph::deleteEdge(std::string city1, std::string city2) {
	int u = getIndexByName(city1);
	int v = getIndexByName(city2);

	if (u == -1 || v == -1) {
		std::cout << "One or both cities not found.\n";
		return;
	}

	// Remove edge from u to v
	DynamicArray<Edge> newEdgesCity1;
	for (int i = 0; i < nodes[u].edges.get_size(); ++i) {
		if (nodes[u].edges[i].to != v) {
			newEdgesCity1.push_back(nodes[u].edges[i]);
		}
	}
	nodes[u].edges = newEdgesCity1;

	// Remove edge from v to u
	DynamicArray<Edge> newEdgesCity2;
	for (int i = 0; i < nodes[v].edges.get_size(); ++i) {
		if (nodes[v].edges[i].to != u) {
			newEdgesCity2.push_back(nodes[v].edges[i]);
		}
	}
	nodes[v].edges = newEdgesCity2;

	std::cout << "Edge between " << city1 << " and " << city2 << " has been removed." << std::endl;
}

void Graph::deleteCity(std::string cityName) {
	int index = getIndexByNameIgnoreCase(cityName);
	if (index == -1) {
		std::cout << "City not found: " << cityName << std::endl;
		return;
	}

	// Remove all edges connected to this city
	for (int i = 0; i < nodes.get_size(); ++i) {
		if (i == index) continue;
		deleteEdge(cityName, nodes[i].name);
	}

	// Shift elements to fill the gap
	for (int i = index; i < nodes.get_size() - 1; ++i) {
		nodes[i] = nodes[i + 1];
	}

	nodes.pop_back(); // Remove last element

	std::cout << "City '" << cityName << "' and all related edges have been deleted." << std::endl;
}