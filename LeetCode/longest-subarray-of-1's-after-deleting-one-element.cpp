class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n=a.size();
        vector<int>l(n),r(n);
        for(int i=0;i<n;++i){
            if(a[i]==0)l[i]=0;
            else l[i]=1+(i?l[i-1]:0);
        }
        for(int i=n-1;i>=0;--i){
            if(a[i]==0)r[i]=0;
            else r[i]=1+(i<n-1?r[i+1]:0);
        }
        int ans=0;
        for(int i=0;i<n;++i){
            int t=0;if(i)t+=l[i-1];
            if(i<n-1)t+=r[i+1];
            ans=max(ans,t);
        }
        return ans;
    }
};
