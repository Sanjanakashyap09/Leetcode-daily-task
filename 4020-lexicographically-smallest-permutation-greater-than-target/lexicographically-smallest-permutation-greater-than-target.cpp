class Solution {
public:
    string result = "";

    bool solve(string& curr, vector<int>& count, string& target, int i, bool greater) {
        if (i == target.length()) {
            if (greater) {
                result = curr;   // store the answer
                return true;
            }
            return false;
        }

        // Shortcut: if already greater, fill rest with smallest letters
        if (greater) {
            for (int j = i; j < target.length(); j++) {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    while (count[ch-'a'] > 0) {
                        curr.push_back(ch);
                        count[ch-'a']--;
                    }
                }
            }
            result = curr;
            return true;
        }

        // Step 1: try equal letter
        if (count[target[i]-'a'] > 0) {
            curr.push_back(target[i]);
            count[target[i]-'a']--;
            if (solve(curr, count, target, i+1, greater)) return true;
            curr.pop_back();
            count[target[i]-'a']++;
        }

        // Step 2: try smallest letter strictly greater than target[i]
        for (char ch = target[i]+1; ch <= 'z'; ch++) {
            if (count[ch-'a'] > 0) {
                curr.push_back(ch);
                count[ch-'a']--;
                if (solve(curr, count, target, i+1, true)) return true;
                curr.pop_back();
                count[ch-'a']++;
            }
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);
        for (char &ch : s) count[ch-'a']++;

        string curr;
        solve(curr, count, target, 0, false);
        return result;
    }
};
