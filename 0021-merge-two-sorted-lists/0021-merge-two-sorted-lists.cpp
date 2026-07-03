class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);          // temporary starting node
        ListNode* tail = &dummy;    // merged list ka last node

        while (list1 != nullptr && list2 != nullptr) {
            
            if (list1->val <= list2->val) {
                tail->next = list1;     // list1 wala smaller node attach
                list1 = list1->next;   // list1 aage move
            } 
            else {
                tail->next = list2;     // list2 wala smaller node attach
                list2 = list2->next;   // list2 aage move
            }

            tail = tail->next;          // merged list ka tail aage move
        }

        // ek list khatam ho gayi, dusri already sorted hai
        if (list1 != nullptr) {
            tail->next = list1;
        } 
        else {
            tail->next = list2;
        }

        return dummy.next;  // dummy khud fake node tha
    }
};