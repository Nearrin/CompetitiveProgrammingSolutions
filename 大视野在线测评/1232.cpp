#include<cstdio>
#include<algorithm>
#include<iostream>
#define sf scanf
#define pf printf
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define ps system("pause");
using namespace std;
struct edge{
    int u,v,w;
}E[100010];
bool operator<(edge x,edge y){
    return x.w<y.w;
}
int n,p,c[100010];
int prt[100010],rak[100010];
int find(int x){
    return x==prt[x]?x:prt[x]=find(prt[x]);
}
void link(int x,int y){
    x=find(x),y=find(y);
    if(rak[x]<rak[y])prt[x]=y;
    else prt[y]=x;
    if(rak[x]==rak[y])++rak[x];
}
int main(){
    sf("%d%d",&n,&p);
    lp(i,1,n)sf("%d",&c[i]);
    lp(i,1,p){
        sf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
        E[i].w=E[i].w*2+c[E[i].u]+c[E[i].v];
    }
    lp(i,1,n)prt[i]=i;
    sort(E+1,E+p+1);
    int ans=0;
    lp(i,1,p){
        if(find(E[i].u)!=find(E[i].v)){
            ans+=E[i].w;
            link(E[i].u,E[i].v);
        }
    }
    ans+=*min_element(c+1,c+n+1);
    cout<<ans<<endl;
    //ps;
    return 0;
}
    
