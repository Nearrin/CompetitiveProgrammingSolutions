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
    TreeNode* sortedArrayToBST(vector<int>& a,int l=-1,int r=-1) {
        if(l==-1)l=0,r=a.size()-1;
        if(l>r)return 0;
        if(l==r)return new TreeNode(a[l]);
        if(l+1==r){
            auto t1=new TreeNode(a[l]);
            auto t2=new TreeNode(a[r]);
            t1->right=t2;
            return t1;
        }
        int m=(l+r)/2;
        auto t1=new TreeNode(a[m]);
        t1->left=sortedArrayToBST(a,l,m-1);
        t1->right=sortedArrayToBST(a,m+1,r);
        return t1;
    }
};
