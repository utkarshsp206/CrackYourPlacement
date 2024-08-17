#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n,m;
    void fun(vector<vector<int>>& grid, int i , int j, int time){
        if(i<0 || i==n || j<0 || j==m || grid[i][j]==0 || (grid[i][j]<time && grid[i][j]>1)){
            return ;
        }
        grid[i][j] = time;
        fun(grid,i-1,j,time+1);
        fun(grid,i,j-1,time+1);
        fun(grid,i+1,j,time+1);
        fun(grid,i,j+1,time+1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        n =grid.size();
        m =grid[0].size();
        int ans=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    fun(grid,i,j,2);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    return -1;
                ans= max(ans,grid[i][j]);
            }
        }
        return ans-2;
    }
};

int main() {


return 0;
}