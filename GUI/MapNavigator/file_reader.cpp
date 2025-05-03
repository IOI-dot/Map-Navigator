#include "file_reader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>  // For formatting if needed
#include <QFile>
#include <QTextStream>
#include <QDebug>

// Helper function to trim whitespace (both leading and trailing)
QString FileReader::trim(const QString &str) {
    return str.trimmed();
}

void FileReader::loadFromFile(const QString& filePath, Graph& graph) {
    FileReader reader;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file: " << filePath;
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        // Trim leading and trailing spaces from the line
        QString line = reader.trim(in.readLine());

        // If the line is empty or a comment, skip it
        if (line.isEmpty() || line.startsWith('#')) continue;

        QStringList parts = line.split('\t');
        if (parts.size() >= 3) {
            QString city1 = reader.trim(parts[0]);
            QString city2 = reader.trim(parts[1]);
            QString distStr = reader.trim(parts[2]);

            bool valid;
            double distance = distStr.toDouble(&valid);

            if (valid) {
            graph.addNode(city1);
            graph.addNode(city2);
            graph.addEdge(city1, city2, distance);
            }
            else
                qDebug() << "Data was not loaded correctly: Invalid distance";

        }

        }

    file.close();
    // std::cout << "Graph loaded from file: " << filePath << "\n";
    }


