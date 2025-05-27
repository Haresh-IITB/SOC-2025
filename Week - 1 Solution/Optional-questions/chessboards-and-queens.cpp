#include<bits/stdc++.h>
using namespace std;

int count_ways = 0 ; 

bool valid(vector<vector<int>> & chessBoard){
    // See if this is valid
    // At every queen position see if there is a queen in the same column or in diagonals

    // Given the chess-board find the position of every queen and see if any other queen lies in diagonal or column.
    // If netiher queen in diagonal or column then that queen position is valid.

    for(int i = 0 ; i<8 ; i++){
        for(int j = 0 ; j<8 ; j++){
            if(chessBoard[i][j] == 2){
                // Column check 
                for(int m = 0 ; m<8 ; m++){
                    if(chessBoard[m][j] == 2 && m != i)
                        return 0 ; 
                }  
                // diagonal check 
                int k = i+1 , l = j-1 ; 
                while(k<8 && l<8 && k>=0 && l>=0){
                    if(chessBoard[k][l] == 2)
                        return 0 ; 
                    k ++ ; 
                    l -- ; 
                }
                k = i+1 , l = j+1 ; 
                while(k<8 && l<8 && k>=0 && l>=0){
                    if(chessBoard[k][l] == 2)
                        return 0 ; 
                    k ++ ; 
                    l ++ ; 
                }
                k = i-1 , l = j-1 ; 
                while(k<8 && l<8 && k>=0 && l>=0){
                    if(chessBoard[k][l] == 2)
                        return 0 ; 
                    k -- ; 
                    l -- ; 
                }
                k = i-1 , l = j+1 ; 
                while(k<8 && l<8 && k>=0 && l>=0){
                    if(chessBoard[k][l] == 2)
                        return 0 ; 
                    k -- ; 
                    l ++ ; 
                }
            }
        }
    }
    return 1 ; 
}

void backtrack(vector<vector<int>> & chessBoard , int n){
    
    // Base case : If you have placed the queens in 8 places then increase the count and return 
    if(n>=8){
        count_ways ++ ;
        return ;
    }

    // Try to place the queen in every (n,i) and check the validity if valid then place the queen on the next row
    for(int i = 0 ; i<8 ; i++){
        if(chessBoard[n][i] == 1){
            chessBoard[n][i] = 2 ; 
            // Check if this is valid else continue 
            if(valid(chessBoard)){
                backtrack(chessBoard,n+1) ; 
            }
            chessBoard[n][i] = 1 ; 
        }
    }
    return ;
}

int main(){
    // Take the chessboard as a input 
    int n = 8 ; 
    vector<vector<int>> chessBoard(n,vector<int>(n,1)) ; 
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            char temp ; 
            cin >> temp ; 
            if(temp == '*')
                chessBoard[i][j] = 0 ; // In-valid position
        }
    }

    // Try to place the queens using backtracking 
    backtrack(chessBoard,0) ; 

    // Now 2-denotes where you have placed the queen 
    cout << count_ways << "\n" ; // Place the first queen on row 0 
    return 0 ; 
}