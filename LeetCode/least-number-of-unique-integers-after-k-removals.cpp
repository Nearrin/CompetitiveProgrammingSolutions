class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>cnt;
        for(auto v:arr)++cnt[v];
        vector<pair<int,int>>b;
        for(auto v:arr)b.emplace_back(cnt[v],v);
        sort(begin(b),end(b));
        unordered_set<int>cc;
        for(int i=k;i<b.size();++i){
            cc.insert(b[i].second);
        }
        return cc.size();
    }
};
