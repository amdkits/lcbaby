// Last updated: 5/8/2026, 6:38:06 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;

        int len{1};
        ListNode* dummy{head};

        while (dummy->next) {
            dummy = dummy->next;
            len++;
        }

        int position{k % len};

        if (!position)
            return head;

        ListNode* curr{head};

        for (int i{0}; i < len - position - 1; i++)
            curr = curr->next;

        ListNode* hed = curr->next;
        curr->next = nullptr;
        dummy->next = head;

        return hed;
    }
};