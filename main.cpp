#include <iostream>
#include "Graph.h"
#include "Dijkstra.h"
#include "File_Reader.h"

bool stringTest(std::string cityName); //Forward declaration for function that validates city name

int main() {
    Graph g;

    FileReader x;
    x.loadFromFile("../city_connections_dataset.txt",g);

    int choice;
    std::string city1, city2;
    double dist;

    while (true) {
        std::cout << "\n--------------MAP NAVIGATOR--------------\n";
        std::cout << "1. Add a city\n";
        std::cout << "2. Add a direct path between two cities\n";
        std::cout << "3. Display available cities\n";
        std::cout << "4. Navigate between two cities\n";
        std::cout << "5. Exit Program\n\n";
        std::cout << "Please select an operation:  ";

        std::cin >> choice;

        while (std::cin.fail() || choice < 1 || choice > 5 ) { //to make sure user enters a number from 1 to 5. std::cin.fail() is in case input is not a number
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Invalid input. Please enter a number from 1 to 5" << std::endl;
            std::cin >> choice;
        }

        // Add a city
        if (choice == 1) {
            std::cout << "Enter city name: " << std::endl;
            std::cin.ignore(); //to empty buffer so that getline is executed
            getline(std::cin, city1);

            while (!stringTest(city1) || city1.empty()) { //name can only be alphabetical and cant be empty
                std::cout << "Invalid input! Please try again. City name must not be empty and can contain only letters: " << std::endl;
                getline(std::cin, city1);
            }

            g.addNode(city1);

        }

        // Add a direct path between two cities
        else if (choice == 2) {
            if (g.getSize() == 0)
                std::cout << "Graph is empty. Cannot add edge. Please add at least two cities before using this feature" << std::endl << std::endl;

            else if (g.getSize() == 1)
                std::cout << "There is only one city. Cannot add edge. Please add another city before using this feature" << std::endl << std::endl;

            else {
                std::cout << "Enter first city: " << std::endl;
                std::cin.ignore();
                getline(std::cin, city1);

                std::cout << "Enter second city: ";
                std::cin.ignore();
                getline(std::cin, city2);

                std::cout << "Please enter the distance in kilometers between " << city1 << " and " << city2 << std::endl;
                while (std::cin.fail() || dist <= 0) {//to make sure distance is not zero or negative, nor non-numeric
                    if (std::cin.fail()) {
                        std::cout << "Invalid input! Please try again" << std::endl;
                        std::cin.clear(); //if input is not a number
                        std::cin.ignore(INT_MAX, '\n');
                    }
                    else
                        std::cout << "Distance cannot be 0 or less! Please try again" << std::endl;

                    std::cin >> dist;
                }

                g.addEdge(city1, city2, dist);
            }
        }

        // Display available cities
        else if (choice == 3) {
            if (g.getSize() == 0)
                std::cout << "No cities available." << std::endl << std::endl;
            else{
                std::cout << "Available cities and their neighbors:" << std::endl;
                g.display();
            }

        }

        // Navigate between two cities (find shortest path)
        else if (choice == 4) {
            if (g.getSize() < 2)
                std::cout << "There aren't enough cities to perform this action." << std::endl;
            else {
                std::cout << "Enter the starting city: " << std::endl;
                std::cin.ignore();
                getline(std::cin, city1);

                std::cout << "Enter the destination city: ";
                std::cin.ignore();
                getline(std::cin, city2);

                Dijkstra::shortestPath(g, city1, city2);
            }
        }
        // Exit Program
        else if (choice == 5)
            break;

    }

    return 0;
}


bool stringTest(std::string name) //function to validate string input
{
    // Returns true if name is all alphabetical
    // False if has any symbols or is only spaces

    bool hasLetter = false;

    for (const auto& curr: name) {
        if (isalpha(curr))
            hasLetter = true; //this part makes sure name is not empty/all spaces
        else if (curr != ' ')  //this part allows spaces in name e.g. New York
            return false; //if !isalpha or is not space, then it is a symbol/invalid character.
    }

    return hasLetter;
    // if false -> no letters were detected in name (which is invalid)
}
