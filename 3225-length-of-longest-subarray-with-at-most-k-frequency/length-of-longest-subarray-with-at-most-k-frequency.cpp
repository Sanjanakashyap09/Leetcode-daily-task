class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int>freq;     //hash map to store freq count

        int n = nums.size();
        
        int left=0;         //start from left
        int ans = 0;        //longest subarray len till now

        for(int right=0; right<nums.size(); right++){    //for loop to traverse each element or thier upcoming freq.
            freq[nums[right]]++;         //update the freq. count in map

            while(freq[nums[right]]>k){        //when count of freq. exceed the kth limit then reduce the left size or update under the map
                freq[nums[left]]--;         
                left++;
            }

            ans = max(ans, right-left+1);   //update longest valid subarray length

        }
        return ans;     //final count
        
    }
};