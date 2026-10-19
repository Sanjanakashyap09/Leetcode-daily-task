class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next || k==0)  // empty list, single node, or no rotation needed
            return head;

        int L = 1;   // length starts from head
        ListNode* tail = head;

        while(tail->next != NULL){
            tail = tail->next;
            L++;   // increment length
        }

        k = k % L;   // remove extra rotations

        if(k == 0){  // rotation has no effect
            return head;
        }

        // circular connect
        tail->next = head;   // make list circular

        int remain = L - k;   // position of new tail

        ListNode* newTail = head;   // find new tail
        for(int c = 1; c < remain; c++){
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;

        newTail->next = NULL;

        return newHead;
    }
};