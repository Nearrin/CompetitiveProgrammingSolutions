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
class Solution {
public:
    int dfs(TreeNode*root,int d){
        if(!root)
            return 0;
        int sr=dfs(root->right,d);
        int sl=dfs(root->left,d+root->val+sr);
        int s=sl+sr+root->val;
        root->val+=d+sr;
        return s;
    }
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root,0);
        return root;
    }
};
