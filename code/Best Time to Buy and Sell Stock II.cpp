class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int ts = prices.size();
        if (ts == 0)    return 0;
        int res[2] = {0,-prices[0]};
        for (int i=1;i<ts;++i)
        {
            int tmp1 = res[0],tmp2 = res[1];
            if (prices[i]+res[1]>res[0])
                tmp1 = prices[i]+res[1];
            if (-prices[i]+res[0]>res[1])
                tmp2 = -prices[i]+res[0];
            res[0] = tmp1;
            res[1] = tmp2;
        }
        return max(res[0],res[1]);
    }
};