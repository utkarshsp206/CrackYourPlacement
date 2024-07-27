#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        // calculating next smaller index
        vector<int>NSI(n);
        stack<int>st1;

        NSI[n-1]=n;
        st1.push(n-1);
        for (int i = n-2; i >= 0; i--){
            while(st1.size()>0 && heights[st1.top()]>=heights[i]){ 
                st1.pop();             
            }
            if(st1.size()==0) NSI[i]=n;
            else NSI[i]=st1.top();
            st1.push(i);  
        }
        // calculating previous smaller index
        vector<int>PSI(n);
        stack<int>st2;
        PSI[0]=-1;
        st2.push(0);
        for (int i = 1; i < n; i++){
            while(st2.size()>0 && heights[st2.top()]>=heights[i]){ 
                st2.pop();             
            }
            if(st2.size()==0) PSI[i]=-1;
            else PSI[i]=st2.top();
            st2.push(i);  
        }
        // area calculation
        int maxArea=0;
        for(int i=0; i<n ;i++){
            int breadth=NSI[i]-PSI[i]-1;
            int Area = heights[i] * breadth;
            if(Area > maxArea){
                maxArea=Area;
            }
        }
        return maxArea;
    }
};

int main() {


return 0;
}