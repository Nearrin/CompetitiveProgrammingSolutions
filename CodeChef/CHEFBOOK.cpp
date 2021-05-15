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
#include<list>
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
#define mc int T;scanf("%d",&T);for(int I=1;I<=T;++I)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int>vi;
typedef pair<int,int>pii;
template<class VAL=double,long long EPS=100000000ll>class EpsilonReal{
private:
    VAL val;
public:
    inline EpsilonReal(const VAL&_val=0):
    val(_val){
    }
    inline VAL&Value(){
        return val;
    }
    inline const VAL&Value()const{
        return val;
    }
    inline operator double()const{
        return val;
    }
    inline EpsilonReal<VAL,EPS>operator-()const{
        return EpsilonReal<VAL,EPS>(-val);
    }
    inline EpsilonReal<VAL,EPS>Add(const EpsilonReal<VAL,EPS>&a){
        return EpsilonReal<VAL,EPS>(val+a.val);
    }
    inline EpsilonReal<VAL,EPS>Minus(const EpsilonReal<VAL,EPS>&a){
        return EpsilonReal<VAL,EPS>(val-a.val);
    }
    inline EpsilonReal<VAL,EPS>Multiply(const EpsilonReal<VAL,EPS>&a){
        return EpsilonReal<VAL,EPS>(val*a.val);
    }
    inline EpsilonReal<VAL,EPS>Divide(const EpsilonReal<VAL,EPS>&a){
        return EpsilonReal<VAL,EPS>(val/a.val);
    }
    inline EpsilonReal<VAL,EPS>&operator+=(const EpsilonReal<VAL,EPS>&a){
        val+=a.val;
        return*this;
    }
    inline EpsilonReal<VAL,EPS>&operator-=(const EpsilonReal<VAL,EPS>&a){
        val-=a.val;
        return*this;
    }
    inline EpsilonReal<VAL,EPS>&operator*=(const EpsilonReal<VAL,EPS>&a){
        val*=a.val;
        return*this;
    }
    inline EpsilonReal<VAL,EPS>&operator/=(const EpsilonReal<VAL,EPS>&a){
        val/=a.val;
        return*this;
    }
    inline bool Less(const EpsilonReal<VAL,EPS>&a)const{
        return val<a.val-VAL(1)/VAL(EPS);
    }
    inline bool LessEqual(const EpsilonReal<VAL,EPS>&a)const{
        return val<a.val+VAL(1)/VAL(EPS);
    }
    inline bool Greater(const EpsilonReal<VAL,EPS>&a)const{
        return val>a.val+VAL(1)/VAL(EPS);
    }
    inline bool GreaterEqual(const EpsilonReal<VAL,EPS>&a)const{
        return val>a.val-VAL(1)/VAL(EPS);
    }
    inline bool NotEqual(const EpsilonReal<VAL,EPS>&a)const{
        return *this<a||*this>a;
    }
    inline bool Equal(const EpsilonReal<VAL,EPS>&a)const{
        return!(*this!=a);
    }
    inline EpsilonReal<VAL,EPS>&Abs(){
        val=std::fabs(val);
        return*this;
    }
    inline EpsilonReal<VAL,EPS>&Pow(const EpsilonReal<VAL,EPS>&a){
        val=std::pow(val,a.val);
        return*this;
    }
    inline EpsilonReal<VAL,EPS>&Root(const EpsilonReal<VAL,EPS>&a){
        val=std::pow(val,1/a.val);
        return*this;
    }
    inline EpsilonReal<VAL,EPS>&Sqrt(){
        val=std::sqrt(val);
        return*this;
    }
    inline void Read(std::istream&s){
        s>>val;
    }
    inline void Write(std::ostream&s)const{
        s<<val;
    }
};
template<class VAL,ll EPS>inline EpsilonReal<VAL,EPS> operator+(const EpsilonReal<VAL,EPS>&a,const EpsilonReal<VAL,EPS>&b){
    return EpsilonReal<VAL,EPS>(a)+=b;
}
template<class VAL,ll EPS>inline EpsilonReal<VAL,EPS> operator-(const EpsilonReal<VAL,EPS>&a,const EpsilonReal<VAL,EPS>&b){
    return EpsilonReal<VAL,EPS>(a)-=b;
}
template<class VAL,ll EPS>inline EpsilonReal<VAL,EPS> operator*(const EpsilonReal<VAL,EPS>&a,const EpsilonReal<VAL,EPS>&b){
    return EpsilonReal<VAL,EPS>(a)*=b;
}
template<class VAL,ll EPS>inline EpsilonReal<VAL,EPS> operator/(const EpsilonReal<VAL,EPS>&a,const EpsilonReal<VAL,EPS>&b){
    return EpsilonReal<VAL,EPS>(a)/=b;
}
template<class VAL,ll EPS>inline bool operator==(const EpsilonReal<VAL,EPS>&a,const EpsilonReal<VAL,EPS>&b){
    return a.Equal(b);
}
template<class VAL,ll EPS>inline bool operator!=(const EpsilonReal<VAL,EPS>&a,const EpsilonReal<VAL,EPS>&b){
    return a.NotEqual(b);
}
template<class VAL,ll EPS>inline bool operator<(const EpsilonReal<VAL,EPS>&a,const EpsilonReal<VAL,EPS>&b){
    return a.Less(b);
}
template<class VAL,ll EPS>inline bool operator<=(const EpsilonReal<VAL,EPS>&a,const EpsilonReal<VAL,EPS>&b){
    return a.LessEqual(b);
}
template<class VAL,ll EPS>inline bool operator>(const EpsilonReal<VAL,EPS>&a,const EpsilonReal<VAL,EPS>&b){
    return a.Greater(b);
}
template<class VAL,ll EPS>inline bool operator>=(const EpsilonReal<VAL,EPS>&a,const EpsilonReal<VAL,EPS>&b){
    return a.GreaterEqual(b);
}
template<class VAL,ll EPS>inline EpsilonReal<VAL,EPS>Abs(const EpsilonReal<VAL,EPS>&a){
    return EpsilonReal<VAL,EPS>(a).Abs();
}
template<class VAL,ll EPS>inline EpsilonReal<VAL,EPS>Pow(const EpsilonReal<VAL,EPS>&a,const EpsilonReal<VAL,EPS>&b){
    return EpsilonReal<VAL,EPS>(a).Pow(b);
}
template<class VAL,ll EPS>inline EpsilonReal<VAL,EPS>Root(const EpsilonReal<VAL,EPS>&a,const EpsilonReal<VAL,EPS>&b=2){
    return EpsilonReal<VAL,EPS>(a).Root(b);
}
template<class VAL,ll EPS>inline EpsilonReal<VAL,EPS>Sqrt(const EpsilonReal<VAL,EPS>&a){
    return EpsilonReal<VAL,EPS>(a).Sqrt();
}
template<class VAL,ll EPS>inline std::istream&operator>>(std::istream&s,EpsilonReal<VAL,EPS>&t){
    t.Read(s);
    return s;
}
template<class VAL,ll EPS>inline std:: ostream&operator<<(std::ostream&s,const EpsilonReal<VAL,EPS>&t){
    t.Write(s);
    return s;
}
template<class VAL=EpsilonReal<>>class Simplex{
private:
    int n,m,p;
    std::vector<std::vector<VAL>  >a;
    std::vector<int>mp,ma,md;
    std::vector<VAL>res;
    inline void pivot(const int&l,const int&e){
        swap(mp[l],md[e]);
        ma[mp[l]]=l;
        ma[md[e]]=-1;
        VAL t(-a[l][e]);
        a[l][e]=VAL(-1);
        std::vector<int>qu;
        for(int i=0;i<=m+1;++i)
            if((a[l][i]/=t)!=VAL(0))
                qu.push_back(i);
        for(int i=0;i<=n+1;++i)
            if(i!=l&&(a[i][e])!=VAL(0)){
                t=a[i][e];
                a[i][e]=VAL(0);
                for(int j=0;j<qu.size();++j)
                    a[i][qu[j]]+=a[l][qu[j]]*t;
            }
        if(-p==l)
            p=e;
        else if(p==e)
            p=-l;
    }
    inline bool opt(const int&d){
        while(true){
            int l=-1,e=-1;
            for(int i=1;i<=m+1;++i)
                if(a[d][i]>VAL(0)){
                    e=i;
                    break;
                }
            if(e==-1)
                return true;
            VAL t;
            for(int i=1;i<=n;++i)
                if(a[i][e]<VAL(0)&&(l==-1||a[i][0]/-a[i][e]<t))
                    t=a[i][0]/-a[i][e],l=i;
            if(l==-1)
                return false;
            pivot(l,e);
        }
    }
public:
    inline Simplex(const int&_n,const int&_m):
    n(_n),m(_m),p(0),a(n+2,std::vector<VAL>(m+2)),mp(n+1),ma(m+n+2),md(m+2),res(m+1){
    }
    inline VAL&At(const int&x,const int&y){
        return a[x][y];
    }
    inline bool Run(){
        for(int i=1;i<=m+1;++i)
            ma[i]=-1,md[i]=i;
        for(int i=m+2;i<=m+n+1;++i)
            ma[i]=i-(m+1),mp[i-(m+1)]=i;
        VAL t;
        int l=-1;
        for(int i=1;i<=n;++i)
            if(l==-1||a[i][0]<t)
                t=a[i][0],l=i;
        if(t<VAL(0)){
            for(int i=1;i<=n;++i)a[i][m+1]=VAL(1);
            a[n+1][m+1]=VAL(-1);
            p=m+1;
            pivot(l,m+1);
            if(!opt(n+1)||a[n+1][0]!=VAL(0))
                return false;
            if(p<0)
                for(int i=1;i<=m;++i)
                    if(a[-p][i]!=VAL(0)){
                        pivot(-p,i);
                        break;
                    }
            for(int i=0;i<=n;++i)
                a[i][p]=VAL(0);
        }
        if(!opt(0))
            return false;
        res[0]=a[0][0];
        for(int i=1;i<=m;++i)
            if(ma[i]!=-1)
                res[i]=a[ma[i]][0];
        return true;
    }
    inline std::vector<VAL>&Result(){
        return res;
    }
};
int n,m;
int P(int x){
    return x;
}
int Q(int y){
    return n+y;
}
int main(){
    int T;si(T);
    lp(i,1,T){
        si(n),si(m);
        Simplex<>sim(2*n+2*m,2*n);
        lp(i,1,n){
            sim.At(i,P(i))=1;
            sim.At(n+i,Q(i))=1;
        }
        lp(i,1,m){
            int x,y,lxy,sxy,txy;
            si(x),si(y),si(lxy),si(sxy),si(txy);
            sim.At(2*n+i,P(x))=1;
            sim.At(2*n+i,Q(y))=-1;
            sim.At(2*n+i,0)=lxy-sxy;
 
            sim.At(2*n+m+i,P(x))=-1;
            sim.At(2*n+m+i,Q(y))=1;
            sim.At(2*n+m+i,0)=txy-lxy;
 
            sim.At(0,0)+=lxy;
            sim.At(0,P(x))+=1;
            sim.At(0,Q(y))-=1;
        }
        if(sim.Run()){
            pi((int)round(sim.Result()[0].Value())),pf("\n");
            lp(i,1,n){
                pi((int)round(sim.Result()[P(i)].Value()));
                if(i==n)pf("\n");
                else pf(" ");
            }
            lp(i,1,n){
                pi((int)round(sim.Result()[Q(i)].Value()));
                if(i==n)pf("\n");
                else pf(" ");
            }
        }else{
            pf("Unlike\n");
        }
    }
    return 0;
}
