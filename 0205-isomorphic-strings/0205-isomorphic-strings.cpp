class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>map1(256,0);
        vector<int>map2(256,0);

        for(int i=0;i<s.size();i++){
            char a=s[i];
            char b=t[i];
            if(map1[a]!=map2[b]){
                return false;

            }
            map1[a]=i+1;
            map2[b]=i+1;
        }
        return true;
        
    }
};