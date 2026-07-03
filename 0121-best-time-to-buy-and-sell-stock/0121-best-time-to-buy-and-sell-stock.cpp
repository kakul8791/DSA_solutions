class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            buyPrice = min(buyPrice, prices[i]);

            int profitToday = prices[i] - buyPrice;

            maxProfit = max(maxProfit, profitToday);
        }

        return maxProfit;
    }
};