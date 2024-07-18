//!LeetCode Problem: 169. Majority Element

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElementBasic(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        return nums[n/2];
    }

    int majorityElement(vector<int>& nums) {
     //Using Hashmap
     int n = nums.size();
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    } 

    int val=n/2;
    for(auto it: mpp){
        if(it.second>val) return it.first;
    }
    return 0;
    }
};
 
int main() {
Solution s;
vector<int> nums={1,2,3,4,2,2,2,2,2};
cout<<s.majorityElementBasic(nums);

return 0;
}