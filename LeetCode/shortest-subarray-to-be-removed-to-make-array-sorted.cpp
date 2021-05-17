class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& a) {
        int l=0;
        while(l+1<a.size()&&a[l]<=a[l+1])
            ++l;
        int r=a.size()-1;
        while(r&&a[r-1]<=a[r])
            --r;
        if(r<=l)
            return 0;
        int ans=r;
        for(int i=0;i<=l;++i){
            while(r<a.size()&&a[r]<a[i])++r;
            ans=min(ans,r-i-1);
        }
        return ans;
    }
};
