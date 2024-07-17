//! Leetcode problem: 11. Container With Most Water

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

 int maxAreaTwoPointer(vector<int>& height) {
        //Using two pointer approach
        int i=0;
        int j = height.size()-1;
        int temp;
        int maxArea=0;
        while(i<j){
             
            temp = min(height[i],height[j])*(j-i);
            if(temp>maxArea) maxArea = temp;
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxArea;
    }

    int maxAreaBrute(vector<int>& height) {
        //Brute Force
        int temp;
        int maxArea=0;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                temp = min(height[i],height[j])*(j-i);
                if(temp>maxArea) maxArea = temp;
            }
    }
        return maxArea;
    }
};
 
int main() {


return 0;
}