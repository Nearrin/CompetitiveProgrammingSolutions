class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>cnt,ccnt;
        for(auto v:arr)++cnt[v];
        for(auto t:cnt){
            ++ccnt[t.second];
            if(ccnt[t.second]>1)return false;
        }
        return true;
    }
};
