#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the smallest window in the string s
    // consisting of all the characters of string p.
    string smallestWindow(string s, string p)
    {
        if (s.size() < p.size()) {
            return "-1";
        }
        unordered_map<char, int> mp;
        for (auto& i : p)
            mp[i]++;
        string ans;
        int len = 1e9;

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                string curr = s.substr(i, j - i + 1);
                unordered_map<char, int> ms;
                for (auto& i : curr) {
                    ms[i]++;
                }
                bool f = 1;
                for (auto& i : mp) {
                    if (ms[i.first] < i.second) {
                        f = 0;
                    }
                }
                if (f) {
                    if (len > curr.size()) {
                        len = curr.size();
                        ans = curr;
                    }
                }
            }
        }
        return ans;
    }
};


int main() {


return 0;
}