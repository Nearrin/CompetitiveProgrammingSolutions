class Solution {
public:
    int minSwapsCouples(vector<int>& a) {
        int n=a.size();
        int ans=0;
        for(int i=0;i<n;i+=2){
            int j=i+1;
            while((a[j]^1)!=a[i])++j;
            if(j!=i+1)++ans,swap(a[i+1],a[j]);
        }
        return ans;
    }
};
