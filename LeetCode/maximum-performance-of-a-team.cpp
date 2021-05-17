class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>a;
        for(int i=0;i<n;++i)a.emplace_back(efficiency[i],speed[i]);
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        multiset<int>s;
        typedef long long ll;
        ll t=0;
        ll ans=0;
        for(int i=0;i<n;++i){
            s.insert(a[i].second);
            t+=a[i].second;
            if(s.size()>k){
                t-=*s.begin();
                s.erase(s.begin());
            }
            ans=max(ans,t*a[i].first);
        }
        return ans%int(1e9+7);
    }
};
