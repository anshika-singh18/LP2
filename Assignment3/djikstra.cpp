#include <bits/stdc++.h>
using namespace std;

class Djikstras{
	public:

	int V;
	vector<vector<int>>graph;

	Djikstras(int vertices): V(vertices), graph(vertices, vector<int>(vertices,0)){}

	int mindist(vector<int>& dist, vector<bool>& mst){
		int min = INT_MAX, minidx = 0;

		for(int i=0; i<V; i++){
			if(dist[i]<=min && mst[i]==false){
				min = dist[i];
				minidx = i;
			}
		}
		return minidx;
	}

	void print(vector<int>& dist){
		for(int i=0; i<V; i++){
			cout<<i<<" \t"<<dist[i]<<endl;
		}
	}

	void solve(int src){
		vector<int>dist(V, INT_MAX);
		vector<bool>mst(V, false);

		dist[src] = 0;

		for(int count=0; count<V-1; count++){
			int u = mindist(dist, mst);
			mst[u] = true;
			for(int v = 0; v<V; v++){
				if(graph[u][v] && !mst[v] && dist[u]!=INT_MAX && dist[v]>graph[u][v]+dist[u]){
					dist[v] = graph[u][v]+dist[u];
				}
			}
		}
		print(dist);
	}
};
int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    Djikstras obj(V);

    obj.graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    obj.solve(src);

    return 0;
}



