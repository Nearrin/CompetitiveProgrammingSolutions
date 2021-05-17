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
    int widthOfBinaryTree(TreeNode* root) {
        struct node{int c;TreeNode*u;};
        vector<node>p;
        if(root)
            p.push_back({1,root});
        int a=0;
        while(p.size()){
            int b=0;
            for(int i=0;i<p.size();++i)
                b+=p[i].c;
            a=max(a,b);
            vector<node>q;
            for(auto v:p){
                if(v.u)
                    q.push_back({1,v.u->left}),
                    q.push_back({1,v.u->right});
                else
                    q.push_back({v.c*2,0});
            }
            p.clear();
            for(auto v:q){
                if(v.u||p.empty()||p.back().u)
                    p.push_back(v);
                else
                    p.back().c+=v.c;
            }
            if(p.size()&&!p.back().u)
                p.erase(p.end()-1);
            if(p.size()&&!p.front().u)
                p.erase(p.begin());
        }
        return a;
    }
};
