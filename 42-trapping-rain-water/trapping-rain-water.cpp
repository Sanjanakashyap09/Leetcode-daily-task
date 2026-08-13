class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        //to store lmax or rmax seperatley or compare them accordingly at ecah step
        vector<int>lmax(n, 0);
        vector<int>rmax(n, 0);

    //initialize first lmax and last rmax
            lmax[0] = height[0];    
        rmax[n-1] = height[n-1];

        for (int i = 1; i < n; i++) {       //start tarverseing from left or compare with lmax at each step
            lmax[i] = max(lmax[i - 1], height[i]);         //update lmax in vector
        }
        for (int i = n - 2; i >= 0; i--) {             //same for rmax or update it accordingly
            rmax[i] = max(rmax[i+1], height[i]);
        }
        int ans = 0;         //to store final ans
        for (int i = 0; i<n; i++) {            // iterate each index to calculate trapped water
            ans += min(lmax[i], rmax[i])-height[i]; //calculate final ans 
        }
        return ans;        //return total trapped water
    }
};