#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> s1,s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int popped;
        if(!s2.empty()){
            popped = s2.top();
            s2.pop();
        }
        else{
            //S1->S2
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            popped = s2.top();
            s2.pop();
        }
        return popped;
    }
    
    int peek() {
        if(!s2.empty()){
            return s2.top();
        }
        else{
            //S1->S2
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        if(s1.empty() && s2.empty()) return 1;
        return 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
 
int main() {


return 0;
}