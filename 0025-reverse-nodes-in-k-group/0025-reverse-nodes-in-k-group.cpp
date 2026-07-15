class Solution {
public:

    ListNode* getkth(ListNode* curr, int k) {

        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }

        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while (true) {

            ListNode* kth = getkth(groupPrev, k);

            if (kth == NULL)
                break;

            ListNode* groupnext = kth->next;

            // Reverse
            ListNode* prev = groupnext;
            ListNode* curr = groupPrev->next;   // ✅ FIX

            while (curr != groupnext) {

                ListNode* temp = curr->next;

                curr->next = prev;

                prev = curr;

                curr = temp;
            }

            // Reconnect
            ListNode* temp = groupPrev->next;

            groupPrev->next = kth;              // ✅ FIX

            groupPrev = temp;
        }

        return dummy->next;
    }
};