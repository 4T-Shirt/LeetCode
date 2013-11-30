/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
    	vector<int> level;
    	if (root == NULL)	return res;
    	queue<pair<TreeNode *,int> > myqueue;
    	myqueue.push(std::make_pair(root,1));
    	int preHei = 1;
    	pair<TreeNode *,int> mypair;
    	while(!myqueue.empty())
    	{
    		mypair = myqueue.front();
    		myqueue.pop();
    		if (mypair.second != preHei)
    		{
    			res.push_back(level);
    			level.clear();		
    			preHei = mypair.second;
    		}
    		level.push_back(mypair.first->val);
    		if (mypair.first->left !=NULL)
    			myqueue.push(make_pair(mypair.first->left,mypair.second + 1));
    		if (mypair.first->right !=NULL)
    			myqueue.push(make_pair(mypair.first->right,mypair.second + 1));
    	}
    	res.push_back(level);
    	reverse(res.begin(),res.end());
    	return res;
    }
};