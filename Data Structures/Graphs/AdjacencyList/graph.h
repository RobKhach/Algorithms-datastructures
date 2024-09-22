#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class graph{

    private:

        int v;
        std::vector<std::vector<int>> adjList;

    public:

        graph(int v);

        void addVertex();
        
        void addEdge(int v, int u);
        bool hasEdge(int u, int v) const;
        void removeEdge(int src, int dest);

        void printGraph() const;

        void BFS_i(int start) const;
        void DFS_i(int start) const;

        void DFS_r(int start) const;
        void BFS_r(int start) const;

        std::vector<int> getNthLevel(int start, int level) const;
        std::vector<int> getShortestPath(int src, int dest) const;
        int getAllPossiblePaths(int src, int dest) const;


        ~graph();

    private:

        int getAllPossiblePaths_h(int dest, int node, std::vector<bool>& visited) const;
        void DFSUtil(int v, std::vector<bool>& visited) const;
        void BFSUtil(std::queue<int>& qu, std::vector<bool>& visited) const;
};

#include "graph.hpp"

#endif