class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int i = 0; i + k <= n; i++) {
            unordered_set<int> seen;

            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }
            for (int x : seen) {
                freq[x]++;
            }
        }
        int ans = -1;
        for (auto& p : freq) {
            if (p.second == 1) {
                ans = max(ans, p.first);
            }
        }
        return ans;
    }
};