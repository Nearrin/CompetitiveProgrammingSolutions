class Solution {
public:
    int numWays(int n, int k) {
        k=min(k,n+1);
        vector<int>f(k);
        f[0]=1;
        while(n--){
            auto g=f;
            for(int i=0;i<k;++i){
                if(i)f[i]+=g[i-1],f[i]%=int(1e9+7);
                if(k-i-1)f[i]+=g[i+1],f[i]%=int(1e9+7);
            }
        }
        return f[0];
    }
};
