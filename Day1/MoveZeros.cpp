//! Leetcode problem: 283. Move Zeroes

#include<bits/stdc++.h>
using namespace std;

void moveZeros(vector<int> &nums){
    int left=0;
    for(int right=0;right<nums.size();right++){
        if(nums[right]!=0){
            swap(nums[left],nums[right]);
            left++;
        }
    }
}
 
int main() {
vector<int> nums={0,1,0,1,1,0,1,0};
moveZeros(nums);
for(auto it: nums){
    cout<<it<<" ";
}

return 0;
}