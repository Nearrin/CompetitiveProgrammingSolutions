/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct info{
    bool bst;
    long long sm,mx,mi,ans;
};
info check(TreeNode* u){
    info t;
    t.bst=false;
    t.ans=0;
    if(!u->left&&!u->right){
        t.sm=t.mx=t.mi=t.ans=u->val;
        t.bst=true;
    }else if(!u->right){
        info t2=check(u->left);
        if(!t2.bst || t2.mx>=u->val){
            t.ans=t2.ans;
        }else{
            t.bst=true;
            t.sm=t2.sm+u->val;
            t.mx=u->val;
            t.mi=t2.mi;
            t.ans=max(t2.ans,t.sm);
        }
    }else if(!u->left){
        info t2=check(u->right);
        if(!t2.bst || t2.mi<=u->val){
            t.ans=t2.ans;
        }else{
            t.bst=true;
            t.sm=t2.sm+u->val;
            t.mx=t2.mx;
            t.mi=u->val;
            t.ans=max(t2.ans,t.sm);
        }
    }else{
        info t2=check(u->left),t3=check(u->right);
        if(!t2.bst||!t3.bst||t2.mx>=u->val||t3.mi<=u->val){
            t.ans=max(t2.ans,t3.ans);
        }else{
            t.bst=true;
            t.sm=t2.sm+t3.sm+u->val;
            t.mx=t3.mx;
            t.mi=t2.mi;
            t.ans=max(t2.ans,t3.ans);
            t.ans=max(t.ans,t.sm);
        }
    }
    return t;
}
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        if(!root)return 0;
        info t=check(root);
        return max(t.ans,0ll);
    }
};
