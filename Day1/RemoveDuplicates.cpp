//! Leetcode problem: 26. Remove Duplicates from Sorted Array

#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
        
        int j=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) continue;
            else{
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
 
int main() {
vector<int> nums={0,0,0,1,1,2,2,3,3,3};
int count = removeDuplicates(nums);
for(int i=0;i<count;i++){
    cout<<nums[i]<<" ";
}

return 0;
}