#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    stack<char> check(stack<char>st,string s){
        for(int i=0;i<s.size();i++){
            if(s[i]!='#'){
                st.push(s[i]);
            }
            else{
                if(!st.empty() ){
                    //int top=st.top();
                    st.pop();
                }
                //return 0;
            }
        }
        return st;
    }
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        stack<char>p =check(st,s);
        stack<char>q =check(st,t);
        
        if(p.size()!=q.size()){
            return false;
        }
        else{
            while(!p.empty() && !q.empty()){
                if(p.top()!=q.top()){
                    return false;
                }
                p.pop();
                q.pop();
            }
        }
        return true;
        
    }
};

int main() {


return 0;
}