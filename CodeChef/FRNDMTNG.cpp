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
    inline EpsilonReal<VAL>operator-()const{
        return EpsilonReal<VAL>(-val);
    }
    inline EpsilonReal<VAL>Add(const EpsilonReal<VAL>&a){
        return EpsilonReal<VAL>(val+a.val);
    }
    inline EpsilonReal<VAL>Minus(const EpsilonReal<VAL>&a){
        return EpsilonReal<VAL>(val-a.val);
    }
    inline EpsilonReal<VAL>Multiply(const EpsilonReal<VAL>&a){
        return EpsilonReal<VAL>(val*a.val);
    }
    inline EpsilonReal<VAL>Divide(const EpsilonReal<VAL>&a){
        return EpsilonReal<VAL>(val/a.val);
    }
    inline EpsilonReal<VAL>&operator+=(const EpsilonReal<VAL>&a){
        val+=a.val;
        return*this;
    }
    inline EpsilonReal<VAL>&operator-=(const EpsilonReal<VAL>&a){
        val-=a.val;
        return*this;
    }
    inline EpsilonReal<VAL>&operator*=(const EpsilonReal<VAL>&a){
        val*=a.val;
        return*this;
    }
    inline EpsilonReal<VAL>&operator/=(const EpsilonReal<VAL>&a){
        val/=a.val;
        return*this;
    }
    inline bool Less(const EpsilonReal<VAL>&a)const{
        return val<a.val-VAL(1)/VAL(EPS);
    }
    inline bool LessEqual(const EpsilonReal<VAL>&a)const{
        return val<a.val+VAL(1)/VAL(EPS);
    }
    inline bool Greater(const EpsilonReal<VAL>&a)const{
        return val>a.val+VAL(1)/VAL(EPS);
    }
    inline bool GreaterEqual(const EpsilonReal<VAL>&a)const{
        return val>a.val-VAL(1)/VAL(EPS);
    }
    inline bool NotEqual(const EpsilonReal<VAL>&a)const{
        return *this<a||*this>a;
    }
    inline bool Equal(const EpsilonReal<VAL>&a)const{
        return!(*this!=a);
    }
    inline EpsilonReal<VAL>&Abs(){
        val=std::fabs(val);
        return*this;
    }
    inline EpsilonReal<VAL>&Pow(const EpsilonReal<VAL>&a){
        val=std::pow(val,a.val);
        return*this;
    }
    inline EpsilonReal<VAL>&Root(const EpsilonReal<VAL>&a){
        val=std::pow(val,1/a.val);
        return*this;
    }
    inline EpsilonReal<VAL>&Sqrt(){
        val=std::sqrt(val);
        return*this;
    }
    inline void Read(std::istream&s){
        s>>val;
    }
    inline void Write(std::ostream&s)const{
        s<<val;
    }
    inline operator double(){
        return val;
    }
};
template<class VAL>inline EpsilonReal<VAL> operator+(const EpsilonReal<VAL>&a,const EpsilonReal<VAL>&b){
    return EpsilonReal<VAL>(a)+=b;
}
template<class VAL>inline EpsilonReal<VAL> operator-(const EpsilonReal<VAL>&a,const EpsilonReal<VAL>&b){
    return EpsilonReal<VAL>(a)-=b;
}
template<class VAL>inline EpsilonReal<VAL> operator*(const EpsilonReal<VAL>&a,const EpsilonReal<VAL>&b){
    return EpsilonReal<VAL>(a)*=b;
}
template<class VAL>inline EpsilonReal<VAL> operator/(const EpsilonReal<VAL>&a,const EpsilonReal<VAL>&b){
    return EpsilonReal<VAL>(a)/=b;
}
template<class VAL>inline bool operator==(const EpsilonReal<VAL>&a,const EpsilonReal<VAL>&b){
    return a.Equal(b);
}
template<class VAL>inline bool operator!=(const EpsilonReal<VAL>&a,const EpsilonReal<VAL>&b){
    return a.NotEqual(b);
}
template<class VAL>inline bool operator<(const EpsilonReal<VAL>&a,const EpsilonReal<VAL>&b){
    return a.Less(b);
}
template<class VAL>inline bool operator<=(const EpsilonReal<VAL>&a,const EpsilonReal<VAL>&b){
    return a.LessEqual(b);
}
template<class VAL>inline bool operator>(const EpsilonReal<VAL>&a,const EpsilonReal<VAL>&b){
    return a.Greater(b);
}
template<class VAL>inline bool operator>=(const EpsilonReal<VAL>&a,const EpsilonReal<VAL>&b){
    return a.GreaterEqual(b);
}
template<class VAL>inline EpsilonReal<VAL>Abs(const EpsilonReal<VAL>&a){
    return EpsilonReal<VAL>(a).Abs();
}
template<class VAL>inline EpsilonReal<VAL>Pow(const EpsilonReal<VAL>&a,const EpsilonReal<VAL>&b){
    return EpsilonReal<VAL>(a).Pow(b);
}
template<class VAL>inline EpsilonReal<VAL>Root(const EpsilonReal<VAL>&a,const EpsilonReal<VAL>&b=2){
    return EpsilonReal<VAL>(a).Root(b);
}
template<class VAL>inline EpsilonReal<VAL>Sqrt(const EpsilonReal<VAL>&a){
    return EpsilonReal<VAL>(a).Sqrt();
}
template<class VAL>inline std::istream&operator>>(std::istream&s,EpsilonReal<VAL>&t){
    t.Read(s);
    return s;
}
template<class VAL>inline std:: ostream&operator<<(std::ostream&s,const EpsilonReal<VAL>&t){
    t.Write(s);
    return s;
}
template<class VAL>class TwoDimensionalPoint{
private:
    VAL x,y;
public:
    inline TwoDimensionalPoint(const VAL&_x,const VAL&_y):
        x(_x),y(_y){
    }
    inline TwoDimensionalPoint<VAL>&operator=(const TwoDimensionalPoint<VAL>&a){
        x=a.x;
        y=a.y;
        return*this;
    }
    inline TwoDimensionalPoint<VAL>operator+(const TwoDimensionalPoint<VAL>&a)const{
        return TwoDimensionalPoint(x+a.x,y+a.y);
    }
    inline TwoDimensionalPoint<VAL>operator-(const TwoDimensionalPoint<VAL>&a)const{
        return TwoDimensionalPoint(x-a.x,y-a.y);
    }
    inline TwoDimensionalPoint<VAL>operator*(const VAL&a)const{
        return TwoDimensionalPoint(x*a,y*a);
    }
    inline TwoDimensionalPoint<VAL>operator/(const VAL&a)const{
        return TwoDimensionalPoint(x/a,y/a);
    }
    inline VAL Dot(const TwoDimensionalPoint<VAL>&a)const{
        return x*a.x+y*a.y;
    }
    inline VAL Det(const TwoDimensionalPoint<VAL>&a)const{
        return x*a.y-a.x*y;
    }
    inline VAL Angle()const{
        return std::atan2(double(x),double(y));
    }
};
template<class VAL>inline VAL Dot(const TwoDimensionalPoint<VAL>&a,const TwoDimensionalPoint<VAL>&b){
    return a.Dot(b);
}
template<class VAL>inline VAL Det(const TwoDimensionalPoint<VAL>&a,const TwoDimensionalPoint<VAL>&b){
    return a.Det(b);
}
template<class VAL>inline VAL Angle(const TwoDimensionalPoint<VAL>&a){
    return a.Angle();
}
template<class VAL>class TwoDimensionalLine{
private:
    TwoDimensionalPoint<VAL>p,q;
    VAL a;
public:
    inline TwoDimensionalLine(const TwoDimensionalPoint<VAL>&a,const TwoDimensionalPoint<VAL>&b):
        p(a),q(b),a((b-a).Angle()){
    }
    inline TwoDimensionalPoint<VAL> Intersection(const TwoDimensionalLine<VAL>&a)const{
       VAL a1=Det(p-a.q,q-p);
       VAL a2=Det(a.p-q,q-p);
       return (a.p*a1+a.q*a2)/(a1+a2);
    }
    inline bool Less(const TwoDimensionalLine<VAL>&b)const{
        if(a!=b.a)
            return a<b.a;
        return Det(q-b.p,b.q-b.p)<VAL(0);
    }
    inline bool Direction(const TwoDimensionalPoint<VAL>&t)const{
        return Det(t-p,q-p)<VAL(0);
    }
    inline VAL Angle()const{
        return a;
    }
};
template<class VAL>inline bool  operator<(const TwoDimensionalLine<VAL>&a,const TwoDimensionalLine<VAL>&b){
    return a.Less(b);
}
template<class VAL>inline bool Direction(const TwoDimensionalLine<VAL>&a,const TwoDimensionalPoint<VAL>&t){
    return a.Direction(t);
}
template<class VAL>inline TwoDimensionalPoint<VAL> Intersection(const TwoDimensionalLine<VAL>&a,const TwoDimensionalLine<VAL>&b){
    return a.Intersection(b);
}
template<class VAL>std::pair<std::vector<TwoDimensionalLine<VAL> >,std::vector<TwoDimensionalPoint<VAL> > >HalfPlaneIntersection(std::vector<TwoDimensionalLine<VAL> >lns){
    std::sort(lns.begin(),lns.end());
    std::deque<TwoDimensionalLine<VAL> >qu;
    for(int i=0;i<lns.size();++i){
        while(qu.size()>1&&!Direction(lns[i],Intersection(qu.back(),qu[qu.size()-2])))
            qu.pop_back();
        while(qu.size()>1&&!Direction(lns[i],Intersection(qu[0],qu[1])))
            qu.pop_front();
        if(qu.empty()||qu.back().Angle()!=lns[i].Angle())
            qu.push_back(lns[i]);
    }
    while(qu.size()>1&&!Direction(qu.front(),Intersection(qu[qu.size()-1],qu[qu.size()-2])))
        qu.pop_back();
    if(qu.size()<3)
        qu.clear();
    std::vector<TwoDimensionalLine<VAL> >ret;
    std::vector<TwoDimensionalPoint<VAL> >ret2;
    for(int i=0;i<qu.size();++i)
        ret.push_back(qu[i]);
    for(int i=0;i<ret.size();++i)
        ret2.push_back(Intersection(ret[i],ret[(i+1)%ret.size()]));
    return std::make_pair(ret,ret2);
}
int main(){
    int T;si(T);
    lp(I,1,T){
        double T1,T2,t1,t2;
        scanf("%lf%lf%lf%lf",&T1,&T2,&t1,&t2);
        std::vector<TwoDimensionalLine<long double> >lns;
        lns.push_back(TwoDimensionalLine<long double>(TwoDimensionalPoint<long double>(0,-t2),   TwoDimensionalPoint<long double>(100,100-t2)));
        lns.push_back(TwoDimensionalLine<long double>(TwoDimensionalPoint<long double>(100,100+t1),   TwoDimensionalPoint<long double>(0,t1)));
        lns.push_back(TwoDimensionalLine<long double>(TwoDimensionalPoint<long double>(0,0),   TwoDimensionalPoint<long double>(T1,0)));
        lns.push_back(TwoDimensionalLine<long double>(TwoDimensionalPoint<long double>(T1,0),   TwoDimensionalPoint<long double>(T1,T2)));
        lns.push_back(TwoDimensionalLine<long double>(TwoDimensionalPoint<long double>(T1,T2),   TwoDimensionalPoint<long double>(0,T2)));
        lns.push_back(TwoDimensionalLine<long double>(TwoDimensionalPoint<long double>(0,T2),   TwoDimensionalPoint<long double>(0,0)));
        double ans=0;
        std::vector<TwoDimensionalPoint<long double> >tmp=HalfPlaneIntersection<>(lns).second;
        vp(i,tmp){
            ans+=double(Det(tmp[i],tmp[(i+1)%tmp.size()]));
        }
        if(ans<0)ans*=-1;
        ans/=2;
        ans/=T1*T2;
        pf("%lf\n",double(ans));
    }
    return 0;
}
