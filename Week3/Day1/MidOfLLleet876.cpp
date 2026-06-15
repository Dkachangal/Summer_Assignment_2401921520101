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
    ListNode* middleNode(ListNode* head) {
        ListNode *temp = head;
        int n = 1;
        while (temp -> next != NULL) {
            temp = temp -> next;
            n++;
        }
        if (n == 1) return head;
        temp = head;
        if (n % 2 == 0) {
            n = n/2 + 1;
            
        while (n != 1) {
            temp = temp -> next;
            n--;
        }
        return temp;

        } else {
            n = n/2;
        while (n != 0) {
            temp = temp -> next;
            n--;
        }
        return temp;
        }
        return 0;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solver;
    ListNode* middle = solver.middleNode(head);

    if (middle != nullptr) {
        std::cout << middle->val << std::endl;
    }

    return 0;
}