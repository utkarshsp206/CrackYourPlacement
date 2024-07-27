#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        while (i < words.size()) {
            int j = i, l = 0;
            while (j < words.size() && l + words[j].size() + (j - i) <= maxWidth) {
                l += words[j].size();
                j++;
            }
            string line = words[i];
            if (j - i > 1 && j < words.size()) {
                int sp = maxWidth - l;
                int diff = sp / (j - i - 1);
                int e = sp % (j - i - 1);
                
                for (int k = i + 1; k < j; k++) {
                    line += string(diff, ' ');
                    if (e > 0) {
                        line += ' ';
                        e--;
                    }
                    line += words[k];
                }
            }
            else {
                for (int k = i + 1; k < j; k++) {
                    line += ' ';
                    line += words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            }
            
            ans.push_back(line);
            i = j;
        }
        
        return ans;
    }
};

int main() {


return 0;
}