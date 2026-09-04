class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();    //size of num array
        vector<int> minFromIndex(n);     //create vector to store min el. from index i to n

        int minEl= INT_MAX;           
        for(int i=n-1; i>=0; i--){    // Build suffix minimum array
            minEl= min(minEl, nums[i]);   // Keep track of minimum element seen so far
            minFromIndex[i]= minEl;      // Store minimum from i to n-1
        }
        int maxEl= INT_MIN;
        for(int i=0; i<n; i++){    // Traverse from left to right
            maxEl= max(maxEl, nums[i]);     // Maximum element from 0 to i

            if(maxEl-minFromIndex[i]<=k)     // Check if current index is stable or not
            return i;
        }
        return -1;
        
    }
};