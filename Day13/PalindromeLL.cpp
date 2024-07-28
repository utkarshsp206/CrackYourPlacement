#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *temp = head;
        stack<int> st;

        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }

        temp=head;
        while(temp!=NULL){
            if(temp->val!=st.top()){
                return 0;
            }
            st.pop();
            temp=temp->next;
        }
        return 1;
    }
};

int main() {


return 0;
}