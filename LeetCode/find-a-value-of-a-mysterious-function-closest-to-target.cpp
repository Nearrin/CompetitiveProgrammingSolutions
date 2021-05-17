class Solution {
public:
    int closestToTarget(vector<int>& a, int k) {
        set<int>t;
        int ans=~0u>>1;
        for(auto v:a){
            set<int>t2;
            t2.insert(v);
            for(auto vv:t)t2.insert(vv&v);
            for(auto vv:t2)ans=min(ans,abs(k-vv));
            t=t2;
        }
        return ans;
    }
};
