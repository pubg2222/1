#include<iostream>

using namespace std;

// Number of vertices in the graph  
const int V=6;

// Function to find the vertex with minimum key value 
int min_Key(int key[], bool visited[])  
{ 
    int min = 999, min_index;  // 999 represents an Infinite value

    for (int v = 0; v < V; v++) { 
        if (visited[v] == false && key[v] < min) { 
        	// vertex should not be visited
            min = key[v];
			min_index = v;  
        }
    }    
    return min_index;  
}  

// Function to print the final MST stored in parent[]  
int print_MST(int parent[], int cost[V][V])  
{  
    int minCost=0;
	cout<<"Edge \tWeight\n";  
    for (int i = 1; i< V; i++) {
		cout<<parent[i]<<" - "<<i<<" \t"<<cost[i][parent[i]]<<" \n";  
		minCost+=cost[i][parent[i]];
    }
	cout<<"Total cost is "<<minCost;
    return 0; 
}  

// Function to find the MST using adjacency cost matrix representation  
void find_MST(int cost[V][V])  
{  
    int parent[V], key[V];
    bool visited[V];

    // Initialize all the arrays 
    for (int i = 0; i< V; i++) { 
        key[i] = 999;    // 99 represents an Infinite value
        visited[i] = false;
        parent[i]=-1;
    }    

    key[0] = 0;  // Include first vertex in MST by setting its key vaue to 0.  
    parent[0] = -1; // First node is always root of MST  

    // The MST will have maximum V-1 vertices  
    for (int x = 0; x < V - 1; x++) 
    {  
        // Finding the minimum key vertex from the 
        //set of vertices not yet included in MST  
        int u = min_Key(key, visited);  

        visited[u] = true;  // Add the minimum key vertex to the MST  

        // Update key and parent arrays
        for (int v = 0; v < V; v++)  
        {
            // cost[u][v] is non zero only for adjacent vertices of u  
            // visited[v] is false for vertices not yet included in MST  
            // key[] gets updated only if cost[u][v] is smaller than key[v]  
            if (cost[u][v]!=0 && visited[v] == false && cost[u][v] < key[v])
            {  
                parent[v] = u;
                key[v] = cost[u][v];  
            }        
        }
    }

    // print the final MST  
	print_MST(parent, cost);  
}  

// main function
int main()  
{  
    int cost[V][V];
	cout<<"Enter the vertices for a graph with 6 vetices  ";
    for (int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
			cin>>cost[i][j];
        }
    }
	find_MST(cost);  

    return 0;  
}  



/*
Enter the vertices for a graph with 6 vetices  
0 7 8 0 0 0
7 0 3 6 0 0 
8 3 0 4 3 0
0 6 4 0 2 5
0 0 3 2 0 2
0 0 0 5 2 0
*/

/*

#include<iostream>
This line includes the necessary header file iostream which provides input/output stream functionalities in C++.


using namespace std;
This line specifies that we are using the std namespace, which contains standard C++ library functions and objects.

const int V=6;
This line declares a constant variable V with a value of 6, which represents the number of vertices in the graph.


int min_Key(int key[], bool visited[])
This line defines a function min_Key that takes two parameters: an integer array key[] and a boolean array visited[]. This function is used to find the vertex with the minimum key value among the set of vertices that are not yet visited.


int min = 999, min_index;
This line declares two variables min and min_index. min is initialized with a large value (999) representing infinity, and min_index will store the index of the vertex with the minimum key value.


for (int v = 0; v < V; v++)
This line starts a loop that iterates over all the vertices in the graph.


if (visited[v] == false && key[v] < min)
This line checks if the vertex v has not been visited (visited[v] == false) and if its key value (key[v]) is less than the current minimum key value (min).


min = key[v];
min_index = v;
If the above condition is true, the minimum key value (min) is updated with key[v], and min_index is updated with the index of the vertex (v) with the minimum key value.


return min_index;
The function min_Key returns the index (min_index) of the vertex with the minimum key value.

int print_MST(int parent[], int cost[V][V])
This line defines a function print_MST that takes two parameters: an integer array parent[] and a 2D integer array cost[][]. This function is responsible for printing the final minimum spanning tree (MST) and calculating the total cost of the MST.


int minCost = 0;
cout << "Edge \tWeight\n";
These lines declare and initialize a variable minCost to 0 and print a header for the MST edges and their weights.


for (int i = 1; i < V; i++)
This line starts a loop that iterates over all vertices (except the first vertex, as it is always the root of the MST).


cout << parent[i] << " - " << i << " \t" << cost[i][parent[i]] << " \n";
This line prints the edge and its weight in the MST. parent[i] represents the parent vertex of i in the MST, and cost[i][parent[i]] represents the weight of the edge between i and its parent.


minCost += cost[i][parent[i]];
This line updates the minCost variable by adding the weight of the current edge in the MST.

cout << "Total cost is " << minCost;
This line prints the total cost of the MST.

return 0;
The function print_MST returns 0.


void find_MST(int cost[V][V])
This line defines a function find_MST that takes a 2D integer array cost[][] as a parameter. This function is responsible for finding and printing the minimum spanning tree (MST) using the adjacency cost matrix representation.


int parent[V], key[V];
bool visited[V];
These lines declare three arrays: parent[] to store the parent of each vertex in the MST, key[] to store the key value of each vertex, and visited[] to keep track of visited vertices during the MST construction.

for (int i = 0; i < V; i++)
This line starts a loop that initializes the key[], visited[], and parent[] arrays for all vertices in the graph.


key[i] = 999;
visited[i] = false;
parent[i] = -1;
These lines initialize key[i] with a large value (999) representing infinity, set visited[i] to false indicating that no vertices are visited yet, and set parent[i] to -1 initially.


key[0] = 0;
parent[0] = -1;
These lines set the key value of the first vertex (index 0) to 0, indicating that it is the starting vertex of the MST, and set its parent as -1.


for (int x = 0; x < V - 1; x++)
This line starts a loop that iterates V-1 times, where V is the number of vertices. This loop constructs the MST by adding V-1 edges to the MST.


int u = min_Key(key, visited);
visited[u] = true;
These lines find the vertex u with the minimum key value among the set of vertices not yet included in the MST using the min_Key function. Then, visited[u] is set to true to mark it as visited.


for (int v = 0; v < V; v++)
This line starts a loop that iterates over all the vertices in the graph.


if (cost[u][v] != 0 && visited[v] == false && cost[u][v] < key[v])
This line checks if there exists an edge between vertices u and v (cost[u][v] != 0), and if vertex v is not yet visited (visited[v] == false), and if the weight of the edge (cost[u][v]) is less than the current key value of vertex v (key[v]).


parent[v] = u;
key[v] = cost[u][v];
If the above condition is true, the parent of vertex v is set as u (as u is the vertex that has the minimum key value to reach v), and the key value of v is updated with the weight of the edge between u and v.


print_MST(parent, cost);
This line calls the print_MST function, passing the parent[] array and the adjacency cost matrix cost[][] to print the final MST and its total cost.


int main()
This line starts the main function, which is the entry point of the program.


int cost[V][V];
cout << "Enter the vertices for a graph with 6 vertices  ";
These lines declare a 2D integer array cost[][] to represent the adjacency cost matrix of the graph, and prompt the user to enter the costs of the edges in the graph.


for (int i = 0; i < V; i++)
{
    for (int j = 0; j < V; j++)
    {
        cin >> cost[i][j];
    }
}
This code block reads the costs of the edges from the user and stores them in the cost[][] matrix.

find_MST(cost);
This line calls the find_MST function, passing the adjacency cost matrix cost[][] to find and print the minimum spanning tree (MST).

return 0;
This line indicates the end of the main function and returns 0, indicating successful program execution.
*/
