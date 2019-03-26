#include <vector>
#include <utility>
#include <iostream>

struct Node{
  int id;
  // To and weight
  std::vector< std::pair<int,int> > adj;
};

struct Graph{
  std::vector<Node> nodes;
};

void addNode(Graph& g){
  Node temp;
  temp.id = g.nodes.size();
  g.nodes.push_back(temp);
}

void addNode(Graph& g, int count){
  for(int i=0;i<count;i++){
    Node temp;
    temp.id = i;
    g.nodes.push_back(temp);
  }
}

void addVertex(Graph& g, int a, int b, int weight){
  if (a<b) {
    g.nodes[a].adj.push_back(std::make_pair(b,weight));
  } else {
    g.nodes[b].adj.push_back(std::make_pair(a,weight));
  }
}

void listGraf(Graph g) {
  std::cout<<"graph dengan "<<g.nodes.size()<<" nodes"<<std::endl;
  for(int i=0;i<g.nodes.size();i++){
    for(int j=0;j<g.nodes[i].adj.size();j++){
      std::cout<<g.nodes[i].id<<"->"<<g.nodes[i].adj[j].first<<" ;weight("<<g.nodes[i].adj[j].second<<")"<<std::endl;
    }
  }
}

void findDeadlock(Graph g) {
  //initial at 0
  std::vector<int> deadEndNodes;
  for (int i=0; i<g.nodes.size(); i++) {
    for (int j=0; j<g.nodes[i].adj.size(); j++) {
      if (g.nodes[j].adj.size() == 0) {
        //jika adj node itu tidak berisi
        deadEndNodes.push_back(j);
      }
    }
  }

  std::cout<<"Node yang buntu ialah: ";
  for (int k=0; k<deadEndNodes.size(); k++) {
    std::cout<<deadEndNodes[k]<<" ";
  }
}

int main(){
  Graph pulau;

  addNode(pulau,8);

  addVertex(pulau,0,1,1);
  addVertex(pulau,1,2,1);
  addVertex(pulau,1,3,1);
  addVertex(pulau,2,4,1);
  addVertex(pulau,2,5,1);
  addVertex(pulau,3,6,1);
  addVertex(pulau,3,7,1);

  listGraf(pulau);

  findDeadlock(pulau);

  return 0;
}
