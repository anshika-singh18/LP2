#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& graph, vector<bool>& visited, queue<int>& q) {
    if (q.empty()) {
        return;
    }

    int current = q.front();
    q.pop();
    cout << current << " ";

    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
           
        }
    }

    bfs(graph, visited, q);
}

void bfsRecursive(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    bfs(graph, visited, q);
}

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int current) {
    cout << current << " ";
    visited[current] = true;

    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            dfs(graph, visited, neighbor);
        }
    }
}

void dfsRecursive(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);

    dfs(graph, visited, start);
}

int main() {
    int n;
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;

    // Input the graph as an adjacency list
    vector<vector<int>> graph(n);
    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (vertex pairs):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Assuming an undirected graph
    }

    int choice, startVertex;

     do {
        cout << "Menu:\n";
        cout << "1. BFS Traversal\n";
        cout << "2. DFS Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the starting vertex for BFS: ";
                cin >> startVertex;
                cout << "BFS Traversal: ";
                bfsRecursive(graph, startVertex);
                cout << endl;
                break;
           
            case 2:
                cout << "Enter the starting vertex for DFS: ";
                cin >> startVertex;
                cout << "DFS Traversal: ";
                dfsRecursive(graph, startVertex);
                cout << endl;
                break;

            case 3:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }

    } while (choice != 3);

    return 0;
}