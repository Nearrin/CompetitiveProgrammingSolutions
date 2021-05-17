/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans=0;
pair<int,int>dp(TreeNode*u){
    if(!u->left&&!u->right){
        pair<int,int> tmp= make_pair(0,0);
        ans=max(ans,tmp.first);
        ans=max(ans,tmp.second);
        return tmp;
    }else if(!u->left){
        pair<int,int> tmp= make_pair(0,dp(u->right).first+1);
        ans=max(ans,tmp.first);
        ans=max(ans,tmp.second);
        return tmp;
    }else if(!u->right){
        pair<int,int> tmp= make_pair(dp(u->left).second+1,0);
        ans=max(ans,tmp.first);
        ans=max(ans,tmp.second);
        return tmp;
    }else{
        pair<int,int> tmp= make_pair(dp(u->left).second+1,dp(u->right).first+1);
        ans=max(ans,tmp.first);
        ans=max(ans,tmp.second);
        return tmp;
    }
}
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        ans=0;
        if(!root)return 0;
        dp(root);
        return ans;
    }
};
