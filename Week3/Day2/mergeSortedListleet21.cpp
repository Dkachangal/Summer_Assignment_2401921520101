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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* newList = new ListNode();
        ListNode* newTraverse = newList;

        while (temp1 != NULL || temp2 != NULL) {
            int val1;
            int val2;
            if (temp1 != NULL) {
                val1 = temp1 -> val;
            }
            if (temp2 != NULL) {
                val2 = temp2 -> val;
            }
            if (temp1 != NULL && temp2 != NULL) {
                if (val1 > val2) {
                    ListNode* newNode = new ListNode(val2);
                    newTraverse -> next = newNode;
                    newTraverse = newTraverse -> next;
                    temp2 = temp2 -> next;
                } else {
                    ListNode* newNode = new ListNode(val1);
                    newTraverse -> next = newNode;
                    newTraverse = newTraverse -> next;
                    temp1 = temp1 -> next;
                }

            } else if (temp1 == NULL) {
                while (temp2 != NULL) {
                    val2 = temp2 -> val;
                    ListNode* newNode = new ListNode(val2);
                    newTraverse -> next = newNode;
                    newTraverse = newTraverse -> next;
                    temp2 = temp2 -> next;
                }

            } else if (temp2 == NULL){
                while (temp1 != NULL) {
                    val1 = temp1 -> val;
                    ListNode* newNode = new ListNode(val1);
                    newTraverse -> next = newNode;
                    newTraverse = newTraverse -> next;
                    temp1 = temp1 -> next;
                }
            }
        }
        return newList -> next;
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
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    std::cout << "List 1: ";
    printList(list1);
    std::cout << "List 2: ";
    printList(list2);

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    std::cout << "Merged List: ";
    printList(mergedList);

    return 0;
}