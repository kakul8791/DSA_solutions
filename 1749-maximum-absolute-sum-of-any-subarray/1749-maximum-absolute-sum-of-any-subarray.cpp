class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int curMax = 0;
        int curMin = 0;

        int maxSum = 0;
        int minSum = 0;

        for (int x : nums) {

            curMax = max(x, curMax + x);
            maxSum = max(maxSum, curMax);

            curMin = min(x, curMin + x);
            minSum = min(minSum, curMin);
        }

        return max(maxSum, abs(minSum));
    }
};