class Solution {
public:
void func(int index, vector<int>&nums,int target, vector<int>&ds,vector<vector<int>>&ans){
    if(index==nums.size()){
        if(target==0){
            ans.push_back(ds);
            
        }
        return;
    }
    if(nums[index]<=target){
        ds.push_back(nums[index]);
        func(index,nums,target-nums[index],ds,ans);
        ds.pop_back();
    }

    func(index+1,nums,target,ds,ans);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        func(0,nums,target,ds,ans);
        return ans;
        
    }
};