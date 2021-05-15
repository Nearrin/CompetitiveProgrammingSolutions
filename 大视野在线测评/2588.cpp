#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<queue>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace seg{
    struct node{
        node(node*a,node*b,int c,int d,int e){
            ch[0]=a;ch[1]=b;l=c;r=d;cnt=e;
        }
        node*ch[2];int l,r,cnt;  
    };
    node*add(node*x,int p){
        if(x->l==x->r)
            return new node(0,0,x->l,x->r,x->cnt+1);
        else{
            int m=x->l+(x->r-x->l)/2;
            if(p<=m){
                return new node(add(x->ch[0],p),x->ch[1],x->l,x->r,x->cnt+1);
            }else{
                return new node(x->ch[0],add(x->ch[1],p),x->l,x->r,x->cnt+1);
            }
        }
    }
    node*build(int l,int r){
        node*x=new node(0,0,l,r,0);
        if(l!=r){
            int m=(l+r)/2;
            x->ch[0]=build(l,m);
            x->ch[1]=build(m+1,r);
        }
        return x;
    }
    int ask(vector<node*>&x,vector<node*>&y,int l,int r,int k){
        if(l==r)return l;
        else{
            int t=0;
            lp(i,0,int(x.size()-1))
                    t+=x[i]->ch[0]->cnt;
            lp(i,0,int(y.size()-1))
                    t-=y[i]->ch[0]->cnt;
            int m=l+(r-l)/2;
            if(t<=k-1){
                k-=t;
                lp(i,0,int(x.size()-1))
                        x[i]=x[i]->ch[1];
                lp(i,0,int(y.size()-1))
                        y[i]=y[i]->ch[1];
                return ask(x,y,m+1,r,k);
            }else{
                lp(i,0,int(x.size()-1))
                        x[i]=x[i]->ch[0];
                lp(i,0,int(y.size()-1))
                        y[i]=y[i]->ch[0];
                return ask(x,y,l,m,k);
            }
        }
    }
}
namespace tree{
    vector<int>to[100010];seg::node*sum[100010];
    int n,m,wei[100010];vector<int>tmp;
    void init(){
        sf("%d%d",&n,&m);
        lp(i,1,n)sf("%d",&wei[i]);
        lp(i,1,n)tmp.push_back(wei[i]);
        sort(tmp.begin(),tmp.end());
        tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
        lp(i,1,n)wei[i]=lower_bound(tmp.begin(),tmp.end(),wei[i])-tmp.begin();
        lp(i,1,n-1){
            int x,y;sf("%d%d",&x,&y);
            to[x].push_back(y);
            to[y].push_back(x); 
        }
    }
    int up[100010][21],dp[100010];
        int lca(int x,int y){
        if(dp[x]<dp[y])swap(x,y);
        lp(i,0,20)if(((dp[x]-dp[y])>>i)&1)x=up[x][i];
        if(x==y)return x;
        rp(i,20,0)
            if(up[x][i]!=up[y][i])
                x=up[x][i],y=up[y][i];
        return up[x][0];
    }
    void bfs(){
        queue<int>qu;qu.push(1);sum[1]=seg::add(seg::build(0,n-1),wei[1]);
        while(!qu.empty()){
            int u=qu.front();qu.pop();
            lp(i,0,int(to[u].size()-1)){
                int v=to[u][i];
                if(v!=up[u][0]){
                    up[v][0]=u;
                    lp(j,1,20)up[v][j]=up[up[v][j-1]][j-1];
                    dp[v]=dp[u]+1;
                    sum[v]=seg::add(sum[u],wei[v]);
                    qu.push(v);
                }
            } 
        }
        //lp(i,1,n)pf("[%d,%d]\n",up[i][0],dp[i]);
        //lp(i,1,n)lp(j,1,n)pf("[%d,%d,%d]\n",i,j,lca(i,j));
    }
    int ask(int u,int v,int k){
        vector<seg::node*>x,y;
        x.push_back(sum[u]);x.push_back(sum[v]);
        int w=lca(u,v);
        y.push_back(sum[w]);
        if(up[w][0])y.push_back(sum[up[w][0]]);
        int tp=seg::ask(x,y,0,n-1,k);
        return tmp[tp];
    }
    void prec(){
        int last=0;
        lp(i,1,m){
            int u,v,k;
            sf("%d%d%d",&u,&v,&k);
            u^=last;
            int ans=ask(u,v,k);
            last=ans;
            pf("%d",last); 
            if(i!=m)pf("\n");
        }
    }
}
int main(){
    tree::init();
    tree::bfs();
    tree::prec();
    //ps;
    return 0;
}
