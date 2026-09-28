class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == NULL || left == right) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        // Move prev to the node just before 'left'
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // curr is the first node that we need to reverse
        ListNode* curr = prev->next;

        // Reverse the part from left to right
        for (int i = 0; i < right - left; i++) {

            ListNode* next = curr->next;

            curr->next = next->next;

            next->next = prev->next;

            prev->next = next;
        }

        return dummy->next;
    }
};