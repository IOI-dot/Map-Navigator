#include "dijkstra.h"
#include <iostream>
#include <limits>
#include <vector>
#include <QString>

std::pair<std::vector<QString>, float> Dijkstra::shortestPath(const Graph& g, QString startCity, QString endCity) {
    int n = g.getSize(); // number of cities (nodes)
    int start = g.getCityIndex(startCity);
    int end = g.getCityIndex(endCity);

    if (start == -1 || end == -1) {
        // std::cout << "Invalid city name.\n";
        return {{}, -1};
    }
    //INITIALIZE DIJKSTRA VARIABLES
    std::vector<double> dist(n, std::numeric_limits<double>::infinity());
    std::vector<int> prev(n, -1);
    std::vector<bool> visited(n, false);

    dist[start] = 0;
    //The Algrothim
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

    std::vector<QString> cityPath;

    if (dist[end] == std::numeric_limits<double>::infinity()) {
        // std::cout << "No path exists between " << startCity << " and " << endCity << std::endl;
        return {{}, -1};
    }
    else {
        // std::cout << "The shortest distance between " << startCity << " and " << endCity << " is: " << dist[end] << " km\n";

        // Retrieve the path
        std::vector<int> path;
        for (int at = end; at != -1; at = prev[at]) {
            path.push_back(at);
        }

        // std::cout << "Below is the path you need to take:" << std::endl;
        for (int i = path.size() - 1; i >= 0; --i) {
            // std::cout << g.getCityName(path[i]) << (i ? " -> " : "\n");
             cityPath.push_back(g.getCityName(path[i]));
        }


    }

     return {cityPath, dist[end]};
}
