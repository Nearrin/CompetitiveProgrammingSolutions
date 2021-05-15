#ifndef DIJKSTRAS_ALGORITHM
#define DIJKSTRAS_ALGORITHM
#include<algorithm>
#include<cmath>
#include<limits>
#include<utility>
#include<vector>
namespace CTL{
    using namespace std;
    template<class T>struct DijkstrasAlgorithm{
        int n,m;vector<vector<int> >to;vector<vector<T> >we;
        T inf;vector<pair<T,int> >sg;vector<T>di;
        DijkstrasAlgorithm(int _n):n(_n),m(1<<(int)ceil(log2(n)+1e-8)),
            to(n+1),we(n+1),inf(numeric_limits<T>::max()),sg(2*m,make_pair(inf,0)),di(n+1,inf){}
        void set(int u,T d){di[u]=d;}
        void add(int u,int v,T w){to[u].push_back(v);we[u].push_back(w);}
        int upd(T&a,T b,T c){if(b!=inf&&c!=inf&&b+c<a){a=b+c;return 1;}return 0;}
        void mod(int u,T d){for(sg[u+m-1]=make_pair(d,u),u=(u+m-1)>>1;u;u>>=1)sg[u]=min(sg[u<<1],sg[u<<1^1]);}
        vector<T>run(){
            for(int i=1;i<=n;++i)sg[i+m-1]=make_pair(di[i],i);
            for(int i=m-1;i>=1;--i)sg[i]=min(sg[i<<1],sg[i<<1^1]);
            for(int u=sg[1].second;sg[1].first!=inf?(mod(u,inf),1):0;u=sg[1].second)
                for(int i=0;i<to[u].size();++i){int v=to[u][i];T w=we[u][i];if(upd(di[v],di[u],w))mod(v,di[v]);}
            return di;}};}
#endif
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;


#include<algorithm>
#include<limits>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N=200000;
template<class COST>struct D{
    int n,src;
    COST di[N],mx;
    vector<int>to[N];
    vector<COST>we[N];
    D(int _n,int _src):
        n(_n),src(_src-1),mx(numeric_limits<COST>::max()){}
    void add(int u,int v,COST w){
        to[u-1].push_back(v-1);
        we[u-1].push_back(w);
    }
    COST segw[N*4];
    int segu[N*4];
    void buildseg(int x,int l,int r){
        segw[x]=mx;
        if(l!=r){
            int m=(l+r)/2;
            buildseg(x*2,l,m);
            buildseg(x*2+1,m+1,r);
        }
    }
    void changeseg(int x,int l,int r,int u,COST w){
        if(l==r){
            segu[x]=u;
            segw[x]=w;
        }else{
             int m=(l+r)/2;
             if(u<=m)
                 changeseg(x*2,l,m,u,w);
             else
                 changeseg(x*2+1,m+1,r,u,w);
             int t=(segw[x*2]>segw[x*2+1]);
             segw[x]=segw[x*2+t];
             segu[x]=segu[x*2+t];
        }
    }
    void run(){
        fill(di,di+n,mx);
        di[src]=0;
        buildseg(1,0,n-1);
        changeseg(1,0,n-1,src,0);
        while(segw[1]!=mx){
            int u=segu[1];
            changeseg(1,0,n-1,u,mx);
            for(int i=0;i<to[u].size();++i){
                int v=to[u][i];
                COST w=we[u][i];
                if(di[u]+w<di[v]){
                    di[v]=di[u]+w;
                    changeseg(1,0,n-1,v,di[v]);
                }
            }
        }
    }
};
struct data{
    int u;
    long long x,y;
}da[200010];
int n;
bool cmpx(data a,data b){
    return a.x<b.x;
}
bool cmpy(data a,data b){
    return a.y<b.y;
}
int dis(data a,data b){
    int t1=a.x-b.x;
    if(t1<0)t1=-t1;
    int t2=a.y-b.y;
    if(t2<0)t2=-t2;
    return min(t1,t2);
}
#ifndef FAST_READER_WRITER
#define FAST_READER_WRITER
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
namespace CTL{
    using namespace std;
    struct FastReader{
        FILE*f;char*p,*e;vector<char>v;
        FastReader(FILE*_f):f(_f){red();}
        FastReader(string _f):f(fopen(_f.c_str(),"r")){red();}
        ~FastReader(){fclose(f);}
        void red(){
            for(int i=0,t;;++i){
                v.resize(v.size()+(1<<i));
                if((t=fread(&v[0]+v.size()-(1<<i),1,1<<i,f))!=(1<<i)){
                    p=&v[0],e=p+v.size()-(1<<i)+t;break;}}}
        void ign(){while(p!=e&&isspace(*p))++p;}
        int isc(){return p!=e&&!isspace(*p);}
        int isd(){return p!=e&&isdigit(*p);}
        FastReader&operator>>(char&a){ign(),a=*p++;return*this;}
        FastReader&operator>>(char*a){for(ign();isc()?1:(*a=0);)*a++=*p++;return*this;}
        FastReader&operator>>(int&a){
            int n=1;if(ign(),a=0,*p=='-')n=-1,++p;
            for(;isd()?1:(a*=n,0);)a=a*10+*p++-'0';
            return*this;}
        FastReader&operator>>(long long&a){
            int n=1;if(ign(),a=0,*p=='-')n=-1,++p;
            for(;isd()?1:(a*=n,0);)a=a*10+*p++-'0';
            return*this;}
        char get(){return*p++;}};
    struct FastWriter{
        FILE*f;vector<char>p;
        FastWriter(FILE*_f):f(_f){}
        FastWriter(string _f):f(fopen(_f.c_str(),"w")){}
        ~FastWriter(){(p.size()?fwrite(&p[0],1,p.size(),f):0),fclose(f);}
        FastWriter&operator<<(char a){p.push_back(a);return*this;}
        FastWriter&operator<<(const char*a){while(*a)p.push_back(*a++);return*this;}
        FastWriter&operator<<(int a){
            if(a<0)p.push_back('-'),a=-a;
            static char t[10];char*q=t;
            do{int b=a/10;*q++=a-b*10+'0',a=b;}while(a);
            while(q>t)p.push_back(*--q);
            return*this;}
        FastWriter&operator<<(long long a){
            if(a<0)p.push_back('-'),a=-a;
            static char t[19];char*q=t;
            do{long long b=a/10;*q++=a-b*10+'0',a=b;}while(a);
            while(q>t)p.push_back(*--q);
            return*this;}
    };
}
#endif
int main(){
    CTL::FastReader rd(stdin);
    rd>>n;
    for(int i=1;i<=n;++i){
        int a,b;
        rd>>a>>b;
        da[i].u=i;
        da[i].x=a;
        da[i].y=b;
    }
    //D<long long>* dij=new D<long long> (n,1);
    CTL::DijkstrasAlgorithm<long long>dij(n);
    dij.set(1,0);
    sort(da+1,da+n+1,cmpx);
    for(int i=1;i<=n;++i){
        if(i!=1){
            int u=da[i].u,v=da[i-1].u;
            int w=dis(da[i],da[i-1]);
            dij.add(u,v,w);
        }
        if(i!=n){
            int u=da[i].u,v=da[i+1].u;
            int w=dis(da[i],da[i+1]);
            dij.add(u,v,w);
        }
    }
    sort(da+1,da+n+1,cmpy);
    for(int i=1;i<=n;++i){
        if(i!=1){
            int u=da[i].u,v=da[i-1].u;
            int w=dis(da[i],da[i-1]);
            dij.add(u,v,w);
        }
        if(i!=n){
            int u=da[i].u,v=da[i+1].u;
            int w=dis(da[i],da[i+1]);
            dij.add(u,v,w);
        }
    }

    cout<<dij.run()[n]<<endl;
    return 0;
}
