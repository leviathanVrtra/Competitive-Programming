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
    if (node == NULL) {
        return node;
    }
    
    Node* curr = node;
    // Insert additional node after every node
    // 1->2->3 ==> 1->1->2->2->3->3
    while (curr) {
        Node* newnode = new Node(curr->val);
        Node* tmp = curr->next;
        curr->next = newnode;
        newnode->next = tmp;
        curr = tmp;
    }

    curr = node;
    // Adjusting the random pointers of the newly added node
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    curr = node;
    Node* ans = node->next;
    // Separate Original and Duplicate LL
    while (curr) {
        Node* tmp = curr->next;
        curr->next = tmp->next;
        curr = curr->next;
        if (tmp->next) {
            tmp->next = curr->next;
        }
    }
    return ans;
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
