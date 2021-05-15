#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define sf scanf
#define pf printf
#define ps for(;;)
#define pb push_back
#define fr(a,b,c) freopen(a,b,c)
#define lp(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
int n;vector<int>to[100010],we[100010],cn[100010];
int ep[100010];
int mp[100010];
int pr[100010],ch[100010][2],mx[100010],sm[100010],dl[100010],cy[100010];
inline void tmax(int&a,int b){
	if(a<b)a=b;
}
void down(int x){
    if(sm[x]!=-(~0u>>1)){
        if(ch[x][0]){
            sm[ch[x][0]]=sm[x];
            dl[ch[x][0]]=-(~0u>>1);
        }
        if(ch[x][1]){
            sm[ch[x][1]]=sm[x];
            dl[ch[x][1]]=-(~0u>>1);
        }
        mx[x]=sm[x];
        cy[x]=sm[x];
        sm[x]=-(~0u>>1);
    }
    if(dl[x]!=-(~0u>>1)){
        if(ch[x][0]){
            if(dl[ch[x][0]]==-(~0u>>1))dl[ch[x][0]]=0;
            dl[ch[x][0]]+=dl[x];
        }
        if(ch[x][1]){
            if(dl[ch[x][1]]==-(~0u>>1))dl[ch[x][1]]=0;
            dl[ch[x][1]]+=dl[x];
        }
        mx[x]+=dl[x];
        cy[x]+=dl[x];
        dl[x]=-(~0u>>1);
    }
}
void upda(int x){
    mx[x]=cy[x];
    if(ch[x][0])down(ch[x][0]),tmax(mx[x],mx[ch[x][0]]);
    if(ch[x][1])down(ch[x][1]),tmax(mx[x],mx[ch[x][1]]);
}
void set(int x,int y,int d){
    ch[x][d]=y;pr[y]=x;
    upda(x);
}
int tp(int x){return x!=ch[pr[x]][0];}
void rot(int x){
    int y=pr[x],d1=tp(x),z=pr[y],d2=tp(y);
    set(y,ch[x][!d1],d1);
    set(x,y,!d1);
    if(z>0)set(z,x,d2);else pr[x]=z;
}
void very(int x){
    if(pr[x]>0)very(pr[x]);
    down(x);
}
void spl(int x){
    very(x);
    while(pr[x]>0){
        if(pr[pr[x]]<=0)rot(x);
        else if(tp(x)==tp(pr[x]))rot(pr[x]),rot(x);
        else rot(x),rot(x);
    }
}
int acc(int x){
    int y=0;
    while(x){
        spl(x);
        pr[ch[x][1]]=-x;
        set(x,y,1);
        y=x,x=-pr[x];
    }
    return y;
}
 
void dfs(int u,int p){
    pr[u]=-p;ep[u]=p;
    lp(i,0,int(to[u].size()-1)){
        int v=to[u][i];
        if(v==p)cy[u]=mx[u]=we[u][i],mp[cn[u][i]]=u;
        else dfs(v,u);
    }
}
int que(int u,int v){
    if(u==v)return 0;//at
    acc(u);
    int w=acc(v);
    acc(w);
    if(w==u){
        spl(v);
        return mx[v];
    }else if(w==v){
        spl(u);
        return mx[u];
    }else{
        spl(v);spl(u);
        return max(mx[u],mx[v]);
    }
}
void msm(int u,int v,int k){
    if(u==v)return;
    acc(u);int w=acc(v);
    acc(w);
    if(w==u){
        spl(v);
        sm[v]=k;
        dl[v]=-(~0u>>1);
    }else if(w==v){
        spl(u);
        sm[u]=k;
        dl[u]=-(~0u>>1);
    }else{
        spl(v);
        sm[v]=k;
        dl[v]=-(~0u>>1);
        spl(u);
        sm[u]=k;
        dl[u]=-(~0u>>1);
    }
}
void msd(int u,int v,int k){
    if(u==v)return;
    acc(u);int w=acc(v);
    acc(w);
    if(w==u){
        spl(v);
        if(dl[v]==-(~0u>>1))dl[v]=0;
        dl[v]+=k;
    }else if(w==v){
        spl(u);
        if(dl[u]==-(~0u>>1))dl[u]=0;
        dl[u]+=k;
    }else{
        spl(v);
        if(dl[v]==-(~0u>>1))dl[v]=0;
        dl[v]+=k;
        spl(u);
        if(dl[u]==-(~0u>>1))dl[u]=0;
        dl[u]+=k;
    }
}
void chg(int x,int w){
    msm(mp[x],ep[mp[x]],w);
}
int main(){
    sf("%d",&n);
    lp(i,1,n-1){
        int u,v,w;sf("%d%d%d",&u,&v,&w);
        to[u].pb(v);we[u].pb(w);cn[u].pb(i);
        to[v].pb(u);we[v].pb(w);cn[v].pb(i);
    }
    dfs(1,0);
    lp(i,1,n)sm[i]=dl[i]=-(~0u>>1);
    char op[110];
    for(sf("%s",op);op[0]!='S';sf("%s",op)){
        if(op[1]=='a'){
            int u,v;sf("%d%d",&u,&v);
            pf("%d\n",que(u,v));
        }else if(op[1]=='o'){
            int u,v,w;sf("%d%d%d",&u,&v,&w);
            msm(u,v,w);
        }else if(op[1]=='h'){
            int u,v;sf("%d%d",&u,&v);
            chg(u,v);
        }else{
            int u,v,w;sf("%d%d%d",&u,&v,&w);
            msd(u,v,w);
        }
    }
    //ps;
    return 0;
}
