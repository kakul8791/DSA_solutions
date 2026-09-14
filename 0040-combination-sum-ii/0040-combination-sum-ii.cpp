class Solution {
public:
    void findc(int index,vector<int>&nums,int target,vector<int>&ds,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<nums.size();i++){
            if(i>index&&nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            ds.push_back(nums[i]);
            findc(i+1,nums,target-nums[i],ds,ans);
        
            ds.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ds;
        vector<vector<int>>ans;
        findc(0,candidates,target,ds,ans);
        return ans;
        
    }
};