#include <iostream>
#include "Graph.h"
#include "Dijkstra.h"
#include "File_Handler.h"
#include "Spell_Checker.h"
#include <unordered_set>
#include <limits>

bool stringTest(std::string cityName); // Forward declaration

// Ask user to confirm or retype a city name if not found
std::string confirmCityName(const std::string& input, Graph& g, SpellChecker& checker) {
    std::string suggestion = checker.findClosestMatch(input);
    std::string answer;

    std::cout << "City \"" << input << "\" not found. Did you mean \"" << suggestion << "\"? (Y/N): ";
    std::getline(std::cin, answer);

    if (!answer.empty() && (answer[0] == 'Y' || answer[0] == 'y')) {
        return suggestion;
    } else {
        std::cout << "Please re-enter the city name: ";
        std::string corrected;
        std::getline(std::cin, corrected);
        return corrected;
    }
}

int main() {
    Graph g;
    FileReader x;
    x.loadFromFile("../city_connections_dataset.txt", g);

    std::unordered_set<std::string> cityNames;
    for (int i = 0; i < g.getSize(); ++i) {
        cityNames.insert(g.getCityName(i));
    }

    SpellChecker checker(cityNames);

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

        while (std::cin.fail() || choice < 1 || choice > 7) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number from 1 to 7: ";
            std::cin >> choice;
        }

        std::cin.ignore(); // Clear input buffer

        // Add a city
        if (choice == 1) {
            std::cout << "Enter city name: ";
            getline(std::cin, city1);

            while (!stringTest(city1) || city1.empty()) {
                std::cout << "Invalid input! City name must not be empty and can only contain letters/spaces: ";
                getline(std::cin, city1);
            }

            g.addNode(city1);
        }

        // Add a direct path between two cities
        else if (choice == 2) {
            if (g.getSize() < 2) {
                std::cout << "Graph is empty or has only one city. Cannot add edge.\n";
            } else {
                std::cout << "Enter first city: ";
                getline(std::cin, city1);
                std::cout << "Enter second city: ";
                getline(std::cin, city2);

                double dist = 0.0;
                bool validDistance = false;

                std::cout << "Please enter the distance in kilometers between " << city1 << " and " << city2 << ": ";

                while (!validDistance) {
                    std::cin >> dist;
                    if (std::cin.fail() || dist <= 0) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << "Invalid input! Enter a positive numeric distance: ";
                    } else {
                        validDistance = true;
                    }
                }
                std::cin.ignore();

                int fromIndex = g.getIndexByNameIgnoreCase(city1);
                int toIndex = g.getIndexByNameIgnoreCase(city2);

                if (fromIndex == -1) {
                    city1 = confirmCityName(city1, g, checker);
                    fromIndex = g.getIndexByNameIgnoreCase(city1);
                }
                if (toIndex == -1) {
                    city2 = confirmCityName(city2, g, checker);
                    toIndex = g.getIndexByNameIgnoreCase(city2);
                }

                if (fromIndex != -1 && toIndex != -1) {
                    g.addEdge(city1, city2, dist);
                }
            }
        }

        // Display cities
        else if (choice == 3) {
            if (g.getSize() == 0)
                std::cout << "No cities available.\n";
            else {
                std::cout << "Available cities and their neighbors:\n";
                g.display();
            }
        }

        // Navigate between two cities
        else if (choice == 4) {
            std::cout << "Enter the starting city: ";
            getline(std::cin, city1);
            std::cout << "Enter the destination city: ";
            getline(std::cin, city2);

            int start = g.getIndexByNameIgnoreCase(city1);
            int end = g.getIndexByNameIgnoreCase(city2);

            if (start == -1) {
                city1 = confirmCityName(city1, g, checker);
                start = g.getIndexByNameIgnoreCase(city1);
            }
            if (end == -1) {
                city2 = confirmCityName(city2, g, checker);
                end = g.getIndexByNameIgnoreCase(city2);
            }

            if (start == end) {
                std::cout << "Start and destination city are the same.\n";
            } else if (start != -1 && end != -1) {
                Dijkstra::shortestPath(g, city1, city2);
            }
        }

        // Delete a city
        else if (choice == 5) {
            std::cout << "Enter city name to delete: ";
            getline(std::cin, city1);

            int cityIndex = g.getIndexByNameIgnoreCase(city1);
            if (cityIndex == -1) {
                city1 = confirmCityName(city1, g, checker);
                cityIndex = g.getIndexByNameIgnoreCase(city1);
            }

            if (cityIndex != -1) {
                g.deleteCity(city1);
            }
        }

        // Delete an edge
        else if (choice == 6) {
            if (g.getSize() < 2) {
                std::cout << "Not enough cities to perform this action.\n";
            } else {
                std::cout << "Enter first city: ";
                getline(std::cin, city1);
                std::cout << "Enter second city: ";
                getline(std::cin, city2);

                int start = g.getIndexByNameIgnoreCase(city1);
                int end = g.getIndexByNameIgnoreCase(city2);

                if (start == -1) {
                    city1 = confirmCityName(city1, g, checker);
                    start = g.getIndexByNameIgnoreCase(city1);
                }
                if (end == -1) {
                    city2 = confirmCityName(city2, g, checker);
                    end = g.getIndexByNameIgnoreCase(city2);
                }

                if (start == end) {
                    std::cout << "Start and destination city are the same.\n";
                } else if (start != -1 && end != -1) {
                    g.deleteEdge(city1, city2);
                }
            }
        }

        // Exit program
        else if (choice == 7) {
            std::cout << "Exiting Program...\n";
            x.saveToFile("../city_connections_dataset.txt", g);
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
