#include "readTopology.h"
#include "drawCDG.h"
#define FILENAME "Mesh-4x4.txt"

int main(){
  Graph topologyGraph(0);
  readTopologyFromFile(FILENAME, topologyGraph, true);
  
  CDG controlDependencyGraph(topologyGraph.numOfEdges);
  controlDependencyGraph.generateCDG(topologyGraph);

  generateDOT(controlDependencyGraph);

  return 0;
}
