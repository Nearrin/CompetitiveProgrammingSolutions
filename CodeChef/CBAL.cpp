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
class FastStream{
private:
    std::FILE*infile,*outfile;
    std::vector<char>inbuffer,outbuffer;
    char*inpointer,*inend;
    inline void read_file(){
        for(int i=0;;++i){
            inbuffer.resize(inbuffer.size()+(1<<i));
            int t=std::fread(&inbuffer[0]+inbuffer.size()-(1<<i),1,(1<<i),infile);
            if(t!=(1<<i)){
                inpointer=&inbuffer[0];
                inend=inpointer+inbuffer.size()-(1<<i)+t;
                break;
            }
        }
    }
    inline void ignore(){
        while(inpointer!=inend&&std::isspace(*inpointer))
            ++inpointer;
    }
public:
    inline FastStream(std::FILE*_infile,std::FILE*_outfile):
    infile(_infile),outfile(_outfile){
        read_file();
    }
    inline FastStream(std::string _infile,std::string _outfile):
    infile(std::fopen(_infile.c_str(),"r")),outfile(std::fopen(_outfile.c_str(),"w")){
        read_file();
    }
    inline~FastStream(){
        fclose(infile);
        if(!outbuffer.empty())
            std::fwrite(&outbuffer[0],1,outbuffer.size(),outfile);
        fclose(outfile);
    }
    inline FastStream&operator>>(char&a){
        ignore();
        a=*inpointer++;
        return*this;
    }
    inline FastStream&operator>>(char*a){
        ignore();
        while(inpointer!=inend&&!std::isspace(*inpointer))
            *a++=*inpointer++;
        *a=0;
        return*this;
    }
    inline FastStream&operator>>(std::string&a){
        ignore();
        while(inpointer!=inend&&!std::isspace(*inpointer))
            a.push_back(*inpointer++);
        return*this;
    }
    inline FastStream&operator>>(int&a){
        ignore();
        bool f=false;
        if(*inpointer=='-'){
            f=true;
            ++inpointer;
        }
        a=0;
        while(inpointer!=inend&&std::isdigit(*inpointer))
            a=a*10+*inpointer++-'0';
        if(f)
            a=-a;
        return*this;
    }
    inline FastStream&operator>>(long long&a){
        ignore();
        bool f=false;
        if(*inpointer=='-'){
            f=true;
            ++inpointer;
        }
        a=0;
        while(inpointer!=inend&&std::isdigit(*inpointer))
            a=a*10+*inpointer++-'0';
        if(f)
            a=-a;
        return*this;
    }
    template<class VAL>inline void ReadVector(std::vector<VAL>&a,int n=0){
        if(n==0)
            *this>>n;
        for(int i=0;i<n;++i){
            VAL t;
            *this>>t;
            a.push_back(t);
        }
    }
    inline FastStream&operator<<(char a){
        outbuffer.push_back(a);
        return*this;
    }
    inline FastStream&operator<<(const char*a){
        while(*a)
            outbuffer.push_back(*a++);
        return*this;
    }
    inline FastStream&operator<<(const std::string&a){
        for(int i=0;i<a.size();++i)
            outbuffer.push_back(a[i]);
        return*this;
    }
    inline FastStream&operator<<(int a){
        if(a<0){
            outbuffer.push_back('-');
            a=-a;
        }
        static char t[10];
        char*p=t;
        do{
            int b=a/10;
            *p++=a-b*10+'0';
            a=b;
        }while(a);
        while(p>t)
            outbuffer.push_back(*--p);
        return*this;
    }
    inline FastStream&operator<<(unsigned a){
        static char t[10];
        char*p=t;
        do{
            int b=a/10;
            *p++=a-b*10+'0';
            a=b;
        }while(a);
        while(p>t)
            outbuffer.push_back(*--p);
        return*this;
    }
    inline FastStream&operator<<(long long a){
        if(a<0){
            outbuffer.push_back('-');
            a=-a;
        }
        static char t[19];
        char*p=t;
        do{
            long long b=a/10;
            *p++=a-b*10+'0';
            a=b;
        }while(a);
        while(p>t)
            outbuffer.push_back(*--p);
        return*this;
    }
    template<class VAL>inline void WriteVector(const std::vector<VAL>&a,const std::string&b){
        for(int i=0;i<a.size();++i){
            if(i!=0)
                *this<<b;
            *this<<a[i];
        }
    }
};
class PartitionedSequence{
private:
    int n,k;
public:
    inline PartitionedSequence(const int&_n,const int&_k):
    n(_n),k(_k){
    }
    inline int BlockCount(){
        return (n+k-1)/k;
    }
    inline int BlockSize(const int&x){
        return End(x)-Start(x)+1;
    }
    inline int Block(const int&x){
        return (x-1)/k+1;
    }
    inline int Start(const int&x){
        return (x-1)*k+1;
    }
    inline int End(const int&x){
        return min(x*k,n);
    }
    inline std::pair<int,int>Partition(const int&x,const int&y){
        int a=Block(x)+1,b=Block(y)-1;
        if(x==Start(Block(x)))
            --a;
        if(y==End(Block(y)))
            ++b;
        return std::make_pair(a,b);
    }
};
template<class VAL,class CMP=std::less<VAL> >class Discretize{
private:
    std::vector<VAL>b;
public:
    inline void Add(const VAL&a){
        b.push_back(a);
    }
    inline void Build(){
        std::sort(b.begin(),b.end(),CMP());
        b.erase(std::unique(b.begin(),b.end()),b.end());
    }
    inline int Result(const VAL&a){
        return std::lower_bound(b.begin(),b.end(),a)-b.begin()+1;
    }
};
static char P[100010];
static int A[100010],L;
void builda(){
    int cnt=0;
    A[1]=0;
    lp(i,1,L){
        cnt^=(1<<(P[i]-'a'));
        A[i+1]=cnt;
    }
    //lp(i,1,L+1)cout<<A[i]<<endl;
    Discretize<int> dis;
    lp(i,1,L+1)dis.Add(A[i]);
    dis.Build();
    lp(i,1,L+1)A[i]=dis.Result(A[i]);
   // lp(i,1,L+1)cout<<A[i]<<endl;
}
ll b0[100010][320];
ll b1[100010][320];
ll b2[100010][320];
static ll count0[100010];
static ll count1[100010];
static ll count2[100010];
void calcb(PartitionedSequence&prs){
    for(int i=1;i<=prs.BlockCount();++i){
           ll tmp0=0,tmp1=0,tmp2=0;
           for(int j=prs.End(i);j>=1;--j){
                tmp0+=count0[A[j]];
                b0[j][i]=tmp0;
                tmp1+=count1[A[j]]-count0[A[j]]*j;
                b1[j][i]=tmp1;
                tmp2+=count2[A[j]]-2*count1[A[j]]*j+count0[A[j]]*ll(j)*ll(j);
                b2[j][i]=tmp2;
                count0[A[j]]++;
                count1[A[j]]+=j;
                count2[A[j]]+=ll(j)*ll(j);
            }
            for(int j=prs.End(i);j>=1;--j){
                count0[A[j]]=0;
                count1[A[j]]=0;
                count2[A[j]]=0;
            }
    }
}

ll c0[320][100010];
ll c1[320][100010];
ll c2[320][100010];
void calcc(PartitionedSequence&prs){
    for(int i=1;i<=L+1;++i){
        count0[A[i]]++;
        count1[A[i]]+=i;
        count2[A[i]]+=ll(i)*ll(i);
        if(i==prs.End(prs.Block(i))){
            int t=prs.Block(i);
            for(int j=1;j<=L+1;++j){
                c0[t][j]=count0[j];
                c1[t][j]=count1[j];
                c2[t][j]=count2[j];
            }
        }
    }
    for(int i=1;i<=L+1;++i){
        count0[A[i]]=0;
        count1[A[i]]=0;
        count2[A[i]]=0;
    }
}
int main(){
	FastStream fs(stdin,stdout);
    int T;fs>>T;
    lp(I,1,T){
        fs>>(P+1);
        L=strlen(P+1);
        builda();
        int t=pow(double(L+1),0.5);
        if(t>4){
            t/=4;
            if((L+1+t-1)/t>319){
                t*=4;
            }
        }
        PartitionedSequence prs(L+1,t);
        calcb(prs);
        calcc(prs);
        ll a=0,b=0;
        ll q;fs>>q;
        while(q--){
            ll x,y;
            fs>>x>>y;
            ll tp;fs>>tp;
            ll l=(x+a)%L+1;
            ll r=(y+b)%L+1;
            //ll l=x;
           // ll r=y;
            if(l>r){
                swap(l,r);
            }
            ll ans=0;
            //cout<<l<<" "<<r<<endl;
            ++r;
            //cout<<"----"<<b0[1][1]<<endl;
            if(tp==0){
                if(prs.Block(l)==prs.Block(r)){
                    for(int i=l;i<=r;++i){
                        ans+=count0[A[i]];
                        ++count0[A[i]];
                    }
                    for(int i=l;i<=r;++i){
                        count0[A[i]]=0;
                    }
                }else{
                    pii hehe=prs.Partition(l,r);
                   if(hehe.first<=hehe.second) ans+=b0[prs.Start(hehe.first)][hehe.second];
                    static int tmp[100010],tmps=0;
                    tmps=0;
                    for(int i=l;i<prs.Start(hehe.first);++i){
                        if(hehe.first<=hehe.second)ans+=c0[hehe.second][A[i]]-c0[hehe.first-1][A[i]];
                        tmp[tmps++]=A[i];
                    }
                    for(int i=prs.End(hehe.second)+1;i<=r;++i){
                        if(hehe.first<=hehe.second)ans+=c0[hehe.second][A[i]]-c0[hehe.first-1][A[i]];
                        tmp[tmps++]=A[i];
                    }
                    for(int i=0;i<tmps;++i){
                        ans+=count0[tmp[i]];
                        ++count0[tmp[i]];
                    }
                    for(int i=0;i<tmps;++i){
                        count0[tmp[i]]=0;
                    }
                }
            }else if(tp==1){
                if(prs.Block(l)==prs.Block(r)){
                    for(int i=l;i<=r;++i){
                        ans+=count0[A[i]]*ll(i)-count1[A[i]];
                        ++count0[A[i]];
                        count1[A[i]]+=i;
                    }
                    for(int i=l;i<=r;++i){
                        count0[A[i]]=0;
                        count1[A[i]]=0;
                    }
                }else{
                    pii hehe=prs.Partition(l,r);
                    if(hehe.first<=hehe.second)ans+=b1[prs.Start(hehe.first)][hehe.second];
                    static int tmpfir[100010],tmpsec[100010],tmps=0;
                    tmps=0;
                    for(int i=l;i<prs.Start(hehe.first);++i){
                        if(hehe.first<=hehe.second)ans+=(c1[hehe.second][A[i]]-c1[hehe.first-1][A[i]])-ll(i)*(c0[hehe.second][A[i]]-c0[hehe.first-1][A[i]]);
                        tmpfir[tmps]=A[i];
                        tmpsec[tmps]=i;
                        ++tmps;
                    }
                    for(int i=prs.End(hehe.second)+1;i<=r;++i){
                        if(hehe.first<=hehe.second)ans+=ll(i)*(c0[hehe.second][A[i]]-c0[hehe.first-1][A[i]])-(c1[hehe.second][A[i]]-c1[hehe.first-1][A[i]]);
                        tmpfir[tmps]=A[i];
                        tmpsec[tmps]=i;
                        ++tmps;
                        
                    }
                    for(int i=0;i<tmps;++i){
                        ans+=ll(tmpsec[i])*count0[tmpfir[i]]-count1[tmpfir[i]];
                        ++count0[tmpfir[i]];
                        count1[tmpfir[i]]+=tmpsec[i];
                    }
                    for(int i=0;i<tmps;++i){
                        count0[tmpfir[i]]=count1[tmpfir[i]]=0;
                    }
                }
            }else if(tp==2){
                if(prs.Block(l)==prs.Block(r)){
                    for(int i=l;i<=r;++i){
                        ans+=count0[A[i]]*ll(i)*ll(i)-2*i*count1[A[i]]+count2[A[i]];
                        ++count0[A[i]];
                        count1[A[i]]+=i;
                        count2[A[i]]+=ll(i)*ll(i);
                    }
                    for(int i=l;i<=r;++i){
                        count0[A[i]]=0;
                        count1[A[i]]=0;
                         count2[A[i]]=0;
                    }
                }else{
                    pii hehe=prs.Partition(l,r);
                    if(hehe.first<=hehe.second)ans+=b2[prs.Start(hehe.first)][hehe.second];
                    static int tmpfir[100010],tmpsec[100010],tmps=0;
                    tmps=0;
                    for(int i=l;i<prs.Start(hehe.first);++i){
                        if(hehe.first<=hehe.second)ans+=(c2[hehe.second][A[i]]-c2[hehe.first-1][A[i]])+ll(i)*ll(i)*(c0[hehe.second][A[i]]-c0[hehe.first-1][A[i]])-2*ll(i)*(c1[hehe.second][A[i]]-c1[hehe.first-1][A[i]]);
                        tmpfir[tmps]=A[i];
                        tmpsec[tmps]=i;
                        ++tmps;
                    }
                    for(int i=prs.End(hehe.second)+1;i<=r;++i){
                         if(hehe.first<=hehe.second)ans+=(c2[hehe.second][A[i]]-c2[hehe.first-1][A[i]])+ll(i)*ll(i)*(c0[hehe.second][A[i]]-c0[hehe.first-1][A[i]])-2*ll(i)*(c1[hehe.second][A[i]]-c1[hehe.first-1][A[i]]);
                        tmpfir[tmps]=A[i];
                        tmpsec[tmps]=i;
                        ++tmps;
                    }
                    for(int i=0;i<tmps;++i){
                        ans+=ll(tmpsec[i])*ll(tmpsec[i])*count0[tmpfir[i]]+count2[tmpfir[i]]-2*ll(tmpsec[i])*count1[tmpfir[i]];
                        ++count0[tmpfir[i]];
                        count1[tmpfir[i]]+=tmpsec[i];
                        count2[tmpfir[i]]+=ll(tmpsec[i])*ll(tmpsec[i]);
                    }
                    for(int i=0;i<tmps;++i){
                        count0[tmpfir[i]]=count1[tmpfir[i]]=count2[tmpfir[i]]=0;
                    }
                }
            }
            fs<<ans<<'\n';
            a=b;
            b=ans;
        }

    }
    return 0;
}
/*
1
cchheeff
5
0 1 0
0 2 1
7 5 2
0 7 0
1 1 2
*/
