class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Step 1: first and last position
        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';

            first[ch] = min(first[ch], i);
            last[ch] = i;
        }

        // Make and validate candidates
        vector<pair<int, int>> intervals;

        for (int c = 0; c < 26; c++) {

            if (last[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];

            bool valid = true;

            for (int j = l; j <= r; j++) {
                int ch = s[j] - 'a';

                if (first[ch] < l) {
                    valid = false;
                    break;
                }

                r = max(r, last[ch]);
            }

            if (valid) {
                intervals.push_back({l, r});
            }
        }

        // sort intervals
        sort(intervals.begin(), intervals.end(),
             [](auto& a, auto& b) {
                 return a.second < b.second;
             });

        // select non-overlapping intervals
        vector<string> ans;
        int prevEnd = -1;

        for (auto& interval : intervals) {
            int l = interval.first;
            int r = interval.second;

            if (l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }
        return ans;
    }
};