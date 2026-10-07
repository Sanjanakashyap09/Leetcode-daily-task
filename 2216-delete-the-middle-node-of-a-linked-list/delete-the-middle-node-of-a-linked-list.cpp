class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
       if(head==NULL ||head->next == NULL ){   //base case
        return NULL;
       } 
       //take two pointer: slow or fast
       ListNode* prevSlow= NULL;
       ListNode* slow = head;
       ListNode* fast= head;
       while(fast !=NULL && fast->next!= NULL){
        prevSlow= slow;
        slow= slow->next;  // move slow one step
        fast= fast->next->next;   // move fast two steps
       }
       prevSlow->next= slow->next;
       delete(slow);
       return head;
    }
};