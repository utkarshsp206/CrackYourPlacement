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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return  NULL;
        ListNode* temp = new ListNode(0,head);
        ListNode* p=temp, *q=head;
        int flag=1;
        while(q!=NULL && q->next!=NULL){
            if(q->val == q->next->val){
                q=q->next;
                flag=0;
            }
            else{
                if(flag!=0){
                    p=p->next;
                    q=q->next;
                }
                else{
                    p->next = q->next;
                    q=q->next;
                }
                flag=1;
            }
        }
        if(flag!=0){
            p=p->next;
            q=q->next;
        }
        else{
            q=q->next;
        }
        return temp->next;
    }
};

int main() {


return 0;
}