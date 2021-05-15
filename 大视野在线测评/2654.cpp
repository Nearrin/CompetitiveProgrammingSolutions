#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
typedef long long ll;
using namespace std;
struct edge{
    edge(){sf("%d%d%d%d",&u,&v,&w,&c);++u;++v;d=0;}
    int u,v,w,c,d;
};
vector<edge>egs;int n,m,k;
bool operator<(edge a,edge b){
    return a.w+a.d==b.w+b.d?a.c<b.c:a.w+a.d<b.w+b.d;
}
int pr[50010];
int fd(int x){return x==pr[x]?x:pr[x]=fd(pr[x]);}
pair<int,int>mst(int x){
    vp(i,egs)if(egs[i].c==0)egs[i].d=x;
    sort(egs.begin(),egs.end());
    int r1=0,r2=0;
    lp(i,1,n)pr[i]=i;
    vp(i,egs){
        if(fd(egs[i].u)!=fd(egs[i].v)){
            pr[fd(egs[i].u)]=egs[i].v;
            r1+=egs[i].w+egs[i].d;
            r2+=1-egs[i].c;
        }
    }
    return mp(r1,r2);
}
int main(){
    sf("%d%d%d",&n,&m,&k);
    lp(i,1,m)egs.pb(edge());
    int left=-200,right=200;
    while(left+1<right){
        int mid=(left+right)/2;
        if(mst(mid).second<k)right=mid;
        else left=mid;
    }
    pf("%d\n",mst(left).first-k*left);
    return 0;
}
