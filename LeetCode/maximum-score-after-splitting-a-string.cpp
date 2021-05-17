class Solution {
public:
    int maxScore(string s) {
        int tans=0;
        for(int i=0;i<s.size()-1;++i){
            int ans=0;
            for(int j=0;j<=i;++j)ans+=s[j]=='0';
            for(int j=i+1;j<s.size();++j)ans+=s[j]=='1';
            tans=max(tans,ans);
        }
        return tans;
    }
};
