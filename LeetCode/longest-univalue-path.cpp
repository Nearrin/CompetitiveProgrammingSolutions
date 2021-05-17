/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode*u,int&ans){
        int d=0;
        int tmp1=-1;
        if(u->left){
            tmp1=dfs(u->left,ans);
            if(u->left->val==u->val)d=max(d,tmp1+1);
            else tmp1=-1;
        }
        int tmp2=-1;
        if(u->right){
            tmp2=dfs(u->right,ans);
            if(u->right->val==u->val)d=max(d,tmp2+1);
            else tmp2=-1;
        }
        if(tmp1!=-1&&tmp2!=-1){
            ans=max(ans,tmp1+tmp2+2);
        }
        ans=max(ans,d);
        return d;
    }
    int longestUnivaluePath(TreeNode* root) {
        int ans=0;
        if(!root)return 0;
        dfs(root,ans);
        return ans;
    }
};
