class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;
        int leftSum = 0, rightSum = 0;
        int leftBlank = 0, rightBlank = 0;

        // check for first half(Alice)---
        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                leftBlank++;
            else
                leftSum += (num[i] - '0');
        }

        // check second half(Bob)---
        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                rightBlank++;
            else
                rightSum += (num[i] - '0');
        }

        // check balance possibility---
        int diff = leftSum - rightSum;
        int BlankDiff = leftBlank - rightBlank;

        return (diff * 2 != (rightBlank - leftBlank) * 9);
    }
};