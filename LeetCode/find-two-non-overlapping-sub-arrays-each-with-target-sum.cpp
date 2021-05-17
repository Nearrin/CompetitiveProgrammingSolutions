class Solution {
public:
    vector<int> solve(vector<int>a,int t){
        int s=0;
        vector<int>ans;
        unordered_map<int,int>mp;
        int i=0;
        mp[0]=-1;
        for(auto v:a){
            s+=v;
            if(mp.count(s-t)){
                ans.push_back(i-mp[s-t]);
            }else{
                ans.push_back(~0u>>1);
            }
            if(i)ans[i]=min(ans[i],ans[i-1]);
            mp[s]=i;
            ++i;
        }
        return ans;
    }
    int minSumOfLengths(vector<int>& a, int t) {
        auto l=solve(a,t);
        reverse(begin(a),end(a));
        auto r=solve(a,t);
        reverse(begin(r),end(r));
        int ans=~0u>>1;
        for(int i=0;i<a.size();++i){
            if(i){
                if(l[i-1]!=~0u>>1&&r[i]!=~0u>>1){
                    ans=min(ans,l[i-1]+r[i]);
                }
            }
        }
        if(ans==~0u>>1)ans=-1;
        return ans;
    }
};
