class Solution {
public:
    void printsub(int index,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans){
        
            ans.push_back(ds);
           
        
        for(int i = index; i < nums.size(); i++) {

            // duplicate skip
            if(i > index && nums[i] == nums[i-1])
                continue;

            ds.push_back(nums[i]);

            printsub(i + 1, nums, ds, ans);

            ds.pop_back();
        }
    

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        vector<vector<int>>ans;
        printsub(0,nums,ds,ans);
        return ans;
        
    }
};