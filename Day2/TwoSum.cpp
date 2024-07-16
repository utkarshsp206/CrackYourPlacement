//! Leetcode Problem : 1. Two Sum

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> nums,int target){
    vector<int> sol;
    map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        int curr = nums[i];
        int more = abs(target-nums[i]);
        if(mpp.find(more)!=mpp.end()){
            sol.push_back(i);
            sol.push_back(mpp[more]);
        }
        else{
            mpp[curr]=i;
        }
    }
    return sol;
}

int main() {
vector<int> nums={1,3,2,5,6,4,2,8};
int target = 14;
vector<int> sol = twoSum(nums,target);
for(auto it: sol) cout<<it<<" ";

return 0;
}