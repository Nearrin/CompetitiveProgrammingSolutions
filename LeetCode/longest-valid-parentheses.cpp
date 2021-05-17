class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int>f(s.size()),g;
        for(int i=0;i<s.size();++i){
            if(s[i]=='('){
                g.push_back(i);
            }else if(g.size()){
                f[g.back()]=i;
                g.pop_back();
            }
        }
        int ans=0;
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]!='('||!f[i])
                continue;
            if(f[i]+1<s.size())
                f[i]=f[i]-i+1+f[f[i]+1];
            else
                f[i]=f[i]-i+1;
            ans=max(ans,f[i]);
        }
        return ans;
    }
};
