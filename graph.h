#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <utility> 

class Graph{
  public:
    int numOfNodes;
    int numOfEdges;
    std::vector<std::pair<int, int>> edges;

    Graph(int n){
      numOfNodes = n;
      numOfEdges = 0;
      edges.clear();
    }

    ~Graph(){}
    
    void setNumOfNodes(int n){
      numOfNodes = n;
      return;
    }
    
    void addEdge(int src, int dest){
      edges.push_back({src, dest});
      numOfEdges += 1;
      return;
    }

    void removeEdge(std::pair<int,int> edge){
      auto edgePtr = std::find(edges.begin(), edges.end(), edge);
      edges.erase(edgePtr);
      numOfEdges -= 1;
      assert(numOfEdges >= 0);
      return;
    }

    void printGraph(){
      std::cout << "Nodes: " << numOfNodes << " Edges: " << numOfEdges << std::endl;
      std::cout << "Src\tDest" << std::endl;
      for(int i=0; i<numOfEdges; i++){
        std::cout << edges[i].first << "\t" << edges[i].second << std::endl; 
      }
    }
};

class CDG: public Graph{
  public:
    std::vector<std::string> nodes;
    std::vector<std::pair<std::string, std::string>> edges;

    CDG(int n): Graph(n){
      numOfNodes = n;
      numOfEdges = 0;
      nodes.clear();
      edges.clear();
    }

    void generateCDG(const Graph &G){

      // Generate CDGNodes
      for(auto it=G.edges.begin(); it<G.edges.end(); it++){
        int src = it->first;
        int dest = it->second;
        std::string CDGNode = "(" + std::to_string(src) + "," + std::to_string(dest) + ")";
        nodes.push_back(CDGNode);
      }

      // Generate CDGEdges
      for(auto it=G.edges.begin(); it<G.edges.end(); it++){
        int src = it->first;
        int dest = it->second;
        std::string CDGSrc = "(" + std::to_string(src) + "," + std::to_string(dest) + ")";

        for(auto jt=G.edges.begin(); jt<G.edges.end(); jt++){
          int srcNext = jt->first;
          int destNext = jt->second;

          if(srcNext != dest) continue;
          if(destNext == src) continue;

          std::string CDGDest = "(" + std::to_string(srcNext) + "," + std::to_string(destNext) + ")";
          edges.push_back({CDGSrc, CDGDest});
          numOfEdges++;
        }
      }
    }

    ~CDG(){}

    void printGraph(){
      std::cout << "Nodes: " << numOfNodes << " Edges: " << numOfEdges << std::endl;
      std::cout << "Src\tDest" << std::endl;
      for(int i=0; i<numOfEdges; i++){
        std::cout << edges[i].first << "\t" << edges[i].second << std::endl; 
      }
    }

};  
