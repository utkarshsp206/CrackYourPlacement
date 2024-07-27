#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool ispossible(int n, int k, vector<int> &stalls, int mid){
        int cow_count = 1;
        int last_position = stalls[0];
        for(int i =0; i< stalls.size(); i++){
            if(stalls[i]- last_position >=mid){
                cow_count ++;
                if(cow_count == k) return true;
                last_position = stalls[i];
            }
        }
        return false;
        
    }
    
    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        sort (stalls.begin(), stalls.end());
        int start =0;
        int maxi = -1;
        
        for(int i =0; i< stalls.size(); i++){
            maxi = max(maxi, stalls[i]);
        }
    
        int end  = maxi;
        int ans = -1;
        
        while(start<= end){
            int mid = start + (end- start)/2;
            
            if(ispossible(n,k, stalls, mid)){
                ans = mid;
                start = mid +1;
            }
            else {
                end = mid -1;
            }
        }
        return ans;
    } 
};

int main() {


return 0;
}