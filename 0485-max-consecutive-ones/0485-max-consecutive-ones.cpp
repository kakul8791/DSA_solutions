class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left=0;
        int ans=0;
        for(int right=0;right<nums.size();right++){

            if(nums[right]!=1){
                left=right+1;
            }

            ans=max(ans,right-left+1);
        }
        return ans;
        
    }
};