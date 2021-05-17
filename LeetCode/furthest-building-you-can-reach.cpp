class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        vector<int>tmp;
        auto check=[&](int x){
            tmp.clear();
            for(int i=1;i<=x;++i){
                if(heights[i]>heights[i-1]){
                    tmp.push_back(heights[i]-heights[i-1]);
                }
            }
            sort(begin(tmp),end(tmp));
            if(tmp.size()<=ladders)
                return true;
            long long cur=0;
            for(int i=0;i<tmp.size()-ladders;++i){
                cur+=tmp[i];
            }
            return cur<=bricks;
        };
        int l=0,r=heights.size()-1;
        if(check(r))return r;
        while(l+1<r){
            int m=(l+r)/2;
            if(check(m))l=m;
            else r=m;
        }
        return l;
    }
};
