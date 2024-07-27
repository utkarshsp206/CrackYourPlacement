#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
    int minSwaps(vector<int>&nums)
    {
        // Code here
        int start=0;
        int end=nums.size()-1;
        int c=0;
        while(start<end)
        {
            if(nums[start]<nums[end])
            {
                start++;
            }
            else
            {
                swap(nums[start],nums[end]);
                c++;
                
                end--;
                
            }
        }
        return c;
    }
};

int main() {


return 0;
}