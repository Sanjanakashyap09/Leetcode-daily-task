class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();       
        vector<int>arr1, arr2;      //separate arr for individual storage

        arr1.push_back(nums[0]);    //push 0th elem. in arr1
        arr2.push_back(nums[1]);    //next one in arr2

        for(int i=2; i<n; i++){     //Traverse remaining elements
            if(arr1.back()>arr2.back())arr1.push_back(nums[i]);    //apply condition for last element otr compare them
            else arr2.push_back(nums[i]);    //if condition  not met then push the element in arr2
        }
        
        //create the result type vector to update final ans or push elem. of both on that or return final ans---
        vector<int>result;     
        for(int x: arr1){        
            result.push_back(x);
        }
        for(int x: arr2){        
            result.push_back(x);
        }
        return result;


        
    }
};