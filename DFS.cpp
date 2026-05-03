#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, const vector<vector<int>>& adjMatrix, vector<bool>& visited) {
    visited[node] = true; //Mark current node as visited
    cout << node << " ";

    // Check all possible adjacent nodes
    for (int i = 0; i < adjMatrix.size(); i++) {
        // If there is a connection and node is not visited
        if (adjMatrix[node][i] == 1 && !visited[i]) {
        // Visit that node recursively
            dfs(i, adjMatrix, visited);  
        }
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    // Create n x n adjacency matrix (initially all values 0)
    vector<vector<int>> adjMatrix(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adjMatrix[i][j];

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    // Create visited array of size n, initialize all to false (not visited)
    vector<bool> visited(n, false);

    cout << "DFS Traversal: ";
    dfs(start, adjMatrix, visited);

    return 0;
}