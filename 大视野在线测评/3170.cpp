#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
struct point{int x,y;long long ans;};
bool cmp1(point a,point b){
    return a.x<b.x; 
}
bool cmp2(point a,point b){
    return a.y<b.y; 
}
point pt[100010];int n;
typedef long long ll;
ll lsum[100010],rsum[100010];
ll ans[100010];
int main(){
    sf("%d",&n);
    lp(i,1,n)sf("%d%d",&pt[i].x,&pt[i].y);
    lp(i,1,n){
        int x=pt[i].x,y=pt[i].y;
        pt[i].x=x-y;
        pt[i].y=x+y;
        pt[i].ans=0;
    }
    sort(pt+1,pt+n+1,cmp1);
    lp(i,1,n)lsum[i]=lsum[i-1]+pt[i].x;
    rp(i,n,1)rsum[i]=rsum[i+1]+pt[i].x;
    lp(i,1,n)pt[i].ans+=ll(pt[i].x)*(i-1)-lsum[i-1]+rsum[i+1]-ll(pt[i].x)*(n-i);
    sort(pt+1,pt+n+1,cmp2);
    lp(i,1,n)lsum[i]=lsum[i-1]+pt[i].y;
    rp(i,n,1)rsum[i]=rsum[i+1]+pt[i].y;
    lp(i,1,n)pt[i].ans+=ll(pt[i].y)*(i-1)-lsum[i-1]+rsum[i+1]-ll(pt[i].y)*(n-i);
    ll as=-1;
    lp(i,1,n)if(as==-1||as>pt[i].ans)as=pt[i].ans;
    pf("%lld\n",as/2);
    //ps;
    return 0; 
}
