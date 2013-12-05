class Solution {
public:
    string alph[10];
    Solution()
    {
        alph[0] = alph[1] = "";
        alph[2] = "abc";alph[3] = "def";alph[4] = "ghi";alph[5] = "jkl";alph[6] = "mno";alph[7] = "pqrs";alph[8] = "tuv";alph[9] = "wxyz";
    }
    void getStr(string digits,int len,int idx,string curStr,vector<string> &vstr)
    {
        if (idx>=len)   vstr.push_back(curStr);
        else
        {
            string tstr = "";
            int tlen = alph[digits[idx] - '0'].length();
            for (int i=0;i<tlen;++i)
                getStr(digits,len,idx+1,curStr + alph[digits[idx] - '0'][i],vstr);
        }
    }
    vector<string> letterCombinations(string digits) {
        //check other's solution after Accepted
        vector<string> vstr;
        vstr.clear();
        string emstr = "";
        if (digits.length() == 0)   {vstr.push_back(emstr);return vstr;}
        for (int i=0;i<digits.length();++i)
            if (!(digits[i]>='2' && digits[i]<='9'))
            {
                vstr.push_back(emstr);                
                return vstr;
            }
        getStr(digits,digits.length(),0,"",vstr);
        return vstr;
    }
};