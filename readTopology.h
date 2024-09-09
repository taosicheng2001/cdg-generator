#include <fstream>
#include <iostream>
#include <string>
#include <cassert>

#include "graph.h"

void readTopologyFromFile(std::string filename, Graph &G, bool bidirectional, std::string routeAlg){
  int n;
  int e;
  int src, dest;
  int ns, we;

  std::ifstream topologyFile;
  topologyFile.open(filename);

  if(!topologyFile){
    std::cout << "TopologyFile Missing!" << std::endl;
    return;
  }

  topologyFile >> n >> e;
  topologyFile >> ns >> we;

  G.setNumOfNodes(n);
  G.numOfnsEdges = ns;
  G.numOfweEdges = we;

  if(bidirectional){
    for(int i=0; i<e/2; i++){
      topologyFile >> src >> dest;
      G.addEdge(src, dest);
      G.addEdge(dest, src);
      if(i<ns/2){
        G.addNSEdge(src, dest);
        G.addNSEdge(dest, src);
      }
      else{
        G.addWEEdge(src, dest);
        G.addWEEdge(dest, src);
      }
    }
  }
  assert(e == G.numOfEdges);
  return;
}

void readTopologyFromStdin(){
  return;
}
