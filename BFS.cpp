#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, const vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size();              // Number of vertices
    vector<bool> visited(n, false);        // Track visited nodes
    queue<int> q;                          // Queue for BFS

    visited[start] = true;                 // Mark start node as visited
    q.push(start);                         // Insert start node into queue

    cout << "BFS Traversal: ";

    // Continue until queue becomes empty
    while (!q.empty()) {
        int node = q.front();              // Get front node
        q.pop();                           // Remove it from queue
        cout << node << " ";               // Process (print) node

        // Check all adjacent nodes
        for (int i = 0; i < n; i++) {
            // If edge exists and node not visited
            if (adjMatrix[node][i] == 1 && !visited[i]) {
                visited[i] = true;         // Mark as visited
                q.push(i);                 // Add to queue
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;  

    // Create n x n adjacency matrix
    vector<vector<int>> adjMatrix(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adjMatrix[i][j];

    int start;
    cout << "Enter starting node: ";
    cin >> start;  

    // Call BFS function
    bfs(start, adjMatrix);

    return 0;
}