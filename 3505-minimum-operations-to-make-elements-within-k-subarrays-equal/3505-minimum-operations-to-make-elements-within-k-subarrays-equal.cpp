class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n - x + 1);

        multiset<int> left, right;
        long long sumLeft = 0, sumRight = 0;

        auto rebalance = [&]() {
            // Keep left with either the same size as right,
            // or one extra element.
            while (left.size() > right.size() + 1) {
                int val = *left.rbegin();
                left.erase(prev(left.end()));
                sumLeft -= val;

                right.insert(val);
                sumRight += val;
            }

            while (left.size() < right.size()) {
                int val = *right.begin();
                right.erase(right.begin());
                sumRight -= val;

                left.insert(val);
                sumLeft += val;
            }

            // Restore ordering: every left value <= every right value.
            while (!left.empty() && !right.empty() &&
                   *left.rbegin() > *right.begin()) {
                int a = *left.rbegin();
                int b = *right.begin();

                left.erase(prev(left.end()));
                right.erase(right.begin());

                sumLeft += b - a;
                sumRight += a - b;

                left.insert(b);
                right.insert(a);
            }
        };

        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumLeft += val;
            } else {
                right.insert(val);
                sumRight += val;
            }

            rebalance();
        };

        auto remove = [&](int val) {
            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                sumLeft -= val;
            } else {
                it = right.find(val);
                right.erase(it);
                sumRight -= val;
            }

            rebalance();
        };

        // Calculate the cost of every window of length x.
        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                long long median = *left.rbegin();

                cost[i - x + 1] =
                    median * (long long)left.size() - sumLeft +
                    sumRight - median * (long long)right.size();
            }
        }

        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, INF)
        );

        // Zero windows cost zero, regardless of the prefix length.
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = j * x; i <= n; i++) {
                // Skip nums[i - 1].
                dp[j][i] = dp[j][i - 1];

                // Select the window [i - x, i - 1].
                int start = i - x;

                if (dp[j - 1][start] != INF) {
                    dp[j][i] = min(
                        dp[j][i],
                        dp[j - 1][start] + cost[start]
                    );
                }
            }
        }

        return dp[k][n];
    }
};