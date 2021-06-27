class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int>cnt(1024);
        cnt[0]=1;
        int cur=0;
        long long ans=0;
        for(auto c:word){
            cur^=1<<(c-'a');
            for(int i=0;i<10;++i){
                ans+=cnt[cur^(1<<i)];
            }
            ans+=cnt[cur];
            cnt[cur]+=1;
        }
        return ans;
    }
};
