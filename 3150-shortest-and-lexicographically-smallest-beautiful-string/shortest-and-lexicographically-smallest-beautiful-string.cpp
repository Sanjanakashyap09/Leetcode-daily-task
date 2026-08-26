class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        for (int len = k; len <= n; len++) {   // check all lengths >= k
            string result = "";

            for (int start = 0; start <= n - len; start++) {
                string temp = s.substr(start, len);

                int ones = 0;
                for (char &ch : temp) {
                    ones += (ch == '1') ? 1 : 0;
                }

                if (ones == k) {
                    if (result.empty() || temp < result) {
                        result = temp;
                    }
                }
            }
            if (!result.empty()) {
                return result;   // return first valid shortest substring
            }
        }
        return ""; // if no substring found
    }
};
