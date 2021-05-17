class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int ans=0;
        vector<pair<int,int>>a;
        pair<int,int>o(location[0],location[1]);
        for(auto&t:points)if(t[0]==location[0]&&t[1]==location[1]){
            ++ans;
        }else{
            a.emplace_back(t[0]-o.first,t[1]-o.second);
        }
        vector<double>pos(a.size());
        for(int i=0;i<a.size();++i){
            pos[i]=atan2(a[i].second,a[i].first)/M_PI*180;
        }
        sort(begin(pos),end(pos));
        auto b=pos;
        for(auto t:pos)b.push_back(t);
        int l=0;
        int dans=0;
        for(int r=0;r<b.size();++r){
            while(true){
                double tmp=b[r]-b[l];
                if(tmp<-1e-12)tmp+=360;
                if(tmp>angle+1e-12)++l;
                else break;
            }
            dans=max(dans,r-l+1);
        }
        return ans+min(dans,(int)pos.size());
    }
};
