class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int n = nums.size();
        int prefixSum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                prefixSum += nums[i];
            } else {
                break;
            }
        }
        // store all nums in set
        int x = prefixSum;
        while (st.count(x)) {
            x++;
        }
        return x;
    }
};