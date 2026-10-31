class Solution {
public:
    const int MOD = 1e9 + 7;

    int m, n;
    vector<vector<int>> grid;
    vector<vector<vector<int>>> memo;

    // dir = 0: right
    // dir = 1: down
    pair<int, int> resolve(int r, int c, int dir) {
        int nr = r + (dir == 1);
        int nc = c + (dir == 0);

        // Out of bounds
        if (nr >= m || nc >= n)
            return {-1, -1};

        // Empty cell: robot stops here
        if (grid[nr][nc] == 0)
            return {nr, nc};

        // Mirror: change direction and continue
        return resolve(nr, nc, 1 - dir);
    }

    int uniquePaths(vector<vector<int>>& input) {
        grid = input;
        m = grid.size();
        n = grid[0].size();

        vector<vector<long long>> dp(
            m, vector<long long>(n, 0)
        );

        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dp[i][j] == 0)
                    continue;

                // Try moving right
                auto [r1, c1] = resolve(i, j, 0);

                if (r1 != -1) {
                    dp[r1][c1] =
                        (dp[r1][c1] + dp[i][j]) % MOD;
                }

                // Try moving down
                auto [r2, c2] = resolve(i, j, 1);

                if (r2 != -1) {
                    dp[r2][c2] =
                        (dp[r2][c2] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};