class Solution {
public:
void findCombination(int index,int target,vector<int>ds,vector<vector<int>>&ans,vector<int>&arr){
    int n=arr.size();
    if(index==n){
        if(target==0){
            ans.push_back(ds);
            
        }
        return;
    }
    if(arr[index]<=target){
        ds.push_back(arr[index]);
        findCombination(index,target-arr[index],ds,ans,arr);
        ds.pop_back();
        
    }
    findCombination(index+1,target,ds,ans,arr);
    
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        findCombination(0,target,ds,ans,candidates);
        return ans;

        
    }
};