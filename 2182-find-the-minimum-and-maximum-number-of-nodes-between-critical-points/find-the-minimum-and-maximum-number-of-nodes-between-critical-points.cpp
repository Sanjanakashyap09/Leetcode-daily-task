class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 1; // node index
        int firstCritical = -1, lastCritical = -1, prevCritical = -1;
        int minDist = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next) {
            int valPrev = prev->val;
            int valCurr = curr->val;
            int valNext = curr->next->val;

            // Check local maxima/minima
            if ((valCurr > valPrev && valCurr > valNext) ||
                (valCurr < valPrev && valCurr < valNext)) {
                
                if (firstCritical == -1) firstCritical = idx;
                else {
                    minDist = min(minDist, idx - prevCritical);
                    lastCritical = idx;
                }
                prevCritical = idx;
            }

            prev = curr;
            curr = curr->next;
            idx++;
        }

        if (lastCritical == -1) return {-1, -1};
        return {minDist, lastCritical - firstCritical};
    }
};
