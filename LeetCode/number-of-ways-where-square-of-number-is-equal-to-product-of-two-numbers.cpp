int f(vector<int>a,vector<int>b){
    int ans=0;
    sort(begin(a),end(a));
    sort(begin(b),end(b));
    for(int i=0;i<b.size();++i){
        int pa=0;
        int pa2=0;
        for(int j=i+1;j<b.size();++j){
            while(pa<a.size()&&1ll*a[pa]*a[pa]<1ll*b[i]*b[j]){
                ++pa;
            }
            while(pa2<a.size()&&1ll*a[pa2]*a[pa2]<=1ll*b[i]*b[j]){
                ++pa2;
            }
            ans+=pa2-pa;
        }
    }
    return ans;
}
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return f(nums1,nums2)+f(nums2,nums1);
    }
};
