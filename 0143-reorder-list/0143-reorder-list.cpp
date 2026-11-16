class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode *slow = head, *fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;

        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode *a = head, *b = prev;

        while(b) {
            ListNode* x = a->next;
            ListNode* y = b->next;

            a->next = b;
            b->next = x;

            a = x;
            b = y;
        }
    }
};