#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>


class Graph{
    private:

        int vertexes;
        std::vector<std::vector<int>> adjMatrix;

    public:

    Graph(int numVertexes);

    ~Graph();

    void addEdge(int src, int dest);
    bool hasEdge(int u, int v) const;
    void removeEdge(int src, int dest);
    void printGraph() const;

    void BFS_i(int start) const;
    void DFS_i(int start) const;

    void DFS_r(int start) const;
    void BFS_r(int start) const;

    std::vector<int> getNthLevel(int start, int level) const;
    std::vector<int> getShortPath(int src, int dest) const;
    int getAllPossiblePaths(int src, int dest) const;

    private:

    int getAllPossiblePaths_h(int dest, int node, std::vector<bool>& visited) const;


    void DFSUtil(int node, std::vector<bool>& visited) const;
    void BFSUtil(std::queue<int>& qu, std::vector<bool>& visited) const;
};

#include "graph.hpp"


#endif