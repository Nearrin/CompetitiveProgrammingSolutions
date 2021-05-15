#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll; 
ll f[(1<<6)+1][(1<<6)+1][7][1<<6],u[1<<6];
void printset(int x){
    pf("[");lp(i,0,5)pf("%d",(x>>i)&1);pf("]"); 
}
void printstate(int i,int j,int k,int l){
    pf("[%d,%d,%d,",i,j,k);
    printset(l),
    pf(",%I64d]",f[i][j][k][l]);
}
int now;
struct val{
    int v[6];
};
bool operator<(val a,val b){
    lp(i,0,5)if((now>>i)&1)
        if(a.v[i]!=b.v[i])return a.v[i]<b.v[i];
    return false;
}
bool operator==(val a,val b){
    lp(i,0,5)if((now>>i)&1)if(a.v[i]!=b.v[i])return false;
    return true;
}
int N,K;
vector<val>V;
ll calc(){
    ll r=0;
    sort(V.begin(),V.end());
    lp(i,0,int(V.size()-1)){
        int j=i;while(j+1<V.size()&&V[j+1]==V[j])++j;
        ll t=j-i+1;
        r+=t*(t-1)/2;
        i=j;
    }
    return r;
}
ll ans[1<<6];
int main(){
    lp(i,0,(1<<6)-1)for(int j=i;j;j-=j&-j)++u[i];
    //lp(i,0,(1<<6)-1)printset(i),pf(" %d\n",u[i]);
    lp(i,0,6)f[0][0][i][0]=1;
    sf("%d%d",&N,&K);
    lp(i,1,(1<<6)){
        lp(j,0,i){
            lp(k,0,6){
                if(k!=K&&k!=K+1)continue; 
                lp(l,0,(1<<6)-1){
                    f[i][j][k][l]+=f[i-1][j][k][l];
                    if(j!=0&&(l&(i-1))==i-1&&u[i-1]==k){
                        for(int m=i-1;;m=((m-1)&(i-1))){
                            f[i][j][k][l]+=f[i-1][j-1][k][l-(i-1)+m];
                            //printstate(i,j,k,l);pf("->");printstate(i-1,j-1,k,l-(i-1)+m);pf("\n");
                            if(!m)break;
                        }
                    }
                    //if(f[i][j][k][l])
                        //printstate(i,j,k,l),pf("\n\n");
                }
            }
        }
    }
    lp(i,1,N){
        val t;lp(j,0,5)sf("%d",&t.v[j]);
        V.push_back(t);
    }
    lp(i,0,(1<<6)-1){
        now=i;
        ans[i]=calc();
        //printset(i);pf("[%lld]\n",ans[i]); 
    }
    ll tans=0;
    lp(i,0,(1<<6)-1){
        lp(j,1,(1<<6)){
            tans+=ans[i]*f[1<<6][j][K][i]*((j%2==1)?1:-1);
            //if(ans[i]*f[1<<6][j][K][i])
                //printset(i),pf("[%d,%I64d,%d]\n",j,ans[i]*f[1<<6][j][K][i],((j%2==1)?1:-1)); 
        }
    }
    ll tans2=0;
    if(K!=6)
    lp(i,0,(1<<6)-1){
        lp(j,1,(1<<6)){
            tans2+=ans[i]*f[1<<6][j][K+1][i]*((j%2==1)?1:-1);
            //if(ans[i]*f[1<<6][j][K][i])
                //printset(i),pf("[%d,%I64d,%d]\n",j,ans[i]*f[1<<6][j][K][i],((j%2==1)?1:-1)); 
        }
    }
    pf("%lld\n",tans-tans2);
    //ps;
    return 0; 
}
