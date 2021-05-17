class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int>c;
        int ans=0;
        for(auto v:dominoes){
            if(v[0]>v[1])swap(v[0],v[1]);
            ans+=c[{v[0],v[1]}];
            ++c[{v[0],v[1]}];
        }return ans;
    }
};
