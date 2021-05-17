class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long ans=0;
        int c0=1,c1=0;
        int cur=0;
        for(auto v:arr){
            if(v%2==1)cur=1-cur;
            if(cur==1)ans+=c0,++c1;
            else ans+=c1,++c0;
        }
        return ans%int(1e9+7);
    }
};
