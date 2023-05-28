#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;
// Define the problem
int n;  // Number of cities
vector<vector<int>> dist;  // Distance between cities
// Define the state
struct State {
    int cost;
    int city;
    vector<int> path;
    
    bool operator < (const State& other) const {
        return cost > other.cost;
    }
};
// Define the heuristic function
int heuristic(vector<bool>& visited, int city) {
    int min_dist = INF;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            min_dist = min(min_dist, dist[city][i]);
        }
    }
    return min_dist;
}
// A* algorithm
int tsp_a_star(int start_city, vector<int>& path) {
    priority_queue<State> pq;
    pq.push({0, start_city, {start_city}});
    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();  
        if (cur.path.size() == n) {
            path = cur.path;
            path.push_back(start_city);
            return cur.cost + dist[cur.city][start_city];
        }   
        vector<bool> visited(n);
        for (int c : cur.path) {
            visited[c] = true;
        }    
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int h = heuristic(visited, i);
                int new_cost = cur.cost + dist[cur.city][i] + h;
                vector<int> new_path = cur.path;
                new_path.push_back(i);
                pq.push({new_cost, i, new_path});
            }
        }
    }   
    return -1;  // No solution
}
// Print the path of vertices
void print_path(const vector<int>& path) {
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] + 1;
        if(i !=(path.size()-1))
            cout<<" -> ";
    }
    cout << endl;
}
int main() {
    cout << "Enter the number of cities: ";
    cin >> n;
    dist.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++){
    	for (int j = 0; j < n; j++){
    	cout<<"Enter distance between City "<<i+1<<" to city "<<j+1<<": ";
    	cin>>dist[i][j];
    	}
    }
    int start_city = 0;
    vector<int> path;
    int ans = tsp_a_star(start_city, path);
    cout << "\nShortest path vertices: ";
    print_path(path);
    cout << "Shortest path length: " << ans << endl;
    return 0;
}
/*
Sure! Let's go through the code line by line and explain its functionality and concepts.

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;
```
- This code includes the necessary libraries and defines a constant `INF` with a value of 1e9 (10^9), representing infinity for distance comparisons.

```cpp
int n;  // Number of cities
vector<vector<int>> dist;  // Distance between cities
```
- `n` represents the number of cities.
- `dist` is a 2D vector representing the distances between cities. `dist[i][j]` stores the distance between city `i` and city `j`.

```cpp
struct State {
    int cost;
    int city;
    vector<int> path;
    
    bool operator < (const State& other) const {
        return cost > other.cost;
    }
};
```
- `State` is a structure that represents the state of the search in the A* algorithm.
- It contains the `cost` (total cost so far), `city` (current city), and `path` (path of visited cities) variables.
- The `<` operator is overloaded to compare `State` objects based on their costs. This is used to order the priority queue in A*.

```cpp
int heuristic(vector<bool>& visited, int city) {
    int min_dist = INF;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            min_dist = min(min_dist, dist[city][i]);
        }
    }
    return min_dist;
}
```
- `heuristic` function calculates the heuristic (estimated) cost from a given city to the nearest unvisited city.
- It takes a `visited` vector (representing visited cities) and the current `city`.
- It iterates through all the cities and finds the minimum distance to an unvisited city.
- The minimum distance serves as the heuristic value.

```cpp
int tsp_a_star(int start_city, vector<int>& path) {
    priority_queue<State> pq;
    pq.push({0, start_city, {start_city}});
    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();  
        if (cur.path.size() == n) {
            path = cur.path;
            path.push_back(start_city);
            return cur.cost + dist[cur.city][start_city];
        }   
        vector<bool> visited(n);
        for (int c : cur.path) {
            visited[c] = true;
        }    
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int h = heuristic(visited, i);
                int new_cost = cur.cost + dist[cur.city][i] + h;
                vector<int> new_path = cur.path;
                new_path.push_back(i);
                pq.push({new_cost, i, new_path});
            }
        }
    }   
    return -1;  // No solution
}
```
- `tsp_a_star` function implements the A* algorithm to solve the TSP problem.
- It takes the `start_city` and a reference to the `path` vector, which will store the optimal path.
- It initializes a priority queue `pq` to store states, starting with the initial state.
- Inside the `while` loop, it retrieves the state with the lowest cost from the priority queue.
- If the current path includes all cities (length of `path` is equal to `n`), it adds the `start_city` to the `path`, calculates

 the total cost, and returns it.
- Otherwise, it marks the current city as visited, explores the unvisited cities, calculates the new cost, and adds the new states to the priority queue.
- The process continues until all states are explored or a solution is found.
- If there is no solution (all states explored), it returns -1.

```cpp
void print_path(const vector<int>& path) {
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] + 1;
        if(i != (path.size() - 1))
            cout << " -> ";
    }
    cout << endl;
}
```
- `print_path` function prints the path of vertices.
- It takes the `path` vector as input and iterates through it, printing the cities.
- If it's not the last city in the path, it prints the arrow separator.

```cpp
int main() {
    cout << "Enter the number of cities: ";
    cin >> n;
    dist.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter distance between City " << i + 1 << " to city " << j + 1 << ": ";
            cin >> dist[i][j];
        }
    }
    int start_city = 0;
    vector<int> path;
    int ans = tsp_a_star(start_city, path);
    cout << "\nShortest path vertices: ";
    print_path(path);
    cout << "Shortest path length: " << ans << endl;
    return 0;
}
```
- The `main` function is the entry point of the program.
- It prompts the user to enter the number of cities (`n`) and the distances between cities.
- It creates a 2D vector `dist` to store the distances.
- It calls the `tsp_a_star` function with the `start_city` and `path` variables.
- It prints the shortest path vertices using the `print_path` function.
- Finally, it prints the shortest path length (`ans`) returned by the `tsp_a_star` function.

The code implements the A* algorithm to solve the Traveling Salesman Problem (TSP) by finding the shortest path that visits all cities and returns to the starting city. It uses a priority queue to explore states, considering both the cost so far and a heuristic estimate of the remaining cost. The code then prints the optimal path and its length.
*/

/*
Certainly! Let's go into more detail about how the data structures and algorithms in the code work.

1. Data Structures:

   - `vector<vector<int>> dist`: This 2D vector represents the distances between cities. `dist[i][j]` stores the distance from city `i` to city `j`. The distances are provided by the user.

   - `struct State`: This structure represents the state of the search in the A* algorithm. It contains the following members:
     - `int cost`: The total cost accumulated so far in the path.
     - `int city`: The current city being considered.
     - `vector<int> path`: The path of visited cities so far.

   - `priority_queue<State>`: This priority queue is used to store the states during the A* search. The states are ordered based on their costs, with lower costs having higher priority. This allows exploring states with lower costs first.

2. Algorithms:

   - `heuristic` function: This function calculates the heuristic (estimated) cost from a given city to the nearest unvisited city. It takes two parameters:
     - `vector<bool>& visited`: A vector that represents the visited cities. `visited[i]` is `true` if city `i` has been visited.
     - `int city`: The current city for which the heuristic is calculated.
     The function iterates through all the cities and finds the minimum distance from the current city to an unvisited city. This minimum distance serves as the heuristic value.

   - `tsp_a_star` function: This function implements the A* algorithm to solve the TSP problem. It takes two parameters:
     - `int start_city`: The starting city for the TSP.
     - `vector<int>& path`: A reference to a vector that will store the optimal path found by the algorithm.
     The function follows these steps:
     - It initializes a priority queue to store the states during the search.
     - It pushes the initial state (starting city) into the priority queue with a cost of 0 and the starting city in the path.
     - While the priority queue is not empty, it retrieves the state with the lowest cost.
     - If the current path includes all cities (length of `path` is equal to `n`), it adds the starting city to the path, calculates the total cost by adding the distance from the current city to the starting city, and returns the total cost.
     - If not all cities have been visited, it marks the current city as visited, explores the unvisited cities, calculates the new cost by adding the distance from the current city to the next city, and adds the new states to the priority queue with the updated cost and path.
     - If the loop finishes without finding a solution (all states explored), it returns -1.

   - `print_path` function: This function prints the path of vertices. It takes a `const vector<int>& path` as input, which represents the optimal path found by the algorithm. The function iterates through the path and prints the cities, separated by arrows (`->`).
*/