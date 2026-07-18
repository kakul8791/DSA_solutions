class Solution {
public:
    int findGCD(vector<int>& nums) {

        int mini = nums[0];
        int maxi = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        return __gcd(mini, maxi);
    }
};