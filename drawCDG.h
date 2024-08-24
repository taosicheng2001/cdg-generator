#include <fstream>

void generateDOT(const CDG &G){
  std::ofstream outFile("CDGgraph.dot");
  
  outFile << "digraph G {" << std::endl;
  for(int i=0; i<G.numOfEdges; i++){
    outFile << "\"" << G.edges[i].first << "\"" << " -> " << "\"" << G.edges[i].second << "\";" << std::endl; 
  }
  outFile << "}" << std::endl;

}
