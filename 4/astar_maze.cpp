#include <bits/stdc++.h>
using namespace std;
#define ROW 9
#define COL 9
typedef pair<int, int> Pair;
vector<pair<int,int>> vec;
typedef pair<double, pair<int, int> > pPair;
bool foundDest = false;
struct cell {
	int parent_i, parent_j;
	double f, g, h;
};
bool isValid(int row, int col)
{
	return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}
bool isUnBlocked(int grid[][COL], int row, int col)
{
	if (grid[row][col] == 0) return (true);
	else return (false);
}
bool isDestination(int row, int col, Pair dest)
{
	if (row == dest.first && col == dest.second) return (true);
	else return (false);
}
double calculateHValue(int row, int col, Pair dest)
{
	return ((double)sqrt((row - dest.first) * (row - dest.first) + (col - dest.second) * (col - dest.second)));
}
void tracePath(cell cellDetails[][COL], Pair dest)
{
	printf("\nThe Path is\n");
	int row = dest.first;
	int col = dest.second;
	stack<Pair> Path;
	while (!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col)) {
		Path.push(make_pair(row, col));
		int temp_row = cellDetails[row][col].parent_i;
		int temp_col = cellDetails[row][col].parent_j;
		row = temp_row;
		col = temp_col;
	}
	Path.push(make_pair(row, col));
	while (!Path.empty()) {
		pair<int, int> p = Path.top();
		Path.pop();
		vec.push_back(p);
		printf("(%d,%d)->", p.first, p.second);
	}
	return;
}
void aStarSearch(int grid[][COL], Pair src, Pair dest)
{
	if (isValid(src.first, src.second) == false) {
		printf("\nSource is invalid\n");
		foundDest=false;
		return;
	}
	if (isValid(dest.first, dest.second) == false) {
		printf("\nDestination is invalid\n");
		foundDest=false;
		return;
	}
	if (isUnBlocked(grid, src.first, src.second) == false || isUnBlocked(grid, dest.first, dest.second) == false) {
		printf("\nSource or the destination is blocked\n");
		foundDest=false;
		return;
	}
	if (isDestination(src.first, src.second, dest) == true) {
		printf("\nWe are already at the destination\n");
		foundDest=false;
		return;
	}
	bool closedList[ROW][COL];
	memset(closedList, false, sizeof(closedList));
	cell cellDetails[ROW][COL];
	int i, j;
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			cellDetails[i][j].f = FLT_MAX;
			cellDetails[i][j].g = FLT_MAX;
			cellDetails[i][j].h = FLT_MAX;
			cellDetails[i][j].parent_i = -1;
			cellDetails[i][j].parent_j = -1;
		}
	}
	i = src.first, j = src.second;
	cellDetails[i][j].f = 0.0;
	cellDetails[i][j].g = 0.0;
	cellDetails[i][j].h = 0.0;
	cellDetails[i][j].parent_i = i;
	cellDetails[i][j].parent_j = j;
	set<pPair> openList;
	openList.insert(make_pair(0.0, make_pair(i, j)));
	while (!openList.empty()) {
		pPair p = *openList.begin();
		openList.erase(openList.begin());
		i = p.second.first;
		j = p.second.second;
		closedList[i][j] = true;
		double gNew, hNew, fNew;
		if (isValid(i - 1, j) == true) {
			if (isDestination(i - 1, j, dest) == true) {
				cellDetails[i - 1][j].parent_i = i;
				cellDetails[i - 1][j].parent_j = j;
				printf("\nThe destination cell is found\n");
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}
			else if (closedList[i - 1][j] == false && isUnBlocked(grid, i - 1, j) == true) {
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(i - 1, j, dest);
				fNew = gNew + hNew;
				if (cellDetails[i - 1][j].f == FLT_MAX || cellDetails[i - 1][j].f > fNew) {
					openList.insert(make_pair(fNew, make_pair(i - 1, j)));
					cellDetails[i - 1][j].f = fNew;
					cellDetails[i - 1][j].g = gNew;
					cellDetails[i - 1][j].h = hNew;
					cellDetails[i - 1][j].parent_i = i;
					cellDetails[i - 1][j].parent_j = j;
				}
			}
		}
		if (isValid(i + 1, j) == true) {
			if (isDestination(i + 1, j, dest) == true) {
				cellDetails[i + 1][j].parent_i = i;
				cellDetails[i + 1][j].parent_j = j;
				printf("\nThe destination cell is found\n");
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}
			else if (closedList[i + 1][j] == false && isUnBlocked(grid, i + 1, j) == true) {
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(i + 1, j, dest);
				fNew = gNew + hNew;
				if (cellDetails[i + 1][j].f == FLT_MAX || cellDetails[i + 1][j].f > fNew) {
					openList.insert(make_pair(fNew, make_pair(i + 1, j)));
					cellDetails[i + 1][j].f = fNew;
					cellDetails[i + 1][j].g = gNew;
					cellDetails[i + 1][j].h = hNew;
					cellDetails[i + 1][j].parent_i = i;
					cellDetails[i + 1][j].parent_j = j;
				}
			}
		}
		if (isValid(i, j + 1) == true) {
			if (isDestination(i, j + 1, dest) == true) {
				cellDetails[i][j + 1].parent_i = i;
				cellDetails[i][j + 1].parent_j = j;
				printf("\nThe destination cell is found\n");
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}
			else if (closedList[i][j + 1] == false && isUnBlocked(grid, i, j + 1)== true) {
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(i, j + 1, dest);
				fNew = gNew + hNew;
				if (cellDetails[i][j + 1].f == FLT_MAX || cellDetails[i][j + 1].f > fNew) {
					openList.insert(make_pair(fNew, make_pair(i, j + 1)));
					cellDetails[i][j + 1].f = fNew;
					cellDetails[i][j + 1].g = gNew;
					cellDetails[i][j + 1].h = hNew;
					cellDetails[i][j + 1].parent_i = i;
					cellDetails[i][j + 1].parent_j = j;
				}
			}
		}
		if (isValid(i, j - 1) == true) {
			if (isDestination(i, j - 1, dest) == true) {
				cellDetails[i][j - 1].parent_i = i;
				cellDetails[i][j - 1].parent_j = j;
				printf("\nThe destination cell is found\n");
				tracePath(cellDetails, dest);
				foundDest = true;
				return;
			}
			else if (closedList[i][j - 1] == false && isUnBlocked(grid, i, j - 1) == true) {
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(i, j - 1, dest);
				fNew = gNew + hNew;
				if (cellDetails[i][j - 1].f == FLT_MAX || cellDetails[i][j - 1].f > fNew) {
					openList.insert(make_pair(fNew, make_pair(i, j - 1)));
					cellDetails[i][j - 1].f = fNew;
					cellDetails[i][j - 1].g = gNew;
					cellDetails[i][j - 1].h = hNew;
					cellDetails[i][j - 1].parent_i = i;
					cellDetails[i][j - 1].parent_j = j;
				}
			}
		}
	}
	if (foundDest == false)
		printf("Failed to find the Destination Cell\n");
	return;
}
int main()
{
	cout<<endl;
	int grid[ROW][COL]
		= { { 0, 1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 1, 1, 1, 0, 1, 1 },
			{ 0, 0, 0, 0, 0, 1, 0, 1, 0 },
			{ 1, 1, 0, 0, 1, 1, 1, 1, 1 },
			{ 1, 0, 1, 0, 1, 1, 0, 1, 1 },
			{ 1, 0, 1, 0, 0, 1, 0, 1, 0 },
			{ 1, 0, 1, 1, 0, 1, 0, 0, 0 },
			{ 1, 0, 1, 1, 0, 1, 0, 1, 0 },
			{ 0, 0, 1, 0, 0, 0, 0, 1, 0 } };
	cout<<"    ";
	for(int i=0;i<COL;i++)
		cout<<i<<" ";
	cout<<endl<<endl;
	for(int i=0;i<ROW;i++)
	{
		cout<<i<<"  |";
		for(int j=0;j<COL;j++)
		{
			if(grid[i][j]==0)
				cout<<" |";
			else cout<<"_|";
		}
		cout<<endl;
	}
	Pair src = make_pair(8, 8);
	Pair dest = make_pair(0, 0);
	cout<<"\nSource : ("<<src.first<<","<<src.second<<")\n";
	cout<<"\nDestination : ("<<dest.first<<","<<dest.second<<")\n";
	aStarSearch(grid, src, dest);
	if(foundDest==false) return 0;
	grid[vec[0].first][vec[0].second]=3;
	grid[vec[vec.size()-1].first][vec[vec.size()-1].second]=4;
	for(int i=1;i<vec.size()-1;i++)
	{
		grid[vec[i].first][vec[i].second]=2;
	}
	cout<<endl<<endl;
	cout<<"    ";
	for(int i=0;i<COL;i++)
		cout<<i<<" ";
	cout<<endl<<endl;
	for(int i=0;i<ROW;i++)
	{
		cout<<i<<"  |";
		for(int j=0;j<COL;j++)
		{
			if(grid[i][j]==0)
				cout<<" |";
			else if(grid[i][j]==2)
			{
				printf("\033[1;34m*\033[1;0m");
				cout<<"|";
			}
			else if(grid[i][j]==3)
			{
				printf("\033[1;31mS\033[1;0m");
				cout<<"|";
			}
			else if(grid[i][j]==4)
			{
				printf("\033[1;32mD\033[1;0m");
				cout<<"|";
			}
			else cout<<"_|";
		}
		cout<<endl;
	}
	return (0);
}

/* 
The code begins by including the necessary header files and defines the grid size as ROWxCOL. It also defines some typedefs and initializes a vector vec to store the path.

The struct cell is defined to store information about each cell. It includes the parent cell coordinates (parent_i, parent_j) and the cost values (f, g, h) for the cell. f is the total cost of the cell, g is the cost to reach the cell from the source, and h is the heuristic cost from the cell to the destination.

The code defines several utility functions:

isValid(row, col): This function checks if a given cell is within the grid boundaries. It returns true if the cell is valid, false otherwise.
isUnBlocked(grid, row, col): This function checks if a given cell is unblocked, which means it has a value of 0 in the grid. It returns true if the cell is unblocked, false otherwise.
isDestination(row, col, dest): This function checks if a given cell is the destination cell. It compares the cell coordinates with the destination coordinates and returns true if they match, false otherwise.
calculateHValue(row, col, dest): This function calculates the heuristic (H) value for a given cell based on its distance from the destination cell. It uses the Euclidean distance formula and returns the calculated value.
The tracePath(cellDetails, dest) function is used to backtrace the path from the destination to the source using the parent information stored in cellDetails. It starts from the destination cell and follows the parent pointers until the source cell is reached. The path coordinates are pushed onto the vec vector. Finally, the function prints the path by iterating over the vec vector.

The aStarSearch(grid, src, dest) function performs the A* search algorithm to find the shortest path from the source to the destination in the given grid. Here's a step-by-step explanation of the function:

It first performs some initial checks to validate the source and destination cells and ensure they are not blocked or already the same.
It initializes the closedList to keep track of visited cells and the cellDetails array to store information about each cell.
It sets the cost values for the source cell and adds it to the openList, which is a set of cells ordered by their cost values.
The function enters a loop that continues until the openList is empty:
It selects the cell with the lowest cost (f value) from the openList and removes it.
The selected cell is marked as visited by setting the corresponding entry in the closedList to true.
The function checks the neighboring cells (up, down, left, right) and updates their cost values and parent information if necessary.
If a neighboring cell is the destination, the path is found. The tracePath function is called to print the path, and the foundDest flag is set to true.
If a neighboring cell is not the destination and it is unvisited and unblocked, its cost values are updated, and it is added to the openList.
If the destination is not found after the loop, the function prints a failure message.
In the main function:

A 2D grid is defined and initialized with values representing blocked (1) and unblocked (0) cells.
The grid is printed to visualize it.
The source and destination cells are set.
The aStarSearch function is called with the grid, source, and destination.
If a path is found (foundDest == true), the grid is updated to mark the path with '*' symbols, the source with 'S', and the destination with 'D'.
Finally, the updated grid is printed to visualize the shortest path.
*/