#ifndef FILEREADER_H
#define FILEREADER_H

#include <QString>
#include "Graph.h"

class FileReader {
public:
    static void loadFromFile(const QString& filePath, Graph& graph);
    QString trim(const QString& str);
};

#endif
