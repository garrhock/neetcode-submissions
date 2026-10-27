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
    void reorderList(ListNode* head) {
        /* Find halfway point*/

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next ){
            slow = slow->next;
            fast = fast->next->next;
        }

        /* Reverse second half */

        ListNode* curr = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        /* Put together */

        ListNode dummy(0);
        ListNode* tail = &dummy;
        ListNode* h1 = head;
        ListNode* h2 = prev;

        while(h1 && h2){
            tail->next = h1;
            h1 = h1->next;
            tail = tail->next;

            tail->next = h2;
            h2 = h2->next;
            tail = tail->next;
        }
        tail->next = h1 ? h1 : h2;
    }
};
