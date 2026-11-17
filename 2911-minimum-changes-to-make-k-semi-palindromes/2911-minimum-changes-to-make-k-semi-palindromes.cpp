
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        // Step 1: Calculate cost of every substring
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;

                    for (int i = 0; i < d; i++) {
                        int left = l + i;
                        int right = l + i + ((len - 1 - i) / d) * d;

                        while (left < right) {
                            if (s[left] != s[right]) {
                                changes++;
                            }

                            left += d;
                            right -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        // Step 2: DP
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));

        dp[0][0] = 0;

        for (int j = 1; j <= k; j++) {
            for (int i = 2 * j; i <= n; i++) {
                for (int p = 2 * (j - 1); p <= i - 2; p++) {

                    if (dp[j - 1][p] == INF)
                        continue;

                    dp[j][i] = min(
                        dp[j][i],
                        dp[j - 1][p] + cost[p][i - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
