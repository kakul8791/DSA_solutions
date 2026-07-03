class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);  // har character ka last index
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];

            // duplicate current window ke andar mila
            if (last[ch] >= left) {
                left = last[ch] + 1;
            }

            last[ch] = right;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};