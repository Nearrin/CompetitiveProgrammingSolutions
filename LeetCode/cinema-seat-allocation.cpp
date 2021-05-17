int check(int l,int r){
    if(l<=2&&r>=9)return 2;
    if(l<=2&&r>=5)return 1;
    if(l<=6&&r>=9)return 1;
    if(l<=4&&r>=7)return 1;
    return 0;
}
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        long long ans=0;
        map<int,vector<int>>res;
        for(int i=0;i<reservedSeats.size();++i){
            res[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
        }
        ans+=n*2;
        for(auto row:res){
            ans-=2;
            vector<int>can(10);
            for(auto tmp:row.second)can[tmp-1]=1;
            for(int i=0;i<10;++i){
                if(can[i])continue;
                int j=i;
                while(j+1<10&&!can[j+1])++j;
                ans+=check(i+1,j+1);
                i=j;
            }
        }
        return ans;
    }
};
