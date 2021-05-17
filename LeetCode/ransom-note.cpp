class Solution {
public:
    bool canConstruct(string r, string m) {
        vector<int>cnt(26);
        for(auto c:r)++cnt[c-'a'];
        for(auto c:m)--cnt[c-'a'];
        for(auto t:cnt)if(t>0)return false;
        return true;
    }
};
