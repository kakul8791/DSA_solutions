class Solution {
public:

    void solve(int n,string curr,int open,int close, vector<string>&ans){
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n){
            solve(n,curr+"(",open+1,close,ans);
        }
        if(open>close){
            solve(n,curr+")",open,close+1,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,"",0,0,ans);
        return ans;
    }
};