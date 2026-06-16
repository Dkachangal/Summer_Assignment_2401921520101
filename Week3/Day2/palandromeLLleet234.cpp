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
    bool isPalindrome(ListNode* head) {
        int size = 0;
        ListNode* temp = head;
        ListNode* second = NULL;

        while (temp != NULL) {
            size++;
            temp = temp -> next;
        }
        temp = head;
        int sz = size/2;

        if (size % 2 == 0) {
            while (sz != 0) {
                sz--;
                temp = temp -> next;
            }

        }
        else {
            while (sz != 0) {
                sz--;
                temp = temp -> next;
            }
            temp = temp -> next;
        }
        ListNode* nxt;
        while (temp != NULL) {
            nxt = temp -> next;
            temp -> next = second;
            second = temp;
            temp = nxt;
        }
        temp = head;
        while (second != NULL) {
            if (second -> val != temp -> val) return false;
            temp = temp -> next;
            second = second -> next;
        }
        return true;

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
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));

    std::cout << "Testing List: ";
    printList(head);

    Solution solution;
    if (solution.isPalindrome(head)) {
        std::cout << "Result: Is a Palindrome!" << std::endl;
    } else {
        std::cout << "Result: Not a Palindrome!" << std::endl;
    }

    return 0;
}