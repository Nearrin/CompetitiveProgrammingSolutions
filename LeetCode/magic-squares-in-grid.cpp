class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        int ans=0;
        for(int i=0;i<n-2;++i)
            for(int j=0;j<m-2;++j){
                int fail=0;
                set<int>alls;
                int ts=0;
                for(int k=0;k<3;++k)ts+=a[i+k][j+k];
                alls.insert(ts);
                ts=0;
                for(int k=0;k<3;++k)ts+=a[i+2-k][j+k];
                alls.insert(ts);
                ts=0;
                for(int k=0;k<3;++k)ts+=a[i+0][j+k];
                alls.insert(ts);
                ts=0;
                for(int k=0;k<3;++k)ts+=a[i+1][j+k];
                alls.insert(ts);
                ts=0;
                for(int k=0;k<3;++k)ts+=a[i+2][j+k];
                alls.insert(ts);
                ts=0;
                for(int k=0;k<3;++k)ts+=a[i+k][j+0];
                alls.insert(ts);
                ts=0;
                for(int k=0;k<3;++k)ts+=a[i+k][j+1];
                alls.insert(ts);
                ts=0;
                for(int k=0;k<3;++k)ts+=a[i+k][j+2];
                alls.insert(ts);
                set<int>ttt;
                for(int k1=0;k1<3;++k1)for(int k2=0;k2<3;++k2)if(a[i+k1][j+k2]<1||a[i+k1][j+k2]>9)fail=1;else ttt.insert(a[i
                    +k1][j+k2]);
                if(alls.size()>1)fail=1;
                if(ttt.size()!=9)fail=1;
                ans+=1-fail;
            }
        return ans;
    }
};
