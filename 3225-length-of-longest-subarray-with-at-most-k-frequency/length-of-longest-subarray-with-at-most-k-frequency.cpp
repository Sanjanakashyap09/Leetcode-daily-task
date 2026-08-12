class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int>freq;
        int n = nums.size();
        int left = 0; // left ptr to start from left always
        int ans = 0;  // initialize sum is 0

        for (int right = 0; right < nums.size(); right++) { // check from right side or updtae their freq. at each step
            freq[nums[right]]++;

            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
       
    }
};