#include <iostream>
using namespace std;

// Definition of singly linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;         // move 1 step
            fast = fast->next->next;   // move 2 steps
        }

        return slow;
    }
};

// Helper function to insert node at end
ListNode* insert(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);

    if (head == nullptr) {
        return newNode;
    }

    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Helper function to print list from a node
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = nullptr;

    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);

    Solution obj;
    ListNode* mid = obj.middleNode(head);

    cout << "Original List: ";
    printList(head);

    cout << "Middle starts from: ";
    printList(mid);

    return 0;
}