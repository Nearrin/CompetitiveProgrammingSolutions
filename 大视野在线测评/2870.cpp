#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<queue>
#include<utility>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
vector<int>to[50010];int wei[50010],del[50010],n;long long ans;
bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first!=b.first)return a.first<b.first;
    else return a.second<a.second;
}
void solve(int rt){
    static int pr[50010],sz[50010];
    queue<int>qu;qu.push(rt);pr[rt]=0;
    vector<int>tmp;
    while(!qu.empty()){
        int u=qu.front();qu.pop();tmp.push_back(u);
        lp(i,0,int(to[u].size()-1)){
            int v=to[u][i];
            if(!del[v]&&v!=pr[u]){
                pr[v]=u;
                qu.push(v);
            }
        }
    }
    lp(i,0,int(tmp.size()-1))sz[tmp[i]]=1;
    rp(i,int(tmp.size()-1),0)sz[pr[tmp[i]]]+=sz[tmp[i]];
    if(sz[rt]==1){ans=max(ans,(long long)wei[rt]);return;}
    else if(sz[rt]==2){
        ans=max(ans,(long long)wei[tmp[0]]);
        ans=max(ans,(long long)wei[tmp[1]]);
        ans=max(ans,(long long)min(wei[tmp[0]],wei[tmp[1]])*2);
        return;
    }
    int ct=-1,cm=-1;
    lp(i,0,int(tmp.size()-1)){
        int u=tmp[i];
        int cu=0;
        lp(j,0,int(to[u].size()-1)){
            int v=to[u][j];
            if(!del[v]&&v!=pr[u]){
                cu=max(cu,sz[v]);
            }
        }
        cu=max(cu,sz[rt]-sz[u]);
        if(cm==-1||cu<cm){
            ct=u;cm=cu;
        }
    }
    vector<int>dol,dor;
    int ty=0;
    lp(i,0,int(to[ct].size()-1)){
        int v=to[ct][i];
        if(!del[v]&&v!=pr[ct]){
            if(ty+sz[v]<=sz[rt]/2){
                dol.push_back(v);
                ty+=sz[v];
            }else
                dor.push_back(v);
        }
    }
    dor.push_back(pr[ct]);
    lp(i,0,int(dol.size()-1)){
        del[dol[i]]=1;
    }
    solve(ct);
    lp(i,0,int(dol.size()-1)){
        del[dol[i]]=0;
    }
    lp(i,0,int(dor.size()-1)){
        del[dor[i]]=1;
    }
    solve(ct);
    lp(i,0,int(dor.size()-1)){
        del[dor[i]]=0;
    }
    qu=queue<int>();qu.push(ct);pr[ct]=0;
    static int len[50010],mii[50010],typ[50010];len[ct]=1;mii[ct]=wei[ct];
    lp(i,0,int(dol.size()-1))typ[dol[i]]=0;
    lp(i,0,int(dor.size()-1))typ[dor[i]]=1;
    while(!qu.empty()){
        int u=qu.front();qu.pop();
        lp(i,0,int(to[u].size()-1)){
            int v=to[u][i];
            if(!del[v]&&v!=pr[u]){
                pr[v]=u;
                len[v]=len[u]+1;
                mii[v]=min(mii[u],wei[v]);
                if(u!=ct)typ[v]=typ[u];
                qu.push(v);
            }
        }
    }
    vector<pair<int,int> >dp1,dp2,dq1,dq2;
    lp(i,0,int(tmp.size()-1)){
        int u=tmp[i];
        if(u!=ct){
            if(typ[u]==0)dp1.push_back(make_pair(mii[u],len[u]));
            else dp2.push_back(make_pair(mii[u],len[u]));
        }
    }
    sort(dp1.begin(),dp1.end(),cmp);
    sort(dp2.begin(),dp2.end(),cmp);
    lp(i,0,int(dp1.size()-1)){
        while(dq1.size()>0&&dq1.back().second<=dp1[i].second)
            dq1.pop_back();
        if(dq1.empty()||dq1.back()!=dp1[i])
            dq1.push_back(dp1[i]);
    }
    lp(i,0,int(dp2.size()-1)){
        while(dq2.size()>0&&dq2.back().second<=dp2[i].second)
            dq2.pop_back();
        if(dq2.empty()||dq2.back()!=dp2[i])
            dq2.push_back(dp2[i]);
    }
    //lp(i,0,int(tmp.size()-1))pf("[%d]",tmp[i]);pf("{%d}\n",ct); 
    //lp(i,0,int(dq1.size()-1))pf("[%d,%d]",dq1[i].first,dq1[i].second);pf("\n");
    //lp(i,0,int(dq2.size()-1))pf("[%d,%d]",dq2[i].first,dq2[i].second);pf("\n");pf("\n");
    int pll=0;
    int prr=-1;
    for(;pll<dq1.size();++pll){
        while(prr+1<dq2.size()&&dq2[prr+1].first<dq1[pll].first)++prr;
        if(prr+1!=dq2.size()){
            ans=max(ans,((long long)dq1[pll].first)*(dq2[prr+1].second+dq1[pll].second-1));
        }
    }
    swap(dq1,dq2);
    pll=0;
    prr=-1;
    for(;pll<dq1.size();++pll){
        while(prr+1<dq2.size()&&dq2[prr+1].first<dq1[pll].first)++prr;
        if(prr+1!=dq2.size()){
            ans=max(ans,((long long)dq1[pll].first)*(dq2[prr+1].second+dq1[pll].second-1));
        }
    }
}
int main(){
    sf("%d",&n);
    lp(i,1,n)sf("%d",&wei[i]);
    lp(i,1,n-1){
        int x,y;sf("%d%d",&x,&y);
        to[x].push_back(y);
        to[y].push_back(x);
    }
    solve(1);
    pf("%lld\n",ans);
    //ps;
    return 0;
}
/*
10
2 3 5 9 4 5 5 3 1 1
1 10
1 2
2 8
2 9
1 3
1 5
3 4
5 6
6 7
*/
