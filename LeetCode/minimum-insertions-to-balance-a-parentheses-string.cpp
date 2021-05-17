class Solution {
public:
    int minInsertions(string s) {
        int ans=0,cur=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='(')++cur;
            else{
                if(i+1==s.size()||s[i+1]!=')')++ans;
                else ++i;
                if(cur)--cur;else ++ans;
            }
        }
        ans+=cur*2;
        return ans;
    }
};
