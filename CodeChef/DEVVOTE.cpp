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
#include<fstream>
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
typedef long double ld;
typedef vector<int>vi;
typedef pair<int,int>pii;


//void printv(vector<int>t){
//    vp(i,t)cout<<t[i]<<" ";
//    cout<<endl;
//}

//vector<vector<int> >state;
//int a[110];

//int vis[110][110][110];
//vector<vector<int> >dp[110][110][110];
//int tyvj;
//int cnt[110][110][110];
//vector<vector<int> > dfs(int now,int n,int sum1,int sum2){

//    if(vis[now][sum1][sum2])
//        return dp[now][sum1][sum2];
//       ++cnt[now][sum1][sum2];
//    vis[now][sum1][sum2]=1;
//    vector<vector<int> >ret;

//    if(now==n+1){
//        ret.push_back(vector<int>());
//    }else{
//        lp(i,0,n){
//            if(sum1+now*i<=n&&sum2+i<=n){
//                vector<vector<int> >hehe=dfs(now+1,n,sum1+now*i,sum2+i);
//                vp(j,hehe){
//                        hehe[j].insert(hehe[j].begin(),i);
//                        ++tyvj;
//                }
//                vp(j,hehe)
//                        ret.push_back(hehe[j]);
//            }
//        }
//    }
//    dp[now][sum1][sum2]=ret;
//    return ret;
//}
//ld f[100010][40][40];
//double calc(int n){
//    lp(i,0,n)lp(j,0,n)lp(k,0,n)vis[i][j][k]=0,dp[i][j][k].clear();
//    state=dfs(1,n,0,0);

//    vp(i,state){
//      //  cout<<i<<" ";
//         //   printv(state[i]);
//    }
//    //cout<<state.size()<<endl;

//    //cout<<"-------------------------";
//  //  cout<<tyvj<<endl;
//  //  lp(i,0,n)lp(j,0,n)lp(k,0,n)
//        //    if(cnt[i][j][k]>1)cout<<cnt[i][j][k]<<endl;
//    map<vector<int>,int>mp;
//    vp(i,state)
//            mp[state[i]]=i;
//   // cout<<1<<endl;
//    lp(j,1,n)
//        lp(i,0,int(state.size()-1))
//                lp(k,1,n){
//        if(j==1){
//            vector<int>tmp(n,0);
//            tmp[0]=1;
//            if(state[i]==tmp&&k==1)
//                f[i][j][k]=n;
//            else
//                f[i][j][k]=0;
//        }else{
//            int zps=0;
//            int zrs=0;
//            vp(u,state[i])
//                    zps+=(u+1)*state[i][u],zrs+=state[i][u];

//            if(zps!=j||state[i][k-1]==0)
//                f[i][j][k]=0;
//            else{
//                if(i==4&&j==3&&k==2){
//             //       cout<<"yes";
//                }
//                f[i][j][k]=0;
//                for(int formal=1;formal<=n;++formal){
//                    if(formal+1==k){
//                        vector<int>pht=state[i];
//                        --pht[k-1];
//                        if(k!=1)
//                            ++pht[k-2];
//                        int r=mp[pht];
//                        int iu;
//                        if(k>=2)
//                            iu=state[i][k-2];
//                        else
//                            iu=n-zrs;
//                        f[i][j][k]+=(iu)*f[mp[pht]][j-1][formal];
//                     //   cout<<"["<<f[i][j][k];
//                    }else{
//                        vector<int>pht=state[i];
//                        --pht[k-1];
//                        if(k!=1)
//                            ++pht[k-2];
//                        int r=mp[pht];
//                        int iu;
//                        if(k>=2)
//                            iu=state[i][k-2];
//                        else
//                            iu=n-zrs;
//                        f[i][j][k]+=(iu+1)*f[r][j-1][formal];
//                    }
//                }
//            }
//        }
//    }
//    ld lz=0;
//   ld lz2=0;
//     lp(i,0,int(state.size()-1))
//             lp(k,1,n){
//                lz+=f[i][n][k];
//             //   cout<<"-------------------------\n";
//           //     printv(state[i]);
//           //     cout<<k<<endl;
//           //     cout<<f[i][n][k]<<endl;
//            //    cout<<"-------------------------\n";

//        }
//     double ans=0;
//     lp(i,0,int(state.size()-1))
//             lp(k,1,n){
//            int tmpp=-1;
//            for(int u=1;u<=n;++u)
//                if(state[i][u-1]!=0)
//                    tmpp=state[i][u-1];
//            ans+=tmpp*double(f[i][n][k])/lz;
//     }
//   //  cout<<f[6][3][1]<<endl;
//   // cout<<f[5][2][1]<<endl;
//    // cout<<f[3][1][1]<<endl;
//    return ans;
//}
double myans[]={0,1.000000,2.000000,2.000000,1.777778,1.656250,1.660800,1.733668,1.828592,1.920742
,1.999589,2.062219,2.109256,2.142717,2.164972,2.178301,2.184725,2.185964,2.183446,2.178343,2.171597,2.163963,2.156033,2.148263,2.141000,2.134497,2.128932,2.124422,2.121035,2.118798,2.117709,2.117741,2.118848,2.120971,2.124043,2.127988,2.132728};
int main(){
    int T;si(T);
    lp(I,1,T){
        int n;si(n);
        cout<<fixed<<setprecision(6)<<myans[n]<<endl;
    }
    return 0;
}
