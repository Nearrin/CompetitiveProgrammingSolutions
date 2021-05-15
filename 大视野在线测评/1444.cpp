#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int n,l,m;
namespace acm{
    int ch[2110][26],fa[2110],tg[2110],nw=1;
    int ins(string s){
        int u=1;lp(i,0,int(s.size()-1)){
            if(!ch[u][s[i]-'A'])ch[u][s[i]-'A']=++nw;
            u=ch[u][s[i]-'A'];
        }
        tg[u]=1;
        return u;
    }
    void bud(){
        queue<int>qu;
        lp(i,0,m-1)
            if(!ch[1][i])ch[1][i]=1;
            else fa[ch[1][i]]=1,qu.push(ch[1][i]);
        while(!qu.empty()){
            int u=qu.front();qu.pop();
            lp(i,0,m-1)
                if(!ch[u][i])ch[u][i]=ch[fa[u]][i];
                else fa[ch[u][i]]=ch[fa[u]][i],qu.push(ch[u][i]);
        } 
        lp(i,1,nw)if(tg[i])lp(j,0,m-1)ch[i][j]=0;
    }
}
namespace gus{
    double a[2110][2110];int n;
    double fbs(double x){
        return x>0?x:-x;
    }
    double ans[110];
    void solve(){
        lp(i,1,n){
            int j=1;while(j<=n&&fbs(a[i][j])<1e-8)++j;
            if(j>n)continue;
            double t=a[i][j];lp(k,0,n)a[i][k]/=t;
            lp(k,1,n)if(k!=i){
                t=a[k][j];
                lp(l,0,n)a[k][l]-=a[i][l]*t;
            }
        }
        lp(i,1,n)lp(j,1,n)if(fbs(a[i][j])>1e-2)ans[j]=a[i][0];
    }
    void print(){
        lp(i,1,n){
            lp(j,0,m)pf("[%.1lf]",a[i][j]);
            pf("\n"); 
        }
    }
}
int mp[2110];double gl[2110];
int bj[2110];
int main(){
    cin>>n>>l>>m;
    lp(i,0,m-1){
        double p,q;cin>>p>>q;gl[i]=p/q;
    }
    lp(i,1,n){
        string t;cin>>t;
        lp(j,0,int(t.size()-1))if(gl[t[j]-'A']<1e-8)bj[i]=1;
        if(!bj[i])mp[i]=acm::ins(t);
    }
    acm::bud();
    gus::n=acm::nw;
    lp(i,1,acm::nw)gus::a[i][i]=-1;
    lp(i,1,acm::nw){
        lp(j,0,m-1)if(acm::ch[i][j])
            gus::a[acm::ch[i][j]][i]+=gl[j];
    }
    lp(i,1,acm::nw)if(acm::tg[i])gus::a[1][i]=1;else gus::a[1][i]=0;
    gus::a[1][0]=1;
    gus::solve();
    //gus::print();
    lp(i,1,n)pf("%.2lf\n",bj[i]?0:gus::ans[mp[i]]);
    //ps;
    return 0;
} 
/*
3 2 2
1 1
0 1
AB
BA
AA
3 4 2
1 2
1 2
AABA
ABAA
BAAA
1 2 2
1 1
0 1
AB
*/
