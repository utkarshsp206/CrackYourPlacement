//! LeetCode Problem: 121. Best Time to Buy and Sell Stock

#include<bits/stdc++.h>
using namespace std;

//* Solution 1
int maxProfit(vector<int> &prices){
    int maximumProfit=0;
    for(int i=0;i<prices.size()-1;i++){
        for(int j=i+1;j<prices.size();j++){
            int profit = prices[j]-prices[i];
            if(profit>maximumProfit) maximumProfit=profit;
        }
    }
    return maximumProfit;

    //^ TC: O(n^2)    SC:O(1)
}

//* Solution 2
int maxProfit2(vector<int>& prices) {
        int i = 0;
        int j = 1;
        int maximumProfit = 0;
        while (j < prices.size()) {
            int profit = prices[j] - prices[i];
            if (profit > maximumProfit) {
                maximumProfit = profit;
            }
            if (prices[j] < prices[i]) {
                i = j;
            }
 j++;
        }
        return maximumProfit;

        //^ TC: O(n)  SC:O(1)

    }
 
int main() {
vector<int> prices = {1,2};
cout<<maxProfit2(prices);

return 0;
}