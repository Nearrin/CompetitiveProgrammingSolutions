class Solution {
public:
    int minDays(vector<int>& a, int m, int k) {
        auto check=[&](int x){
          int cnt=0;
            for(int i=0;i<a.size();++i){
                if(a[i]>x)continue;
                int j=i;
                while(j+1<a.size()&&a[j+1]<=x)++j;
                cnt+=(j-i+1)/k;
                i=j;
            }
            return cnt>=m;
        };
        int l=0,r=int(1e9+2);
        if(!check(r))return -1;
        while(l+1<r){
            int m=(l+r)/2;
            if(check(m))r=m;
            else l=m;
        }
        return r;
    }
};
