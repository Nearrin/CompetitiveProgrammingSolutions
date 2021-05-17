template<class T>int f(T l,T r,int m){
    if(l==r)return 0;
    vector<int>a;
    for(auto i=l;i<r;++i)a.push_back(*i);
    int n=a.size();
    vector<vector<int>>f(n,vector<int>(m+1));
    vector<vector<int>>g(n,vector<int>(m+1));
    for(int i=0;i<n;++i)for(int j=0;j<=m;++j){
        if(i==0){
            if(j==0)f[i][j]=0;
            else f[i][j]=a[i];
            g[i][j]=0;
        }else{
            if(j==0)f[i][j]=f[i-1][j];
            else f[i][j]=max(f[i-1][j],g[i-1][j-1]+a[i]);
            g[i][j]=f[i-1][j];
        }
    }
    return f[n-1][m];
}
class Solution {
public:
    int maxSizeSlices(vector<int>& a) {
        return max(f(a.begin()+2,a.end()-1,a.size()/3-1)+a[0],f(a.begin()+1,a.end(),a.size()/3));
    }
};
