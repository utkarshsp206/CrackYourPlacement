#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSumBetter(vector<int>& nums) {
        set<vector<int>> sol;
        for(int i=0;i<nums.size();i++){
            set<int> mp;
            for(int j=i+1;j<nums.size();j++){
                int third = -(nums[i]+nums[j]);
                if(mp.find(third)!=mp.end()){
                    vector<int> temp = {nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    sol.insert(temp);
                
                }
                    mp.insert(nums[j]);
            }
        }
        vector<vector<int>> res(sol.begin(),sol.end());
        return res;
    }

     vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size()){
            int j = i+1;
            int k=nums.size()-1;
            while(j<nums.size() && j<k){
               
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                     vector<int> temp={nums[i],nums[j],nums[k]};
                    res.push_back(temp);
                    int chk = nums[j];
                     while(j<k && nums[j]==chk) j++;
                }
                else if(sum<0){
                    int chk = nums[j];
                     while(j<k && nums[j]==chk) j++;
                }
                else{
                    int chk = nums[k];
                     while(j<k && nums[k]==chk) k--;
                }
            }
            int chk = nums[i];
            while(i<nums.size() && nums[i]==chk) i++;
        }
        return res;
    }
};
 
int main() {


return 0;
}