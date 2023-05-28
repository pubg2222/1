#include <bits/stdc++.h> 
using namespace std; 
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){ 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    vector<int> distTo(V, INT_MAX); 
        
    distTo[S] = 0;         
    pq.push({0, S}); 
               
    while (!pq.empty()){ 
        int node = pq.top().second;             
        int dis = pq.top().first;             
        pq.pop(); 
        for (auto it : adj[node]){                 
            int v = it[0];                 
            int w = it[1];                 
            if (dis + w < distTo[v]){ 
            distTo[v] = dis + w; 
            pq.push({dis + w, v}); 
            } 
        } 
    }
    return distTo;
} 
int main() 
{     
    int V, E, S; 
    cout<<"Enter number of nodes :";     
    cin>>V;
    cout<<"Enter number of edges :";     
    cin>>E;     
    cout<<"Enter source node :";     
    cin>>S;     
    vector<vector<int>> adj[V];     
    for(int i=0; i<E; i++){         
        int start_ind, dist_ind, wt; 
        cout<<"Enter start node, distination node, weight between them for edge"<<i+1<<" :";         
        cin>>start_ind>>dist_ind>>wt;         
        vector<int>vec1{dist_ind, wt};         
        vector<int>vec2{start_ind, wt};         
        adj[start_ind].push_back(vec1);         
        adj[dist_ind].push_back(vec2); 
    } 
    vector<int> res = dijkstra(V, adj, S);     
    cout<<"Shortest distance from node "<<S<<" to remaining nodes is : ";     
    for (int i = 0; i < V; i++){ 
        cout << res[i] << " "; 
    } 
    cout << endl;     
    return 0; 
} 

/* 
The code begins by including the necessary header files and using the std namespace.

The dijkstra function is defined, which implements the Dijkstra's algorithm to find the shortest path from a source node S to all other nodes in a weighted graph. Here's a step-by-step explanation of the function:

It takes the number of vertices V, an array of adjacency lists adj[], and the source node S as input.
It initializes a priority queue pq to store nodes ordered by their distance values. The priority queue is implemented as a min heap, so the node with the smallest distance will be at the top.
It initializes a vector distTo with INT_MAX values to store the shortest distances from the source node to all other nodes. The distance to the source node itself is set to 0.
The source node is inserted into the priority queue with a distance of 0.
The function enters a loop that continues until the priority queue is empty:
It extracts the node with the smallest distance from the priority queue.
For each adjacent node of the extracted node, it calculates the new distance if the path through the current node is shorter than the previously calculated distance. If the new distance is smaller, it updates the distTo vector and inserts the node into the priority queue.
After the loop, the function returns the distTo vector containing the shortest distances from the source node to all other nodes.
In the main function:

The number of vertices V, the number of edges E, and the source node S are read from the user.
An adjacency list adj[] is initialized to store the graph.
A loop is used to read the start node, destination node, and weight between them for each edge from the user. The adjacency list is updated accordingly.
The dijkstra function is called with the number of vertices, the adjacency list, and the source node. The result is stored in the res vector.
The shortest distances from the source node to all other nodes are printed.
*/