#include <iostream>
#include "Graph.h"
#include "Dijkstra.h"
#include "File_Handler.h"

bool stringTest(std::string cityName); //Forward declaration for function that validates city name

int main() {
    Graph g;

    FileReader x;
    x.loadFromFile("../city_connections_dataset.txt",g);

    int choice;
    std::string city1, city2;

    while (true) {
        std::cout << "\n--------------MAP NAVIGATOR--------------\n";
        std::cout << "1. Add a city\n";
        std::cout << "2. Add a direct path between two cities\n";
        std::cout << "3. Display available cities\n";
        std::cout << "4. Navigate between two cities\n";
		std::cout << "5. Delete a city\n";
		std::cout << "6. Delete a direct path between two cities\n";
        std::cout << "7. Exit Program\n\n";
        std::cout << "Please select an operation:  ";

        std::cin >> choice;

        while (std::cin.fail() || choice < 1 || choice > 7 ) { //to make sure user enters a number from 1 to 5. std::cin.fail() is in case input is not a number
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
			if (g.getSize() < 2) {
				std::cout << "Graph is empty or has only one city. Cannot add edge.\n";
			}
			else {
				std::cout << "Enter first city: ";
				std::cin.ignore();
				getline(std::cin, city1);
				std::cout << "Enter second city: ";
				//std::cin.ignore(); updated
				getline(std::cin, city2);

				double dist = 0.0;
				bool validDistance = false;

				std::cout << "Please enter the distance in kilometers between " << city1 << " and " << city2 << std::endl;

				while (!validDistance) {
					std::cin >> dist;
					if (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore(10000, '\n');
						std::cout << "Invalid input! Please enter a numeric distance greater than zero: ";
					}
					else if (dist <= 0) {
						std::cout << "Distance must be greater than zero. Please try again: ";
					}
					else {
						validDistance = true;
					}
				}

				int fromIndex = g.getIndexByNameIgnoreCase(city1);
				int toIndex = g.getIndexByNameIgnoreCase(city2);

				if (fromIndex == -1 || toIndex == -1) {
					std::cout << "One or both cities not found. Please check spelling.\n";
				}
				else {
					g.addEdge(city1, city2, dist);
				}
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

        // Navigate between two cities (find shortest path) updated
		else if (choice == 4) {
			std::cout << "Enter the starting city: ";
			std::cin.ignore();
			getline(std::cin, city1);
			std::cout << "Enter the destination city: ";
			getline(std::cin, city2);

			int start = g.getIndexByNameIgnoreCase(city1);
			int end = g.getIndexByNameIgnoreCase(city2);
			if (start == -1 || end == -1) {
				std::cout << "One or both cities do not exist.\n";
			}
			else if (start == end) {
				std::cout << "Start and destination city are the same.\n";
			}
			else {
				Dijkstra::shortestPath(g, city1, city2);
			}
		}
		else if (choice == 5) {
			std::cout << "Enter city name to delete: ";
			std::cin.ignore();
			getline(std::cin, city1);
			int cityIndex = g.getIndexByNameIgnoreCase(city1);
			if (cityIndex == -1) {
				std::cout << "City does not exist\n";
			}
			else
				g.deleteCity(city1);
		}
		else if (choice == 6) {
			if (g.getSize() < 2)
				std::cout << "There aren't enough cities to perform this action." << std::endl;
			else {
				std::cout << "Enter first city: ";
				std::cin.ignore();
				getline(std::cin, city1);
				std::cout << "Enter second city: ";
				getline(std::cin, city2);
				int start = g.getIndexByNameIgnoreCase(city1);
				int end = g.getIndexByNameIgnoreCase(city2);
				if (start == -1 || end == -1) {
					std::cout << "One or both cities do not exist.\n";
				}
				else if (start == end) {
					std::cout << "Start and destination city are the same.\n";
				}
				else {
					g.deleteEdge(city1, city2);
				}

			}
		}
        else if (choice == 7) {
	        std::cout << "Exiting Program...";
        	x.saveToFile("../city_connections_dataset.txt",g);
        	break;
        }

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
