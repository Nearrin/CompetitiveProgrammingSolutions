#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<stack>
#include<map>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
using namespace std;
typedef long long ll;
int a[21][50010],l[21][50010],k,n,r,p[50010],g[50010]; 
int main(){
    sf("%d%d",&k,&n);
    lp(i,1,k){
        static char tmp[50010];
        sf("%s",tmp+1);stack<int>stk;
        lp(j,1,n){
            a[i][j]=a[i][j-1]+(tmp[j]=='('?1:-1);
            while(!stk.empty()&&a[i][stk.top()]>=a[i][j])stk.pop();
            if(stk.empty())l[i][j]=-1;
            else l[i][j]=stk.top();
            stk.push(j);
        }
    }
    /*lp(i,1,k){
        lp(j,1,n)pf("%d ",a[i][j]);
        pf("\n"); 
    }
    lp(i,1,k){
        lp(j,1,n)pf("%d ",l[i][j]);
        pf("\n"); 
    }*/
    map<vector<int>,int>mp;mp[vector<int>(k,0)]=0;
    lp(i,1,n){
        vector<int>t;
        lp(j,1,k)t.pb(a[j][i]);
        if(mp.count(t)){
            int u=mp[t];
            int f=0;
            lp(j,1,k)if(l[j][i]>u){f=1;break;}
            if(!f)p[u+1]=p[i]=i;
        }
        mp[t]=i; 
    }
    rp(i,n,1){
        if(p[i]!=0&&p[i]!=i){
            if(p[i]!=n&&p[p[i]+1]!=0&&p[p[i]+1]!=p[i]+1)
                g[i]=g[p[i]+1]+1;
            else
                g[i]=1;
            r+=g[i];
        }
    }
    pf("%d\n",r);
    //ps;
    return 0;
}
