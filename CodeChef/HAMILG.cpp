//#include<bits/stdc++.h>
//#define lop(i,a,b) for(int i=a;i<=int(b);++i)
//#define rlp(i,a,b) for(int i=a;i>=b;--i)
//#define vlp(i,a) for(int i=0;i<a.size();++i)
//#define mcs int css;cin>>css;lop(csn,1,css)
//#define fio ios::sync_with_stdio(0)
//#define all(a) a.begin(),a.end()
//#define pub push_back
//#define pob pop_back
//#define mkp make_pair
//#define vec vector
//#define scf scanf
//#define ptf printf
//namespace CTL{}
//using namespace CTL;
//using namespace std;
//typedef long long lli;
//typedef unsigned long long ull;
//typedef double dbl;
//typedef long double ldb;
//typedef string str;
//typedef pair<int,int> pii;




//#ifndef MAXIMUM_MATCHING
//#define MAXIMUM_MATCHING
//#include<bits/stdc++.h>
//namespace CTL{
//    using namespace std;
//    struct MaximumMatching{
//        int n;vector<int>res,nxt,mrk,vis,top,prt,rnk;
//        vector<vector<int> >to;queue<int>qu;
//        MaximumMatching(int _n):
//            n(_n),res(n+1),nxt(n+1),mrk(n+1),
//            vis(n+1),top(n+1),to(n+1),prt(n+1),rnk(n+1){}
//        int fd(int x){return x==prt[x]?x:prt[x]=fd(prt[x]);}
//        void lk(int x,int y){
//            if(rnk[x=fd(x)]>rnk[y=fd(y)])prt[y]=x;
//            else if(rnk[x]<rnk[y])prt[x]=y;
//            else prt[x]=y,++rnk[y];}
//        int lca(int x,int y){
//            static int t;++t;
//            for(;;swap(x,y))if(x){
//                x=top[fd(x)];if(vis[x]==t)return x;vis[x]=t;
//                if(!res[x])x=nxt[res[x]];else x=0;}}
//        void uni(int x,int p){
//            for(;fd(x)!=fd(p);){
//                int y=res[x],z=nxt[y];
//                if(fd(z)!=fd(p))nxt[z]=y;
//                if(mrk[y]==2)mrk[y]=1,qu.push(y);
//                if(mrk[z]==2)mrk[z]=1,qu.push(z);
//                int t=top[fd(z)];lk(x,y);lk(y,z);
//                top[fd(z)]=t;x=z;}}
//        void aug(int s){
//            for(int i=1;i<=n;++i)
//                nxt[i]=0,mrk[i]=0,top[i]=i,prt[i]=i,rnk[i]=0;
//            mrk[s]=1;qu=queue<int>();
//            for(qu.push(s);!qu.empty();){
//                int x=qu.front();qu.pop();
//                for(int i=0;i<to[x].size();++i){
//                    int y=to[x][i];
//                    if(res[x]==y||fd(x)==fd(y)||mrk[y]==2)
//                        continue;
//                    if(mrk[y]==1){
//                        int z=lca(x,y);
//                        if(fd(x)!=fd(z))nxt[x]=y;
//                        if(fd(y)!=fd(z))nxt[y]=x;
//                        uni(x,z);uni(y,z);}
//                    else if(!res[y]){
//                        for(nxt[y]=x;y;){
//                            int z=nxt[y],mz=res[z];
//                            res[z]=y;res[y]=z;y=mz;}
//                        return;
//                    }else{
//                        nxt[y]=x;mrk[res[y]]=1;
//                        qu.push(res[y]);mrk[y]=2;}}}}
//        void add(int x,int y){
//            to[x].push_back(y);to[y].push_back(x);}
//        int run(){
//            for(int i=1;i<=n;++i)if(!res[i])
//                for(int j=0;j<to[i].size();++j)
//                    if(!res[to[i][j]]){
//                        res[to[i][j]]=i;res[i]=to[i][j];break;}
//            for(int i=1;i<=n;++i)if(!res[i])aug(i);
//            int r=0;for(int i=1;i<=n;++i)if(!res[i])++r;
//            return r/2;}};}
//#endif


//int main(){
//        int n,m;
//       while(cin>>n>>m){
//        MaximumMatching mm(n);
//        for(int i=1;i<=m;++i){
//            int u,v;
//            cin>>u>>v;
//            mm.add(u,v);
//        }
//        cout<<n-mm.run()-1<<endl;}
//        return 0;
//    }
#include<bits/stdc++.h>
#define lop(i,a,b) for(int i=a;i<=int(b);++i)
#define rlp(i,a,b) for(int i=a;i>=b;--i)
#define vlp(i,a) for(int i=0;i<a.size();++i)
#define mcs int css;cin>>css;lop(csn,1,css)
#define fio ios::sync_with_stdio(0)
#define all(a) a.begin(),a.end()
#define pub push_back
#define pob pop_back
#define mkp make_pair
#define vec vector
#define scf scanf
#define ptf printf
namespace CTL{}
using namespace CTL;
using namespace std;
typedef long long lli;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldb;
typedef string str;
typedef pair<int,int> pii;
 
 
 
 
#ifndef SYMMETRIC_GAME_OF_NO_RETURN
#define SYMMETRIC_GAME_OF_NO_RETURN
#include<bits/stdc++.h>
namespace CTL{
    using namespace std;
    struct SymmetricGameOfNoReturn{
        int n;vector<int>mh,nx,mk,vs,tp,pr,rk;
        vector<bool>wi;queue<int>qu;
        vector<vector<int> >to;
        SymmetricGameOfNoReturn(int _n):
            n(_n),mh(n+1),nx(n+1),mk(n+1),wi(n+1,true),
            vs(n+1),tp(n+1),to(n+1),pr(n+1),rk(n+1){}
        int fd(int x){return x==pr[x]?x:pr[x]=fd(pr[x]);}
        void lk(int x,int y){
            if(rk[x=fd(x)]>rk[y=fd(y)])pr[y]=x;
            else if(rk[x]<rk[y])pr[x]=y;
            else pr[x]=y,++rk[y];}
        int lca(int x,int y){
            static int t;++t;
            for(;;swap(x,y))if(x){
                x=tp[fd(x)];if(vs[x]==t)return x;vs[x]=t;
                if(mh[x])x=nx[mh[x]];else x=0;}}
        void uni(int x,int p){
            for(;fd(x)!=fd(p);){
                int y=mh[x],z=nx[y];
                if(fd(z)!=fd(p))nx[z]=y;
                if(mk[y]==2)mk[y]=1,qu.push(y);
                if(mk[z]==2)mk[z]=1,qu.push(z);
                int t=tp[fd(z)];lk(x,y);lk(y,z);
                tp[fd(z)]=t;x=z;}}
        void aug(int s,int t){
            for(int i=1;i<=n;++i)
                nx[i]=0,mk[i]=0,tp[i]=i,pr[i]=i,rk[i]=0;
            mk[s]=1;qu=queue<int>();
            for(qu.push(s);!qu.empty();){
                int x=qu.front();qu.pop();if(t)wi[x]=0;
                for(int i=0;i<to[x].size();++i){
                    int y=to[x][i];
                    if(mh[x]==y||fd(x)==fd(y)||mk[y]==2)
                        continue;
                    if(mk[y]==1){
                        int z=lca(x,y);
                        if(fd(x)!=fd(z))nx[x]=y;
                        if(fd(y)!=fd(z))nx[y]=x;
                        uni(x,z);uni(y,z);}
                    else if(!mh[y]){
                        nx[y]=x;while(y){
                            int z=nx[y],mz=mh[z];
                            mh[z]=y;mh[y]=z;y=mz;}
                        return;}
                    else{
                        nx[y]=x;mk[mh[y]]=1;
                        qu.push(mh[y]);mk[y]=2;}}}}
        void add(int x,int y){
            to[x].push_back(y);to[y].push_back(x);}
        vector<bool>run(){
            for(int i=1;i<=n;++i)if(!mh[i])
                for(int j=0;j<to[i].size();++j)
                    if(!mh[to[i][j]]){
                        mh[to[i][j]]=i;mh[i]=to[i][j];break;}
            for(int i=1;i<=n;++i)if(!mh[i])aug(i,0);
            for(int i=1;i<=n;++i)if(!mh[i])aug(i,1);
            return wi;}};}
#endif
 
 
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        static vector<int>to[2010];
        SymmetricGameOfNoReturn mm(n+1);
        for(int i=1;i<=n;++i)
            to[i].clear();
        for(int i=1;i<=m;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            to[u].push_back(v);
            to[v].push_back(u);
            mm.add(u,v);
        }
        auto wi=mm.run();
        int ans=0;
        for(int i=1;i<=n;++i)if(!wi[i])++ans;
        printf("%d\n",ans);
    }
    return 0;
}