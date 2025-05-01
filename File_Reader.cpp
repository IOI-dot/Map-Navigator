#include "File_Reader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>  // For formatting if needed
// Helper function to trim whitespace (both leading and trailing)
std::string FileReader::trim(const std::string &str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");

    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}
void FileReader::loadFromFile(const std::string& filePath, Graph& graph) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filePath << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Trim leading and trailing spaces from the line
        FileReader a;
        line = a.trim(line);

        // If the line is empty or a comment, skip it
        if (line.empty() || line[0] == '#') continue;

        std::istringstream iss(line);
        std::string city1, city2;
        double distance;

        // Try reading city1, city2, and distance
        if (std::getline(iss, city1, '\t') || std::getline(iss, city1, ' ')) {
            // Remove leading/trailing spaces around city1
            city1 = a.trim(city1);
            // Try reading city2 (for case with space/tab separation)
            if (std::getline(iss, city2, '\t') || std::getline(iss, city2, ' ')) {
                city2 = a.trim(city2);
                // Attempt to read the distance
                if (iss >> distance) {
                    // Add cities and the edge (distance between them)
                    graph.addNode(city1.c_str());
                    graph.addNode(city2.c_str());
                    graph.addEdge(city1.c_str(), city2.c_str(), distance);

                    std::cout << "Read: [" << city1 << "] [" << city2 << "] [" << distance << "]\n";
                } else {
                    std::cerr << "Error: Distance not found for cities [" << city1 << "], [" << city2 << "]\n";
                }
            }
        }
    }

    std::cout << "Graph loaded from file: " << filePath << "\n";
}


