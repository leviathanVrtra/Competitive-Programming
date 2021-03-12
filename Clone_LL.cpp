#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
};

Node* newNode(int data) {
    Node* tmp = new Node;
    tmp->val = data;
    tmp->next = tmp->random = NULL;
    return tmp;
}

void Print(Node* node) {
    Node* curr = node;
    while (curr) {
        cout << curr->val << " " << curr->random->val << endl;
        curr = curr->next;
    }
}

Node* findCloneLL(Node* node) {
    Node* curr = node;
    Node* tmp = NULL;

    // Insert additional node after every node
    // 1->2->3 ==> 1->1->2->2->3->3
    while (curr) {
        tmp = curr->next;
        curr->next = newNode(curr->val);
        curr->next->next = tmp;
        curr = tmp;
    }

    curr = node;
    // Adjusting the random pointers of the newly added node
    while (curr) {
        if (curr->next) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            } else {
                curr->next->random = curr->random;
            }
            curr = curr->next->next;
        } else {
            curr = curr->next;
        }
    }

    Node* org = node;
    Node* cpy = node->next;
    tmp = cpy;
    // Separate Original and Duplicate LL
    while (org && cpy) {
        if (org->next) {
            org->next = org->next->next;
        } else {
            org->next = org->next;
        }
        if (cpy->next) {
            cpy->next = cpy->next->next;
        } else {
            cpy->next = cpy->next;
        }

        org = org->next;
        cpy = cpy->next;
    }

    return tmp;
}

int main()
{
    Node* node = newNode(1);
    node->next = newNode(2);
    node->next->next = newNode(3);
    node->next->next->next = newNode(4);
    node->next->next->next->next = newNode(5);

    node->random = node->next->next;
    node->next->random = node;
    node->next->next->random = node->next->next->next->next;
    node->next->next->next->random = node->next->next->next->next;
    node->next->next->next->next->random = node->next;
    
    cout << "Before : " << endl;
    Print(node);
    Node* clone = findCloneLL(node);
    cout << "After : " << endl;
    Print(clone);

    return 0;
}