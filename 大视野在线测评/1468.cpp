#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstdlib>
#define sf scanf
#define pf printf
#define fr(a,b,c) freopen(a,b,c)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int to[100010],wei[100010],nx[100010],nw=1;
int bg[50010];
int n,m,k,ans;
void add(int u,int v,int w){to[++nw]=v;wei[nw]=w;nx[nw]=bg[u];bg[u]=nw;}
int vi[50010],dis[50010],pr[50010];int qu[60010],qf,qb;
int tmp[50010];
void bfs(int x){
	pr[x]=0;
    qf=1;qb=2;qu[qf]=x;
    while(qf!=qb){
        int u=qu[qf];++qf;if(qf>60000)qf=1;tmp[++tmp[0]]=u;
        for(int i=bg[u];i;i=nx[i])
            if(!vi[to[i]]&&to[i]!=pr[u]){
                qu[qb]=to[i];++qb;if(qb>60000)qb=1;
                pr[to[i]]=u,dis[to[i]]=dis[u]+wei[i];
            }
    }
}
int mx[50010],siz[50010];
void part(int x,int&e,int cnt){
    tmp[0]=0;pr[x]=0;
    qf=1;qb=2;qu[qf]=x;
    while(qf!=qb){
        int u=qu[qf];++qf;if(qf>60000)qf=1;tmp[++tmp[0]]=u;siz[u]=1;
        for(int i=bg[u];i;i=nx[i])
            if(!vi[to[i]]&&to[i]!=pr[u]){
                qu[qb]=to[i];++qb;if(qb>60000)qb=1;
                pr[to[i]]=u;
            }
    }
    for(int i=tmp[0];i;--i){
        int u=tmp[i];mx[u]=cnt-siz[u];
        if(pr[u]!=0)siz[pr[u]]+=siz[u];
		for(int i=bg[u];i;i=nx[i]){
			if(!vi[to[i]]&&to[i]!=pr[u]){
				mx[u]=max(mx[u],siz[to[i]]);
			}
		}
		if(e==-1||mx[e]>mx[u])e=u;
    }
}
int gob[50010];
bool cmp(int a,int b){return dis[a]<dis[b];}
void solve(int rt,int cnt){
	int x=-1;
	part(rt,x,cnt);
	vi[x]=1;tmp[0]=0;
	for(int i=bg[x];i;i=nx[i])
		if(!vi[to[i]]){
			int t=tmp[0];
			dis[to[i]]=wei[i];
			bfs(to[i]);
			sort(tmp+t+1,tmp+tmp[0]+1,cmp);
			lp(i,t+1,tmp[0])if(dis[tmp[i]]<=k)++ans;
			int p2=tmp[0];
			lp(p1,t+1,tmp[0]){
				while(p2>=t+1&&dis[tmp[p1]]+dis[tmp[p2]]>k)--p2;
				if(p2>p1)ans-=p2-p1;
				else break;
			}
		}
	sort(tmp+1,tmp+tmp[0]+1,cmp);
	int p2=tmp[0];
	lp(p1,1,tmp[0]){
		while(p2&&dis[tmp[p1]]+dis[tmp[p2]]>k)--p2;
		if(p2>p1)ans+=p2-p1;
		else break;
	}
	int str=gob[0];
	for(int i=bg[x];i;i=nx[i])
		if(!vi[to[i]])gob[++gob[0]]=siz[to[i]];
	for(int i=bg[x];i;i=nx[i])
		if(!vi[to[i]])solve(to[i],gob[++str]);
}
int main(){
    //fr("data.in","r",stdin);
    //fr("hehe.out","w",stdout);
    sf("%d",&n);
		nw=1;gob[0]=0;
		lp(i,1,n)bg[i]=0,vi[i]=0;ans=0;
		lp(i,1,n-1){
			int u,v,w;
			sf("%d%d%d",&u,&v,&w);
			add(u,v,w);add(v,u,w);
		}
		sf("%d",&k);
		solve(1,n);
		pf("%d\n",ans);
	
	return 0;
}
