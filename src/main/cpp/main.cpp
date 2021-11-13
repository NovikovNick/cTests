#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val);
};

ListNode *generateList(int32_t arr[], int32_t size);

std::string toString(ListNode *head);

int main() {

    Solution sol;
    int32_t arr[] = {6, 2, 3, 6, 6, 4, 5, 6};
    ListNode *list = generateList(arr, 6);
    std::cout << "generated: " << toString(list);

    sol.removeElements(list, 6);
    std::cout << "removed  : " << toString(list);

    return 0;
}

/* SOLUTION */

ListNode *Solution::removeElements(ListNode *head, int val) {

    ListNode dummy = ListNode(-1, head);
    ListNode *cursor = &dummy;
    while (cursor->next != nullptr) {
        ListNode *next = cursor->next;
        if (next->val == val) {
            cursor->next = next->next;
        } else {
            cursor = cursor->next;
        }
    }
    return dummy.next;
}


/* CONVENIENCE */

ListNode *generateList(int32_t arr[], int32_t size) {

    ListNode dummy = ListNode();
    ListNode *cursor = &dummy;
    for (int i = 0; i < size; ++i) {
        cursor = cursor->next = new ListNode(arr[i]);
    }
    return dummy.next;
}

std::string toString(ListNode *head) {
    std::string res = "";
    while (head != nullptr) {
        res += std::to_string(head->val) + "\t";
        head = head->next;
    }
    return res + "\n";;
}
