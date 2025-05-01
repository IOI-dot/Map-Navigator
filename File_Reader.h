#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include "Graph.h"

class FileReader {
public:
    static void loadFromFile(const std::string& filePath, Graph& graph);
    std::string trim(const std::string& str);
};

#endif
