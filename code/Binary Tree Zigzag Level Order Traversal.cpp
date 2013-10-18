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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > res;
        vector<int> tmp;
        TreeNode *p;
        if (root == NULL)   return res;
        
        int cnt[2] = {0,0};
        int flag = 0;
        
        queue<TreeNode *> myque;
        myque.push(root); cnt[0] = 1;
        while(!myque.empty())
        {
            p = myque.front();  myque.pop();
            if (p->left != NULL) {myque.push(p->left); cnt[1-flag]++;}
            if (p->right != NULL) {myque.push(p->right); cnt[1-flag]++;}
            if (flag == 0)  tmp.push_back(p->val);
            else    tmp.insert(tmp.begin(),p->val);
            cnt[flag] -- ;
            if (cnt[flag] <= 0)
            {
                flag = 1 - flag;
                res.push_back(tmp);
                tmp.clear();
            }
        }
        return res;
    }
};