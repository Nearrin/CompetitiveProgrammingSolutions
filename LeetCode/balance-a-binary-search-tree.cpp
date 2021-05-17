/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<TreeNode*>cache;
void dfs(TreeNode*u){
    if(u){
        dfs(u->left);
        cache.push_back(u);
        dfs(u->right);
    }
}
TreeNode*build(int l,int r){
    if(l==r){
        cache[l]->left=cache[l]->right=0;
        return cache[l];
    }else if(l+1==r){
        cache[l]->left=0;
        cache[l]->right=build(r,r);
        return cache[l];
    }else{
        int m=(l+r)/2;
        cache[m]->left=build(l,m-1);
        cache[m]->right=build(m+1,r);
        return cache[m];
    }
}
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        cache.clear();
        dfs(root);
        return build(0,cache.size()-1);
    }
};
