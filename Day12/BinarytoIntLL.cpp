#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string s{};
        for(; head; head = head -> next) s += head -> val + '0';
        return stoull(s, 0, 2);
    }
};

int main() {


return 0;
}