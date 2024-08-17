// C++ program for flattening a Linked List

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next, *bottom;

    Node(int new_data) {
        data = new_data;
        next = bottom = NULL;
    }
};

// function to flatten the linked list
Node* flatten(Node* root) {

    vector<int> values;

    // Push values of all nodes into an array
    while (root != NULL) {

        // Push the head node of the sub-linked-list
        values.push_back(root->data);

        // Push all the nodes of the sub-linked-list
        Node* temp = root->bottom;
        while (temp != NULL) {
            values.push_back(temp->data);
            temp = temp->bottom;
        }

        // Move to the next head node
        root = root->next;
    }

    // Sort the node values in ascending order
    sort(values.begin(), values.end());

    // Construct the new flattened linked list
    Node* tail = NULL;
    Node* head = NULL;
    for (int i = 0; i < values.size(); i++) {
        Node* newNode = new Node(values[i]);

        // If this is the first node of the linked list,
        // make the node as head
        if (head == NULL) {
            head = newNode;
        }
        else {
            tail->bottom = newNode;
        }
        tail = newNode;
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->bottom;
    }
    cout << endl;
}

int main() {

    /* Create a hard-coded linked list:
        5 -> 10 -> 19 -> 28
        |    |     |
        V    V     V
        7    20    22
        |          |
        V          V
        8          50
        |
        V
        30
    */
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);

    // Function call
    head = flatten(head);

    printList(head);
    return 0;
}
