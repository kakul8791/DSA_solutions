class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int orignalSum=0;
        int actualSum=0;
        for(int i=0;i<=nums.size();i++){
            orignalSum+=i;
            
        }
        for(int i=0;i<nums.size();i++){
            actualSum+=nums[i];
        }

        return orignalSum-actualSum;

        
    }
};