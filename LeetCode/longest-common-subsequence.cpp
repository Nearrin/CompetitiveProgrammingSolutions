class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        vector<vector<int>>f(a.size()+1,vector<int>(b.size()+1));
        for(int i=0;i<a.size();++i)
            for(int j=0;j<b.size();++j)
                f[i+1][j+1]=max(f[i][j+1],f[i+1][j]),
                f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+(a[i]==b[j]));
        return f[a.size()][b.size()];
    }
};
