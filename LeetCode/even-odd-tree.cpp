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
    bool isEvenOddTree(TreeNode* root) {
        vector<TreeNode*>q,nq;
        q.push_back(root);
        int cur=1;
        while(q.size()){
            nq.clear();
            for(int i=1;i<q.size();++i){
                if(cur){
                    if(q[i-1]->val>=q[i]->val)return false;
                }else{
                    if(q[i-1]->val<=q[i]->val)return false;
                }
            }
            for(int i=0;i<q.size();++i){
                if(q[i]->val%2!=cur)return false;
                if(q[i]->left)nq.push_back(q[i]->left);
                if(q[i]->right)nq.push_back(q[i]->right);
            }
            nq.swap(q);
            cur^=1;
        }
        return true;
    }
};
