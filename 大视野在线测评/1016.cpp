#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<utility>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int n,m;
struct edge{
    edge(){sf("%d%d%d",&u,&v,&w);}
    int u,v,w;
};
bool operator<(edge a,edge b){
    return a.w<b.w;
}
vector<edge>eg;
int pr[110];
int fd(int x){return pr[x]==x?x:pr[x]=fd(pr[x]);}
int ans=1;
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,m)eg.push_back(edge());
    sort(eg.begin(),eg.end());
    for(int i=0,j=0;i<eg.size();i=j+1,j=i){
        while(j+1<eg.size()&&eg[j+1].w==eg[j].w)++j;
        vector<edge>tmp;
        lp(k,i,j)tmp.push_back(eg[k]);
        int cnt=0,exc=0;
        lp(l,1,n)pr[l]=l;
        lp(l,0,int(tmp.size()-1)){
            int u=tmp[l].u,v=tmp[l].v;
            if(fd(u)!=fd(v))
                pr[fd(u)]=v;
        }
        lp(l,1,n)exc+=(pr[l]==l);
        lp(k,0,(1<<tmp.size())-1){
            int fail=0;
            lp(l,1,n)pr[l]=l;
            for(int l=0;l<tmp.size();++l)
                if((k>>l)&1){
                    int u=tmp[l].u,v=tmp[l].v;
                    if(fd(u)==fd(v)){fail=1;break;}
                    else pr[fd(u)]=v;
                }
            int tc=0;
            lp(l,1,n)tc+=(pr[l]==l);
            if(!fail&&tc==exc)++cnt;
        }
        ans=ans*cnt%31011;
        lp(l,1,n)pr[l]=l;
        lp(l,0,int(tmp.size()-1)){
            int u=tmp[l].u,v=tmp[l].v;
            if(fd(u)!=fd(v))
                pr[fd(u)]=v;
        }
        static int tag[110];int nw=0;
        lp(l,1,n)if(pr[l]==l)tag[l]=++nw;
        n=nw;
        lp(l,0,int(eg.size()-1))
            eg[l].u=tag[fd(eg[l].u)],
            eg[l].v=tag[fd(eg[l].v)];
    }
    pf("%d\n",ans*(n==1));
    //ps;
    return 0;
}
