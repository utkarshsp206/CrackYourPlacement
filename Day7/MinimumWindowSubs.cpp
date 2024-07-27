#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string str, string t) {
        vector<int> freq(123, 0);
        for (char c : t) {
            freq[c]++;
        }
        int minLen = INT_MAX, start = 0, copy, len;
        for (int s = 0, e = 0, count = t.size(); e < str.size(); e++) {
            if (freq[str[e]]-- > 0) {
                count--;
            }
            copy = count;
            while (count == 0 && s <= e) {
                if (freq[str[s++]]++ >= 0) {
                    count++;
                }
            }
            if (copy == 0 && minLen > (len = e - s + 2)) {
                minLen = len;
                start = s - 1;
            }
        }
        return minLen != INT_MAX ? str.substr(start, minLen) : "";
    }
};

int main() {


return 0;
}