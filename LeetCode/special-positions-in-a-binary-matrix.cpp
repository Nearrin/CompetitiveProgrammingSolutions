class Solution {
public:
    int numSpecial(vector<vector<int>>& a) {
        int ans=0;
        for(int i=0;i<a.size();++i){
            for(int j=0;j<a[i].size();++j){
                if(a[i][j]!=1)continue;
                int cnt=0;
                for(int k=0;k<a[i].size();++k)cnt+=a[i][k];
                for(int k=0;k<a.size();++k)cnt+=a[k][j];
                ans+=cnt==2;
            }
        }
        return ans;
    }
};
