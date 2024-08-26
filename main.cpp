#include "readTopology.h"
#include "drawCDG.h"
#define IFILENAME "Mesh-4x4.txt"
#define OFILENAME "Mesh-4x4.txt"

int main(int argc, char *argv[]){
  std::string ifilename;
  std::string ofilename;

  if(argc == 1){
    ifilename = IFILENAME;
    ofilename = OFILENAME;
  }
  
  assert(argc >= 3);
  ifilename = argv[1];
  ofilename = argv[2];

  Graph topologyGraph(0);
  readTopologyFromFile(ifilename, topologyGraph, true);
  
  CDG controlDependencyGraph(topologyGraph.numOfEdges);
  controlDependencyGraph.generateCDG(topologyGraph);

  generateDOT(ofilename, controlDependencyGraph);

  return 0;
}
