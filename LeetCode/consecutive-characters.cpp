class Solution {
public:
    int maxPower(string s) {
        int ans=0;
        int pre=-1;
        int cur=0;
        for(auto c:s){
            if(c==pre)++cur;
            else pre=c,cur=1;
            ans=max(ans,cur);
        }
        return ans;
    }
};
