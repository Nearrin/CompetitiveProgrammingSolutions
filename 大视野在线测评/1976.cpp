#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
struct edge{int v,c;}edges[40*40*40*6*10];int nw=1;
vector<int>bg[40*40*40+100];
void add(int u,int v,int c){
    //pf("[%d,%d,%d]\n",u,v,c);
    bg[u].push_back(++nw);
    edge&e=edges[nw];e.v=v;e.c=c;
}
int dis[40*40*40+100],gap[40*40*40+100],vcnt;
int dfs(int u,int f){
    if(u==vcnt)return f;
    int g=f;
    lp(i,0,int(bg[u].size()-1)){
        edge&e=edges[bg[u][i]],&ev=edges[bg[u][i]^1];
        if(e.c&&dis[u]==dis[e.v]+1){
            int t=dfs(e.v,min(g,e.c));
            e.c-=t;ev.c+=t;g-=t;
            if(!g||dis[1]==vcnt)return f-g;
        }
    }
    if((--gap[dis[u]])==0)dis[1]=vcnt;
    ++gap[++dis[u]];
    return f-g;
}
int isap(){
    gap[0]=vcnt;int r=0;while(dis[1]<vcnt)r+=dfs(1,~0u>>1);
    return r;
}
int n;
int tr(int x,int y,int z){return (x-1)*n*n+(y-1)*n+z+1;}
#define st 1
#define et tr(n,n,n)+1
int dir[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
int chk(int x){
    return x>0&&x<=n;
}
int main(){
    int cnt=0;
    sf("%d",&n);
    lp(i,1,n)lp(j,1,n){
        char op[110];sf("%s",op+1);
        lp(k,1,n){
            if(op[k]=='P'){
                if((i+j+k)%2){
                    add(st,tr(i,j,k),~0u>>1);
                    add(tr(i,j,k),st,0);
                }else{
                    add(et,tr(i,j,k),0);
                    add(tr(i,j,k),et,~0u>>1);
                }
            }else if(op[k]=='N'){
                if((i+j+k)%2){
                    add(et,tr(i,j,k),0);
                    add(tr(i,j,k),et,~0u>>1);
                }else{
                    add(st,tr(i,j,k),~0u>>1);
                    add(tr(i,j,k),st,0);
                }
            }
            lp(l,0,5){
                int ii=i+dir[l][0],jj=j+dir[l][1],kk=k+dir[l][2];
                if(chk(ii)&&chk(jj)&&chk(kk)&&((i<ii)||(i==ii&&j<jj)||(i==ii&&j==jj&&k<kk))){
                    add(tr(i,j,k),tr(ii,jj,kk),1);
                    add(tr(ii,jj,kk),tr(i,j,k),1);
                    ++cnt;
                }
            }
        }
    }
    vcnt=et;
    pf("%d\n",cnt-isap());
    //ps;
    return 0;
}
