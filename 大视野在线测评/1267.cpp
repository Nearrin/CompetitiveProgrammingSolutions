#include<cstdio>
#include<algorithm>
#include<vector>
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
    edge(int a,int b,edge*c):v(a),w(b),nxt(c){}
    int v,w;edge*nxt;
}*bg[50010];
void add(int u,int v,int w){
    bg[u]=new edge(v,w,bg[u]);
}
int n,k;
int siz[50010],mxs[50010],prt[50010];
ll dis[50010],nds[50010];
int pos[50010],ns;
void dfs(int u){
    siz[u]=1;mxs[u]=0;nds[++ns]=u;
    for(edge*e=bg[u];e;e=e->nxt){
        if(e->v!=prt[u]){
            prt[e->v]=u;
            dis[e->v]=dis[u]+e->w;
            dfs(e->v);
            siz[u]+=siz[e->v];
            mxs[u]=max(mxs[u],siz[e->v]);
        }
    }
    pos[u]=ns;
}
struct data{int l,m,r;};
vector<ll>tmp1;
vector<data>tmp2;
void treedc(int u){
    ns=0;prt[u]=dis[u]=0;dfs(u);
    if(siz[u]==1)return;
    if(siz[u]==2){
    	data dt;dt.l=tmp1.size();
    	dt.m=dt.l;dt.r=dt.l+1;
    	tmp1.pb(0);tmp1.pb(bg[u]->w);
    	tmp2.pb(dt);
    	return;
    }
    lp(i,1,ns)mxs[nds[i]]=max(mxs[nds[i]],siz[u]-siz[nds[i]]);
    lp(i,1,ns)if(mxs[nds[i]]<mxs[u])u=nds[i];
    ns=0;prt[u]=dis[u]=0;dfs(u);//pf("[%d]\n",u);
    edge*mid=bg[u];int t=siz[bg[u]->v];
    while(t+siz[mid->nxt->v]<siz[u]/2)t+=siz[mid->nxt->v],mid=mid->nxt;
    ll *pl=nds+2,*pm=nds+pos[mid->v],*pr=nds+ns;
    for(ll*i=pl;i<=pr;++i)*i=dis[*i];
    sort(pl,pm+1);sort(pm+1,pr+1);
    data ut;ut.l=tmp1.size();
    for(ll*i=pl;i<=pm;++i)tmp1.pb(*i);
    ut.m=tmp1.size()-1;
    for(ll*i=pm+1;i<=pr;++i)tmp1.pb(*i);
    ut.r=tmp1.size()-1;
    tmp2.pb(ut);
    edge*te=mid->nxt;mid->nxt=0;treedc(u);
    bg[u]=te;treedc(u);
}
ll checkbig(ll lim){
	ll ret=0;
	vp(wjmzbmr,tmp2){
		int l=tmp2[wjmzbmr].l,m=tmp2[wjmzbmr].m,r=tmp2[wjmzbmr].r;
		int pr=r+1;
		lp(i,l,m){
			while(pr-1>m&&tmp1[pr-1]+tmp1[i]>lim)--pr;
			ret+=r-pr+1;
		}
	}
	return ret;
}
vector<ll>tmp3;
void printbig(ll lim){
	vp(wjmzbmr,tmp2){
		int l=tmp2[wjmzbmr].l,m=tmp2[wjmzbmr].m,r=tmp2[wjmzbmr].r;
		int pr=r+1;
		lp(i,l,m){
			while(pr-1>m&&tmp1[pr-1]+tmp1[i]>lim)--pr;
			lp(j,pr,r)tmp3.pb(tmp1[j]+tmp1[i]);
		}
	}
}
int main(){
    sf("%d%d",&n,&k);
    lp(i,1,n-1){
        int u,v,w;sf("%d%d%d",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
    treedc(1);
    //vp(i,tmp1)pf("[%lld]",tmp1[i]);pf("\n");
    //vp(i,tmp2)pf("(%d,%d,%d)",tmp2[i].l,tmp2[i].m,tmp2[i].r);pf("\n");
    ll l=-1,r=1;
    while(checkbig(r)>=k)r*=2;
    while(l+1<r){
    	ll m=(l+r)/2;
    	if(checkbig(m)>=k)l=m;
    	else r=m;
    }
    printbig(r);
    while(tmp3.size()<k)tmp3.pb(r);
    sort(tmp3.begin(),tmp3.end());
    wp(i,tmp3)pf("%lld\n",tmp3[i]);
    return 0;
}
