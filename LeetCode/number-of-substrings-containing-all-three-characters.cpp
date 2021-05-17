bool check(int l,int r,vector<vector<int>>&s){
    for(int i=0;i<3;++i){
        int tmp;
        if(l==0)
            tmp=0;
        else tmp=s[l-1][i];
        tmp=s[r][i]-tmp;
        if(tmp==0)
            return false;
    }
    return true;
}
class Solution {
public:
    int numberOfSubstrings(string a) {
        vector<vector<int>>s(a.size(),vector<int>(3));
        int n=a.size();
        for(int i=0;i<n;++i){
            s[i][a[i]-'a']++;
            if(i){
                for(int j=0;j<3;++j)s[i][j]+=s[i-1][j];
            }
        }
        int l=0;
        long long ans=0;
        for(int r=0;r<n;++r){
            if(!check(l,r,s))continue;
            while(check(l+1,r,s))
                ++l;
            ans+=l+1;
        }
        return ans;
    }
};
