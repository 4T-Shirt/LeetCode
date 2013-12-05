class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end)   return 1;
        unordered_set<string> add;
        int level1 = 0, level2 = 0;
        queue<string> myqueue;myqueue.push(start);level1 ++ ;
        int res = 1;
        while (!myqueue.empty())
        {
            string mystr = myqueue.front();myqueue.pop();--level1;
            for (int i=0;i<mystr.length();++i)
            {
                string tmp = mystr;
                for (int j=0;j<26;j++)
                {
                    if ((j+'a') != tmp[i])
                    {
                        tmp[i] = 'a' + j;
                        if (tmp == end) return res + 1;
                        if(add.find(tmp)==add.end() && dict.find(tmp)!=dict.end())
                        {
                            add.insert(tmp);
                            myqueue.push(tmp);
                            ++level2;
                        }
                    }
                }
            }
            if (level1 == 0)
            {
                ++res ;
                level1 = level2;
                level2 = 0;
            }
        }
        return 0;
    }
};