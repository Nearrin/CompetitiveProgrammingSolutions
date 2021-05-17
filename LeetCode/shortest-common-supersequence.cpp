class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        vector<vector<int>>f(a.size()+1,vector<int>(b.size()+1));
        for(int i=1;i<=a.size();++i){
            for(int j=1;j<=b.size();++j){
                if(a[i-1]==b[j-1]){
                    f[i][j]=1+f[i-1][j-1];
                }else{
                    f[i][j]=max(f[i-1][j],f[i][j-1]);
                }
            }
        }
        string c;
        int i=a.size(),j=b.size();
        while(i+j>0){
            if(i==0){
                c.push_back(b[j-1]);
                --j;
            }else if(j==0){
                c.push_back(a[i-1]);
                --i;
            }else{
                if(a[i-1]==b[j-1]){
                    c.push_back(a[i-1]);
                    --i,--j;
                }else{
                    if(f[i][j]==f[i-1][j]){
                        c.push_back(a[i-1]);
                        --i;
                    }else{
                        c.push_back(b[j-1]);
                        --j;
                    }
                }
            }
        }
        reverse(c.begin(),c.end());
        return c;
    }
};
