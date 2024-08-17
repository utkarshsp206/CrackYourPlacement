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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1)
            return head;

        // Dummy node initialization
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* ptr = dummy;

        while (ptr != nullptr) {
            ListNode* tracker = ptr;

            // Check if there are at least k nodes ahead
            for (int i = 0; i < k && tracker != nullptr; i++) {
                tracker = tracker->next;
            }

            if (tracker == nullptr) {
                break;
            }

            // Reverse the k nodes
            auto updatedNodes = reverseLinkedList(ptr->next, k);

            ListNode* previous = updatedNodes.first;
            ListNode* current = updatedNodes.second;

            // Link the reversed part back to the main list
            ListNode* lastNodeOfReversedGroup = ptr->next;
            lastNodeOfReversedGroup->next = current;
            ptr->next = previous;
            ptr = lastNodeOfReversedGroup;
        }

        return dummy->next;
    }

private:
    pair<ListNode*, ListNode*> reverseLinkedList(ListNode* head, int k) {
        ListNode* previous = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        for (int i = 0; i < k; i++) {
            // Temporarily store the next node
            next = current->next;
            // Reverse the current node
            current->next = previous;
            // Before we move to the next node, point previous to the current
            // node
            previous = current;
            // Move to the next node
            current = next;
        }

        // Return the new head and the next pointer for further operations
        return {previous, current};
    }
};

int main() {


return 0;
}