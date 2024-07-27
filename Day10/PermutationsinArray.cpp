#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
     bool isPossible(long a[], long b[], int n, long k) {
        // Your code goes here
        // Your code goes here
        sort(a,a+n);
        sort(b,b+n);
        reverse(b,b+n);
        for(int i=0; i<n; i++){
                    if(a[i]+b[i]<k) return false;
            }
            return true;
    }};

int main() {


return 0;
}