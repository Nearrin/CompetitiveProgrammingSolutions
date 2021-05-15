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
#include<cstring>
#include<sstream>
struct sa{
    char s[100010];int n,m,sa[100010],t[2][100010],*r,*g,c[100010],h[100010],mh[100010][21],pw[100010];
    ll dl[100010];
    void build(){
        m=256;r=t[0];g=t[1];
        lp(i,1,m)c[i]=0;
        lp(i,1,n)++c[r[i]=s[i]];
        lp(i,1,m)c[i]+=c[i-1];
        rp(i,n,1)sa[c[r[i]]--]=i;
        for(int j=1,p=0;j<=n;j*=2,p=0){
            lp(i,n-j+1,n)g[++p]=i;
            lp(i,1,n)if(sa[i]>j)g[++p]=sa[i]-j;
            lp(i,1,m)c[i]=0;
            lp(i,1,n)++c[r[g[i]]];
            lp(i,1,m)c[i]+=c[i-1];
            rp(i,n,1)sa[c[r[g[i]]]--]=g[i];
            swap(g,r);p=r[sa[1]]=1;
            lp(i,2,n)if(g[sa[i]]==g[sa[i-1]]&&sa[i]+j<=n&&sa[i-1]+j<=n&&
                g[sa[i]+j]==g[sa[i-1]+j])r[sa[i]]=p;
            else r[sa[i]]=++p;
            if((m=p)==n)break;
        }
        for(int i=1,j=0;i<=n;++i,j?--j:j){
            if(r[i]!=1){
                while(i+j<=n&&sa[r[i]-1]+j<=n&&s[i+j]==s[sa[r[i]-1]+j])++j;
                h[r[i]]=j;
            }else h[r[i]]=0;
        }
        lp(i,1,n)mh[i][0]=h[i];
        for(int j=1;(1<<j)<=n;++j)
        	for(int i=1;i+(1<<j)-1<=n;++i)
        		mh[i][j]=min(mh[i][j-1],mh[i+(1<<(j-1))][j-1]);
        pw[1]=0;
        lp(i,2,n)if((1<<(pw[i-1]+1))<=i)pw[i]=pw[i-1]+1;
        	else pw[i]=pw[i-1];
        dl[1]=n-sa[1]+1;
        lp(i,2,n)dl[i]=dl[i-1]+n-sa[i]+1-h[i];
    }
    int lcp(int x,int y){
    	if(x==y)return n-x+1;
    	x=r[x];y=r[y];
    	if(x>y)swap(x,y);++x;
    	int t=pw[y-x+1];
    	return min(mh[x][t],mh[y-(1<<t)+1][t]);
    }
    pair<int,int>kth(ll x){
    	if(dl[n]<x)return mp(-1,-1);
    	int y=0,z=n;
    	while(y+1<z){
    		int w=(y+z)/2;
    		if(dl[w]<x)y=w;
    		else z=w;
    	}
    	if(y)x-=dl[y];
    	return mp(sa[y+1],sa[y+1]+h[y+1]+x-1);
    }
}sa1,sa2;
int main(){
	int n,q;static char s[100010];
	sf("%d%d%s",&n,&q,s+1);
	sa1.n=sa2.n=n;
	lp(i,1,n)sa1.s[i]=sa2.s[i]=s[i];
	reverse(sa2.s+1,sa2.s+n+1);
	sa1.build();sa2.build();
	lp(i,1,q){
		ll x,y;sf("%lld%lld",&x,&y);
		pair<int,int>xx=sa1.kth(x),yy=sa1.kth(y);
		if(xx.first==-1||yy.first==-1)pf("-1\n");
		else{
			//pf("[%d,%d],[%d,%d]\n",xx.first,xx.second,yy.first,yy.second);
			int t1=sa1.lcp(xx.first,yy.first);
			t1=min(t1,min(xx.second-xx.first+1,yy.second-yy.first+1));
			int t2=sa2.lcp(n-xx.second+1,n-yy.second+1);
			t2=min(t2,min(xx.second-xx.first+1,yy.second-yy.first+1));
			pf("%lld\n",ll(t1)*ll(t1)+ll(t2)*ll(t2));
		}
	}
    return 0;
}
