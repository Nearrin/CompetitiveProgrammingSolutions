#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define sf scanf
#define pf printf
#define ps system("pause")
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int MXN=100010;
int chd[MXN][2],siz[MXN],val[MXN],cnt[MXN],rt,nw,fix[MXN];
void rotate(int &x,int d){
    int t=chd[x][d];
    chd[x][d]=chd[t][!d];
    chd[t][!d]=x;
    siz[t]=siz[x];
    siz[x]=siz[chd[x][0]]+siz[chd[x][1]]+cnt[x];
    x=t;
}
void insert(int &x,int v){
    if(!x)x=++nw,cnt[x]=1,val[x]=v,fix[x]=rand()*rand();
    else if(val[x]==v)++cnt[x];
    else {
        insert(chd[x][v>val[x]],v);
        if(fix[chd[x][v>val[x]]]>fix[x])
            rotate(x,v>val[x]);
    }
    ++siz[x];
}
int pred(int x,int v){
   if(!x)return -(~0u>>1);
   else if(val[x]>=v)return pred(chd[x][0],v);
   else return max(val[x],pred(chd[x][1],v));
}
int find(int x,int k){
    if(k<=siz[chd[x][0]])return find(chd[x][0],k);
    else if(k<=siz[chd[x][0]]+cnt[x])return val[x];
    else return find(chd[x][1],k-siz[chd[x][0]]-cnt[x]);
}
void splay(int &x,int v){
    if(v==val[x])return;
    else splay(chd[x][v>val[x]],v),rotate(x,v>val[x]);
}
int n,mi,delta,ans;
char op;int k;
int main(){
    sf("%d%d",&n,&mi);
    lp(i,1,n){
        op=getchar();
        op=getchar();
        sf("%d",&k);
        switch(op){
            case 'I':if(k-delta>=mi)insert(rt,k-delta);break;
            case 'A':delta+=k,mi-=k;break;
            case 'S':delta+=-k,mi-=-k;break;
            case 'F':pf("%d\n",k>siz[rt]?-1:find(rt,siz[rt]-k+1)+delta);break;
        }
        int t=pred(rt,mi);
        if(t!=-(~0u>>1)){
            splay(rt,t);
            ans+=siz[chd[rt][0]]+cnt[rt];
            rt=chd[rt][1];
        }
    }
    pf("%d\n",ans);
    //ps;
    return 0;
}
