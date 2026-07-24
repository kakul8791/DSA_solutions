class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> present(MAXX, false);

        for (int x : nums)
            present[x] = true;

        vector<int> vals;
        for (int i = 0; i < MAXX; i++)
            if (present[i]) vals.push_back(i);

        vector<bool> pairXor(MAXX, false);

        for (int a : vals) {
            for (int b : vals) {
                pairXor[a ^ b] = true;
            }
        }

        vector<bool> ans(MAXX, false);

        for (int x = 0; x < MAXX; x++) {
            if (!pairXor[x]) continue;
            for (int v : vals) {
                ans[x ^ v] = true;
            }
        }

        int cnt = 0;
        for (bool x : ans)
            if (x) cnt++;

        return cnt;
    }
};