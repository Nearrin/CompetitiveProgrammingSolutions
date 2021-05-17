class Solution {
public:
    bool isPossible(vector<int>& a) {
        unordered_map<int,multiset<int>>f;
        for(auto v:a){
            auto&fv1=f[v-1];
            if(fv1.size()){
                int t=*fv1.begin();
                fv1.erase(fv1.begin());
                f[v].insert(t+1);
            }else{
                f[v].insert(1);
            }
        }
        int ans=1;
        for(auto v:f)for(auto u:v.second)if(u<3)ans=0;
        return ans;
    }
};
