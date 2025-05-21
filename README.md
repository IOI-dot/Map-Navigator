# Applied Data Structures Spring 2025
# Project : Map Navigator

## Students:
* Mahinour Abdelgawad
* Omar Abdel Motalb
* Rami Atef Zayed
* Saif Al-Deen Taher Ahmad
* Seifeldin Mostafa

## Overview
This project presents a robust and feature-rich map navigation application developed in
C++ using Qt framework, integrating Dijkstra’s algorithm for the optimization of path finding
and Levenshtein distance for intelligent input correction as a bonus feature showing the passion
of the individuals behind said project. The application is also equipped with a File handling
system and the underlying graph class is designed to handle the dynamic interactions between
the nodes as well as the edges.

## Features

- **Shortest Path Finder** using Dijkstra’s algorithm  
- **Smart Input Correction** with Levenshtein distance  
- **Dynamic Graph Construction** from external files  
- **Interactive GUI** built with Qt  

## Algorithms Used

### 1. Dijkstra’s Algorithm
- Computes shortest paths between nodes (cities)
- Linear search implementation with **O(n²)** time complexity
- Ideal for **small to medium-sized graphs**

### 2. Levenshtein Distance
- Handles misspellings by computing minimum edit distance
- Uses a dynamic programming matrix to find the nearest valid city name
- Time complexity: **O(m × n)** where *m* and *n* are string lengths

### 3. File Handler
- Reads `.txt` files with city names and distances
- Ignores blank lines and comments
- Adds nodes and edges dynamically to the graph


## Data Format

- The application reads a text file containing city names and weighted edges representing distances.
- Each line in the file represents a connection between two cities with an associated distance.
- The file handler ignores comments and blank lines.
- Whitespace around city names and distances is trimmed automatically.
- The data forms a weighted, undirected graph modeling the cities in the dataset.

## Usage
1. Prepare the input file with city connections.
2. Run the application.
3. Enter start and destination cities (typos will be corrected automatically).
4. The app displays the shortest route on the GUI.


---