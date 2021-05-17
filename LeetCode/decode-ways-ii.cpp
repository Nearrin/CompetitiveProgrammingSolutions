class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>f(n+1);
        auto ways=[](string u)->int{
            if(u.size()==1){
                if(u=="*")
                    return 9;
                return u!="0";
            }else{
                if(u=="**")
                    return 15;
                if(u[0]=='*'){
                    if(u[1]<='6')
                        return 2;
                    return 1;
                }
                if(u[1]=='*'){
                    if(u[0]=='0')return 0;
                    if(u[0]=='1')return 9;
                    if(u[0]=='2')return 6;
                    return 0;
                }
                if(u[0]=='0')return 0;
                if(u[0]=='1')return 1;
                if(u[0]=='2')return u[1]<='6';
                return 0;
            }
        };
        f[0]=1;
        for(int i=0;i<n;++i){
            f[i+1]=1ll*f[i]*ways(s.substr(i,1))%int(1e9+7);
            if(i)f[i+1]+=1ll*f[i-1]*ways(s.substr(i-1,2))%int(1e9+7),f[i+1]%=int(1e9+7);
        }
        return f[n];
    }
};
