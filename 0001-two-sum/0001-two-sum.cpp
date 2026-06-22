class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]=i;

        }
        for(int i=0;i<nums.size();i++){
            int compliment=target-nums[i];
            if(hash.count(compliment) && hash[compliment]!=i){
                return {i,hash[compliment]};
            }
        }
        return {};
    }
};