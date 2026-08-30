class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();

        // ensure minIdx <= maxIdx
        if (minIdx > maxIdx)
            swap(minIdx, maxIdx);

        int option1 = maxIdx + 1;

        int option2 = n - minIdx;

        int option3 = (minIdx + 1) + (n - maxIdx);

        return min({option1, option2, option3});
    }
};
