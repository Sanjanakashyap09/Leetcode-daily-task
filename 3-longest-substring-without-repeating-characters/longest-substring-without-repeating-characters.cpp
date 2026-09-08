class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;  //create set to store unique elem.

        int left = 0; // as left pointer
        int ans = 0;  // to store max len. found

        //remove char. until current one's becomes unique
        for (int right = 0; right < s.length(); right++) {
            while (st.find(s[right]) != st.end()) {   //for dupe's check
                st.erase(s[left]);    //to remove dupe's
                left++;   
            }
            //add current char to the window
            st.insert(s[right]);
            ans= max(ans, right-left+1);  //update max len.
        }
        return ans;
    }
};