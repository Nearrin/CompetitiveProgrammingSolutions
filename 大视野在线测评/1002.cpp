#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<iomanip>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace gas{
    long double fbs(double a){
        return a>0?a:-a;
    }
    long double mt[110][110];int n;
    long double solve(){
        lp(i,1,n){
            int j=i;while(j<=n&&fbs(mt[j][i])<1e-8)++j;
            lp(k,1,n)swap(mt[i][k],mt[j][k]);
            lp(k,i+1,n){
                if(fbs(mt[k][i])>1e-8){
                    long double t=mt[k][i];
                    lp(l,1,n)mt[k][l]-=mt[i][l]/mt[i][i]*t;
                }
            }
        }
        long double ans=1;
        lp(i,1,n)ans*=mt[i][i];
        return ans;
    }
}
struct num{
    int dat[310],len;
};
num mul4(num a){
    lp(i,1,a.len)a.dat[i]*=4;
    lp(i,1,a.len-1){
        a.dat[i+1]+=a.dat[i]/10;
        a.dat[i]%=10; 
    }
    while(a.dat[a.len]>=10){
        a.dat[a.len+1]=a.dat[a.len]/10;
        a.dat[a.len]%=10;
        ++a.len;
    }
    return a;
} 
num plu(num a,num b){
    num c;c.len=max(a.len,b.len);
    lp(i,1,c.len)c.dat[i]=0;
    lp(i,1,a.len)c.dat[i]+=a.dat[i];
    lp(i,1,b.len)c.dat[i]+=b.dat[i];
    lp(i,1,c.len-1){
        c.dat[i+1]+=c.dat[i]/10;
        c.dat[i]%=10; 
    }
    while(c.dat[c.len]>=10){
        c.dat[c.len+1]=c.dat[c.len]/10;
        c.dat[c.len]%=10;
        ++c.len;
    }
    return c;
}
void prit(num a){
    rp(i,a.len,1)pf("%d",a.dat[i]);
} 
num mins(num a,num b){
    while(b.len<a.len)++b.len,b.dat[b.len]=0;
    lp(i,1,b.len)b.dat[i]=9-b.dat[i];
    num c=plu(a,b);num d;d.len=1;d.dat[1]=1;
    c=plu(c,d);
    c.len=a.len;
    while(c.dat[c.len]==0&&c.len!=1)--c.len;
    return c;
}

num f[110];
int main(){
    f[1].len=1;f[1].dat[1]=1;
    f[2].len=1;f[2].dat[1]=5;
    f[3].len=2;f[3].dat[1]=6;f[3].dat[2]=1;
    lp(i,4,100){
        f[i]=plu(mul4(mins(f[i-1],f[i-2])),f[i-3]);
    }
    int n;sf("%d",&n);
    prit(f[n]);
    pf("\n"); 
    //ps; 
    return 0;
} 
