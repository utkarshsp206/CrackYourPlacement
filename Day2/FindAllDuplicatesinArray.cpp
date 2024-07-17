//!Leetcode problem : 442. Find All Duplicates in an Array

#include<bits/stdc++.h>
using namespace std;
 


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        while(j<nums.size()){
            if(nums[i]==nums[j]){
                res.push_back(nums[i]);
                i=j;
                j++;
            }
            else{
                i++;
                j++;
            }
        }
    return res;
    }
};

int main() {


return 0;
}