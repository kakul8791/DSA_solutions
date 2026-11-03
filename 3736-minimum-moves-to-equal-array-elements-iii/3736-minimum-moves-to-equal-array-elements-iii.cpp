class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int max =* max_element(nums.begin(),nums.end());
        int count = 0;


        for(int num : nums){
            count += abs(max-num);

        }
        return count;
        
    }
};