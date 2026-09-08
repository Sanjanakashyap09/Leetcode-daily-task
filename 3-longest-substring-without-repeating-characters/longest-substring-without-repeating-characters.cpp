class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;

        int left = 0; // as left pointer
        int ans = 0;  // store max len.

        // remove char. until current one's becomes unique
        for (int right = 0; right < s.length(); right++) {
            while (st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }
            //add current char to the window
            st.insert(s[right]);
            ans= max(ans, right-left+1);  //update max len.
        }
        return ans;
    }
};