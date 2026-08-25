class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> present(101, false); // since nums[i] <= 100
        for (int x : nums) present[x] = true;

        int multiple = k;
        while (true) {
            if (multiple > 100 || !present[multiple]) {
                return multiple; // first missing multiple
            }
            multiple += k;
        }
    }
};
