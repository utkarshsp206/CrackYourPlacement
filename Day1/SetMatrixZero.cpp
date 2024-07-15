//! Leetcode problem: 73. Set Matrix Zeroes

#include<bits/stdc++.h>
using namespace std;

void setMatrixZero(vector<vector<int>>& matrix) {
        set<int> ivalue;
        set<int> jvalue;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    ivalue.insert(i);
                    jvalue.insert(j);
                }
            }
        }

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(ivalue.find(i)!=ivalue.end()||jvalue.find(j)!=jvalue.end()){
                    matrix[i][j]=0;
                }
            }
        }
    }
int main() {
vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
setMatrixZero(matrix);

for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix[i].size();j++){
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
}

return 0;
}