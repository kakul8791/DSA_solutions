class Solution {
public:
    long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        if (b == 0)
            return 1;

        long long half = power(a, b / 2);
        long long ans = (half * half) % MOD;

        if (b % 2 == 1)
            ans = (ans * a) % MOD;

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long ans1 = power(5, even);
        long long ans2 = power(4, odd);

        return (ans1 * ans2) % MOD;
    }
};