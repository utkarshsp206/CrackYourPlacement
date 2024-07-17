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

 vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int index = abs(nums[i])-1;
            if(nums[index]<0) {
                res.push_back(abs(nums[i]));
            }
            else{
                nums[index]=-nums[index];
            }
        }
        return res;
    }

};

int main() {


return 0;
}