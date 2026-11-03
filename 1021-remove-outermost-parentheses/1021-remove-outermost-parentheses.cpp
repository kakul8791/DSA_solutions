class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        string ans = "";
        for(char c : s){
            if(c == '('){
                if(depth>0){
                    ans += c;
                }
                depth++;

            }
            else{
                depth--;
                if(depth>0){
                    ans += c;
                }
            }
        }
        return ans;
        
    }
};