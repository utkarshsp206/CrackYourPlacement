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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){
            return NULL;
        }

        ListNode* p1 = head;
        ListNode* p2 = head;

        while(n--){
            p2=p2->next;
        }

        if(p2==NULL){
            return head->next;
        }

        while(p2!=NULL && p2->next!=NULL){
            p1=p1->next;
            p2=p2->next;
        }

        ListNode *temp = p1->next;
        p1->next = temp->next;
        delete temp;

        return head;
    }
};

int main() {


return 0;
}