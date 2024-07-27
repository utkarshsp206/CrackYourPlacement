#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid;
        while(l<=r) {
            mid=(l+r)/2;
            if(nums[mid]==target) {
                return mid;
            }
            else if(nums[l]<=nums[mid]) {
                if(target>=nums[l] && target<=nums[mid]) {
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else {
                if(target<=nums[r] && target>=nums[mid]) {
                    l=mid+1;
                }
                else {
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};

int main() {


return 0;
}