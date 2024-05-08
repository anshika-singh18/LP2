#include <bits/stdc++.h>
using namespace std;

struct Edge
{
  int src, dest, weight;
};

bool compareEdges(const Edge& e1, const Edge& e2){
  return e1.weight < e2.weight;
}

int findparent(vector<int>& parent, int u){
  if(parent[u]!=u){
    parent[u] = findparent(parent, parent[u]);
  }
  return parent[u];
}

void unionset(vector<int>& parent, vector<int>& rank, int x, int y){
  int xroot = findparent(parent, x);
  int yroot = findparent(parent, y);

  if(rank[xroot]<rank[yroot]){
    parent[xroot] = yroot;
  }
  else if(rank[xroot]>rank[yroot]){
    parent[yroot] = xroot;
  }
  else{
    parent[yroot] = xroot;
    rank[xroot]++;
  }
}

vector<Edge> solve(vector<Edge>& edges, int V){
  vector<Edge>res;
  vector<int>parent(V);
  vector<int>rank(V, 0);
  sort(edges.begin(), edges.end(), compareEdges);
  for(int i=0; i<V; i++){
    parent[i] = i;
  }

  for(Edge e: edges){
    int x = findparent(parent, e.src);
    int y = findparent(parent, e.dest);

    if(x!=y){
      res.push_back(e);
      unionset(parent, rank, x, y);
    }
  }
  return res;
}

int main() {
  // Sample graph edges
  vector<Edge> edges = {
    {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {2, 4, 7}, {1, 4, 5}, {1, 3, 8}, {3, 4, 9}
  };
  int V = 7; // Number of vertices in the graph

  // Find MST using Kruskal's algorithm
  vector<Edge> mst = solve(edges, V);

  cout << "Edges in the constructed MST: \n";
  for (Edge edge : mst) {
    cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
  }
  return 0;
}

