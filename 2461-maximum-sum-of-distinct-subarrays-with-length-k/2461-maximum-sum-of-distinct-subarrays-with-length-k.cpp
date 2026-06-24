class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> freq;
        long long sum = 0;

        for(int i = 0; i < k; i++) {
            sum += nums[i];
            freq[nums[i]]++;
        }

        long long ans = 0;

        if(freq.size() == k)
            ans = sum;

        for(int i = k; i < nums.size(); i++) {

            sum += nums[i];
            freq[nums[i]]++;

            sum -= nums[i-k];
            freq[nums[i-k]]--;

            if(freq[nums[i-k]] == 0)
                freq.erase(nums[i-k]);

            if(freq.size() == k)
                ans = max(ans, sum);
        }

        return ans;
    }
};