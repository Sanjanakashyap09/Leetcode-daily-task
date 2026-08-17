class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int minLenWindow= INT_MAX;   //store min len of valid subarray
        int currentSum=0;           //store sum of elem in current window size
        int low=0;       //left pointer
        int high=0;      //right pointer
        while (high<nums.size()){           //explore the all elem.
            currentSum += nums[high];        
            high++;                 
            while(currentSum >= target){

                int currentWindowSize= high-low; //Calculate the current window length
                minLenWindow= min(minLenWindow, currentWindowSize);
                currentSum -= nums[low];
                low++;
            }

        }
        return minLenWindow == INT_MAX ? 0: minLenWindow;   // Return 0 if no valid window exists
        
    }
};