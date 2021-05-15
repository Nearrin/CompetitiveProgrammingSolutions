#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define sf scanf
#define pf printf
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define ps system("pause");
using namespace std;
struct edge{
    int nxt;
    char c,w;
    short u,v;
}E[4010010];
int E_now=1,bg[4010],pre[4010],dis[4010],in[4010],V_cnt;
int que[4010],bck;
bool spfa(){
    lp(i,1,V_cnt)dis[i]=-(~0u>>1),pre[i]=in[i]=0;
    bck=1;
    que[1]=1;in[1]=1,dis[1]=0;
    while(bck){
        int u=que[bck--];in[u]=0;
        for(int p=bg[u];p;p=E[p].nxt){
            int v=E[p].v,w=E[p].w;
            if(E[p].c&&dis[u]+w>dis[v]){
                dis[v]=dis[u]+w;
                pre[v]=p;
                if(!in[v]){
                    que[++bck]=v;
                    in[v]=1;
                }
            }
        }
    }
    return dis[V_cnt]!=-(~0u>>1);
}
int work(){
    int ret=0;
    while(spfa()){
        int d=~0U>>1;
        for(int p=pre[V_cnt];p;p=pre[E[p].u])
            d=min(d,int(E[p].c));
        for(int p=pre[V_cnt];p;p=pre[E[p].u])
            E[p].c-=d,E[p^1].c+=d;
        ret+=d*dis[V_cnt];
    }
    return ret;
}
void add_edge(int u,int v,int w,int c){
    E_now=E_now+1;
    E[E_now].u=u,E[E_now].v=v;
    E[E_now].w=w,E[E_now].c=c;
    E[E_now].nxt=bg[u];bg[u]=E_now;
    E_now=E_now+1;
    E[E_now].u=v,E[E_now].v=u;
    E[E_now].w=-w,E[E_now].c=0;
    E[E_now].nxt=bg[v];bg[v]=E_now;
}
int n;
struct poit{
    int x,y;
}poits[2010];
bool operator<(poit a,poit b){
    return a.x!=b.x?a.x<b.x:a.y<b.y;
}
//1和2源点，V_cnt汇点，对于点i对应的两点是(i+1)*2和(i+1)*2+1 
int main(){
    sf("%d",&n);
    lp(i,1,n)sf("%d%d",&poits[i].x,&poits[i].y);
    sort(poits+1,poits+n+1);
    V_cnt=2+2*n+4;
    lp(i,1,n)
        lp(j,i+1,n)
            if(poits[i].y<=poits[j].y)
                add_edge((i+1)*2+1,(j+1)*2,0,1);
    lp(i,1,n)add_edge((i+1)*2,(i+1)*2+1,1,1);
    add_edge(1,2,0,2);
    lp(i,1,n)add_edge(2,(i+1)*2,0,1);
    lp(i,1,n)add_edge((i+1)*2+1,V_cnt,0,1);
    pf("%d\n",work());
    //pf("%d\n",E_now);
    return 0;
}
