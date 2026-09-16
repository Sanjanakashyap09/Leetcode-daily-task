class Solution {
public:
    // Since answer can become very large,
    // we take everything modulo 1e9 + 7.
    int M = 1e9 + 7;
    int dp[1001][1001]; // dp[k][i] = number of ways to make k segments

    int numberOfSets(int n, int k) {
        for (int i = 0; i <= n; i++) { // Calculate for 1, 2, 3... segments
            dp[0][i] = 1;
        }

        for (int k = 1; k <= n; k++) {
            vector<int> prevRowSum(n + 1,
                                   0); // Stores suffix sums of the previous row
            for (int x = n - 1; x >= 0; x--) {
                prevRowSum[x] = (prevRowSum[x + 1] + dp[k - 1][x]) % M;
            }
            // Calculate suffix sum from right to left
            for (int i = n - 1; i >= 0; i--) {
                int take = prevRowSum[i + 1];
                int skip = dp[k][i + 1] % M;
                dp[k][i] = (take + skip) % M;
            }
        }
        return dp[k][0]; // Number of ways to make k segments
    }
};