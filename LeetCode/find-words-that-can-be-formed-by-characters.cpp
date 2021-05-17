class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        for(auto word:words){
            unordered_map<char,int>cnt;
            for(auto c:chars)++cnt[c];
            for(auto c:word)--cnt[c];
            int fail=0;
            for(auto p:cnt)if(p.second<0)fail=1;
            ans+=(1-fail)*word.size();
        }
        return ans;
    }
};
