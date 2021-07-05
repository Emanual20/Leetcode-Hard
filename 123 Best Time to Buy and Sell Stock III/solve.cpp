class Solution {
public:
    // int dfs(vector<int>& prices, int left){
    //     if(left >= prices.size()) return 0;
    //     int stand = prices[left];
    //     int ans = 0, now_ans = 0;
    //     for(int i = left + 1; i < prices.size(); i++){
    //         ans = max(ans, prices[i] - stand);
    //         stand = min(stand, prices[i]);
    //         if(i + 1 >= prices.size()) {
    //             now_ans = max(now_ans, ans);
    //             continue;
    //         }
    //         int in_stand = prices[i+1], in_ans = 0;
    //         for(int j = i + 2; j < prices.size(); j++){
    //             in_ans = max(in_ans, prices[j] - in_stand);
    //             in_stand = min(in_stand, prices[j]);
    //         }
    //         now_ans = max(now_ans, ans + in_ans);
    //     }
    //     return now_ans;
    // }
    // int maxProfit(vector<int>& prices) {
    //     return dfs(prices, 0);
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};