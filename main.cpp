#include <iostream>
#include "Graph.h"
#include "Dijkstra.h"
#include "File_Reader.h"
int main() {
    Graph g;
    int choice;
FileReader x;
   x.loadFromFile("C:/Users/Omar/CLionProjects/Map-Navigator/city_connections_dataset.txt",g);
    while (true) {
        std::cout << "\n--- Map Navigator ---\n";
        std::cout << "1. Add City\n";
        std::cout << "2. Add Distance Between Cities\n";
        std::cout << "3. Display Graph\n";
        std::cout << "4. Find Shortest Path\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            char city[30];
            std::cout << "Enter city name: ";
            std::cin >> city;
            g.addNode(city);
        } else if (choice == 2) {
            char city1[30], city2[30];
            double dist;
            std::cout << "Enter first city: ";
            std::cin >> city1;
            std::cout << "Enter second city: ";
            std::cin >> city2;
            std::cout << "Enter distance (km): ";
            std::cin >> dist;
            g.addEdge(city1, city2, dist);
        } else if (choice == 3) {
            g.display();
        } else if (choice == 4) {
            char start[30], end[30];
            std::cout << "Enter start city: ";
            std::cin >> start;
            std::cout << "Enter destination city: ";
            std::cin >> end;
            Dijkstra::shortestPath(g, start, end);
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Invalid choice\n";
        }
    }

    return 0;
}
