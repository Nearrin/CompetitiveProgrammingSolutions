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
    int closestValue(TreeNode* root, double target) {
        int ans=root->val;
        if(root->left&&ans>target){
            int t=closestValue(root->left,target);
            if(abs(t-target)<abs(target-ans))ans=t;
        }
        if(root->right&&root->val<target){
            int t=closestValue(root->right,target);
            if(abs(t-target)<abs(target-ans))ans=t;
        }
        return ans;
    }
};
