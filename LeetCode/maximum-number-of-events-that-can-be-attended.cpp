class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int l=events[0][0],r=l;
        unordered_map<int,vector<int>>a;
        for(int i=0;i<events.size();++i){
            for(int j=0;j<2;++j){
                l=min(l,events[i][j]);
                r=max(r,events[i][j]);
            }
            a[events[i][0]].push_back(events[i][1]);
        }
        multiset<int>cur;
        int ans=0;
        for(int i=l;i<=r;++i){
            for(auto j:a[i])
                cur.insert(j);
            while(cur.size()&&*cur.begin()<i)
                cur.erase(cur.begin());
            if(cur.size())
                ++ans,cur.erase(cur.begin());
        }
        return ans;
    }
};
