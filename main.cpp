#include "Graph.h"
#include <iostream>
int main() {
    Graph g;
    g.addNode("CityA");
    g.addNode("CityB");
    g.addNode("CityC");

    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 5);
    g.addEdge(0, 2, 15);

    g.display();

    return 0;
}
