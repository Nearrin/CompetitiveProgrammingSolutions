class Solution {
public:
    int countVowelStrings(int n) {
        vector<int>f(6);
        f[0]=1;
        for(int i=1;i<=n;++i){
            vector<int>g(6);
            for(int k=1;k<=5;++k){
                for(int pre=0;pre<=k;++pre){
                    g[k]+=f[pre];
                }
            }
            f=g;
        }
        return f[0]+f[1]+f[2]+f[3]+f[4]+f[5];
    }
};
