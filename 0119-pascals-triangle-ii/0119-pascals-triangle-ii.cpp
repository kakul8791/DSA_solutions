class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int> ans;

        long long value = 1;

        ans.push_back(1);

        for (int i = 1; i <= rowIndex; i++) {

            value = value * (rowIndex - i + 1);

            value = value / i;

            ans.push_back(value);
        }

        return ans;
    }
};