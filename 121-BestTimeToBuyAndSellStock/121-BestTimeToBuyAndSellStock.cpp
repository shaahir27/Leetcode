// Last updated: 8/3/2026, 11:37:26 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int best_buy = prices[0];
        int profit = 0;

        for(int i=1; i<n; i++){

            if(best_buy < prices[i]){
                profit = max(profit, prices[i] - best_buy);
            }

            best_buy = min(best_buy, prices[i]);
        }   

        return profit;
    }
};