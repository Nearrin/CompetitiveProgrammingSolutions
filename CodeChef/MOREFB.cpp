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
template<class VAL,class MOD>inline VAL ModularMultiply(VAL a,VAL b,const MOD&c){
    VAL r=0;
    for(;b!=VAL(0);b>>=1,a=(a+a)%c)
        if(b%VAL(2)==1)
            r=(r+a)%c;
    return r;
}
template<class VAL,class POW,class MOD>inline VAL ModularPower(VAL a,POW b,const MOD&c,const bool&s=false){
    VAL r=1;
    for(;b!=POW(0);b>>=1,a=s?ModularMultiply(a,a,c):a*a%c)
        if(b%POW(2)==1)
            r=s?ModularMultiply(r,a,c):r*a%c;
    return r;
}
template<class VAL=long long,VAL MOD=(long long)(1e9+7),bool SAF=false>class ModularInteger{
private:
    VAL val;
public:
    inline ModularInteger(const VAL&_val=0):
    val(_val){
        if(val<VAL(0)||val>=MOD)
            val=(val%MOD+MOD)%MOD;
    }
    inline VAL&Value(){
        return val;
    }
    inline const VAL&Value()const{
        return val;
    }
    inline ModularInteger<VAL,MOD,SAF>operator-()const{
        return ModularInteger<VAL,MOD,SAF>(val>VAL(0)?MOD-val:0);
    }
    inline ModularInteger<VAL,MOD,SAF>Add(const ModularInteger<VAL,MOD,SAF>&a){
        return ModularInteger<VAL,MOD,SAF>(val+a.val>=MOD?val+a.val-MOD:val+a.val);
    }
    inline ModularInteger<VAL,MOD,SAF>Minus(const ModularInteger<VAL,MOD,SAF>&a){
        return ModularInteger<VAL,MOD,SAF>(val-a.val<VAL(0)?val-a.val+MOD:val-a.val);
    }
    inline ModularInteger<VAL,MOD,SAF>Multiply(const ModularInteger<VAL,MOD,SAF>&a){
        return ModularInteger<VAL,MOD,SAF>(SAF?ModularMultiply(val,a.val,MOD):val*a.val%MOD);
    }
    inline ModularInteger<VAL,MOD,SAF>Divide(const ModularInteger<VAL,MOD,SAF>&a){
        if(SAF)
            return ModularInteger<VAL,MOD,SAF>(ModularMultiply(val,ModularPower(a.val,MOD-VAL(2),MOD,SAF),MOD));
        else
            return ModularInteger<VAL,MOD,SAF>(val*ModularPower(a.val,MOD-VAL(2),MOD,SAF)%MOD);
    }
    inline std::vector<ModularInteger<VAL,MOD,SAF> >Root(const int&a)const{
        std::vector<ModularInteger<VAL,MOD,SAF> >r;
        for(VAL i=0;i<MOD;++i){
            if(ModularPower(i,a,MOD,SAF)==val)
                r.push_back(ModularInteger<VAL,MOD,SAF>(i));
        }
        return r;
    }
    inline std::vector<ModularInteger<VAL,MOD,SAF> >Sqrt()const{
        return Root(2);
    }
    inline ModularInteger<VAL,MOD,SAF>&operator+=(const ModularInteger<VAL,MOD,SAF>&a){
        val+=a.val;
        if(val>=MOD)
            val-=MOD;
        return*this;
    }
    inline ModularInteger<VAL,MOD,SAF>&operator-=(const ModularInteger<VAL,MOD,SAF>&a){
        val-=a.val;
        if(val<VAL(0))
            val+=MOD;
        return*this;
    }
    inline ModularInteger<VAL,MOD,SAF>&operator*=(const ModularInteger<VAL,MOD,SAF>&a){
        val=SAF?ModularMultiply(val,a.val,MOD):val*a.val%MOD;
        return*this;
    }
    inline ModularInteger<VAL,MOD,SAF>&operator/=(const ModularInteger<VAL,MOD,SAF>&a){
        if(SAF)
            val=ModularMultiply(val,ModularPower(a.val,MOD-VAL(2),MOD,SAF),MOD);
        else
            val=val*ModularPower(a.val,MOD-VAL(2),MOD,SAF)%MOD;
        return*this;
    }
    inline bool NotEqual(const ModularInteger<VAL,MOD,SAF>&a){
        return val!=a.val;
    }
    inline bool Equal(const ModularInteger<VAL,MOD,SAF>&a){
        return!(*this!=a);
    }
    inline ModularInteger<VAL,MOD,SAF>&Pow(const VAL&a){
        val=ModularPower(val,a,MOD,SAF);
        return*this;
    }
    inline void Read(std::istream&s){
        s>>val;
        val=(val%MOD+MOD)%MOD;
    }
    inline void Write(std::ostream&s)const{
        s<<val;
    }
};
template<class VAL,VAL MOD,bool SAF>inline ModularInteger<VAL,MOD,SAF>operator+(const ModularInteger<VAL,MOD,SAF>&a,const ModularInteger<VAL,MOD,SAF>&b){
    return ModularInteger<VAL,MOD,SAF>(a)+=b;
}
template<class VAL,VAL MOD,bool SAF>inline ModularInteger<VAL,MOD,SAF>operator-(const ModularInteger<VAL,MOD,SAF>&a,const ModularInteger<VAL,MOD,SAF>&b){
    return ModularInteger<VAL,MOD,SAF>(a)-=b;
}
template<class VAL,VAL MOD,bool SAF>inline ModularInteger<VAL,MOD,SAF>operator*(const ModularInteger<VAL,MOD,SAF>&a,const ModularInteger<VAL,MOD,SAF>&b){
    return ModularInteger<VAL,MOD,SAF>(a)*=b;
}
template<class VAL,VAL MOD,bool SAF>inline ModularInteger<VAL,MOD,SAF>operator/(const ModularInteger<VAL,MOD,SAF>&a,const ModularInteger<VAL,MOD,SAF>&b){
    return ModularInteger<VAL,MOD,SAF>(a)/=b;
}
template<class VAL,VAL MOD,bool SAF>inline std::vector<ModularInteger<VAL,MOD,SAF> >Root(const ModularInteger<VAL,MOD,SAF>&a,const int&b){
    return a.Root(b);
}
template<class VAL,VAL MOD,bool SAF>inline std::vector<ModularInteger<VAL,MOD,SAF> >Sqrt(const ModularInteger<VAL,MOD,SAF>&a){
    return a.Sqrt();
}
template<class VAL,VAL MOD,bool SAF>inline bool operator==(const ModularInteger<VAL,MOD,SAF>&a,const ModularInteger<VAL,MOD,SAF>&b){
    return a.Equal(b);
}
template<class VAL,VAL MOD,bool SAF>inline bool operator!=(const ModularInteger<VAL,MOD,SAF>&a,const ModularInteger<VAL,MOD,SAF>&b){
    return a.NotEqual(b);
}
template<class VAL,VAL MOD,bool SAF>inline ModularInteger<VAL,MOD,SAF>Pow(const ModularInteger<VAL,MOD,SAF>&a,const VAL&b){
    return ModularInteger<VAL,MOD,SAF>(a).Pow(b);
}
template<class VAL,VAL MOD,bool SAF>inline std::istream&operator>>(std::istream&s,ModularInteger<VAL,MOD,SAF>&t){
    t.Read(s);
    return s;
}
template<class VAL,VAL MOD,bool SAF>inline std:: ostream&operator<<(std::ostream&s,const ModularInteger<VAL,MOD,SAF>&t){
    t.Write(s);
    return s;
}
template<class VAL>inline void FastFourierTransform(std::vector<std::complex<VAL> >&a,const int&n,const VAL&s){
    std::complex<VAL> im(VAL(0),VAL(1));
    VAL pi=acos(VAL(-1));
    for(int i=0;i<n;++i){
        int j=0;
        for(int k=0;(1<<k)<n;++k)
            j<<=1,j+=((i>>k)&1);
        if(i<j)
            swap(a[i],a[j]);
    }
    for(int i=1;(1<<i)<=n;++i){
        int m=(1<<i);
        std::complex<VAL>wm=exp(VAL(s)*im*VAL(2)*pi/VAL(m));
        for(int j=0;j<n;j+=m){
            std::complex<VAL> w(VAL(1));
            for(int k=0;k<(m>>1);++k){
                std::complex<VAL> u=a[j+k],v=w*a[j+k+(m>>1)];
                a[j+k]=u+v;
                a[j+k+(m>>1)]=u-v;
                w*=wm;
            }
        }
    }
}
template<class VAL,class CPX=long double,ll DEL=2>inline std::vector<VAL>Convolution(const std::vector<VAL>&a,const std::vector<VAL>&b){
    int n=1;
    while(n<a.size()+b.size()-1)
        n*=2;
    std::vector<std::complex<CPX> >ta(n),tb(n);
    for(int i=0;i<a.size();++i)
        ta[i]=a[i];
    for(int i=0;i<b.size();++i)
        tb[i]=b[i];
    FastFourierTransform(ta,n,(long double)1);
    FastFourierTransform(tb,n,(long double)1);
    for(int i=0;i<n;++i)
        ta[i]*=tb[i];
    FastFourierTransform(ta,n,(long double)(-1));
    std::vector<VAL>ret(a.size()+b.size()-1);
    for(int i=0;i<ret.size();++i)
        ret[i]=real(ta[i])/n+CPX(1)/CPX(DEL);
    return ret;
}
typedef ModularInteger<ll,99991,false>Int;
std::vector<ll>divandc(int*a,int l,int r,int t){
    if(l==r){
        std::vector<ll>tmp;
        tmp.push_back(1);
        tmp.push_back(ModularPower(ll(t),ll(a[l]),99991ll));
        return tmp;
    }else{
        int m=(l+r)/2;
        std::vector<ll>tmp1=divandc(a,l,m,t),tmp2=divandc(a,m+1,r,t);
        std::vector<ll>ret=Convolution<ll>(tmp1,tmp2);
        for(int i=0;i<ret.size();++i)
            ret[i]%=99991;
        return ret;
    }
}
Int calc(int*a,int n,int k,Int t){
    return Int(divandc(a,1,n,t.Value())[k]);
}
int main(){
    Int t1,t2,c1,c2;
    t1=(Int(1)+Int(10104))/Int(2);
    c1=Int(1)/Int(10104);
    t2=(Int(1)-Int(10104))/Int(2);
    c2=Int(-1)/Int(10104);
    //lp(i,1,10)
    //fibtest(i);
    int n,k;
    si(n),si(k);
    static int a[50010];
    lp(i,1,n)si(a[i]);
    cout<<c1*calc(a,n,k,t1)+c2*calc(a,n,k,t2)<<endl;
    return 0;
}
