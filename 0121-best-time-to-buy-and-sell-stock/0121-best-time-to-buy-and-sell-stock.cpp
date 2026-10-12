class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuyPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            maxProfit = max(maxProfit, (prices[i] - bestBuyPrice));
            bestBuyPrice = min(bestBuyPrice, prices[i]);
        }
        return maxProfit;
    }
};