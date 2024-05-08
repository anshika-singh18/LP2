#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class PrimMST {
private:
    int V;
    vector<vector<int>> graph;

    int minKey(const vector<int>& key, const vector<bool>& mstSet) {
        int min = numeric_limits<int>::max();
        int min_index = -1;

        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }
        return min_index;
    }

public:
    PrimMST(int vertices) : V(vertices) {
        graph.resize(V, vector<int>(V, 0));  // Initialize graph with V vertices
    }

    void addEdge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight; // For undirected graph
    }

    void printMST(const vector<int>& parent) {
        cout << "Edge \tWeight\n";
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
        }
    }

    void primMST() {
        vector<int> parent(V);
        vector<int> key(V, numeric_limits<int>::max());
        vector<bool> mstSet(V, false);

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;
            for (int v = 0; v < V; v++) {
                if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }
        printMST(parent);
    }
};

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices (V): ";
    cin >> V;
    cout << "Enter the number of edges (E): ";
    cin >> E;

    PrimMST graph(V);

    cout << "Enter the edges (format: u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    cout << "Minimum Spanning Tree:\n";
    graph.primMST();

    return 0;
}
