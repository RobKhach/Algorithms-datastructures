#include "graph.h"
#include <iostream>

int main() {
    // Create a graph with 5 vertices
    graph g(5);

    // Add edges between vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Print the adjacency list representation of the graph
    std::cout << "Graph structure (DFS traversal): ";
    g.printGraph();
    
    // Test BFS iterative traversal
    std::cout << "BFS Iterative from vertex 0: ";
    g.BFS_i(0);
    
    // Test DFS iterative traversal
    std::cout << "DFS Iterative from vertex 0: ";
    g.DFS_i(0);

    // Test BFS recursive traversal
    std::cout << "BFS Recursive from vertex 0: ";
    g.BFS_r(0);

    // Test DFS recursive traversal
    std::cout << "DFS Recursive from vertex 0: ";
    g.DFS_r(0);

    // Test getNthLevel function
    int level = 2;
    std::vector<int> nthLevel = g.getNthLevel(0, level);
    std::cout << "Nodes at level " << level << " from vertex 0: ";
    for (int node : nthLevel) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    // Test getShortestPath function
    int src = 0, dest = 4;
    std::vector<int> shortestPath = g.getShortestPath(src, dest);
    std::cout << "Shortest path from " << src << " to " << dest << ": ";
    for (int node : shortestPath) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    // Test getAllPossiblePaths function
    int possiblePaths = g.getAllPossiblePaths(src, dest);
    std::cout << "All possible paths from " << src << " to " << dest << ": " << possiblePaths << std::endl;

    return 0;
}
