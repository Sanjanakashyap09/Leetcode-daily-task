class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> memo;

    int dfs(int i, int M) {
        if (i >= n) return 0;                  // base case: no piles left
        if (memo[i][M] != -1) return memo[i][M]; // already computed

        int best = 0;
        for (int X = 1; X <= 2*M && i+X <= n; X++) {
            // Alice takes X piles, Bob plays optimally afterwards
            best = max(best, suffix[i] - dfs(i+X, max(M, X)));
        }
        return memo[i][M] = best;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffix.assign(n+1, 0);
        memo.assign(n+1, vector<int>(n+1, -1));

        // build suffix sum array
        for (int i = n-1; i >= 0; i--) {
            suffix[i] = suffix[i+1] + piles[i];
        }

        return dfs(0, 1); // start from pile 0 with M=1
    }
};
