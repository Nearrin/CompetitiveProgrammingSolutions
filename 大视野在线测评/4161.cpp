#ifndef LINEAR_HOMOGENEOUS_RECURRENCE_RELATIONS_WITH_CONSTANT_COEFFICIENTS
#define LINEAR_HOMOGENEOUS_RECURRENCE_RELATIONS_WITH_CONSTANT_COEFFICIENTS
#include<vector>
namespace CTL{
    using namespace std;
    template<class T>struct LinearHomogeneousRecurrenceRelationsWithConstantCoefficients{
        static vector<T>cal(int n,int k,vector<T>&c,T p){
            vector<T>r(2*k);
            if(n<k){
                r[n]=1;
                return r;
            }
            vector<T>u=cal(n/2,k,c,p);
            for(int i=0;i<k;++i)
                for(int j=0;j<k;++j)
                    r[i+j]=(r[i+j]+u[i]*u[j])%p;
            if(n&1)r.insert(r.begin(),0);
            for(int i=2*k-1;i>=k;--i)
                for(int j=1;j<=k;++j)
                    r[i-j]=(r[i-j]+c[j-1]*r[i])%p;
            return r;
        }
        static T run(vector<T>a,vector<T>c,int n,T p){
            if(n<a.size())
                return a[n];
            int k=a.size();
            vector<T>b=cal(n-k+1,k,c,p);
            a.resize(2*k-1);
            for(int i=k;i<=2*k-2;++i){
                for(int j=0;j<k;++j)
                    a[i]=(a[i]+a[i-j-1]*c[j])%p;
            }
            T r=0;
            for(int j=0;j<k;++j)
                r=(r+b[j]*a[k-1+j])%p;
            return r;
        }

    };
}
#endif
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;ll p=1000000007;
int main(){
    int n,k;
    vector<ll>c,a;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;++i){
        int t;scanf("%d",&t);
        c.push_back((t%p+p)%p);
    }
    for(int i=1;i<=k;++i){
        int t;scanf("%d",&t);
        a.push_back((t%p+p)%p);
    }
   int res= CTL::LinearHomogeneousRecurrenceRelationsWithConstantCoefficients<ll>::run(a,c,n,p);
    printf("%d\n",res);
    return 0;
}