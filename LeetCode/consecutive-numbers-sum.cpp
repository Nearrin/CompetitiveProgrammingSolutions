class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans=0;
        using ll=long long;
        auto test=[&](long long u,long long v){
            if((u+v)%2==0)return;
            ll n=(u+v-1)/2;
            ll m=n-u;
            if(n>m&&m>=0){
                ++ans;
            }
        };
        for(ll p=1;p*p<=2*N;++p){
            if(2*N%p!=0){
                continue;
            }
            ll q=2*N/p;
            test(p,q);
            if(p!=q)test(q,p);
        }
        return ans;
    }
};
