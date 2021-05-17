typedef long long ll;
bool check(vector<int>&nums,ll x,int m){
    int tmp=0;
    for(int i=0;i<nums.size();++i){
        ll cur=nums[i];
        int j=i;
        while(j+1<nums.size()&&cur+nums[j+1]<=x){
            ++j;
            cur+=nums[j];
        }
        i=j;
        ++tmp;
    }
    return tmp<=m;
}
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        ll l=*max_element(nums.begin(),nums.end());
        if(check(nums,l,m))
            return l;
        ll r=l;
        while(!check(nums,r,m))r*=2;
        while(l+1<r){
            ll mm=(l+r)/2;
            if(check(nums,mm,m))r=mm;
            else l=mm;
        }
        return r;
    }
};
