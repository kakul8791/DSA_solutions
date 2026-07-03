class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int ans = INT_MIN;

        // Chhoti dimension ko pairs ke liye use karna better hota hai
        if (rows > cols) {
            vector<vector<int>> transposed(cols, vector<int>(rows));

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    transposed[j][i] = matrix[i][j];
                }
            }

            matrix = transposed;
            rows = matrix.size();
            cols = matrix[0].size();
        }

        // top row fix karo
        for (int top = 0; top < rows; top++) {
            vector<int> colSum(cols, 0);

            // bottom row expand karo
            for (int bottom = top; bottom < rows; bottom++) {

                // top se bottom tak har column ka sum
                for (int col = 0; col < cols; col++) {
                    colSum[col] += matrix[bottom][col];
                }

                /*
                   Ab colSum ek 1D array hai.
                   Isme maximum subarray sum find karo jo <= k ho.
                */
                set<int> prefixSums;
                prefixSums.insert(0);

                int prefix = 0;

                for (int sum : colSum) {
                    prefix += sum;

                    /*
                      Need:
                      prefix - oldPrefix <= k

                      oldPrefix >= prefix - k

                      lower_bound(prefix - k) first aisa oldPrefix deta hai
                      jo >= prefix-k ho.
                    */
                    auto it = prefixSums.lower_bound(prefix - k);

                    if (it != prefixSums.end()) {
                        ans = max(ans, prefix - *it);
                    }

                    prefixSums.insert(prefix);
                }
            }
        }

        return ans;
    }
};