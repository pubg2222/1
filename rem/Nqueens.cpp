#include <bits/stdc++.h>
using namespace std;
int N;

// function for printing the solution
void printSol(vector<vector<int>> board)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

/* Optimized isSafe function
isSafe function to check if current row contains or current left diagonal or current right diagonal contains any queen or not if
yes return false
else return true
*/

bool isSafe(int row, int col, vector<bool> rows, vector<bool> left_digonals, vector<bool> Right_digonals)
{

	if (rows[row] == true || left_digonals[row + col] == true || Right_digonals[col - row + N - 1] == true)
	{
		return false;
	}

	return true;
}

// Recursive function to solve N-queen Problem
bool solve(vector<vector<int>> &board, int col, vector<bool> rows, vector<bool> left_digonals, vector<bool> Right_digonals)
{
	// base Case : If all Queens are placed
	if (col >= N)
	{
		return true;
	}

	/* Consider this Column and move in all rows one by one */
	for (int i = 0; i < N; i++)
	{
		if (isSafe(i, col, rows, left_digonals, Right_digonals) == true)
		{
			rows[i] = true;
			left_digonals[i + col] = true;
			Right_digonals[col - i + N - 1] = true;
			board[i][col] = 1; // placing the Queen in board[i][col]

			/* recur to place rest of the queens */

			if (solve(board, col + 1, rows, left_digonals, Right_digonals) == true)
			{
				return true;
			}

			// Backtracking
			rows[i] = false;
			left_digonals[i + col] = false;
			Right_digonals[col - i + N - 1] = false;
			board[i][col] = 0; // removing the Queen from board[i][col]
		}
	}

	return false;
}

int main()
{
	// Taking input from the user

	cout << "Enter the no of rows for the square Board : ";
	cin >> N;

	// board of size N*N
	vector<vector<int>> board(N, vector<int>(N, 0));

	// array to tell which rows are occupied
	vector<bool> rows(N, false);

	// arrays to tell which diagonals are occupied
	vector<bool> left_digonals(2 * N - 1, false);
	vector<bool> Right_digonals(2 * N - 1, false);

	bool ans = solve(board, 0, rows, left_digonals, Right_digonals);

	if (ans == true)
	{

		// printing the solution Board
		printSol(board);
	}
	else
	{
		cout << "Solution Does not Exist\n";
	}
}

/*
The provided code is an implementation of the N-Queens problem using backtracking. Let's go through the code line by line to understand its functionality:

1. ```#include <bits/stdc++.h>```: This line includes a standard library that provides various functionalities, including input/output operations and data structures.

2. ```using namespace std;```: This line allows you to use standard library functions and objects without explicitly specifying the namespace.

3. ```int N;```: This declares an integer variable `N`, which will represent the size of the chessboard and the number of queens to be placed.

4. ```void printSol(vector<vector<int>> board)```: This is a function that takes a 2D vector `board` as input and prints the board's configuration, where 1 represents a queen and 0 represents an empty cell.

5. ```for (int i = 0; i < N; i++)```: This initiates a loop to iterate through the rows of the chessboard.

6. ```for (int j = 0; j < N; j++)```: This nested loop iterates through the columns of the chessboard.

7. ```cout << board[i][j] << " ";```: This statement prints the value at cell `(i, j)` of the chessboard, followed by a space.

8. ```cout << "\n";```: This prints a new line character to move to the next row after printing all the cells in the current row.

9. ```bool isSafe(int row, int col, vector<bool> rows, vector<bool> left_digonals, vector<bool> Right_digonals)```: This is a function that checks if it is safe to place a queen at a particular position `(row, col)` on the chessboard. It takes the current row, column, and three vectors (`rows`, `left_digonals`, `Right_digonals`) as inputs.

10. ```if (rows[row] == true || left_digonals[row + col] == true || Right_digonals[col - row + N - 1] == true)```: This condition checks if the current row, left diagonal, or right diagonal already contains a queen. If any of them is true, it means it is not safe to place a queen at `(row, col)`.

11. ```return false;```: If it is not safe to place a queen, this line returns `false` from the `isSafe` function.

12. ```return true;```: If it is safe to place a queen, this line returns `true` from the `isSafe` function.

13. ```bool solve(vector<vector<int>> &board, int col, vector<bool> rows, vector<bool> left_digonals, vector<bool> Right_digonals)```: This function is the main recursive function to solve the N-Queens problem. It takes the chessboard (`board`), current column (`col`), and three vectors (`rows`, `left_digonals`, `Right_digonals`) as inputs. The chessboard is passed by reference to update its configuration.

14. ```if (col >= N)```: This condition checks if all queens have been placed on the chessboard. If `col` is greater than or equal to `N`, it means all columns have been processed, and a solution has been found.

15. ```return true;```: If a solution has been found, this line returns `true` from the `solve` function.

16. ```for (int i = 0; i < N; i++)```: This loop iterates through all the rows of the current column (`col`) to find a

 safe position to place a queen.

17. ```if (isSafe(i, col, rows, left_digonals, Right_digonals) == true)```: This condition checks if it is safe to place a queen at the current position `(i, col)`.

18. ```rows[i] = true;```: This line updates the `rows` vector to mark the `i`th row as occupied.

19. ```left_digonals[i + col] = true;```: This line updates the `left_digonals` vector to mark the left diagonal as occupied. The left diagonal can be determined by the sum of the row and column indices.

20. ```Right_digonals[col - i + N - 1] = true;```: This line updates the `Right_digonals` vector to mark the right diagonal as occupied. The right diagonal can be determined by the difference between the column and row indices.

21. ```board[i][col] = 1;```: This line updates the `board` with a queen placed at `(i, col)`.

22. ```if (solve(board, col + 1, rows, left_digonals, Right_digonals) == true)```: This recursive call checks if it is possible to place queens in the next column (`col + 1`) by calling the `solve` function recursively.

23. ```return true;```: If a solution is found by placing queens in the next column, this line returns `true` from the `solve` function.

24. ```rows[i] = false;```: If the recursive call doesn't lead to a solution, this line backtracks by marking the `i`th row as unoccupied.

25. ```left_digonals[i + col] = false;```: This line backtracks by marking the left diagonal as unoccupied.

26. ```Right_digonals[col - i + N - 1] = false;```: This line backtracks by marking the right diagonal as unoccupied.

27. ```board[i][col] = 0;```: This line removes the queen from the `board` at `(i, col)`.

28. ```return false;```: If all positions in the current column have been checked, and no solution is found, this line returns `false` from the `solve` function.

29. ```int main()```: This is the main function where the execution of the program starts.

30. ```cout << "Enter the no of rows for the square Board : ";```: This line prompts the user to enter the size of the chessboard (number of rows) they want to use.

31. ```cin >> N;```: This line reads the input from the user and assigns it to the variable `N`.

32. ```vector<vector<int>> board(N, vector<int>(N, 0));```: This line creates a 2D vector `board` of size `N x N` and initializes all elements to 0. This vector will represent the chessboard.

33. ```vector<bool> rows(N, false);```: This line creates a vector `rows` of size `N` and initializes all elements to `false`. It will keep track of which rows are occupied by queens.

34. ```vector<bool> left_digonals(2 * N - 1, false);```: This line creates a vector `left_digonals` of size `2 * N - 1` and initializes all elements to `false`. It will keep track of which left diagonals are occupied by queens.

35. ```vector<bool> Right_digonals(2 * N - 1, false);```: This line creates

 a vector `Right_digonals` of size `2 * N - 1` and initializes all elements to `false`. It will keep track of which right diagonals are occupied by queens.

36. ```bool ans = solve(board, 0, rows, left_digonals, Right_digonals);```: This line calls the `solve` function to solve the N-Queens problem. It passes the chessboard (`board`), starting column index (`0`), and the three vectors (`rows`, `left_digonals`, `Right_digonals`).

37. ```if (ans == true)```: This condition checks if a solution is found.

38. ```printSol(board);```: If a solution is found, this line calls the `printSol` function to print the configuration of the chessboard.

39. ```else```: If no solution is found, this line executes.

40. ```cout << "Solution Does not Exist\n";```: This line prints a message indicating that no solution exists for the given size of the chessboard.

Overall, the code uses the backtracking approach to solve the N-Queens problem, where it tries to place queens column by column, backtracking when a queen cannot be placed safely. The code keeps track of occupied rows, left diagonals, and right diagonals using vectors, and updates the board accordingly. Finally, it prints the solution if one exists or displays a message if no solution is found.
*/