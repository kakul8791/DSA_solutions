class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min_ele = *min_element(nums.begin(),nums.end());
        int max_ele = *max_element(nums.begin(),nums.end());
        unordered_set<int>st(nums.begin(),nums.end());
        vector<int>missing;

        for(int i=min_ele+1;i<max_ele;i++){
            if(st.find(i)==st.end()){
                missing.push_back(i);
            }
        }
        return missing;
        
    }
};