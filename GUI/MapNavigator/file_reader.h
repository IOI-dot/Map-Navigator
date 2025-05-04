#ifndef FILEREADER_H
#define FILEREADER_H

#include <QString>
#include "Graph.h"

class FileReader {
public:
    static void loadFromFile(const QString& filePath, Graph& graph);
    static void saveToFile(const QString& filePath);
    QString trim(const QString& str);
};

#endif
