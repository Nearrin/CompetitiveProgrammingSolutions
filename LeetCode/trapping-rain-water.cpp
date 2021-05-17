class Solution {
public:
    int trap(vector<int>& h) {
        int m=0,w=0;
        auto g=h;
        for(int i=h.size()-2;i>=0;--i)
            g[i]=max(h[i],g[i+1]);
        for(int i=0;i<h.size();++i){
            m=max(m,h[i]);
            w+=max(min(m,g[i])-h[i],0);
        }
        return w;
    }
};
