#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int,int> mpp;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mpp[nums2[i]]=-1;
                st.push(nums2[i]);
            }
            else{
                mpp[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
        }
        for(int i=0;i<nums1.size();i++){
            result.push_back(mpp[nums1[i]]);
        }
        return result;
    }
};

int main() {


return 0;
}