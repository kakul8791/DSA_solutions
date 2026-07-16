class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int total = 0;

        int curMax = 0, maxSum = INT_MIN;
        int curMin = 0, minSum = INT_MAX;

        for (int x : nums) {

            total += x;

            curMax = max(x, curMax + x);
            maxSum = max(maxSum, curMax);

            curMin = min(x, curMin + x);
            minSum = min(minSum, curMin);
        }

        // All elements are negative
        if (maxSum < 0)
            return maxSum;

        return max(maxSum, total - minSum);
    }
};