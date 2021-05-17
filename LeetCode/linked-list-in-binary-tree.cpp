/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool dfs(TreeNode*u,vector<int>&q,vector<int>&s){
    bool ans=false;
    s.push_back(u->val);
    //cout<<u->val<<"vis"<<endl;
    if(q.size()<=s.size()){
        //for(int i=0;i<s.size();++i)
         //   cout<<s[i]<<" ";
        cout<<endl;
         int sm=1;
        for(int i=0;i<q.size();++i){
            if(q[q.size()-i-1]!=s[s.size()-i-1])sm=0;
        }
        if(sm)ans=true;
        if(ans)return ans;
    }
    if(u->left){
        if(dfs(u->left,q,s))ans=true;
    }
    if(u->right)
        if(dfs(u->right,q,s))ans=true;
    s.pop_back();
    return ans;
}
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int>q;
        for(auto p=head;p;p=p->next)
            q.push_back(p->val);
        vector<int>s;
        return dfs(root,q,s);
    }
};
