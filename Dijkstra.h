#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"

class Dijkstra {
public:
    static void shortestPath(const Graph& g, std::string startCity, std::string endCity);
};

#endif
