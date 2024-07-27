#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
        {
            return head;
        }
        ListNode* current = head;

        while(current-> next != NULL)
        {
            if(current-> val == current-> next-> val)
            {
                ListNode* temp = current-> next;
                current-> next = current-> next-> next;
                delete temp;
            }
            else
            {
                current = current-> next;
            }
        }
        return head;
    }
};

int main() {


return 0;
}