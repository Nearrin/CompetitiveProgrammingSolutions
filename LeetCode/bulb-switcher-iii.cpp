class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int ans=0;
        int mx=0;
        int sz=0;
        for(auto v:light){
            ++sz;
            mx=max(mx,v);
            if(mx==sz)++ans;
        }
        return ans;
    }
};
