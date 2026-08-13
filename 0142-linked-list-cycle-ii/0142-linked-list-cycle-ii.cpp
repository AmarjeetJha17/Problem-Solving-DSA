/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slowPtr = head;
        ListNode *fastPtr = head;

        while (fastPtr != nullptr && fastPtr->next != nullptr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if (fastPtr == slowPtr) {
                slowPtr = head;
                while (fastPtr != slowPtr) {
                    slowPtr = slowPtr->next;
                    fastPtr = fastPtr->next;
                }
                return slowPtr;
            }
        }
        return nullptr;
    }
};