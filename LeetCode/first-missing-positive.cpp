class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        for(auto&v:a){
            if(v<=0)v=a.size()+2;
        }
        for(auto v:a){
            auto u=abs(v);
            if(u<=a.size())a[u-1]=-abs(a[u-1]);
        }
        for(int i=1;i<=a.size();++i)if(a[i-1]>0)return i;
        return a.size()+1;
    }
};
