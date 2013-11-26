class Solution {
public:
    int biSearch(int n)
    {
        long long tmp = 1LL;
        int low=0,high=n,mid=1;
        int res = 0;
        while(low<=high)
        {
            mid = (low + high)/2;
            tmp = mid * 1LL * mid;
            if (tmp < n)
            {
                res = mid;
                low = mid + 1;
            }
            else if (tmp > n)
                high = mid - 1;
            else
            {
                res = mid;
                break;
            }
        }
        return res;
    }
    int sqrt(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return biSearch(x);
    }
};