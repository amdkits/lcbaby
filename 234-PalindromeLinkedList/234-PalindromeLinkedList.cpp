// Last updated: 5/8/2026, 6:37:17 PM
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
    bool isPalindrome(ListNode* head) {
        vector<int> bro;

        while (head) {
            bro.push_back(head->val);
            head = head->next;
        }

        int left {0}, right {(int)bro.size() - 1};

        while (left < right) {
            if (bro[left] != bro[right])
            return false;
            left++; right--;
        }
        return true;
    }
};