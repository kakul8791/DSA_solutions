class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        for(int shift=0;shift<s.size();shift++){
            int j=0;
            while(j<s.size() && s[(shift+j)%s.size()]==goal[j]){
                j++;
            }
            if(j==s.size()) return true;


        }
        return false;
        
    }
};