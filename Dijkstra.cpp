#include "Dijkstra.h"
#include <iostream>
#include <limits>
#include <vector>

void Dijkstra::shortestPath(const Graph& g, const char* startCity, const char* endCity) {
    int n = g.getSize();
    int start = g.getCityIndex(startCity);
    int end = g.getCityIndex(endCity);

    if (start == -1 || end == -1) {
        std::cout << "Invalid city name.\n";
        return;
    }

    std::vector<double> dist(n, std::numeric_limits<double>::infinity());
    std::vector<int> prev(n, -1);
    std::vector<bool> visited(n, false);

    dist[start] = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == std::numeric_limits<double>::infinity()) {
            break;
        }

        visited[u] = true;

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

    if (dist[end] == std::numeric_limits<double>::infinity()) {
        std::cout << "No path exists.\n";
    } else {
        std::cout << "Shortest path distance: " << dist[end] << " km\n";

        // Retrieve the path
        std::vector<int> path;
        for (int at = end; at != -1; at = prev[at]) {
            path.push_back(at);
        }

        std::cout << "Path: ";
        for (int i = path.size() - 1; i >= 0; --i) {
            std::cout << g.getCityName(path[i]) << (i ? " -> " : "\n");
        }
    }
}
