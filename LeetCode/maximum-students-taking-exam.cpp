int get_s(int s,int i){
    return (s>>i)&1;
}
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int inf=~0u>>1;
        int n=seats.size(),m=seats[0].size();
        vector<int>f(1<<m,-inf);
        f[0]=0;
        for(int i=0;i<n;++i){
            vector<int>new_f(1<<m,-inf);
            for(int s=0;s<(1<<m);++s){
                int cnt=0;
                for(int j=0;j<m;++j){
                    if(  get_s(s,j)&&seats[i][j] =='#')
                        goto next;
                    if(get_s(s,j)){
                        if(j&&get_s(s,j-1))goto next;
                        if(j+1<m&&get_s(s,j+1))goto next;
                    }
                    if(get_s(s,j))++cnt;
                }
                for(int s_p=0;s_p<(1<<m);++s_p){
                    if(f[s_p]==-inf)
                        goto next2;
                    for(int j=0;j<m;++j)if(get_s(s,j)){
                        if(j&&get_s(s_p,j-1))
                            goto next2;
                        if(j+1<m&&get_s(s_p,j+1))
                            goto next2;
                    }
                    new_f[s]=max(new_f[s],f[s_p]+cnt);
                    next2:continue;
                }
                if(new_f[s]!=-inf&&0){
                    cout<<i<<" "<<s<<" "<<new_f[s]<<endl;
                }
                next:continue;
            }
            f=new_f;
        }
        int ans=0;
        for(int i=0;i<f.size();++i)ans=max(ans,f[i]);
        return ans;
    }
};
