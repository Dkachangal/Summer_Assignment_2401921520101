    #include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *temp = head;
        int m = 0;
        while (temp != NULL) {
            if (m > 10000) return true;
            m++;
            temp = temp -> next;
        }
        return false;
    }
};

int main() {
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    Solution solver;
    if (solver.hasCycle(head)) {
        std::cout << "Cycle detected" << std::endl;
    } else {
        std::cout << "No cycle detected" << std::endl;
    }

    return 0;
}