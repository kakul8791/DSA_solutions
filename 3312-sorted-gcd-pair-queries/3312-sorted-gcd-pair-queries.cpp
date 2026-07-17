class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        // Frequency of each number
        vector<long long> freq(mx + 1, 0);

        for (int x : nums) {
            freq[x]++;
        }

        // exactGCD[d] = number of pairs having GCD exactly d
        vector<long long> exactGCD(mx + 1, 0);

        // Process from large to small
        for (int d = mx; d >= 1; d--) {

            long long divisible = 0;

            // Count numbers divisible by d
            for (int multiple = d; multiple <= mx; multiple += d) {
                divisible += freq[multiple];
            }

            // Total pairs where both numbers are divisible by d
            exactGCD[d] = divisible * (divisible - 1) / 2;

            // Remove pairs whose GCD is a larger multiple of d
            for (int multiple = 2 * d; multiple <= mx; multiple += d) {
                exactGCD[d] -= exactGCD[multiple];
            }
        }

        // Prefix count
        vector<long long> prefix(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {
            prefix[d] = prefix[d - 1] + exactGCD[d];
        }

        vector<int> answer;

        for (long long q : queries) {

            // First index where prefix[index] > q
            int gcdValue =
                upper_bound(prefix.begin(), prefix.end(), q)
                - prefix.begin();

            answer.push_back(gcdValue);
        }

        return answer;
    }
};