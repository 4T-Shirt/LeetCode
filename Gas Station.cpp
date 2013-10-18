class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.  test
        int ts = gas.size();
        for (int i=0;i<ts;++i) cost[i] = gas[i] - cost[i];
        int sum = cost[0],cnt = 1,precnt = 0;
        while (precnt < ts)
        {
            if (sum>=0 && cnt-precnt>=ts)
                break;
                
            if (cost[precnt] <0)
            {
                sum -= cost[precnt++];
                sum += cost[cnt % ts];
                cnt ++;
                continue;
            }
            
            if (sum < 0)
            {
                sum -= cost[precnt++];
                sum += cost[cnt % ts];
                cnt ++;
            }
            else
            {
                sum += cost[cnt % ts];
                cnt ++;
            }
        }
        if (cnt-precnt>=ts && sum>=0)
            return precnt;
        return -1;
    }
};