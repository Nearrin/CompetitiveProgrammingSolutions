class Solution {
public:
    int work(vector<int>&a){
        int n=a.size();
        int ans=0;
        vector<int>p,q;
        for(int i=0;i<a.size();++i){
            auto j=lower_bound(begin(p),end(p),a[i])-begin(p);
            if(j!=p.size())
                ans=max(ans,a[i]*(i-q[j]));
            if(p.empty()||p.back()<a[i])
                p.push_back(a[i]),q.push_back(i);
        }
        return ans;
    }
    int maxArea(vector<int>& a) {
        int ans=work(a);
        reverse(begin(a),end(a));
        return max(ans,work(a));
    }
};
