// #include <iostream>
// #include <vector>

// using namespace std;

// bool isSafe(const vector<int>& board, int row, int col) {
//     for (int i = 0; i < row; ++i) {
//         if (board[i] == col || (abs(board[i] - col) == abs(i - row))) {
//             return false;
//         }
//     }
//     return true;
// }

// void solveNQueensUtil(vector<vector<int>>& solutions, vector<int>& board, int row, int n) {
//     if (row == n) {
//         solutions.push_back(board);
//         return;
//     }

//     for (int col = 0; col < n; ++col) {
//         if (isSafe(board, row, col)) {
//             board[row] = col;
//             solveNQueensUtil(solutions, board, row + 1, n);
//             board[row] = -1; // backtrack
//         }
//     }
// }

// vector<vector<int>> solveNQueens(int n) {
//     vector<vector<int>> solutions;
//     vector<int> board(n, -1);
//     solveNQueensUtil(solutions, board, 0, n);
//     return solutions;
// }

// void printBoard(const vector<int>& board) {
//     int n = board.size();
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             if (board[i] == j) cout << "Q ";
//             else cout << ". ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

// int main() {
//     int n = 4;
//     vector<vector<int>> solutions = solveNQueens(n);

//     cout << "Number of solutions for " << n << "-queens: " << solutions.size() << endl;

//     for (const auto& solution : solutions) {
//         printBoard(solution);
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

bool issafe(vector<int>& board, int row, int col){
    for(int i=0; i<row; i++){
        if(board[i]==col || (abs(board[i]-col)==abs(i-row))){
            return false;
        }
    }
    return true;
}

void solveutil(vector<vector<int>>& solutions, vector<int>& board, int row, int n){
    if(row==n){
        solutions.push_back(board);
        return;
    }

    for(int col = 0; col<n; col++){
        if(issafe(board, row, col)){
            board[row] = col;
            solveutil(solutions, board, row+1, n);
            board[row] = -1;
        }
    }
}

vector<vector<int>> solve(int n){
    vector<int>board(n, -1);
    vector<vector<int>> solution;
    solveutil(solution, board, 0, n);
    return solution;
}


void print(const vector<int>& board){
    int n = board.size();
    for(int i=0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(board[i]==j) cout<<" Q ";
            else cout<<" . ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    int n = 4;
    vector<vector<int>>solution = solve(n);

    for(auto& c: solution){
        print(c);
    }
}
