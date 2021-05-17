class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        set<vector<int>>vis;
        set<pair<int,vector<int>>>cur;
        vis.insert(vector<int>(a.size()));
        int tmp=0;
        for(int i=0;i<a.size();++i)
            tmp+=a[i][0];
        cur.insert({tmp,vector<int>(a.size())});
        while(k--){
            auto t=*cur.begin();
            tmp=t.first;
            //cout<<tmp<<endl;
            cur.erase(cur.begin());
            for(int i=0;i<a.size();++i){
                if(t.second[i]+1<a[i].size()){
                    ++t.second[i];
                    t.first-=a[i][t.second[i]-1];
                    t.first+=a[i][t.second[i]];
                    if(!vis.count(t.second)){
                        vis.insert(t.second);
                        cur.insert(t);
                    }
                    t.first+=a[i][t.second[i]-1];
                    t.first-=a[i][t.second[i]];
                    --t.second[i];
                }
            }
        }
        return tmp;
    }
};
