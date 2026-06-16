#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;

        while (temp != NULL) {
            count++;
            temp = temp -> next;
        }
        int nSt = count - n + 1;

        temp = head;
        
        if (nSt -1 == 0) {
            return head -> next;
        }
        while (nSt != 1) {
            if (nSt == 2) {
                temp -> next = temp -> next -> next;
                break;
            }
            nSt--;
            temp = temp -> next;
        }
        return head;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    std::cout << "Original List: ";
    printList(head);

    Solution solution;
    int n = 2;
    ListNode* updatedList = solution.removeNthFromEnd(head, n);

    std::cout << "Updated List (removed " << n << "nd from end): ";
    printList(updatedList);

    return 0;
}