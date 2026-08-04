class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        // Store all elements in a hash set
        unordered_set<int> st(nums.begin(), nums.end());

        // Find minimum and maximum element
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> missing;

        // Check every number between min and max
        for (int i = minVal + 1; i < maxVal; i++) {

            // If number is not present, add it
            if (st.find(i) == st.end()) {
                missing.push_back(i);
            }
        }

        return missing;
    }
};