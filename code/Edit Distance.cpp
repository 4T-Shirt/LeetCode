const int maxs = 502;
class Solution {
public:
    int minDistance(string word1, string word2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int lena = word1.length(),lenb=word2.length();
        int dp[maxs][maxs];
        memset(dp,0,sizeof(dp));
        for (int i=0;i<lena;++i)
            dp[i][lenb] = lena-i;
        for (int i=0;i<=lenb;++i)
            dp[lena][i] = lenb-i;
        for (int i=lena-1;i>=0;--i)
            for (int j=lenb-1;j>=0;--j)
                dp[i][j] = min(dp[i+1][j+1]+(word1[i]==word2[j]?0:1),1+min(dp[i][j+1],dp[i+1][j]));
        return dp[0][0];
    }
};