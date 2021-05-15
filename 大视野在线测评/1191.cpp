#include<cstdio>
#include<algorithm>
#include<vector> 
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int a[2010][3];
vector<int>to[4010];
int mk[4010];
vector<int>stk;
void add(int x,int vx,int y,int vy){
    to[x*2+1-vx].push_back(y*2+vy);
    to[y*2+1-vy].push_back(x*2+vx);
}
int dfs(int x){
    if(mk[x])return 1;
    if(mk[x^1])return 0;
    mk[x]=1;stk.push_back(x);
    lp(i,0,int(to[x].size()-1)){
        if(!dfs(to[x][i]))return 0;
    }
    return 1; 
}
int check(int x){
    lp(i,1,x)to[i*2].clear(),to[i*2+1].clear();
    lp(i,1,x)mk[i*2]=0,mk[i*2+1]=0;
    lp(i,1,x)
        lp(j,i+1,x){
            if(a[i][1]==a[j][1])add(i,1,j,1);
            if(a[i][1]==a[j][2])add(i,1,j,0);
            if(a[i][2]==a[j][1])add(i,0,j,1);
            if(a[i][2]==a[j][2])add(i,0,j,0);
        }
    lp(i,1,x)
        if(!mk[i*2]&&!mk[i*2+1]){
            stk.clear();
            if(!dfs(i*2)){
                lp(k,0,int(stk.size()-1))
                    mk[stk[k]]=0;
                if(!dfs(i*2+1))return 0; 
            }
        }
    return 1;
}
int main(){
    int n;
    sf("%d",&n);
    sf("%d",&n); 
    lp(i,1,n)sf("%d%d",&a[i][1],&a[i][2]);
    int l=1,r=n+1;
    while(l+1<r){
        int m=(l+r)/2;
        if(check(m))l=m;
        else r=m;
    } 
    pf("%d\n",l); 
    //ps;
    return 0;
}
