#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        // * Firstly, figure out the sum of 1st Kth elements
        int leftSum = 0, rightSum = 0, maxSum = 0;
        for(int i = 0; i < k; i++) 
            leftSum += cardPoints[i];
        // * Initially, out maxSum becomes left Sum
        maxSum = leftSum;

        for(int leftIdx = k-1, rightIdx = n-1; leftIdx >= 0; leftIdx--, rightIdx--){
            // * Shrink from START (leftIdx)
            leftSum -= cardPoints[leftIdx];
            //  * Increase size from END (rightIdx)
            rightSum += cardPoints[rightIdx];
            maxSum = max(maxSum, leftSum + rightSum);
        }

        return maxSum;
    }
};
 
int main() {


return 0;
}