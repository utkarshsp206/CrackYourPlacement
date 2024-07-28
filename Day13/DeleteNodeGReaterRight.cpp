#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    Node *compute(Node *head)
    {
        if(head->next==NULL)return head;
        vector<int> v;
        Node* a = head;
        while(a!=NULL)
        {
            v.push_back(a->data);
            a=a->next;
        }
        vector<int> st;
        for(int i=0;i<v.size();i++)
        {
            bool flag=false;
            for(int j=i+1;j<v.size();j++)
            {
                if(v[j]>v[i])
                {
                    flag=true;
                    break;
                }
            }
            if(!flag)
            {
                st.push_back(v[i]);
            }
        }
        
        Node* ans = new Node(st[0]);
        Node* b = ans;
        for(int i=1;i<st.size();i++)
        {
            b->next  = new Node(st[i]);
            b=b->next;
        }
        return ans;
        // your code goes here
    }
    
};

int main() {


return 0;
}