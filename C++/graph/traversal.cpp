#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adjList, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
    }
}

void bfs(int start, vector<vector<int>> &adjList) {
    vector<bool> visited(adjList.size(), false);
    vector<int> queue;
    visited[start] = true;
    queue.push_back(start);

    while (!queue.empty()) {
        int node = queue.front();
        queue.erase(queue.begin());
        cout << node << " ";
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push_back(neighbor);
            }
        }
    }
}

int main() {
    int n = 5; // number of nodes
    vector<vector<int>> adjList(n);
    
    // Example graph (undirected)
    adjList[0] = {1, 2};
    adjList[1] = {0, 3};
    adjList[2] = {0, 4};
    adjList[3] = {1};
    adjList[4] = {2};

    cout << "DFS Traversal: ";
    vector<bool> visited(n, false);
    dfs(0, adjList, visited);
    cout << endl;

    cout << "BFS Traversal: ";
    bfs(0, adjList);
    cout << endl;

    return 0;
}