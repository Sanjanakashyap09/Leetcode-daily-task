class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXOR = 0;     //start from 0
        int n = nums.size();

        // calculate XOR of all elements
        for (int i = 0; i < n; i++) {
            totalXOR ^= nums[i];
        }

        // check cases
        if (totalXOR != 0) {
            return n;
        } else {
            bool allZero = true;
            for (int i = 0; i < n; i++) {
                if (nums[i] != 0) {
                    allZero = false;
                    break;
                }
            }
            if(allZero){
                return 0;
            }
            else {
                return n - 1;
            }
        }
    }
};