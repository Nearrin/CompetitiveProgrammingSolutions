#define rang(a) begin(a), end(a)
#define gene template<class T>
#define lp(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define lv(i, a) for (int i = 0; i < int(a.size()); ++i)
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }
template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
typedef vector<int> vi;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty())return vi();
        sort(nums);
        vi f(nums.size(),1),g(nums.size(),-1);
        lv(i,nums){
            lp(j,0,i-1){
                if(nums[i]%nums[j]==0){
                    if(tmax(f[i],f[j]+1)){
                        g[i]=j;
                    }
                }
            }
        }
        int p=0;
        lv(i,nums)if(f[i]>f[p])p=i;
        vi ans;
        while(true){
            ans.push_back(nums[p]);
            if(f[p]==1)break;
            p=g[p];
        }
        return ans;
    }
};
