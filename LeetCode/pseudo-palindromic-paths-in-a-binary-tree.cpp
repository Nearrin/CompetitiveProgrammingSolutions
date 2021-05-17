/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
int ans;
set<int>cur;
void dfs(TreeNode* root){
    int op;
    if(cur.count(root->val)){
        cur.erase(root->val);
        op=1;
    }else{
        cur.insert(root->val);
        op=0;
    }

    if(!root->left&&!root->right)
        ans+=cur.size()<=1;
    else{
        if(root->left)dfs(root->left);
        if(root->right)dfs(root->right);
    }
    
    if(op==1){
        cur.insert(root->val);
    }else{
        cur.erase(root->val);
    }
}
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        ans=0;
        dfs(root);
        return ans;
    }
};
