class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int cur=0;
        for(auto t:s)if(t=='(')++cur,ans=max(ans,cur);else if(t==')') --cur;
        return ans;
    }
};
