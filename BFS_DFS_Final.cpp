#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int numNodes;
    vector<vector<int>> adjList;
    vector<bool> visited;

public:
    Graph(int nodes) : numNodes(nodes), adjList(nodes), visited(nodes, false) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void DFS(int startNode) {
        visited[startNode] = true;
        cout << startNode << " ";

        for (int neighbor : adjList[startNode]) {
            if (!visited[neighbor]) {
                DFS(neighbor);
            }
        }
    }

    void BFS(int startNode) {
        visited[startNode] = true;
        queue<int> q;
        q.push(startNode);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int numNodes, numEdges;
    int u, v;
    int startNode;
    char choice;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    Graph graph(numNodes);

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < numEdges; i++) {
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    cout << "Enter the starting node: ";
    cin >> startNode;

    cout << "Enter 'D' for Depth First Search (DFS) or 'B' for Breadth First Search (BFS): ";
    cin >> choice;

    cout << "Traversal: ";
    if (choice == 'D' || choice == 'd') {
        graph.DFS(startNode);
    } else if (choice == 'B' || choice == 'b') {
        graph.BFS(startNode);
    } else {
        cout << "Invalid choice!" << endl;
    }

    cout << endl;

    return 0;
}
/* 
Sure! Let's go through the provided code line by line to understand its functionality:

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
```
This section includes the necessary header files for input/output, vectors, and queues. The `std` namespace is imported to avoid explicitly using the `std::` prefix for standard library components.

```cpp
class Graph {
private:
    int numNodes;
    vector<vector<int>> adjList;
    vector<bool> visited;

public:
    Graph(int nodes) : numNodes(nodes), adjList(nodes), visited(nodes, false) {}
```
Here, a class named `Graph` is defined to represent a graph. It has private member variables `numNodes` to store the number of nodes in the graph, `adjList` to represent the adjacency list of the graph, and `visited` to keep track of visited nodes during traversals.

The class has a public constructor that takes the number of nodes as a parameter and initializes the `adjList` and `visited` vectors with the appropriate sizes.

```cpp
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
```
The `addEdge` function is used to add an edge between two nodes in the graph. It takes two integers `u` and `v` as parameters, representing the nodes to connect. It adds `v` to the adjacency list of `u` and `u` to the adjacency list of `v`, since it's an undirected graph.

```cpp
    void DFS(int startNode) {
        visited[startNode] = true;
        cout << startNode << " ";

        for (int neighbor : adjList[startNode]) {
            if (!visited[neighbor]) {
                DFS(neighbor);
            }
        }
    }
```
The `DFS` function implements a depth-first search traversal of the graph. It takes an integer `startNode` as the starting node for the traversal.

The function marks the `startNode` as visited, prints its value, and then recursively calls `DFS` for each unvisited neighbor of the current node. This recursive process continues until all reachable nodes have been visited.

```cpp
    void BFS(int startNode) {
        visited[startNode] = true;
        queue<int> q;
        q.push(startNode);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
```
The `BFS` function implements a breadth-first search traversal of the graph. It takes an integer `startNode` as the starting node for the traversal.

The function marks the `startNode` as visited, initializes a queue, and enqueues the `startNode`. Then, in a loop, it dequeues a node from the front of the queue, prints its value, and enqueues all its unvisited neighbors. This process continues until the queue becomes empty, ensuring all reachable nodes are visited.

```cpp
};

int main() {
    int numNodes, numEdges;
    int u, v;
    int startNode;
    char choice;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    Graph graph(numNodes);

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < numEdges; i++) {
        cin
*/