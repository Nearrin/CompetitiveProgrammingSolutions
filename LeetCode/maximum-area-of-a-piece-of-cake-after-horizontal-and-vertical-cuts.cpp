class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        vector<int>u;
        int t=0;
        sort(begin(hc),end(hc));
        for(auto i:hc){
            u.push_back(i-t);
            t=i;
        }
        u.push_back(h-t);
        vector<int>v;
        t=0;
        sort(begin(vc),end(vc));
        for(auto i:vc){
            v.push_back(i-t);
            t=i;
        }
        v.push_back(w-t);
        sort(begin(u),end(u));
        sort(begin(v),end(v));
        return (long long)u.back()*v.back()%int(1e9+7);
    }
};
