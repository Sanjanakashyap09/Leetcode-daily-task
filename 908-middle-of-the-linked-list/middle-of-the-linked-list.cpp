class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head; // slow pointer tends to move 1
        ListNode* fast = head; // moves 2
        while (fast != NULL &&
               fast->next != NULL) { // check if fast can move 2 steps
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // return slow, which points to the middle node
    }
};