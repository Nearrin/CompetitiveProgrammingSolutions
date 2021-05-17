/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int dfs(TreeNode*&x,int l,int s){
    int mxd;
    if(!x->left&&!x->right)
        mxd=0;
    else{
        mxd=numeric_limits<int>::min();
        if(x->left){
            int tmp=dfs(x->left,l,s+x->val);
            mxd=max(tmp,mxd);
        }
        if(x->right){
            int tmp=dfs(x->right,l,s+x->val);
            mxd=max(tmp,mxd);
        }
    }
    mxd+=x->val;
    if(mxd+s<l)x=0;
    return mxd;
}
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        dfs(root,limit,0);
        return root;
    }
};
