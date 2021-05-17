class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int ans=0;
        for(int i=1;i<a.size();++i){
            a[i]+=a[i-1];
        }
        auto s=[&](int i,int j){
            if(i>j)return 0;
            int t=a[j];
            if(i)t-=a[i-1];
            return t;
        };
        for(int i=0;i<=k;++i){
            int t=0;
            t+=s(0,i-1);
            t+=s(a.size()-(k-i),a.size()-1);
            ans=max(ans,t);
        }
        return ans;
    }
};
