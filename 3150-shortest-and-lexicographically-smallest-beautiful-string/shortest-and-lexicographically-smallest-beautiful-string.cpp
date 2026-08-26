class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, ones = 0;
        string result = "";

        for (int right = 0; right < n; right++) {
            if (s[right] == '1') ones++;

            // shrink window until ones == k
            while (ones == k) {
                string temp = s.substr(left, right - left + 1);
                if (result.empty() || temp.size() < result.size() ||
                   (temp.size() == result.size() && temp < result)) {
                    result = temp;
                }
                // shrink from left to try smaller substring
                if (s[left] == '1') ones--;
                left++;
            }
        }
        return result;
    }
};
