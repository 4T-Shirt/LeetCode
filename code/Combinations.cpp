vector< vector<int> > res;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        res.clear();
        vector<int> ans;
        ans.clear();
        findComb(n,k,1,ans);
        return res;
    }
    void findComb(int n,int k,int num,vector<int> ans)
    {
    	if (num>n || ans.size()>=k)
    	{
    		if(ans.size() >= k)
    			res.push_back(ans);
    		return ;
    	}
    	else
    	{
    		for (int i=num;i<=n;++i)
    		{
    		    if ((n-i)+ans.size()+1 < k)
    		        break;
    			ans.push_back(i);
    			findComb(n,k,i+1,ans);
    			ans.pop_back();
    		}
    	}
    }
};