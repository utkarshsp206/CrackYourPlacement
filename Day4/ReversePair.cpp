#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]>2*nums[j]) count++;
            }
        }
        return count;
    }
};

int main() {


return 0;
}