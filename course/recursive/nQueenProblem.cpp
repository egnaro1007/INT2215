#include <iostream>
#include <cstring>

bool isSafe(bool **board, int n, int row, int col);
bool solveNQueen(bool **board, int n, int col);
void printBoard(bool **board, int n);

int main() {
    int n;
    std::cin >> n;
    bool **board = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new bool[n];
        std::memset(board[i], 0, n * sizeof(bool)); // Initialize the board with false values
    }
    if (solveNQueen(board, n, 0)) {
        printBoard(board, n);
    } else {
        std::cout << "No solution found." << std::endl;
    }
}


bool isSafe(bool **board, int n, int row, int col) {
    // check row
    for (int i = 0; i < col; i++) {
        if (board[row][i]) return false;
    }
    // No need to check column because we are placing queens column by column
    // check upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; ) {
        if (board[i][j]) return false;
        i--; 
        j--;
    }
    // check lower diagonal
    for (int i = row, j = col; i < n && j >= 0;) {
        if (board[i][j]) return false; 
        i++;
        j--;
    }
    return true;
}
bool solveNQueen(bool **board, int n, int col) {
    // All queens are placed
    if (col >= n) return true;

    // Try to place queen in all rows
    for (int i = 0; i < n; i++){
        // Check if queen can be placed in this row
        if (isSafe(board, n, i, col)) {
            // Place the queen
            board[i][col] = true;

            // Recursively check if placing queen in this row leads to a solution
            if (solveNQueen(board, n, col + 1)) return true;
            // If not, backtrack
            board[i][col] = false;
        }
    }
    
    return false;
}
void printBoard(bool **board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) std::cout << "1 ";
            else std::cout << "0 ";
        }
        std::cout << "\n";
    }
}