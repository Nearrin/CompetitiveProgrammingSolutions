class Solution {
public:
    int palindromePartition(string s, int k) {
        vector<vector<int>>f(s.size()+1,vector<int>(k+1,(~0u>>1)/2));
        f[0][0]=0;
        vector<vector<int>>c(s.size()+1,vector<int>(s.size()+1));
        for(int i=1;i<=s.size();++i)
            for(int j=i;j<=s.size();++j){
                int l=i,r=j;
                while(l<r){
                    c[i][j]+=(s[l-1]!=s[r-1]);
                    ++l,--r;
                }
            }
        for(int i=1;i<=s.size();++i)
            for(int j=1;j<=k;++j){
                for(int l=1;l<=i;++l){
                    f[i][j]=min(f[i][j],f[l-1][j-1]+c[l][i]);
                }
            }
        return f.back().back();
    }
};
