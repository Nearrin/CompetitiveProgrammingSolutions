#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int a[10010],b[10010],v[10010],n;map<int,int>pos;
int main(){
    sf("%d",&n);
    lp(i,1,n)sf("%d",&a[i]),b[i]=a[i];
    sort(a+1,a+n+1);
    lp(i,1,n)pos[a[i]]=i;
    long long ans=0;
    int emi=~0u>>1;
    lp(i,1,n)emi=min(emi,a[i]);
    lp(i,1,n){
        if(!v[i]){
            int t=i;long long sum=0,mi=~0u>>1,sz=0;
            do{
                //pf("[%d]",t);
                v[t]=1;
                sum+=a[t];mi=min(mi,(long long)a[t]);
                ++sz;
                t=pos[b[t]];
                //pf("[%d]",t);
            }while(!v[t]);
            ans+=min((sz-1)*mi+sum-mi,emi+mi+sum+sz*emi);
        }
    }
    pf("%lld\n",ans);
    //ps;
    return 0; 
}
