#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
using namespace std;
typedef long long ll;
int p[2]={7,2848631};
int inv[3000010];
int isv[7];
int fac[3000010];
int ccm[7][7];
int com(int a,int b,int d){
    if(a<b)return 0;
    else if(d==0)return ccm[a][b];
    else return ll(fac[a])*inv[ll(fac[b])*fac[a-b]%p[1]]%p[1];
}
int lus(int a,int b,int d){
    int r=1;
    while(a||b){
        r=ll(r)*com(a%p[d],b%p[d],d)%p[d];
        a/=p[d];
        b/=p[d];
    }
    return r;
}
int cal(int x1,int y1,int x2,int y2,int d){
    int dx=x2-x1,dy=y2>y1?y2-y1:y1-y2;
    if((dx+dy)%2==1||(dx+dy)/2>dx)return 0;
    return lus(dx,(dx+dy)/2,d);
}
int sov(int x1,int y1,int x2,int y2,int d){
    return (cal(x1,y1,x2,y2,d)-cal(x1,-y1-2,x2,y2,d)+p[d])%p[d];
}
struct point{int x,y;};
bool operator<(const point&a,const point&b){return a.x<b.x;}
bool operator==(const point&a,const point&b){return a.x==b.x;}
int main(){
    lp(i,0,p[0]-1)lp(j,0,i)if(j==0||j==i)ccm[i][j]=1;else ccm[i][j]=(ccm[i-1][j-1]+ccm[i-1][j])%p[0];
    inv[1]=1;lp(j,2,p[1]-1)inv[j]=ll(p[1]-p[1]/j)*inv[p[1]%j]%p[1];
    fac[0]=1;lp(j,1,p[1]-1)fac[j]=ll(fac[j-1])*j%p[1];
    isv[1]=1;lp(j,2,6)isv[j]=(7-7/j)*isv[7%j]%7;
    int n,k;sf("%d%d",&n,&k);
    static point pts[1000010];
    lp(i,1,k)sf("%d%d",&pts[i].x,&pts[i].y);
    pts[++k].x=0;pts[k].y=0;pts[++k].x=n;pts[k].y=0;
    sort(pts+1,pts+k+1);
    k=unique(pts+1,pts+k+1)-pts-1;
    int mx=0,cnt[2]={1,1};
    lp(i,1,k-1){
        lp(j,0,1)cnt[j]=ll(cnt[j])*sov(pts[i].x,pts[i].y,pts[i+1].x,pts[i+1].y,j)%p[j];
        int dx=pts[i+1].x-pts[i].x,dy=pts[i+1].y-pts[i].y;
        if(dy>0)mx=max(mx,pts[i].y+(dx+dy)/2);
        else mx=max(mx,pts[i+1].y+(dx-dy)/2);
    }
    int ans=(ll(cnt[0])*p[1]*isv[p[1]%7]%(p[0]*p[1])+ll(cnt[1])*p[0]*inv[7]%(p[0]*p[1]))%(p[0]*p[1]);
    pf("%d %d\n",ans,mx);
    //ps;
    return 0;
}
