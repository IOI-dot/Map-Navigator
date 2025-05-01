#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Graph.h"
#include "Dijkstra.h"

class GraphVisualizer {
private:
    Graph& graph;
    Dijkstra dijkstra;

public:
    GraphVisualizer(Graph& g) : graph(g) {}

    void run() {
        sf::RenderWindow window(sf::VideoMode({800, 600}), "Graph Visualization");

        // Define the colors
        sf::Color cityColor(0, 128, 255);
        sf::Color edgeColor(255, 0, 0);
        sf::Color backgroundColor(255, 255, 255);

        // Setup the font for city names
        sf::Font font;
        if (!font.openFromFile("arial.ttf")) {
            std::cerr << "Failed to load font" << std::endl;
            return;
        }

        while (window.isOpen()) {
            auto event = window.pollEvent();
            while (event.has_value()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }
                event = window.pollEvent();
            }

            // Clear the window with the background color
            window.clear(backgroundColor);

            // Display the graph structure (cities and edges)
            displayGraph(window, cityColor, edgeColor, font);

            // Display the window contents
            window.display();
        }
    }

private:
    void displayGraph(sf::RenderWindow& window, const sf::Color& cityColor, const sf::Color& edgeColor, sf::Font& font) {
        float radius = 20.f;  // Radius of the city circle
        float spacing = 100.f; // Spacing between cities

        // Draw edges
        for (int i = 0; i < graph.getSize(); ++i) {
            const auto& edges = graph.getEdges(i);
            for (int j = 0; j < edges.get_size(); ++j) {
                int to = edges[j].to;
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(i * spacing + radius, i * spacing + radius), edgeColor),
                    sf::Vertex(sf::Vector2f(to * spacing + radius, to * spacing + radius), edgeColor)
                };
                window.draw(line, 2, sf::PrimitiveType::Lines);
            }
        }

        // Draw nodes (cities)
        for (int i = 0; i < graph.getSize(); ++i) {
            sf::CircleShape city(radius);
            city.setFillColor(cityColor);
            city.setPosition({i * spacing, i * spacing});  // Position each city
            window.draw(city);

            // Add the name of the city
            sf::Text cityName("", font, 18);  // Initialize with empty string, font, and size
            cityName.setString(graph.getCityName(i));
            cityName.setFillColor(sf::Color::Black);
            cityName.setPosition({i * spacing + 25.f, i * spacing + 5.f});
            window.draw(cityName);
        }
    }
};

int main() {
    // Example usage
    Graph graph;

    // Adding nodes (cities)
    graph.addNode("CityA");
    graph.addNode("CityB");
    graph.addNode("CityC");

    // Adding edges (roads between cities)
    graph.addEdge("CityA", "CityB", 5);
    graph.addEdge("CityB", "CityC", 3);
    graph.addEdge("CityA", "CityC", 10);

    // Running the GUI
    GraphVisualizer visualizer(graph);
    visualizer.run();

    return 0;
}