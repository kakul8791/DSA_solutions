class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        
        // End ki extra spaces hatao
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        
        int count = 0;
        
        // Last word ke characters count karo
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }
        
        return count;
    }
};