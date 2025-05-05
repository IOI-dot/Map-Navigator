#include "Dijkstra.h"
#include <iostream>
#include <limits>
#include <vector>
//TIME COMPELXITY (O(N^2+E)) (No min-heaps or fibonacci heaps but could be used for better preformance)
//Finds the shortest path between the starting city and the ending city using Dijkstra's algorithm
void Dijkstra::shortestPath(const Graph& g, std::string startCity, std::string endCity) {
    int n = g.getSize(); // number of cities (nodes)
    int start = g.getCityIndex(startCity);
    int end = g.getCityIndex(endCity);

    if (start == -1 || end == -1) {
        std::cout << "Invalid city name.\n";
        return;
    }
    //INITIALIZE DIJKSTRA VARIABLES

    std::vector<double> dist(n, std::numeric_limits<double>::infinity());
    std::vector<int> prev(n, -1);
    std::vector<bool> visited(n, false);

    dist[start] = 0;
    //The Algroithm

    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == std::numeric_limits<double>::infinity()) {
            break;// No more reachable nodes
        }

        visited[u] = true;
        //Finding the shortest path

        const auto& edges = g.getEdges(u);
        for (int j = 0; j < edges.get_size(); j++) {
            int v = edges[j].to;
            double w = edges[j].weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
            }
        }
    }

    // No path found
    if (dist[end] == std::numeric_limits<double>::infinity()) {
        std::cout << "No path exists between " << startCity << " and " << endCity << std::endl;
    }
    else { // Prints the length of the shortest path

        std::cout << "The shortest distance between " << startCity << " and " << endCity << " is: " << dist[end] << " km\n";

        // Retrieve the path
        std::vector<int> path;
        for (int at = end; at != -1; at = prev[at]) {
            path.push_back(at);
        }
        // Prints the cities along the path in sequential order
        std::cout << "Below is the path you need to take:" << std::endl;
        for (int i = path.size() - 1; i >= 0; --i) {
            std::cout << g.getCityName(path[i]) << (i ? " -> " : "\n");
        }
    }
}
