#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int mx=500010;
int bg[mx*2],to[mx*2],nx[mx*2],nw;
int n,wei[mx];
void add(int u,int v){to[++nw]=v;nx[nw]=bg[u];bg[u]=nw;}
void build_tree(){
    sf("%d",&n);
    lp(i,1,n-1){
        int a,b;sf("%d%d",&a,&b);
        add(a,b),add(b,a);
    }
    lp(i,1,n)sf("%d",&wei[i]);
}
int prt[mx],stk[mx*2],que[mx];
void calc_prt(){
    stk[0]=2;stk[1]=1;stk[2]=0;
    while(stk[0]){
        int p=stk[stk[0]--],u=stk[stk[0]--];
        prt[u]=p;
        for(int i=bg[u];i;i=nx[i]){
            int v=to[i];
            if(v!=p)stk[++stk[0]]=v,stk[++stk[0]]=u;
        }
    }
}
long long sumd[mx],engd[mx];
void calc_sumd(){
    stk[0]=2;stk[1]=1;stk[2]=0;
    while(stk[0]){
        int t=stk[stk[0]--],u=stk[stk[0]--];
        if(t==0){
            stk[++stk[0]]=u,stk[++stk[0]]=1;
            sumd[u]=wei[u];
            for(int i=bg[u];i;i=nx[i]){
                int v=to[i];
                if(v!=prt[u])stk[++stk[0]]=v,stk[++stk[0]]=0;
            }
        }else{
            for(int i=bg[u];i;i=nx[i]){
                int v=to[i];
                if(v!=prt[u])sumd[u]+=sumd[v];
            }
        }
    }
}
void calc_engd(){
    stk[0]=2;stk[1]=1;stk[2]=0;
    while(stk[0]){
        int t=stk[stk[0]--],u=stk[stk[0]--];
        if(t==0){
            stk[++stk[0]]=u,stk[++stk[0]]=1;
            for(int i=bg[u];i;i=nx[i]){
                int v=to[i];
                if(v!=prt[u])stk[++stk[0]]=v,stk[++stk[0]]=0;
            }
        }else{
            for(int i=bg[u];i;i=nx[i]){
                int v=to[i];
                if(v!=prt[u])engd[u]+=engd[v]+sumd[v];
            }
        }
    }
}
long long engu[mx],sumu[mx];
void calc_sumu(){
    long long t=0;lp(i,1,n)t+=wei[i];
    lp(i,1,n)sumu[i]=t-sumd[i];
}
void calc_engu(){
    stk[0]=1;stk[1]=1;
    while(stk[0]){
        int u=stk[stk[0]--];
        if(prt[u]){
            for(int i=bg[prt[u]];i;i=nx[i]){
                int w=to[i];
                if(w!=u&&w!=prt[prt[u]]){
                    engu[u]+=engd[w]+sumd[w];
                }
            }
            engu[u]+=sumu[prt[u]]+engu[prt[u]];
        }
        for(int i=bg[u];i;i=nx[i]){
            int v=to[i];
            if(v!=prt[u])stk[++stk[0]]=v;
        }
    }
}
int lt[mx],rt[mx],ti;
void calc_dfs(){
    stk[0]=2;stk[1]=1;stk[2]=0;
    while(stk[0]){
        int t=stk[stk[0]--],u=stk[stk[0]--];
        if(t==0){
            stk[++stk[0]]=u,stk[++stk[0]]=1;
            lt[u]=++ti;
            for(int i=bg[u];i;i=nx[i]){
                int v=to[i];
                if(v!=prt[u])stk[++stk[0]]=v,stk[++stk[0]]=0;
            }
        }else{
            rt[u]=ti;
        }
    }
}
long long ans=-1;
int stku[mx],stkx[mx],stky[mx],stkdx[mx],stkdy[mx],stktp;
long long stkex[mx],stkey[mx];
void calc_ans(){
    for(int i=bg[1];i;i=nx[i]){
        int v=to[i];
        ++stktp;
        stku[stktp]=v;
        stkx[stktp]=1;
        stkex[stktp]=engd[1]-(engd[v]+sumd[v]);
        stkdx[stktp]=0;
        stky[stktp]=v;
        stkey[stktp]=engd[v];
        stkdy[stktp]=0;
    }
    while(stktp){
        int u=stku[stktp];
        int x=stkx[stktp];
        long long ex=stkex[stktp];
        int dx=stkdx[stktp];
        int y=stky[stktp];
        long long ey=stkey[stktp];
        int dy=stkdy[stktp];
        --stktp;
        while(true){
            int flg=0;
            for(int i=bg[x];i;i=nx[i]){
                int z=to[i],k=0;
                long long t=0;
                if(z==u)continue;
                if(z==prt[x]){
                    if(lt[x]<=lt[prt[u]]&&rt[x]>=rt[prt[u]])k=dx+1;
                    else k=dx-1;
                }else{
                    if(lt[x]<=lt[prt[u]]&&rt[x]>=rt[prt[u]]){
                        if(lt[z]<=lt[prt[u]]&&rt[z]>=rt[prt[u]])k=dx-1;
                        else k=dx+1;
                    }else k=dx+1;
                }
                t=engd[z]+engu[z]+sumu[z]-(engd[u]+(k+1)*sumd[u]);
                if(t<ex){x=z,ex=t,dx=k,flg=1;break;}
            }
            if(!flg)break;
        }
        while(true){
            int flg=0;
            for(int i=bg[y];i;i=nx[i]){
                int z=to[i],k=0;long long t;
                if(z==prt[u])continue;
                if(z==prt[y])k=dy-1;
                else k=dy+1;
                t=engd[z]+engu[z]+sumu[z]-(engu[u]+(k+1)*sumu[u]);
                if(t<ey){y=z,ey=t,dy=k,flg=1;break;}
            }
            if(!flg)break;
        }
        if(ans==-1||ans>ex+ey)ans=ex+ey;
        for(int i=bg[u];i;i=nx[i]){
            int v=to[i];
            if(v!=prt[u]){
                if(!(lt[v]<=lt[y]&&rt[v]>=rt[y])){
                    ++stktp;
                    stku[stktp]=v;
                    stkx[stktp]=x;
                    stkex[stktp]=ex+(engd[u]-(engd[v]+sumd[v]))+(sumd[u]-sumd[v])*(dx+1);
                    stkdx[stktp]=dx+1;
                    stky[stktp]=v;
                    stkey[stktp]=engd[v];
                    stkdy[stktp]=0;
                }else{
                    ++stktp;
                    stku[stktp]=v;
                    stkx[stktp]=x;
                    stkex[stktp]=ex+(engd[u]-(engd[v]+sumd[v]))+(sumd[u]-sumd[v])*(dx+1);
                    stkdx[stktp]=dx+1;
                    stky[stktp]=y;
                    stkey[stktp]=ey-(engd[u]-(engd[v]+sumd[v]))-dy*(sumd[u]-sumd[v]);
                    stkdy[stktp]=dy-1;
                }
            }
        }
    }
}
int main(){
    build_tree();
    calc_prt();
    calc_sumd();
    calc_engd();
    calc_sumu();
    calc_engu();
    calc_dfs();
    calc_ans();
    pf("%lld\n",ans);
    //ps;
    return 0;
}
