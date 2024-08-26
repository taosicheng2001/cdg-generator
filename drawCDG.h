#include <fstream>

void generateDOT(std::string filename, const CDG &G){
  std::ofstream outFile(filename);
  
  outFile << "digraph G {" << std::endl;
  for(int i=0; i<G.numOfEdges; i++){
    outFile << "\"" << G.edges[i].first << "\"" << " -> " << "\"" << G.edges[i].second << "\";" << std::endl; 
  }
  outFile << "}" << std::endl;

}
