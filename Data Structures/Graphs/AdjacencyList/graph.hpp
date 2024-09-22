#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "graph.h"

graph::graph(int v){
   this->v = v;
   adjList.resize(v);

}

void graph::addVertex(){
    ++v;
    adjList.resize(v);
}

void graph::addEdge(int u, int v){
    if(u >= v || v >= this->v){
        return;
    }else{
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void graph::removeEdge(int src, int dest){
    if(src >= 0 && src < v && dest >= 0 && dest < v){
        auto it = std::find(adjList[src].begin(), adjList[src].end(), dest);
        auto it2 = std::find(adjList[dest].begin(), adjList[dest].end(), src);
        adjList[src].erase(it);
        adjList[dest].erase(it2);       
    }
}

bool graph::hasEdge(int u, int v) const{
    if(u >= v || v >= this->v){
        return false;
    }else{

        for(const auto el : adjList[u]){
            if(el == v){
                return true;
            }
        }

        return false;
    }
}

void graph::printGraph() const{
    std::vector<bool> visited(this->v, false);
    DFSUtil(0, visited);
    std::cout << "\n";
}

void graph::DFSUtil(int v, std::vector<bool>& visited) const{
    if(!visited[v]){
        std::cout << v << " ";
        visited[v] = true;
        for(const auto it : adjList[v]){
            DFSUtil(it, visited);
        }
    }
}

void graph::BFS_i(int start) const{
    if(start >= v) return;

    std::queue<int> queue;
    std::vector<bool> visited(v, false);

    visited[start] = true;
    queue.push(start);

    while(!queue.empty()){
        int ver = queue.front();
        std::cout << ver << " ";
        queue.pop();

        for(int el : adjList[ver]){
            if(!visited[el]){
                visited[el] = true;
                queue.push(el);
            }
        }

    }

    std::cout << "\n";
}

void graph::DFS_i(int start) const{

    std::vector<bool> visited(v, false);
    std::stack<int> st;

    st.push(start);
    visited[start] = true;

    while(!st.empty()){
        int vertex = st.top();
        st.pop();

        std::cout << vertex << " ";

        for(const auto& el : adjList[vertex]){
            if(!visited[el]){
                st.push(el);
                visited[el] = true;
            }
        }
    }

    std::cout << std::endl;
}

void graph::DFS_r(int start) const{
    std::vector<bool> visited(v, false);
    DFSUtil(start, visited);

    for(int i = 0; i < v; ++i){
        if(!visited[i]){
            DFSUtil(i, visited);
        }
    }  

    std::cout << std::endl;
}

void graph::BFS_r(int start) const{
    std::vector<bool> visited(v, false);
    std::queue<int> qu;

    qu.push(start);
    visited[start] = true;

    BFSUtil(qu, visited);

    std::cout << std::endl;

}

void graph::BFSUtil(std::queue<int>& qu, std::vector<bool>& visited) const{

        if(qu.empty()) return;

        int vertex = qu.front();
        qu.pop();

        std::cout << vertex << " ";

        for(const auto& vert : adjList[vertex]){
            if(!visited[vert]){
                qu.push(vert);
                visited[vert] = true;
            }
        }

        BFSUtil(qu, visited);
}

std::vector<int> graph::getNthLevel(int start, int level) const{
    std::vector<bool> visited(v, false);
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

                for(const auto& el : adjList[vertex]){
                    if(!visited[el]){
                        qu.push(el);
                        visited[el] = true;
                    }
                }
            }

            --level;
        }
    }

    return result;
}

int graph::getAllPossiblePaths(int src, int dest) const{
    if(src >= 0 && src < v && dest >= 0 && dest < v){
        std::vector<bool> visited(v, false);
        return getAllPossiblePaths_h(dest, src, visited);
    }else{
        throw std::out_of_range("Invalide src or dest");
    }
}

int graph::getAllPossiblePaths_h(int dest, int node, std::vector<bool>& visited) const{
    if(node == dest){
        return 1;
    }else{
        if(!visited[node]){

            int paths = 0;
            visited[node] = true;

            for(const auto& el : adjList[node]){
                if(!visited[el]){
                    paths += getAllPossiblePaths_h(dest, el, visited);
                }
            }
            
            visited[node] = false;
            return paths;

        }else{
            return 0;
        }
    }
}

std::vector<int> graph::getShortestPath(int src, int dest) const{
    if(src >= 0 && src < v && dest >= 0 && dest < v){
        std::vector<bool> visited(v, false);
        std::vector<int> result;
        std::vector<int> parent(v, -1);
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
                return result;

            }else{
                for(const auto& el : adjList[vertex]){
                    if(!visited[el]){
                        qu.push(el);
                        parent[el] = vertex;
                        visited[el] = true;
                    }
                }
            }
        }

        return result;

    }else{
        throw std::out_of_range("Invalid src or dest");
    }
}

graph::~graph(){}

#endif

