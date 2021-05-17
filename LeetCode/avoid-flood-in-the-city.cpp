class Solution {
public:
    vector<int> avoidFlood(vector<int>& a) {
        unordered_map<int,vector<int>>w;
        for(int i=0;i<a.size();++i)
            if(a[i]>0)
                w[a[i]].push_back(i);
        set<int>c;
        vector<int>ans;
        for(int i=0;i<a.size();++i){
            if(a[i]>0){
                if(c.count(i)){
                    return {};
                }else{
                    auto&t=w[a[i]];
                    int j=lower_bound(begin(t),end(t),i)-begin(t);
                    if(j+1<t.size())
                        c.insert(t[j+1]);
                }
                ans.push_back(-1);
            }else{
                if(c.size()){
                    ans.push_back(a[*c.begin()]);
                    c.erase(c.begin());
                }else
                    ans.push_back(1);
            }
        }
        return ans;
    }
};
