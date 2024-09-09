#include "readTopology.h"
#include "drawCDG.h"
#define IFILENAME "Mesh-4x4.txt"
#define OFILENAME "CDGGraphMesh-4x4.txt"

int main(int argc, char *argv[]){
  std::string ifilename;
  std::string ofilename;
  std::string routeAlg;

  if(argc == 1){
    ifilename = IFILENAME;
    ofilename = OFILENAME;
  }
  
  assert(argc >= 3);
  ifilename = argv[1];
  ofilename = argv[2];

  if(argc >= 4)
    routeAlg = argv[3];
  else
    routeAlg = "";

  Graph topologyGraph(0);
  readTopologyFromFile(ifilename, topologyGraph, true, routeAlg);
  
  CDG controlDependencyGraph(topologyGraph.numOfEdges);
  controlDependencyGraph.generateCDG(topologyGraph, routeAlg);

  generateDOT(ofilename, controlDependencyGraph);

  return 0;
}
