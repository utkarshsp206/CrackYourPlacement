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
    ListNode* findMid(ListNode* head){
        if (head == nullptr || head->next == nullptr) {
        return head;
    }
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while(p2!=NULL && p2->next!=NULL){
            p1=p1->next;
            p2=p2->next->next;
        }
        return p1;
    }

    ListNode* MergeTwoList(ListNode* head1, ListNode* head2){
        ListNode* list1 = head1;
        ListNode* list2 = head2;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(list1!=NULL && list2!=NULL){
            if(list2->val<list1->val){
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
            else{
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
        }
        if(list1!=NULL){
            temp->next=list1;
        }
        else{
            temp->next=list2;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
          if (head == nullptr || head->next == nullptr) {
        return head;
    }
        ListNode* midNode = findMid(head);
        ListNode* rightHead = midNode->next;
        midNode->next=NULL;
        ListNode* leftHead = head;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return MergeTwoList(leftHead,rightHead);
    }
};

int main() {


return 0;
}