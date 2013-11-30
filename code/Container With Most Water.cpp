class Solution {
public:
    int maxArea(vector<int> &height) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int ts = height.size();
        int i = 0, j = ts - 1;
        int res = 0;
        while(i < j)
        {
            res = std::max(res,(j-i)*std::min(height[j],height[i]));
            if (height[i] <= height[j]) ++i;
            else --j;
        }
        return res;
    }
};