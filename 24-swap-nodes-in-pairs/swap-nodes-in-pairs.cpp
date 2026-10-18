class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)  //base case
        return head;

        //A= head
        //B= nead->next
        //C=head->next->next
        //A->B>C....
        ListNode* temp= head->next;
        head->next= swapPairs(head->next->next);
        temp->next=head;

        return temp;
        
    }
};