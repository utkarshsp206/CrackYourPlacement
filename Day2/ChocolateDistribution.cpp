//! GFG Problem

#include<bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    if(n==1) return 0;
    sort(a.begin(),a.end());
    long long i=0;
    long long j = m-1;
    long long minDif = INT_MAX;
    while(j<n){
        long long dif = a[j]-a[i];
        if(dif<minDif) minDif = dif;
        i++;
        j++;
    }
    return minDif;
    
    }   
 
int main() {
vector<long long> packets={3, 4, 1, 9, 56, 7, 9, 12};
long long n = packets.size();
long long m = 5;
cout<<findMinDiff(packets,n,m);

return 0;
}