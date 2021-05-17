class Solution {
public:
    int numWays(string s) {
        int cnt1=0;
        for(auto c:s)cnt1+=c=='1';
        if(cnt1%3!=0)return 0;
        int n=s.size();
        if(cnt1==0){
            return 1ll*(n-1)*(n-2)/2%int(1e9+7);
        }
        cnt1/=3;
        int m1=0;
        int m2=0;
        int t=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='1')++t;
            if(t==cnt1){
                ++m1;
            }
            if(t==cnt1*2)++m2;
        }
        return 1ll*m1*m2%int(1e9+7);
    }
};
