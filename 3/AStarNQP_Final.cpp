/* C++ program to solve N Queen Problem using
backtracking */

#include <bits/stdc++.h>
#define N 4
using namespace std;

/* A utility function to print solution */
void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		if(board[i][j])
			cout << " Q ";
		else cout<<" o ";
		printf("\n");
	}
}

/* A utility function to check if a queen can
be placed on board[row][col]. Note that this
function is called when "col" queens are
already placed in columns from 0 to col -1.
So we need to check only left side for
attacking queens */
bool isSafe(int board[N][N], int row, int col)
{
	int i, j;

	/* Check this row on left side */
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

/* A recursive utility function to solve N
Queen problem */
bool solveNQUtil(int board[N][N], int col)
{
	/* base case: If all queens are placed
	then return true */
	if (col >= N)
		return true;

	/* Consider this column and try placing
	this queen in all rows one by one */
	for (int i = 0; i < N; i++) {
		/* Check if the queen can be placed on
		board[i][col] */
		if (isSafe(board, i, col)) {
			/* Place this queen in board[i][col] */
			board[i][col] = 1;

			/* recur to place rest of the queens */
			if (solveNQUtil(board, col + 1))
				return true;

			/* If placing queen in board[i][col]
			doesn't lead to a solution, then
			remove queen from board[i][col] */
			board[i][col] = 0; // BACKTRACK
		}
	}

	/* If the queen cannot be placed in any row in
		this column col then return false */
	return false;
}

/* This function solves the N Queen problem using
Backtracking. It mainly uses solveNQUtil() to
solve the problem. It returns false if queens
cannot be placed, otherwise, return true and
prints placement of queens in the form of 1s.
Please note that there may be more than one
solutions, this function prints one of the
feasible solutions.*/
bool solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

	if (solveNQUtil(board, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}

	printSolution(board);
	return true;
}

// driver program to test above function
int main()
{
	solveNQ();
	return 0;
}


/*
line-by-line explanation of the logic in the provided code:

1. `#include <bits/stdc++.h>`: This line includes the necessary header files for input/output and standard library functions.

2. `#define N 4`: This line defines the size of the chessboard as 4x4. You can modify this value to solve the N-Queen problem for a different board size.

3. `using namespace std;`: This line allows you to use standard library functions and objects without specifying the namespace.

5. `void printSolution(int board[N][N])`: This function is used to print the solution, where `board` is a 2D array representing the chessboard.

9. `for (int i = 0; i < N; i++) {`: This loop iterates over the rows of the chessboard.

10. `for (int j = 0; j < N; j++)`: This loop iterates over the columns of the chessboard.

11. `if (board[i][j])`: This condition checks if a queen is present at the current position on the chessboard.

12. `cout << " Q ";`: If a queen is present, it prints " Q " to represent a queen.

14. `else cout<<" o ";`: If a queen is not present, it prints " o " to represent an empty cell.

17. `bool isSafe(int board[N][N], int row, int col)`: This function checks if it is safe to place a queen at a given position (`row`, `col`) on the chessboard.

21. `for (i = 0; i < col; i++)`: This loop checks if there is a queen present in the same row on the left side of the current position.

23. `if (board[row][i])`: If a queen is present in the same row, it returns false (not safe to place a queen here).

27. `for (i = row, j = col; i >= 0 && j >= 0; i--, j--)`: This loop checks the upper diagonal on the left side of the current position.

31. `if (board[i][j])`: If a queen is present in the upper diagonal, it returns false (not safe to place a queen here).

35. `for (i = row, j = col; j >= 0 && i < N; i++, j--)`: This loop checks the lower diagonal on the left side of the current position.

39. `if (board[i][j])`: If a queen is present in the lower diagonal, it returns false (not safe to place a queen here).

43. `bool solveNQUtil(int board[N][N], int col)`: This is a recursive utility function to solve the N-Queen problem.

46. `if (col >= N)`: This condition serves as the base case. If all queens are placed (col >= N), it returns true.

50. `for (int i = 0; i < N; i++)`: This loop iterates over the rows of the chessboard.

53. `if (isSafe(board, i, col))`: This condition checks if it is safe to place a queen at the current position (i, col).

55. `board[i][col] = 1;`: If it is safe, it places a queen at the current position.

58. `if (solveNQUtil(board, col + 1))`: It recursively calls the `solveNQUtil` function to place the remaining queens.

61. `board[i][col] = 0;`: If placing a queen in board[i][col

] doesn't lead to a solution, it backtracks and removes the queen from the current position.

65. `bool solveNQ()`: This function initializes the chessboard and calls the `solveNQUtil` function to solve the N-Queen problem.

71. `solveNQ();`: The main function calls the `solveNQ` function to solve and print the solution to the N-Queen problem.

73. `return 0;`: The program terminates successfully.
*/
