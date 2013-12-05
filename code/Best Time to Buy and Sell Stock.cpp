class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        int res = 0,curMin = prices[0];
        for (int i=1,ts=prices.size();i<ts;++i)
        {
            res = std::max(res,prices[i] - curMin);
            curMin = std::min(prices[i],curMin);
        }
        return res;
    }
};