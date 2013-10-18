class Solution {
public:
    bool isLegal(string str,int s,int len)
    {
        int res = 0;
        for (int i=0;i<len;i++)
            res = res*10 + (str[s+i]-'0');
        if (len>1 && str[s]=='0')
            return false;
        if (res>=0 && res<256)
            return true;
        return false;
    }
    vector<string> restoreIpAddresses(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = s.length();
        vector<string> res;
        string tmpStr;
        int pos[4];
        for (int i=1;i<=3; ++i)
        {
            pos[0] = 0; pos[1] = pos[0] + i;
            if (pos[1]>len || !isLegal(s,pos[0],i))   continue;
            for (int j=1;j<=3;++j)
            {
                pos[2] = pos[1] + j;
                if (pos[2]>len || !isLegal(s,pos[1],j)) continue;
                for (int k=1;k<=3;++k)
                {
                    pos[3] = pos[2] + k;
                    if (pos[3]>len || !isLegal(s,pos[2],k)) continue;
                    if (pos[3]>=len || !isLegal(s,pos[3],len-pos[3])) continue;
                    tmpStr = s;
                    tmpStr.insert(pos[3],1,'.');
                    tmpStr.insert(pos[2],1,'.');
                    tmpStr.insert(pos[1],1,'.');
                    res.push_back(tmpStr);
                }
            }
        }
        return res;
    }
};