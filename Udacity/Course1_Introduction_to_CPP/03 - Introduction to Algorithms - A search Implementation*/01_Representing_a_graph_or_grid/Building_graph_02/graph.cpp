#include <iostream> 
#include "graph.h"

/* 
Node - "City Name"
Node - "Neighbors / connections / adjacent_edges
*/

// implement addNode
void Graph::addNode(const std::string& name){
    nodes.push_back(name);                  // add the node's name to the nodes list which lets us display it later
    adjList.push_back(std::vector<int>()); 

    // nodes[i] ->  the name of i-th node
    // adjList[i] -> neighbors of the i-th node
}


// implement addEdge
void Graph::addEdge(int u, int v){
    // 0, 1
    // 1, 0
    if(u >= 0 && v >= 0 && u < nodes.size() && v < nodes.size()){
        adjList[u].push_back(v); 
        adjList[u].push_back(u); 
    }else{
        std::cout << "Invalid node index"; 
    }
}

// implement printGraph
void Graph::printGraph() const{
    for(int i = 0; i < nodes.size(); i++){
        std::cout << nodes[i] << " -> "; 
        for(int neighbor : adjList[i]){
            std::cout << nodes[neighbor] << " "; 
        }
        std::cout << std::endl; 
    }
}