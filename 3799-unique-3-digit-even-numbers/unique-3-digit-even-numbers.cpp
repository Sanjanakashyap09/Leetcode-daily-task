class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int n = digits.size();   //size of array
        set<int> st;    //store unique 3 digit no.

        //apply 3 differ loop to get unique possible 3 digit number
        for (int i = 0; i < n; i++) {   
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {

                    if (i == j || j == k || i == k)   //check the repetition condition to ensure use 3 differ indices
                        continue;

                    if (digits[i] == 0)  // first one can't be 0
                        continue;
                    if (digits[k] % 2 != 0) // last one must be even
                        continue;

                    int nums = digits[i] * 100 + digits[j] * 10 + digits[k];  //classic 3 digit formation

                    st.insert(nums);  ///at last insert in set
                }
            }
        }
        return st.size();  //or return final digit size
    }
};