#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"

class Dijkstra {
public:
    static std::pair<std::vector<QString>, float> shortestPath(const Graph& g, QString startCity, QString endCity);
};

#endif
