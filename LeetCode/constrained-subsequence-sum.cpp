class Solution {
public:
    int constrainedSubsetSum(vector<int>& a, int k) {
        vector<int>f(a.size());
        deque<int>s;
        int ans=-(~0u>>1);
        for(int i=0;i<a.size();++i){
            while(s.size()&&i-s.front()>k)s.pop_front();
            if(s.size())f[i]=a[i]+max(f[s.front()],0);
            else f[i]=a[i];
            while(s.size()&&f[s.back()]<=f[i])s.pop_back();
            s.push_back(i);
            ans=max(ans,f[i]);
        }
        return ans;
    }
};
