class Solution {
public:
    vector<int> dp;         //dp array
    bool helper(int n) {

         //base case---if stones end teh player will loose the game     
        if (n == 0)        
            return false;
        //in case of already choosen tehn simply retrun it    
        if (dp[n] != -1)
            return dp[n];

        for (int i = 1; i * i <= n; i++) {    //try to remove every possible perfect sqr
            if (!helper(n - i * i))           //if opponent get loose then current will definitely won
                return dp[n] = true;
        }
        return dp[n] = false;           //current one will loose the game if not any winning move left
    }
    bool winnerSquareGame(int n) {

        dp.assign(n + 1, -1);
        return helper(n);
    }
};