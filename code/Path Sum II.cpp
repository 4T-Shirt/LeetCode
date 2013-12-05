/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 vector<vector<int> > res;
 
class Solution {
public:
    void cal(TreeNode *node,int curSum,vector<int> tv,int sum)
    {
        if(node->left==NULL && node->right==NULL)
        {
            if (curSum + node->val==sum)
            {
                tv.push_back(node->val);
                res.push_back(tv);
                tv.pop_back();
            }
        }
        else
        {
            tv.push_back(node->val);
            if(node->left != NULL)
                cal(node->left,curSum+node->val,tv,sum);
            if(node->right != NULL)
                cal(node->right,curSum+node->val,tv,sum);
            tv.pop_back();
        }
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        res.clear();
        if(root == NULL) return res;
        vector<int> tv;
        cal(root,0,tv,sum);
        return res;
    }
};
