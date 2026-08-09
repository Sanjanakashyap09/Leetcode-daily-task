class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();        //len of piles
        vector<int>suffix(n+1, 0);    //total stones from i to end

        for(int i=n-1; i>=0; i--){
            suffix[i]= suffix[i+1]+piles[i];    // fill suffix sum array from right to left
        }
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));    //create dp table

        for(int i=n-1; i>=0; i--){        //outer loop to solve subproblem first
            for(int M=1; M<=n; M++){      //middle loop to chcek every possible value of M
                for(int X=1; X<=2*M && i+X<= n; X++){      //inner loop for Alice(total count of piles taken by Alice)
                    dp[i][M]= max(dp[i][M], suffix[i]- dp[i+X][max(M,X)]);
                }
            }
        }
        return dp[0][1];        //final max stone choosen by Alice
        
    }
};