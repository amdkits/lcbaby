// Last updated: 5/8/2026, 6:37:24 PM
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
    ListNode* reverseList(ListNode* head) {
        ListNode* bruh = head;
        ListNode* prev = nullptr;

        while (bruh != nullptr) {
            ListNode* temp = bruh->next;
            bruh->next = prev;
            prev = bruh;
            bruh = temp;
        }
        return prev;
    }
};