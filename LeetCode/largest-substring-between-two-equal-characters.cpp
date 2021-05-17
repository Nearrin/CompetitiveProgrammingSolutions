class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans=-1;
        for(int c='a';c<='z';++c){
            int pre=-1;
            for(int i=0;i<s.size();++i){
                if(s[i]==c){
                    if(pre!=-1){
                        ans=max(ans,i-pre-1);
                    }
                    else pre=i;
                }
            }
        }
        return ans;
    }
};
