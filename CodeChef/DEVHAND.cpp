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
template<class VAL,class POW,class MOD>inline VAL ModularPower(VAL a,POW b,const MOD&c,bool s=true){
    VAL r=1;
    for(;b!=POW(0);b>>=1,a=s?ModularMultiply(a,a,c):a*a%c)
        if(b%POW(2)==1)
            r=s?ModularMultiply(r,a,c):r*a%c;
    return r;
}
template<class VAL,VAL MOD,bool SAF>class ModularInteger{
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
    inline void Write(std::ostream&s){
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
template<class VAL,VAL MOD,bool SAF>inline ModularInteger<VAL,MOD,SAF>operator%(const ModularInteger<VAL,MOD,SAF>&a,const ModularInteger<VAL,MOD,SAF>&b){
    return ModularInteger<VAL,MOD,SAF>(a)%=b;
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


typedef ModularInteger<ll,ll(1e9+7),false> INT;

INT ALL(INT n,INT k){
    return Pow(k*(INT(1)-Pow(k,n.Value()))/(INT(1)-k),3ll);
}
INT AB_BC_AC(INT n,INT k){
    INT s1=INT(3)*Pow(k,2ll)/Pow(k-INT(1),2ll)*Pow(Pow(k,n.Value())-INT(1),2ll);
    INT s2=INT(6)*Pow(k,2ll)/Pow(k-INT(1),2ll)*(INT(1)-Pow(k,n.Value()))*(k*(INT(1)-Pow(k,n.Value()))/(INT(1)-k)-n*Pow(k,n.Value()));
    return s1+s2;
}
INT S4(INT n,INT k){
    INT s11=(INT(0)-k+INT(2)*k*(INT(1)-Pow(k,n.Value()))/(INT(1)-k)-(INT(2)*n-INT(1))*Pow(k,(n+INT(1)).Value()))/(INT(1)-k);
    INT s12=s11-Pow(k,(n+INT(1)).Value())*n*n;
    INT s1=s12/(INT(1)-k);
    INT s2=(k*(INT(1)-Pow(k,n.Value()))/(INT(1)-k)-n*Pow(k,(n+INT(1)).Value()))/(INT(1)-k);
    INT s3=k*(INT(1)-Pow(k,n.Value()))/(INT(1)-k);
    //cout<<s1.a<<endl;
    //cout<<s2.a<<endl;
    //cout<<s3.a<<endl;
    return s1-INT(2)*s2+s3;
}
INT S3(INT n,INT k){
    INT s11=(INT(0)-k+INT(2)*k*(INT(1)-Pow(k,n.Value()))/(INT(1)-k)-(INT(2)*n-INT(1))*Pow(k,(n+INT(1)).Value()))/(INT(1)-k);
    INT s12=s11-Pow(k,(n+INT(1)).Value())*n*n;
    INT s1=s12/(INT(1)-k);
    INT s2=(k*(INT(1)-Pow(k,n.Value()))/(INT(1)-k)-n*Pow(k,(n+INT(1)).Value()))/(INT(1)-k);
    INT s3=k*(INT(1)-Pow(k,n.Value()))/(INT(1)-k);
    //cout<<s1.a<<endl;
    //cout<<s2.a<<endl;
    //cout<<s3.a<<endl;
    return (s1-INT(3)*s2+INT(2)*s3);
}
INT ABIBC(INT n,INT k){
    INT s1=k*(INT(1)-Pow(k,n.Value()))/(INT(1)-k);
    INT s2=INT(4)*k/(INT(1)-k)*(k*(INT(1)-Pow(k,n.Value()))/(INT(1)-k)-n*Pow(k,n.Value()));
    INT s3=S3(n,k);
    INT s4=S4(n,k);
   // cout<<s4.a<<endl;
    INT s51=k*(INT(1)-Pow(k,n.Value()))/(INT(1)-k);
    INT s52=INT(-2)*n*Pow(k,n.Value());
    INT s53=Pow(k,  2*n.Value()-1  )*(INT(1)-INT(1)/Pow(k,n.Value()))/(INT(1)-INT(1)/k);




    INT s5=(s51+s52+s53)/((INT(1)-k)*(INT(1)-k))*k*k;
//    cout<<s1.a<<endl;
//     cout<<s2.a<<endl;
//      cout<<s3.a<<endl;
//      cout<<s4.a<<endl;
//       cout<<s5.a<<endl;
    //cout<<"["<<(s3).a<<endl;
    return s1+s2+s3+s4+s5;
}
INT ABIACIBC(INT n,INT k){
    INT s1=INT(3)*S4(n,k);
    INT s2=INT(3)/(INT(1)-k)*( k*k*(INT(1)-Pow(k,   (n-INT(1) ).Value()   )   )/(INT(1)-k)   - (n-INT(1))*Pow(k,(n+INT(1)).Value())   );
    INT s3=k*(INT(1)-Pow(k,n.Value()))/(INT(1)-k);
   // cout<<s21.a<<endl;
   // cout<<s22.a<<endl;
    //cout<<s3.a<<endl;
    return s1+s2+s3;
}
ll calc(ll n,ll k){
   // cout<<ALL(n,k).a<<endl;
   // cout<<AB_BC_AC(n,k).a<<endl;
   // cout<<ABIBC(n,k).a<<endl;
   // cout<<ABIACIBC(n,k).a<<endl;
    return(ALL(n,k)-AB_BC_AC(n,k)+INT(3)*ABIBC(n,k)-ABIACIBC(n,k)).Value();
}
bool bfc(string a,string b){
    int i=0;
    while(i<a.size()&&i<b.size())
        if(a[i]!=b[i])
            return true;
        else
            ++i;
    return false;
}

int bf(int n,int k){
    vector<string>all;
    lp(i,1,n){
        string t(i,'a');
        while(true){
            all.push_back(t);
            if(t==string(i,'a'+k-1))
                break;
            ++t[0];
            for(int i=0;i<t.size();++i)
                if(t[i]=='a'+k){
                    t[i]='a';
                    ++t[i+1];
                }
        }
    }
    //vp(i,all)
    //cout<<all[i]<<endl;
    int ans=0;
    vp(i,all)vp(j,all)vp(k,all)
        if(bfc(all[i],all[j])&&bfc(all[i],all[k])&&bfc(all[k],all[j]))
            ++ans;

   // cout<<all.size()*all.size()*all.size()<<endl;
    int ans2=0;
    vp(i,all)vp(j,all)vp(k,all)
    if(!bfc(all[i],all[j]))
        ++ans2;
    //cout<<ans2*3<<endl;



    int ans31=0;
    vp(i,all)vp(j,all)vp(k,all)
    if(!bfc(all[i],all[j])&&!bfc(all[j],all[k])){
        if(all[j].size()>all[i].size()&&all[j].size()<all[k].size())
          ++ans31;

    }
    //cout<<"["<<2*ans31<<endl;

    int ans3=0;
    vp(i,all)vp(j,all)vp(k,all)
    if(!bfc(all[i],all[j])&&!bfc(all[i],all[k]))
        ++ans3;
    //cout<<ans3<<endl;
    int ans4=0;
    vp(i,all)vp(j,all)vp(k,all)
    if(!bfc(all[i],all[j])&&!bfc(all[i],all[k])&&!bfc(all[j],all[k]))
        ++ans4;
   // cout<<ans4<<endl;

    cout<<ans<<endl;


}

int main(){

    int T;si(T);

    lp(I,1,T){
        ll n,k;
        sf("%lld%lld",&n,&k);
        pf("%lld\n",calc(n,k));
        //pf("\n");
        //bf(n,k);
    }

    return 0;
}
