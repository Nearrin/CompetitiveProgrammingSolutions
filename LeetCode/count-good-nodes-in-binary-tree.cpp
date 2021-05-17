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
    int goodNodes(TreeNode* root,int mx=-(~0u>>1)) {
        mx=max(mx,root->val);
        int ans=0;
        if(root->val==mx)
            ++ans;
        if(root->left)ans+=goodNodes(root->left,mx);
        if(root->right)ans+=goodNodes(root->right,mx);
        return ans;
    }
};
