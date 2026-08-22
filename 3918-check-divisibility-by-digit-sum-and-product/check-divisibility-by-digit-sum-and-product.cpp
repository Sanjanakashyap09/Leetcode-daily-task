class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int temp = n;

        while (temp > 0) {
            int digit = temp % 10; // last digit
            sum += digit;       // add to sum
            product *= digit;   // add to product
            temp/= 10;            // remove last digit
        }
        int finalValue = sum + product; // final value to check both sum
        return (n % finalValue == 0);
    }
};