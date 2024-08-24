#include <fstream>
#include <iostream>
#include <string>
#include <cassert>

#include "graph.h"

void readTopologyFromFile(std::string filename, Graph &G, bool bidirectional){
  int n;
  int e;
  int src, dest;

  std::ifstream topologyFile;
  topologyFile.open(filename);

  if(!topologyFile){
    std::cout << "TopologyFile Missing!" << std::endl;
    return;
  }

  topologyFile >> n >> e;
  G.setNumOfNodes(n);
  if(bidirectional){
    for(int i=0; i<e/2; i++){
      topologyFile >> src >> dest;
      G.addEdge(src, dest);
      G.addEdge(dest, src);
    }
  }
  assert(e == G.numOfEdges);
  return;
}

void readTopologyFromStdin(){
  return;
}
