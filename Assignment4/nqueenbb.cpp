// #include<bits/stdc++.h> 
// using namespace std; 
// int N; 


// // function for printing the solution 
// void printSol(vector<vector<int>>board) 
// { 
// for(int i = 0;i<N;i++){ 
// 	for(int j = 0;j<N;j++){
//         if(board[i][j]==1){
//             cout<<" Q "<<" ";
//         } 
// 		else cout<<" . "<<" "; 
// 	} 
// 	cout<<"\n"; 
// } 
// } 


// bool isSafe(int row ,int col ,vector<bool>rows , vector<bool>left_digonals ,vector<bool>Right_digonals) 
// {	
//     if(rows[row] == true || left_digonals[row+col] == true || Right_digonals[col-row+N-1] == true){ 
//         return false; 
//     } 
        
//     return true; 
// } 


// bool solve(vector<vector<int>>& board ,int col ,vector<bool>rows , vector<bool>left_digonals ,vector<bool>Right_digonals) 
// {	 
// 	if(col>=N){ 
// 		return true; 
// 	} 

// 	for(int i = 0;i<N;i++) 
// 	{ 
// 		if(isSafe(i,col,rows,left_digonals,Right_digonals) == true) 
// 		{ 
// 			rows[i] = true; 
// 			left_digonals[i+col] = true; 
// 			Right_digonals[col-i+N-1] = true; 
// 			board[i][col] = 1;

// 			if(solve(board,col+1,rows,left_digonals,Right_digonals) == true){ 
// 				return true; 
// 			} 
				
// 			// Backtracking 
// 			rows[i] = false; 
// 			left_digonals[i+col] = false; 
// 			Right_digonals[col-i+N-1] = false; 
// 			board[i][col] = 0; // removing the Queen from board[i][col] 

// 		} 
// 	} 

// 		return false; 
// } 


// int main() 
// { 
// // Taking input from the user 

//     cout<<"Enter the no of rows for the square Board : "; 
//     cin>>N; 


//     // board of size N*N 
//     vector<vector<int>>board(N,vector<int>(N,0)); 


//         // array to tell which rows are occupied 
//     vector<bool>rows(N,false);		 

//     // arrays to tell which diagonals are occupied					 
//     vector<bool>left_digonals(2*N-1,false); 
//     vector<bool>Right_digonals(2*N-1,false); 


//     bool ans = solve(board , 0, rows,left_digonals,Right_digonals); 

//     if(ans == true){ 
//         printSol(board); 
//     } 
//     else{ 
//         cout<<"Solution Does not Exist\n"; 
//     } 
// } 



#include <bits/stdc++.h>
using namespace std;
int N;

void print(vector<vector<int>>board){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(board[i][j]==1) cout<<" Q ";
            else cout<<" . ";
        }
        cout<<endl;
    }
    cout<<endl;
}


bool issafe(int row, int col, vector<bool>& rows, vector<bool>& leftdiag, vector<bool>& rightdiag){
    if(rows[row]==true || leftdiag[row+col]==true || rightdiag[col-row+N-1]==true){
        return false;
    }
    return true;
}

bool solve(vector<vector<int>>& board, int col, vector<bool>& rows, vector<bool>& leftdiag, vector<bool>& rightdiag){
    if(col>=N){
        return true;
    }

    for(int i=0; i<N; i++){
        if(issafe(i, col, rows, leftdiag, rightdiag)==true){
            rows[i] = true;
            leftdiag[i+col] = true;
            rightdiag[col-i+N-1] = true;
            board[i][col] = 1;

            if(solve(board, col+1, rows, leftdiag, rightdiag)==true){
                return true;
            }

            rows[i] = false;
            leftdiag[i+col] = false;
            rightdiag[col-i+N-1] = false;
            board[i][col] = 0;

        }
    }
    return false;
}

int main(){
    cin>>N;

    vector<vector<int>>board(N, vector<int>(N,0));
    vector<bool>rows(N, false);

    vector<bool>leftdiag(2*N-1, false);
    vector<bool>rightdiag(2*N-1, false);

    bool ans = solve(board, 0, rows, leftdiag, rightdiag);

    if(ans==true){
        print(board);
    }
    else{
        cout<<"no solu";
    }
}