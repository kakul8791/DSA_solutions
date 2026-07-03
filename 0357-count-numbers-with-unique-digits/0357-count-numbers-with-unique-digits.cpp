class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;

        int ans = 10;      // 0 to 9
        int unique = 9;    // 2-digit unique numbers: first digit choices
        int available = 9; // second digit ke liye choices

        while (n > 1 && available > 0) {
            unique = unique * available;
            ans += unique;

            available--;
            n--;
        }

        return ans;
    }
};