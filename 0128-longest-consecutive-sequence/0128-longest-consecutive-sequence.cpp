class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int num : st) {
            
            // num tabhi sequence ka starting point hai
            // jab num - 1 set mein nahi hai
            if (st.find(num - 1) == st.end()) {
                int currentNum = num;
                int length = 1;

                // consecutive numbers count karo
                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};