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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        // Variables to store values of previous, current, and next nodes
        int prevVal= 0;
        int currVal=0;
        int nextVal=0;

        int minDist= INT_MAX;   // Minimum distance initialized to maximum possible
        int firstCriticalPos=0;;  // Position of the first critical point
        int prevCriticalPos=0;  // Position of the previous critical point

        int i=0;  // Index counter for nodes
        vector<int>result={-1,-1}; //if fewer than 2 critical points are found

        while(head!= NULL){    // Traverse the linked list
            prevVal= currVal;
            currVal= nextVal;
            nextVal=head->val;

            // Check if current node is a critical point
            // Condition: local minima OR local maxima
            if(prevVal!=0 && currVal!=0 && nextVal!= 0 && 
            ((prevVal>currVal && currVal<nextVal)||(prevVal<currVal && currVal>nextVal))){

                if(firstCriticalPos==0){
                    firstCriticalPos=i;
                }else{
                    minDist = min(minDist, i-prevCriticalPos);   // Update minimum distance 
                    result={minDist,i-firstCriticalPos};   // Update result
                }
                prevCriticalPos=i;   // Update previous critical point position
            }
            i++;
            head= head->next;
        }
        return result;
        
    }
};