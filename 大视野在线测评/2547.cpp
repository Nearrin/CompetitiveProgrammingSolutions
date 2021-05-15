#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int M,N,K,T;
int Qx[110],Qy[110],Bx[110],By[110],Tx,Ty;
int Tgx[110],Tgy[110],Tgr[110];
int Hei[110][110];
int Dp[110][110][110][3];//1Q2B
void init(){
    sf("%d%d%d%d",&M,&N,&K,&T);
    lp(i,1,K)sf("%d%d",&Bx[i],&By[i]);
    lp(i,1,K)sf("%d%d",&Qx[i],&Qy[i]);
    sf("%d%d",&Tx,&Ty);
    lp(i,1,T)sf("%d%d%d",&Tgx[i],&Tgy[i],&Tgr[i]);
    lp(i,1,M)lp(j,1,N)sf("%d",&Hei[i][j]);
}
struct node{
    node(int a,int b,int c):
        x(a),y(b),z(c){}
    int x,y,z;
};
bool operator<(node a,node b){
    return a.z<b.z;
}
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
void mkdp(){
    lp(tg,1,T){
        priority_queue<pair<int,node> >qu;
        lp(i,1,M)lp(j,1,N)Dp[tg][i][j][1]=Dp[tg][i][j][2]=~0u>>1;
        Dp[tg][Tgx[tg]][Tgy[tg]][1]=Dp[tg][Tgx[tg]][Tgy[tg]][2]=0;
        qu.push(make_pair(-0,node(Tgx[tg],Tgy[tg],1)));
        qu.push(make_pair(-0,node(Tgx[tg],Tgy[tg],2)));
        while(!qu.empty()){
            int d=-qu.top().first;
            int x=qu.top().second.x;
            int y=qu.top().second.y;
            int z=qu.top().second.z;
            qu.pop();if(Dp[tg][x][y][z]!=d)continue;
            lp(i,0,3){
                int xt=x+dir[i][0],yt=y+dir[i][1];
                if(xt>M||xt<1||yt>N||yt<1)continue;
                if(z==1){
                    if(Hei[xt][yt]>=Hei[x][y]&&Dp[tg][xt][yt][1]>Dp[tg][x][y][1])
                        Dp[tg][xt][yt][1]=Dp[tg][x][y][1],
                        qu.push(make_pair(-Dp[tg][xt][yt][1],node(xt,yt,1)));
                    if(Hei[xt][yt]>=Hei[x][y]&&Dp[tg][xt][yt][2]>Dp[tg][x][y][1]+1)
                        Dp[tg][xt][yt][2]=Dp[tg][x][y][1]+1,
                        qu.push(make_pair(-Dp[tg][xt][yt][2],node(xt,yt,2)));
                }else{
                    if(Hei[xt][yt]<=Hei[x][y]&&Dp[tg][xt][yt][2]>Dp[tg][x][y][2])
                        Dp[tg][xt][yt][2]=Dp[tg][x][y][2],
                        qu.push(make_pair(-Dp[tg][xt][yt][2],node(xt,yt,2)));
                    if(Hei[xt][yt]<=Hei[x][y]&&Dp[tg][xt][yt][1]>Dp[tg][x][y][2]+1)
                        Dp[tg][xt][yt][1]=Dp[tg][x][y][2]+1,
                        qu.push(make_pair(-Dp[tg][xt][yt][1],node(xt,yt,1)));
                }
            } 
        }
        /*lp(i,1,8)pf("-");pf("\n");
        lp(i,1,M){
            lp(j,1,N)pf("[%d]",Dp[tg][i][j][1]);
            pf("\n");
        }
        pf("\n");
        lp(i,1,M){
            lp(j,1,N)pf("[%d]",Dp[tg][i][j][2]);
            pf("\n");
        }
        lp(i,1,8)pf("-");pf("\n");*/
    }
}
struct edge{
    edge(){}
    edge(int a,int b):
        v(a),c(b){}
    int v,c;
}edges[100010];//lazy....
vector<int>bg[1010];
int nw,vcnt;
void add(int u,int v,int c){
    edge&e=edges[++nw];
    e.v=v;e.c=c;
    bg[u].push_back(nw);
}
//S 1
//Q 2~K+1  i+1
//B K+2,2*K+1 K+1+i
//Target 2*K+2,2*K+1+T 2*K+1+i
//T 2*K+T+2
int dis[1010];
int dfs(int u,int f){
    if(u==vcnt)return f;
    int g=f;
    lp(i,0,int(bg[u].size()-1)){
        edge&e=edges[bg[u][i]];
        edge&ev=edges[bg[u][i]^1];
        if(e.c&&dis[e.v]+1==dis[u]){
            int t=dfs(e.v,min(g,e.c));
            g-=t,e.c-=t,ev.c+=t;
            if(!g)return f;
        }
    }
    ++dis[u];
    return f-g;
}
int isap(){
    lp(i,1,vcnt)dis[i]=0;
    int r=0;
    while(dis[1]<vcnt)r+=dfs(1,~0u>>1);
    return r;
}
bool check(int x){
    nw=1;vcnt=2+2*K+T;
    lp(i,1,vcnt)bg[i].clear();
    lp(i,1,K)add(1,i+1,1),add(i+1,1,0);
    lp(i,1,K)add(1,K+i+1,1),add(K+i+1,1,0);
    lp(i,1,T)add(2*K+1+i,2*K+T+2,Tgr[i]),
        add(2*K+T+2,2*K+1+i,0);
    lp(i,1,K)lp(j,1,T)if(Dp[j][Qx[i]][Qy[i]][1]<=x)
        add(i+1,2*K+1+j,~0u>>1),
        add(2*K+1+j,i+1,0);//pf("[%d,%d,%d]",x,i,j);
    lp(i,1,K)lp(j,1,T)if(Dp[j][Bx[i]][By[i]][2]<=x)
        add(K+1+i,2*K+1+j,~0u>>1),
        add(2*K+1+j,K+1+i,0);
    return isap()+x>=2*K;
}
void solve(){
    int l=-1,r=2*K;
    while(l+1<r){
        int m=(l+r)/2;
        if(check(m))r=m;
        else l=m; 
    } 
    pf("%d\n",r); 
}
int main(){
    init();
    mkdp();
    solve();
    //ps;
    return 0;
}
