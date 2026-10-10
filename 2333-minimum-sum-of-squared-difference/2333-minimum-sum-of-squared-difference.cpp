
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<int> diff(n);
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
        }

        long long total = 0;
        for (int d : diff) total += d;

        if (k >= total) return 0;

        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long needed = 0;

            for (int d : diff) {
                if (d > mid) needed += d - mid;
            }

            if (needed <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        long long ans = 0;
        long long remaining = k;

        for (int d : diff) {
            if (d > low) {
                remaining -= d - low;
                d = low;
            }
            ans += 1LL * d * d;
        }

        // Use leftover operations to reduce differences
        // from low to low - 1.
        for (int i = 0; i < n && remaining > 0; i++) {
            if (diff[i] >= low && diff[i] > 0) {
                ans -= 2LL * low - 1;
                remaining--;
            }
        }

        return ans;
    }
};
