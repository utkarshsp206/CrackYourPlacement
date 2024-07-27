#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string originalString = path;
        originalString = originalString + "/"; // Adding additional / to avoid a case where there is not / at the end.
        
        // First Replacing All /./
        string substringToReplace = "/./";
        string newSubstring = "/";
        size_t pos = originalString.find(substringToReplace);
        while (pos != string::npos) {
            originalString.replace(pos, substringToReplace.length(), newSubstring);
            pos = originalString.find(substringToReplace);
        }
        
        // Secondly Relacing All // 
        substringToReplace = "//";
        newSubstring = "/";
        pos = originalString.find(substringToReplace);
        while (pos != string::npos) {
            originalString.replace(pos, substringToReplace.length(), newSubstring);
            pos = originalString.find(substringToReplace);
        }

        // Finally Replacing /../ and Previous path/Directory.
        substringToReplace = "/../";
        pos = originalString.find(substringToReplace);
        while(pos != string::npos) {
            int cnt = 0;
            int newPos = 0;
            for(int i=pos-1;i>=0;i--) {
                if(originalString[i] != '/') {
                    cnt++;
                    newPos = i;
                } else {
                    newPos = i;
                    cnt++;
                    break;
                }
            }
            originalString.replace(newPos, cnt, "");
            pos = originalString.find(substringToReplace);
            originalString.replace(pos, substringToReplace.length(), newSubstring);
            pos = originalString.find(substringToReplace);
        }
        if(originalString.size()>1) {
            if(originalString[originalString.size()-1]=='/') {
                originalString.pop_back();
            }
        }

        return originalString;
    }
};

int main() {


return 0;
}