class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
  	int len = S.length();
	int h = L.size(), w = L[0].size();
	map<string, int> words;
	map<string,int> cur;
	for (int i=0;i<h;++i)
		++words[L[i]];
	vector<int> res;
	if (h <= 0)	return res;
	for(int i=0;i<=len-h*w;++i)
	{
		cur.clear();
		int j=0;
		for (;j<h;j++)
		{
			string str = S.substr(i+j*w,w);
			if (words.find(str) == words.end())
				break;
			++cur[str];
			if(cur[str] > words[str])
				break;
		}
		if (j == h)	res.push_back(i);
	}
	return res;
    }
};

