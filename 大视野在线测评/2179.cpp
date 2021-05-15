#ifndef KARATSUBA_ALGORITHM
#define KARATSUBA_ALGORITHM
#include<algorithm>
#include<cmath>
#include<vector>
namespace CTL{
    using namespace std;
    template<class T>struct KaratsubaAlgorithm{
        static void kar(T*a,T*b,int n,int l,T**r){
            T*rl=r[l],*rll=r[l-1]; for(int i=0;i<2*n;++i)*(rl+i)=0;
            if(n<=30){for(int i=0;i<n;++i)for(int j=0;j<n;++j)
                *(rl+i+j)+=*(a+i)**(b+j);return;}
            kar(a,b,n>>1,l-1,r);
            for(int i=0;i<n;++i)*(rl+i)+=*(rll+i),*(rl+i+(n>>1))+=*(rll+i);
            kar(a+(n>>1),b+(n>>1),n>>1,l-1,r);
            for(int i=0;i<n;++i)*(rl+i+n)+=*(rll+i),*(rl+i+(n>>1))+=*(rll+i);
            for(int i=0;i<(n>>1);++i)
                *(rl+(n<<1)+i)=*(a+(n>>1)+i)-*(a+i),
                *(rl+i+(n>>1)*5)=*(b+i)-*(b+(n>>1)+i);
            kar(rl+(n<<1),rl+(n>>1)*5,n>>1,l-1,r);
            for(int i=0;i<n;++i)*(rl+i+(n>>1))+=*(rll+i);
        }
        static vector<T>run(vector<T>a,vector<T>b){
            int l=ceil(log2(max(a.size(),b.size()))+1e-8);
            vector<T>rt(a.size()+b.size()-1);
            a.resize(1<<l);b.resize(1<<l);
            T**r=new T*[l+1];for(int i=0;i<=l;++i)r[i]=new T[(1<<i)*3];
            kar(&a[0],&b[0],1<<l,l,r);
            for(int i=0;i<rt.size();++i)rt[i]=*(r[l]+i);
            for(int i=0;i<=l;++i)delete r[i];delete r;
            return rt;}};}
#endif
#include<vector>
#include<iostream>
#include<cstdio>
using namespace std;
static char s[100010];
#include<algorithm>
int main(){int n;
    scanf("%d",&n);
    vector<int>a(n),b(n);

    scanf("%s",s);
    for(int i=0;i<n;++i)a[i]=s[i]-'0';
    scanf("%s",s);
    for(int i=0;i<n;++i)b[i]=s[i]-'0';
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    vector<int>c=CTL::KaratsubaAlgorithm<int>::run(a,b);
    int up;
    for(int i=0;i<c.size();++i){
        up=c[i]/10;
        c[i]%=10;
        if(i+1!=c.size())
            c[i+1]+=up;
    }
    if(up)c.push_back(up);
    for(int i=c.size()-1;i>=0;--i)
        printf("%d",c[i]);printf("\n");
    return 0;
}
/*
20
12345678901234567890
12345678901234567890
*/
