#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
int n,m;char mp[15][15];
vector<pair<ll,int> >hs[2][4007];
void add(int t,ll s,int d){
    vector<pair<ll,int> >&h=hs[t][s%4007];
    lp(i,0,int(h.size()-1))
        if(h[i].first==s){
            h[i].second=(h[i].second+d)%10007;
            return;
        }
    h.push_back(make_pair(s,d)); 
}
void clear(int d){
    lp(i,0,4006)hs[d][i].clear(); 
}
int code[15];
void dec(ll s){
    lp(i,1,m+1)code[i]=(s&7),s>>=3;
}
ll enc(){
    static int id[15];
    lp(i,1,m+1)id[code[i]]=-1;
    id[0]=0;int nw=0;
    lp(i,1,m+1)if(id[code[i]]==-1)
        id[code[i]]=++nw;
    ll r=0;
    rp(i,m+1,1){
        r<<=3;
        r+=id[code[i]];
    }
    return r;
}
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,n)sf("%s",mp[i]+1);
    int cur=0,pre=1;
    add(cur,0,1);
    lp(i,1,n)lp(j,1,m){
        swap(cur,pre);
        clear(cur);
        lp(k,0,4006){
            lp(l,0,int(hs[pre][k].size()-1)){
                ll s=hs[pre][k][l].first;int d=hs[pre][k][l].second;
                dec(s);int left=code[j],up=code[j+1];
                if(i==1&&j==1){
                    if(j!=m&&mp[i][j+1]!='#'){
                        code[1]=0;code[2]=1;
                        add(cur,j==m?(enc()<<3):enc(),d);
                    }
                    if(i!=n&&mp[i+1][j]!='#'){
                        code[1]=1;code[2]=0;
                        add(cur,j==m?(enc()<<3):enc(),d);
                    }
                }else if(i==n&&j==m){
                    if((left&&!up)||(up&&!left)){
                        code[j]=code[j+1]=0;
                        add(cur,j==m?(enc()<<3):enc(),d);
                    }
                }else if(mp[i][j]=='#'){
                    code[j]=code[j+1]=0;
                    add(cur,j==m?(enc()<<3):enc(),d);
                }else{
                    if(left&&up){
                        if(left!=up){
                            code[j]=code[j+1]=0;
                            lp(u,1,m+1)if(code[u]==left)code[u]=up;
                            add(cur,j==m?(enc()<<3):enc(),d);
                        }
                    }else if((left&&!up)||(up&&!left)){
                        int t=left?left:up;
                        if(i!=n&&mp[i+1][j]!='#'){
                            code[j]=t;code[j+1]=0;
                            add(cur,j==m?(enc()<<3):enc(),d);
                        }
                        if(j!=m&&mp[i][j+1]!='#'){
                            code[j]=0;code[j+1]=t;
                            add(cur,j==m?(enc()<<3):enc(),d);
                        }
                    }else{
                        code[j]=code[j+1]=0;
                        add(cur,j==m?(enc()<<3):enc(),d);
                        if(i!=n&&mp[i+1][j]!='#'&&j!=m&&mp[i][j+1]!='#'){
                            code[j]=code[j+1]=13;
                            add(cur,j==m?(enc()<<3):enc(),d);
                        }
                    }
                }
            }
        }
    }
    int ans=0;
    lp(i,0,4006)
        lp(j,0,int(hs[cur][i].size()-1))
            ans=(ans+hs[cur][i][j].second)%10007;
    pf("%d\n",ans);
    //ps;
    return 0;
}
