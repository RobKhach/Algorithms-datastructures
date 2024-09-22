#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "graph.h"

Graph::Graph(int numVertexes) : vertexes(numVertexes), adjMatrix(vertexes, std::vector(vertexes, 0)){}

Graph::~Graph(){}

void Graph::addEdge(int src, int dest){
    if(src >= 0 && src < vertexes && dest >= 0 && dest < vertexes){
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }
}

void Graph::removeEdge(int src, int dest){
    if(src >= 0 && src < vertexes && dest >= 0 && dest < vertexes){
        adjMatrix[src][dest] = 0;
        adjMatrix[dest][src] = 0;
    }
}

bool Graph::hasEdge(int src, int dest) const{
    if(src >= 0 && src < vertexes && dest >= 0 && dest < vertexes){
        return adjMatrix[src][dest] == 1 && adjMatrix[dest][src] == 1;
    }else{
        return false;
    }
}


void Graph::printGraph() const{
    for(auto vec : adjMatrix){
        for(auto el : vec){
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::DFS_i(int start) const{
    if(start >= 0 && start < vertexes && start >= 0 && start < vertexes){
        
        std::stack<int> st;
        std::vector<bool> visited(vertexes, false);
        st.push(start);
        visited[start] = true;

        while(!st.empty()){

            int vertex = st.top();
            st.pop();

            
            std::cout << vertex << " ";

            for(int i = 0; i < vertexes; ++i){
                if(adjMatrix[vertex][i] != 0 && !visited[i]){
                    st.push(i);
                    visited[i] = true;
                }
            }
        }
        
        std::cout << std::endl;    
    }
}

void Graph::BFS_i(int start) const{
    if(start >= 0 && start < vertexes && start >= 0 && start < vertexes){
        
        std::queue<int> qu;
        std::vector<bool> visited(vertexes, false);
        qu.push(start);
        visited[start] = true;

        while(!qu.empty()){

            int vertex = qu.front();
            qu.pop();

            
            std::cout << vertex << " ";

            for(int i = 0; i < vertexes; ++i){
                if(adjMatrix[vertex][i] != 0 && !visited[i]){
                    qu.push(i);
                    visited[i] = true;
                }
            }
        }
        
        std::cout << std::endl;    
    }
}

void Graph::DFS_r(int start) const{
    if(start >= 0 && start < vertexes && start >= 0 && start < vertexes){


    std::vector<bool> visited(vertexes, false);

    DFSUtil(start, visited);

    for(int i = 0; i < vertexes; ++i){
        if(!visited[i]){
            DFSUtil(i, visited);
        }
    }

    std::cout << std::endl;

    }
}

void Graph::DFSUtil(int node, std::vector<bool>& visited) const{
    if(!visited[node]){
        std::cout << node << " ";
        visited[node] = true;
        for(int i = 0; i < vertexes; ++i){
            if(adjMatrix[node][i] != 0 && !visited[i]){
                DFSUtil(i, visited);
            }
        }
    }
}

void Graph::BFS_r(int start) const{
    if(start >= 0 && start < vertexes && start >= 0 && start < vertexes){
        std::vector<bool> visited(vertexes, false);
        std::queue<int> qu;

        qu.push(start);
        visited[start] = true;

        BFSUtil(qu, visited);

        std::cout << std::endl;
    }
}

void Graph::BFSUtil(std::queue<int>& qu, std::vector<bool>& visited) const{
    if(qu.empty()) return;

    int vertex = qu.front();
    qu.pop();

    std::cout << vertex << " ";

    for(int i = 0; i < vertexes; ++i){
        if(adjMatrix[vertex][i] != 0 && !visited[i]){
            qu.push(i);
            visited[i] = true;
        }
    }

    BFSUtil(qu, visited);
}

std::vector<int> Graph::getNthLevel(int start, int level) const{
    if(start >= 0 && start < vertexes && start >= 0 && start < vertexes){
    std::vector<bool> visited(vertexes, false);
    std::vector<int> result;
    std::queue<int> qu;

    qu.push(start);
    visited[start] = true;

    while(!qu.empty()){

        if(level == 0){

            while(!qu.empty()){
                result.push_back(qu.front());
                qu.pop();
            }

            return result;
        }else{

            int size = qu.size();
            for(int i = 0; i < size; ++i){
                int vertex = qu.front();
                qu.pop();

                for(int i = 0; i < vertexes; ++i){
                    if(adjMatrix[vertex][i] != 0 && !visited[i]){
                        qu.push(i);
                        visited[i] = true;
                    }
                }
            }

            --level;
        }

    }
        return result;
    }else{
        throw std::out_of_range("Invalid Vertexes");
    }
}

std::vector<int> Graph::getShortPath(int src, int dest) const{
    if (src >= 0 && src < vertexes && dest >= 0 && dest < vertexes)
    {
        std::vector<bool> visited(vertexes, false);
        std::vector<int> parent(vertexes, -1);
        std::vector<int> result;
        std::queue<int> qu;

        qu.push(src);
        visited[src] = true;

        while(!qu.empty()){

            int vertex = qu.front();
            qu.pop();

            if(vertex == dest){

                int index = dest;

                while(index != -1){
                    result.push_back(index);
                    index = parent[index];
                }

                std::reverse(result.begin(), result.end());          
            }else{
                for(int i = 0; i < vertexes; ++i){
                    if(adjMatrix[vertex][i] != 0 && !visited[i]){
                        qu.push(i);
                        visited[i] = true;
                        parent[i] = vertex;
                    }
                }
            }
        }

        return result;
    }else{
        throw std::out_of_range("Invalid Vertexes");
    }
    
}
int Graph::getAllPossiblePaths(int src, int dest) const{
    if (src >= 0 && src < vertexes && dest >= 0 && dest < vertexes){
        std::vector<bool> visited(vertexes, false);
        return getAllPossiblePaths_h(dest, src, visited);
    }else{
        throw std::out_of_range("Invalid src or dest");
    }
}


int Graph::getAllPossiblePaths_h(int dest, int node, std::vector<bool>& visited) const{
        if(node == dest){
            return 1;
        }else{
            if(!visited[node]){
                int paths = 0;
                visited[node] = true;
                for(int i = 0; i < vertexes; ++i){
                    if(adjMatrix[node][i] && !visited[i]){
                        paths += getAllPossiblePaths_h(dest, i, visited);
                    }
                }
                visited[node] = false;
                return paths;
            }else{
                return 0;
            }
        }
}

#endif