// C++ program to subtract smaller valued list from
// larger valued list and return result as a list.
#include <bits/stdc++.h>
using namespace std;

// A linked List Node
struct Node {
    int data;
    struct Node* next;
};

// A utility which creates Node.
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

/* A utility function to get length
 of linked list */
int getLength(Node* Node)
{
    int size = 0;
    while (Node != NULL) {
        Node = Node->next;
        size++;
    }
    return size;
}

/* A Utility that padds zeros in front of the
   Node, with the given diff */
Node* paddZeros(Node* sNode, int diff)
{
    if (sNode == NULL)
        return NULL;

    Node* zHead = newNode(0);
    diff--;
    Node* temp = zHead;
    while (diff--) {
        temp->next = newNode(0);
        temp = temp->next;
    }
    temp->next = sNode;
    return zHead;
}

/* Subtract LinkedList Helper is a recursive function,
   move till the last Node,  and subtract the digits and
   create the Node and return the Node. If d1 < d2, we
   borrow the number from previous digit. */
Node* subtractLinkedListHelper(Node* l1, Node* l2,
                               bool& borrow)
{
    if (l1 == NULL && l2 == NULL && borrow == 0)
        return NULL;

    Node* previous = subtractLinkedListHelper(
        l1 ? l1->next : NULL, l2 ? l2->next : NULL, borrow);

    int d1 = l1->data;
    int d2 = l2->data;
    int sub = 0;

    /* if you have given the value to next digit then
       reduce the d1 by 1 */
    if (borrow) {
        d1--;
        borrow = false;
    }

    /* If d1 < d2, then borrow the number from previous
       digit. Add 10 to d1 and set borrow = true; */
    if (d1 < d2) {
        borrow = true;
        d1 = d1 + 10;
    }

    /* subtract the digits */
    sub = d1 - d2;

    /* Create a Node with sub value */
    Node* current = newNode(sub);

    /* Set the Next pointer as Previous */
    current->next = previous;

    return current;
}

/* This API subtracts two linked lists and returns the
   linked list which shall  have the subtracted result. */
Node* subtractLinkedList(Node* l1, Node* l2)
{
    // Base Case.
    if (l1 == NULL && l2 == NULL)
        return NULL;

    // In either of the case, get the lengths of both
    // Linked list.
    int len1 = getLength(l1);
    int len2 = getLength(l2);

    Node *lNode = NULL, *sNode = NULL;

    Node* temp1 = l1;
    Node* temp2 = l2;

    // If lengths differ, calculate the smaller Node
    // and padd zeros for smaller Node and ensure both
    // larger Node and smaller Node has equal length.
    if (len1 != len2) {
        lNode = len1 > len2 ? l1 : l2;
        sNode = len1 > len2 ? l2 : l1;
        sNode = paddZeros(sNode, abs(len1 - len2));
    }

    else {
        // If both list lengths are equal, then calculate
        // the larger and smaller list. If 5-6-7 & 5-6-8
        // are linked list, then walk through linked list
        // at last Node as 7 < 8, larger Node is 5-6-8
        // and smaller Node is 5-6-7.
        while (l1 && l2) {
            if (l1->data != l2->data) {
                lNode = l1->data > l2->data ? temp1 : temp2;
                sNode = l1->data > l2->data ? temp2 : temp1;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    // If both lNode and sNode still have NULL value,
    // then this means that the  value of both of the given
    // linked lists is the same and hence we can directly
    // return a node with value 0.
    if (lNode == NULL && sNode == NULL) {
        return newNode(0);
    }
    // After calculating larger and smaller Node, call
    // subtractLinkedListHelper which returns the subtracted
    // linked list.
    bool borrow = false;
    return subtractLinkedListHelper(lNode, sNode, borrow);
}

/* A utility function to print linked list */
void printList(struct Node* Node)
{
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

// Driver program to test above functions
int main()
{
    Node* head1 = newNode(1);
    head1->next = newNode(0);
    head1->next->next = newNode(0);

    Node* head2 = newNode(1);

    Node* result = subtractLinkedList(head1, head2);

    printList(result);

    return 0;
}

// This code is contributed by Sania Kumari Gupta (kriSania804)
