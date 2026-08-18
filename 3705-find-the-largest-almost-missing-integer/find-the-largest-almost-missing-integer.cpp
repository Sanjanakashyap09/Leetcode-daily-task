class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freq;     //to store freq count of all
        int n = nums.size();
        
        // iterate over all subarrays of size k starting at index i
        for (int i = 0; i+k <= n; i++) {      
            unordered_set<int> seen;      //put subarray of current elements      

            // traverse current subarray [i ... i+k-1]
            for (int j = i; j < i + k; j++) {    
                seen.insert(nums[j]);            
            }
            for (int x : seen) {         
                freq[x]++;
            }
        }

        int ans = -1;         //for safe return
        for (auto& p : freq) {
            if (p.second == 1) {
                ans = max(ans, p.first);
            }
        }
        return ans;
    }
};