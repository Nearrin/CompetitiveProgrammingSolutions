#include<algorithm>
#include<cctype>
#include<climits>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>
#define sf scanf
#define si(a)scanf("%d",&a)
#define pf printf
#define pi(a)printf("%d",a)
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b)for(int i=a;i<=int(b);++i)
#define rp(i,a,b)for(int i=int(a);i>=b;--i)
#define vp(i,a)for(int i=0;i<int(a.size());++i)
#define wp(i,a)for(int i=int(a.size())-1;i>=0;--i)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
bool cmp(pii a,pii b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}
struct tri{
    tri(int u,int v,int w,int x){
        a=u;
        b=v;
        c=w;
        d=x;
    }

    int a,b,c,d;
};vector<tri>ansx;
  static int b[110][110];
  int up[110][110];
  int lft[110][110];
  int rht[110][110];
  void solve(int x1,int y1,int x2,int y2){
      for(int y=y2;y>=y1;--y){
          for(int x=x1;x<=x2;++x){
              if(b[x][y]==0)
                  up[x][y]=0;
              else if(y==y2)
                  up[x][y]=1;
              else
                  up[x][y]=up[x][y+1]+1;
          }
      }

    for(int y=y2;y>=y1;--y){
            vector<pair<int,int> >q1;
         for(int x=x1;x<=x2;++x){
                while(!q1.empty()&&q1.back().first>=up[x][y]){
                    q1.pop_back();
                }
                if(q1.empty())
                    lft[x][y]=x-x1+1;
                else
                    lft[x][y]=x-q1.back().second;
                q1.push_back(mp(up[x][y],x));
           }
     }

    for(int y=y2;y>=y1;--y){
            vector<pair<int,int> >q1;
         for(int x=x2;x>=x1;--x){
                while(!q1.empty()&&q1.back().first>=up[x][y]){
                    q1.pop_back();
                }
                if(q1.empty())
                    rht[x][y]=x2-x+1;
                else
                    rht[x][y]=q1.back().second-x;
                q1.push_back(mp(up[x][y],x));
           }
     }
    int ansi,ansj;
    int ans=0;
    for(int y=y2;y>=y1;--y){
        for(int x=x1;x<=x2;++x){
            if(up[x][y]*(lft[x][y]+rht[x][y]-1)>ans){
                ans=up[x][y]*(lft[x][y]+rht[x][y]-1);
                ansi=x;
                ansj=y;
            }
        }
    }
     if(ans==0)return;
    int tx1=ansi-lft[ansi][ansj]+1;
    int tx2=ansi+rht[ansi][ansj]-1;
    int ty1=ansj;
    int ty2=ansj+up[ansi][ansj]-1;

    ansx.push_back(tri(tx1,ty1,tx2,ty2));
    if(tx1>x1)solve(x1,y1,tx1-1,y2);
    if(tx2<x2)solve(tx2+1,y1,x2,y2);
    if(ty1>y1)solve(tx1,y1,tx2,ty1-1);
    if(ty2<y2)solve(tx1,ty2+1,tx2,y2);
 }

bool check(tri u,tri v){
    if(u.c+1==v.a&&u.b==v.b&&u.d==v.d)
        return true;
    if(v.c+1==u.a&&u.b==v.b&&u.d==v.d)
        return true;
    if(u.d+1==v.b&&u.a==v.a&&u.c==v.c)
        return true;
    if(v.d+1==u.b&&u.a==v.a&&u.c==v.c)
        return true;
    return false;
}
tri check2(tri u,tri v){
    if(u.c+1==v.a&&u.b==v.b&&u.d==v.d)
        return tri(u.a,u.b,v.c,u.d);
    if(v.c+1==u.a&&u.b==v.b&&u.d==v.d)
        return tri(v.a,u.b,u.c,u.d);
    if(u.d+1==v.b&&u.a==v.a&&u.c==v.c)
        return tri(u.a,u.b,u.c,v.d);
    if(v.d+1==u.b&&u.a==v.a&&u.c==v.c)
        return tri(u.a,v.b,u.c,u.d);
}
int main(){
    int T;si(T);
    lp(I,1,T){
        ansx.clear();
        int n,m;
        si(n),si(m);
        static int a[110][110];
        lp(i,1,n)lp(j,1,m)si(a[i][j]);
        static int count[1010];
        lp(i,1,1000)count[i]=0;
        lp(i,1,n)lp(j,1,m){
            ++count[a[i][j]];
        }
        static std::vector<pair<int,int> >pos[1010];
        lp(i,1,1000)pos[i].clear();
        lp(i,1,n)lp(j,1,m){
            pos[a[i][j]].push_back(mp(i,j));
        }
        lp(i,1,1000)
                sort(pos[i].begin(),pos[i].end());

        lp(i,1,n)lp(j,1,m)b[i][j]=0;
        lp(i,1,1000){
            for(int u=0;u<count[i]/2;++u)
                b[pos[i][u].first][pos[i][u].second]=1;
        }
        /*lp(i,1,n){
                lp(j,1,m)
                    cout<<b[i][j]<<" ";
                cout<<endl;
        }*/
        vector<tri>ans2;
        solve(1,1,n,m);
        
        int ty=0;
        static int mch[10010];
        vp(i,ansx)
            mch[i]=-1;
        vp(i,ansx)
                lp(j,i+1,int(ansx.size()-1))
                    if(mch[i]==-1&&mch[j]==-1&&check(ansx[i],ansx[j]))
                        mch[i]=j,mch[j]=i;
        vp(i,ansx){
            if(mch[i]==-1)
                ans2.push_back(ansx[i]);
            else if(mch[i]>i){
                ans2.push_back(check2(ansx[i],ansx[mch[i]]));
            }
        }
        ansx=ans2;
        cout<<ansx.size()<<endl;
        vp(i,ansx)cout<<ansx[i].a<<" "<<ansx[i].b<<" "<<ansx[i].c<<" "<<ansx[i].d<<endl;
    }
    return 0;
}
