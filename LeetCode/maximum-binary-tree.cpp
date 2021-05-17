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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*>cur;
        for(int v:nums){
            TreeNode*x=new TreeNode(v);
            TreeNode*ch=0;
            while(cur.size()&&cur.back()->val<v){
                ch=cur.back();
                cur.pop_back();
            }
            x->left=ch;
            if(cur.size())cur.back()->right=x;
            cur.push_back(x);
        }
        return cur.front();
    }
};
