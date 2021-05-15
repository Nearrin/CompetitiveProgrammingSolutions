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
#ifndef FAST_READER_WRITER
#define FAST_READER_WRITER
#include<bits/stdc++.h>
namespace CTL{
    using namespace std;
    struct FastReader{
        FILE*f;char*p,*e;vector<char>v;
        FastReader(FILE*_f):f(_f){ipt();}
        FastReader(string _f):f(fopen(_f.c_str(),"r")){ipt();}
        ~FastReader(){fclose(f);}
        void ipt(){
            for(int i=0,t;;++i){
                v.resize(v.size()+(1<<i));
                if((t=fread(&v[0]+v.size()-(1<<i),1,1<<i,f))!=(1<<i)){
                    p=&v[0],e=p+v.size()-(1<<i)+t;break;}}}
        void ign(){while(p!=e&&isspace(*p))++p;}
        int isc(){return p!=e&&!isspace(*p);}
        int isd(){return p!=e&&isdigit(*p);}
        template<class T>FastReader&operator>>(T&a){
            int n=1;if(ign(),a=0,*p=='-')n=-1,++p;
            for(;isd()?1:(a*=n,0);)a=a*10+*p++-'0';
            return*this;}
        FastReader&operator>>(char&a){
            ign(),a=*p++;return*this;}
        FastReader&operator>>(char*a){
            for(ign();isc()?1:(*a=0);)*a++=*p++;return*this;}
        char get(){return*p++;}};
    struct FastWriter{
        FILE*f;vector<char>p;
        FastWriter(FILE*_f):f(_f){}
        FastWriter(string _f):f(fopen(_f.c_str(),"w")){}
        ~FastWriter(){
            (p.size()?fwrite(&p[0],1,p.size(),f):0),fclose(f);}
        FastWriter&operator<<(char a){
            p.push_back(a);return*this;}
        FastWriter&operator<<(const char*a){
            while(*a)p.push_back(*a++);return*this;}
        template<class T>FastWriter&operator<<(T a){
            if(a<0)p.push_back('-'),a=-a;
            static char t[19];char*q=t;
            do{T b=a/10;*q++=a-b*10+'0',a=b;}while(a);
            while(q>t)p.push_back(*--q);
            return*this;}};}
#endif

lli f[10000010];
int isp[10000010],p[10000010];
int h[10000010];

#ifndef EULERS_TOTIENT_FUNCTION
#define EULERS_TOTIENT_FUNCTION
#include<bits/stdc++.h>
namespace CTL{
    using namespace std;
    namespace EulersTotientFunction{
        vector<int>run(int n){
            vector<int>p,ntp(n+1),u(n+1);ntp[1]=1;u[1]=1;
            for(int i=2;i<=n;++i){
                if(!ntp[i])p.push_back(i),u[i]=i-1;
                for(int j=0;j<p.size()&&p[j]*i<=n;++j){
                    ntp[p[j]*i]=1;
                    if(i%p[j]==0){u[p[j]*i]=u[i]*p[j];break;}
                    else u[p[j]*i]=u[i]*(p[j]-1);}}
            return u;}}}
#endif
//auto phi=EulersTotientFunction::run(10000000);
//int fa(int x){
//    int r=0;
//    lop(i,1,x)if(x%i==0)r+=i*phi[i];
//    return r;
//}
int main(){
    f[1]=1;
    for(int i=2;i<=10000000;++i){
        if(!isp[i]){
            f[i]=lli(i)*i-i+1;
            h[i]=1;
            p[++p[0]]=i;
        }
        for(int j=1;j<=p[0]&&lli(p[j])*i<=10000000;++j){
            int t=i*p[j];
            isp[t]=1;
            if(i%p[j]==0){
                h[t]=h[i];
                int P=p[j];
                int PK=t/h[t];
                lli U=1+lli(P)*PK*PK;
                U/=1+P;
                f[t]=f[h[t]]*U;
                break;
            }else{
                f[i*p[j]]=f[i]*f[p[j]];
                h[i*p[j]]=i;
            }
        }
    }
//    lop(i,1,20000){
//        if(f[i]!=fa(i)){for(;;);}
//        cout<<i<<" ";
//        cout<<f[i]<<" ";
//        cout<<fa(i)<<endl;
//    }
    FastReader fr(stdin);
    FastWriter fw(stdout);
    int ty;fr>>ty;
    while(ty--){
        int n;fr>>n;
        fw<<f[n]<<'\n';
    }
    return 0;
}
