#include <iostream>
using namespace std;

// Definition for singly linked list
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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;         // 1 step
            fast = fast->next->next;   // 2 steps

            if (slow == fast) {
                return true; // cycle found
            }
        }

        return false;
    }
};

// Helper function to create linked list
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

int main() {
    ListNode* head = nullptr;

    // Create linked list: 3 -> 2 -> 0 -> -4
    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 0);
    head = insert(head, -4);

    // 🔥 Create cycle manually (last node points to node at index 1)
    ListNode* temp = head;
    ListNode* cycleNode = nullptr;
    int index = 0;

    while (temp->next != nullptr) {
        if (index == 1) {
            cycleNode = temp;
        }
        temp = temp->next;
        index++;
    }

    temp->next = cycleNode; // create cycle

    Solution obj;
    bool result = obj.hasCycle(head);

    cout << (result ? "Cycle Detected" : "No Cycle") << endl;

    return 0;
}