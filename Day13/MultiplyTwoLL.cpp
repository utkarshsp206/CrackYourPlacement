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

class solution {
  public:
    long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
  
    long long  a = 0;
    long long  b = 0;
    Node* t1 = l1;
    Node* t2 = l2;
    while(t1 || t2){
        if(t1 != NULL){
            a = (a*10)%1000000007 + t1->data;
            t1 = t1->next;
        }
        if(t2 != NULL){
            b = (b*10)%1000000007 + t2->data;
            t2 = t2->next;
        }
    }
    
    return (a*b)%1000000007;

}
};

int main() {


return 0;
}