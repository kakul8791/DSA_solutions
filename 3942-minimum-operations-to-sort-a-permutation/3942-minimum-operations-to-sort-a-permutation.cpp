
class Solution {
public:
    int getRotation(vector<int>& a) {
        int n = a.size();
        int k = -1;

        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                k = i;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (a[(k + i) % n] != i) {
                return -1;
            }
        }

        return k;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Case 1: Only rotations are needed.
        int k1 = getRotation(nums);
        int ans = INT_MAX;

        if (k1 != -1) {
            ans = min(k1, n - k1 + 2);
        }

        // Case 2: Reverse first, then rotate.
        vector<int> rev = nums;
        reverse(rev.begin(), rev.end());

        int k2 = getRotation(rev);

        if (k2 != -1) {
            ans = min(ans, min(k2 + 1, n - k2 + 1));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
