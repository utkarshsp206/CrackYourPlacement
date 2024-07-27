#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int checkEightNeighbours(int n,int  m,vector<vector<int>>&board,int i,int j){
        int countOnes =0;
                if(i-1 >=0 && j-1>=0){
                    if(board[i-1][j-1] ==1 ) countOnes++;
                    
                }
                if(i-1 >=0 && j+1 <m){
                       if(board[i-1][j+1] ==1 ) countOnes++;
                        
                }
                if(j-1 >= 0){
                    if(board[i][j-1] ==1 ) countOnes++;
                   
                }
                if(j+1<m ){
                    if(board[i][j+1] ==1 ) countOnes++;
                   
                }
                if(i+1<n && j+1<m){
                    if(board[i+1][j+1] ==1 ) countOnes++;
                   
                }
                if(i+1<n){
                    if(board[i+1][j] ==1 ) countOnes++;
                  
                }
                if(i+1<n && j-1>=0){
                    if(board[i+1][j-1] ==1 ) countOnes++;
                   
                }
                if(i-1>=0){
                    if(board[i-1][j] ==1 ) countOnes++;
                    
                }
                return countOnes;
    }
    void gameOfLife(vector<vector<int>>& board) {
         int n = board.size();
         int m = board[0].size();
         vector<vector<int>>newBoard(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                int countOnes = checkEightNeighbours(n,m,board,i,j);
                if(board[i][j]==0){
                    if(countOnes==3) newBoard[i][j] = 1;
                }else{
                    if(countOnes==2 || countOnes==3){
                        newBoard[i][j] = 1;
                    }
                }
            }
        }


        board = newBoard;
    }
};

int main() {


return 0;
}