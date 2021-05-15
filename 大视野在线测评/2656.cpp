#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<cstring>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
void check(){
    static int a[81000];a[0]=0;a[1]=1;
    lp(i,2,80001)
        if(i%2)a[i]=a[(i-1)/2]+a[(i-1)/2+1];
        else a[i]=a[i/2];
    lp(i,1,100)pf("%d:%d\n",i,a[i]);pf("\n");
}
struct num{
    int d[310],l;
};
bool operator<(num a,num b){
    if(a.l!=b.l)return a.l<b.l;
    for(int i=a.l;i;--i)if(a.d[i]!=b.d[i])
        return a.d[i]<b.d[i];
    return false;
}
num add1(num a){
    ++a.d[1];
    for(int i=1;i<=a.l;++i){
        if(a.d[i]==10){
            if(i==a.l)++a.l,a.d[a.l]=0;
            a.d[i]=0,++a.d[i+1];
        }
    }
    return a;
}
num div2(num a){
    for(int i=a.l;i;--i){
        a.d[i-1]+=(a.d[i]%2)*10;
        a.d[i]/=2;
    }
    while(a.d[a.l]==0&&a.l>1)--a.l;
    return a;
}
num operator+(num a,num b){
    num c;c.l=max(a.l,b.l);
    lp(i,1,min(a.l,b.l))c.d[i]=a.d[i]+b.d[i];
    lp(i,min(a.l,b.l)+1,a.l)c.d[i]=a.d[i];
    lp(i,min(a.l,b.l)+1,b.l)c.d[i]=b.d[i];
    for(int i=1;i<=c.l;++i){
        if(c.d[i]>9){
            if(i==c.l)++c.l,c.d[c.l]=0;
            c.d[i+1]+=c.d[i]/10;
            c.d[i]%=10;
        }
    }
    return c;
}
void print(num a){
    for(int i=a.l;i;--i)pf("%c",a.d[i]+'0');pf("\n");
}
map<num,num>mp;set<num>st;
num f(num x){
    if(st.count(x))return mp[x];
    else{
        st.insert(x);
        if(x.l==1&&x.d[1]==0){
            num t;t.l=1;t.d[1]=0;
            return mp[x]=t;
        }else if(x.l==1&&x.d[1]==1){
            num t;t.l=1;t.d[1]=1;
            return mp[x]=t;
        }else if(x.d[1]%2==0)return mp[x]=f(div2(x));
        else return mp[x]=f(div2(x))+f(add1(div2(x)));
    }
}
int main(){
    //check();
    int t;sf("%d",&t);
    lp(i,1,t){
        char op[210];sf("%s",op+1);
        num n;n.l=strlen(op+1);
        lp(j,1,n.l)n.d[j]=op[n.l-j+1]-'0';
        print(f(n));
    }
    //ps;
    return 0;    
}
