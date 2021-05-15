#include<bits/stdc++.h>
using namespace std;
namespace PrimitiveRoot{
    template<class T>T mul(T x,T y,T z){
        if(typeid(T)==typeid(int))
            return (long long)x*y%z;
        else
            return (x*y-(T)(((long double)x*y+0.5)/z)*z+z)%z;
    }
    template<class T>T pow(T a,T b,T c){
        T r=1;
        for(;b;b&1?r=mul(r,a,c):0,b>>=1,a=mul(a,a,c));
        return r;
    }
    template<class T>bool chk(T a,int c=10){
        if(a==1)
            return false;
        T u=a-1,t=0;
        for(;u%2==0;u/=2,++t);
        for(int i=0;i<c;++i){
            T x=pow(T(rand()*1.0/RAND_MAX*(a-2)+1),u,a),y;
            for(int j=0;j<t;++j){
                y=x;
                x=mul(x,x,a);
                if(x==1&&y!=1&&y!=a-1)
                    return false;
            }
            if(x!=1)
                return false;
        }
        return true;
    }
    template<class T>T gcd(T a,T b){
        if(a<0)
            a=-a;
        if(b<0)
            b=-b;
        return b?gcd(b,a%b):a;
    }
    template<class T>T rho(T a,T c){
        T x=double(rand())/RAND_MAX*(a-1),y=x;
        for(int i=1,k=2;;){
            x=(mul(x,x,a)+c)%a;
            T d=gcd(y-x,a);
            if(d!=1&&d!=a)
                return d;
            if(y==x)
                return a;
            if(++i==k)
                y=x,k=2*k;
        }
    }
    template<class T>vector<pair<T,int> >fac(T a){
        if(a==1)
            return vector<pair<T,int> >();
        if(chk(a))
            return vector<pair<T,int> >(1,make_pair(a,1));
        T b=a;
        while((b=rho(b,T(double(rand())/RAND_MAX*(a-1))))==a);
        vector<pair<T,int> >u=fac(b),v=fac(a/b),r;
        for(int pu=0,pv=0;pu<u.size()||pv<v.size();){
            if(pu==u.size())
                r.push_back(v[pv++]);
            else if(pv==v.size())
                r.push_back(u[pu++]);
            else if(u[pu].first==v[pv].first)
                r.push_back(make_pair(u[pu].first,(u[pu].second+v[pv].second))),++pu,++pv;
            else if(u[pu].first>v[pv].first)
                r.push_back(v[pv++]);
            else
                r.push_back(u[pu++]);}
        return r;
    }
    template<class T>void dfs(vector<pair<T,int> >&f,int i,T now,vector<T>&r){
        if(i==f.size()){
            r.push_back(now);
            return;
        }
        for(int j=0;j<=f[i].second;++j,now*=f[i].first)
            dfs(f,i+1,now,r);
    }
    template<class T>T run(T a){
        vector<pair<T,int> >fa=fac(a),fpa;
        if(fa.size()==0||fa.size()>2)
            return -1;
        if(fa.size()==1&&fa[0].first==2&&fa[0].second>2)
            return -1;
        if(fa.size()==2&&fa[0]!=make_pair(T(2),1))
            return -1;
        T pa=a;
        for(int i=0;i<fa.size();++i)
            pa=pa/fa[i].first*(fa[i].first-1);
        fpa=fac(pa);
        vector<T>fs;
        dfs(fpa,0,1,fs);
        for(T g=1,f=0;;++g,f=0){
            for(int i=0;i<fs.size();++i)
                if(fs[i]!=pa&&pow(g,fs[i],a)==1){
                    f=1;
                    break;
                }
            if(!f)
                return g;
        }
    }
}


#include<bits/stdc++.h>
using namespace std;
template<class T>struct ModularInteger{
    ModularInteger(T t=0):
        v(t){
        if(v<0||v>=p)
            v=(v%p+p)%p;
    }
    ModularInteger<T>&operator=(T a){
        v=a;
        if(v<0||v>=p)
            v%=p;
        return*this;
    }
    ModularInteger<T>operator-(){
        return v?p-v:0;
    }
    ModularInteger<T>&operator+=(ModularInteger<T>a){
        return*this=*this+a;
    }
    ModularInteger<T>&operator-=(ModularInteger<T>a){
        return*this=*this-a;
    }
    ModularInteger<T>&operator*=(ModularInteger<T>a){
        return*this=*this*a;
    }
    ModularInteger<T>&operator/=(ModularInteger<T>a){
        return*this=*this/a;
    }
    T v;
    static T p;
};
template<class T>ModularInteger<T>pow(ModularInteger<T>a,long long b){
    ModularInteger<T>r(1);
    for(;b;b>>=1,a=a*a)
        if(b&1)
            r=r*a;
    return r;
}
template<class T>ModularInteger<T>inv(ModularInteger<T>a){
    return pow(a,a.p-2);
}
template<class T>vector<ModularInteger<T> >sqrt(ModularInteger<T>a){
    vector<ModularInteger<T> >r;
    if(!a.v)
        r.push_back(ModularInteger<T>(0));
    else if(pow(a,a.p-1>>1).v==1){
        int s=a.p-1,t=0;
        ModularInteger<T>b=1;
        for(;pow(b,a.p-1>>1).v!=a.p-1;b=rand()*1.0/RAND_MAX*(a.p-1));
        for(;s%2==0;++t,s/=2);
        ModularInteger<T>x=pow(a,(s+1)/2),e=pow(a,s);
        for(int i=1;i<t;++i,e=x*x/a)
            if(pow(e,1<<t-i-1).v!=1)
                x=x*pow(b,(1<<i-1)*s);
        r.push_back(x);
        r.push_back(-x);
    }
    return r;
}
template<class T>ModularInteger<T>operator+(ModularInteger<T>a,ModularInteger<T>b){
    ModularInteger<T>c(a.v+b.v);
    if(c.v>=a.p)
        c.v-=a.p;
    return c;
}
template<class T>ModularInteger<T>operator-(ModularInteger<T>a,ModularInteger<T>b){
    ModularInteger<T>c(a.v-b.v);
    if(c.v<0)
        c.v+=a.p;
    return c;
}
template<class T>ModularInteger<T>operator*(ModularInteger<T>a,ModularInteger<T>b){
    if(typeid(T)!=typeid(int))
        return ModularInteger<T>((a.v*b.v-(long long)(((long double)a.v*b.v+0.5)/a.p)*a.p+a.p)%a.p);
    else
        return ModularInteger<T>((long long)a.v*b.v%a.p);
}
template<class T>ModularInteger<T>operator/(ModularInteger<T>a,ModularInteger<T>b){
    return a*inv(b);
}
template<class T>bool operator==(ModularInteger<T>a,ModularInteger<T>b){
    return a.v==b.v;
}
template<class T>bool operator!=(ModularInteger<T>a,ModularInteger<T>b){
    return a.v!=b.v;
}
template<class T>istream&operator>>(istream&s,ModularInteger<T>&a){
    s>>a.v;
    return s;
}
template<class T>ostream&operator<<(ostream&s,ModularInteger<T>a){
    s<<a.v;
    if(a.v<0||a.v>=a.p)
        a.v%=a.p;
    return s;
}
template<class T>T ModularInteger<T>::p=1e9+7;


#include<bits/stdc++.h>
template<class T,int N>struct Matrix{
    Matrix(T t=0){
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                u[i][j]=i==j?t:0;
    }
    T u[N][N];
};
template<class T,int N>Matrix<T,N>operator+(const Matrix<T,N>&a,const Matrix<T,N>&b){
    Matrix<T,N>c;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            c.u[i][j]=a.u[i][j]+b.u[i][j];
    return c;
}
template<class T,int N>Matrix<T,N>operator*(const Matrix<T,N>&a,const Matrix<T,N>&b){
    Matrix<T,N>c;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            for(int k=0;k<N;++k)
                c.u[i][j]+=a.u[i][k]*b.u[k][j];
    return c;
}
template<class T,int N>Matrix<T,N>operator*(const Matrix<T,N>&a,const T&b){
    Matrix<T,N>c=a;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            c.u[i][j]*=b;
    return c;
}
template<class T,int N>Matrix<T,N>operator/(const Matrix<T,N>&a,const T&b){
    Matrix<T,N>c=a;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            c.u[i][j]/=b;
    return c;
}
template<class T,int N>Matrix<T,N>pow(Matrix<T,N>a,long long b){
    Matrix<T,N>r(1);
    for(;b;a=a*a,b>>=1)
        if(b&1)
            r=r*a;
    return r;
}
template<class T,int N>ostream&operator<<(ostream&s,const Matrix<T,N>a){
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            s<<a.u[i][j]<<(j+1==N?'\n':' ');
    return s;
}

int main(){
    int T;cin>>T;
    while(T--){
        ModularInteger<int> k;
        int p;long long n;
        cin>>n>>k>>p;
        ModularInteger<int>::p=p;
        ModularInteger<int>w=pow(ModularInteger<int>(PrimitiveRoot::run(p)),(p-1)/k.v);
        typedef Matrix<ModularInteger<int> ,2>Mat;
        Mat g;
        g.u[0][0]=g.u[0][1]=g.u[1][0]=1;
        Mat r;
        //cout<<w<<endl;
        //cout<<g<<endl;
        for(int i=1;i<=k.v;++i){
            Mat t=g*pow(w,i)+Mat(1);
            r=r+pow(t,n);
        }
        r=r/k;
        cout<<r.u[0][0]<<endl;
    }
    return 0;
}
