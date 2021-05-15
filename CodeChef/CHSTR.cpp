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
template<int SIG=26>class SuffixAutomaton{
public:
    class Node{
    private:
        friend class SuffixAutomaton;
        Node*pr,*tr[SIG];
        int ln,cnt;
    public:
        inline Node(Node*_pr=0,const int&_ln=0,const int&_cnt=0):
            pr(_pr),ln(_ln),cnt(_cnt){
            std::fill(tr,tr+SIG,(Node*)0);
        }
        inline Node*Parent(){
            return pr;
        }
        inline Node*Transfer(const int&a){
            return tr[a];
        }
        inline int Length(){
            return ln;
        }
        inline int Count(){
            return cnt;
        }
    }*root;
    std::vector<Node*>all;
    typedef Node*Pointer;
    inline SuffixAutomaton():
        root(new Node()){
        all.push_back(root);
    }
    inline ~SuffixAutomaton(){
        for(int i=0;i<all.size();++i)
            delete all[i];
    }

    inline Node*Root(){
        return root;
    }
    inline std::vector<Node*>&Nodes(){
        return all;
    }
    inline Node*Append(Node*lst,int c){
        if(lst->tr[c]){
            Node*p=lst,*q=lst->tr[c];
            if(q->ln==p->ln+1){
                ++q->cnt;
                return q;
            }else{
                Node*np=new Node(q->pr,p->ln+1,1);
                all.push_back(np);
                std::copy(q->tr,q->tr+SIG,np->tr);
                q->pr=np;
                for(;p&&p->tr[c]==q;p=p->pr)
                    p->tr[c]=np;
                return np;
            }
        }else{
            Node*p=lst,*np=new Node(0,p->ln+1,1);
            all.push_back(np);
            for(;p&&!p->tr[c];p=p->pr)
                p->tr[c]=np;
            if(!p)
                np->pr=root;
            else{
                Node*q=p->tr[c];
                if(q->ln==p->ln+1)
                    np->pr=q;
                else{
                    Node*nq=new Node(q->pr,p->ln+1,0);
                    all.push_back(nq);
                    std::copy(q->tr,q->tr+SIG,nq->tr);
                    q->pr=np->pr=nq;
                    for(;p&&p->tr[c]==q;p=p->pr)
                        p->tr[c]=nq;
                }
            }
            return np;
        }
    }
    inline void Build(){
        std::vector<int>cnt(all.size());
        std::vector<Node*>tmp=all;
        for(int i=0;i<tmp.size();++i)
            ++cnt[tmp[i]->ln];
        for(int i=1;i<cnt.size();++i)
            cnt[i]+=cnt[i-1];
        for(int i=0;i<tmp.size();++i)
            all[--cnt[tmp[i]->ln]]=tmp[i];
        for(int i=int(all.size())-1;i>0;--i)
            all[i]->pr->cnt+=all[i]->cnt;
    }
};
ll jiec[5010];
typedef ModularInteger<> Int;
Int ij[5010];
int main(){
    jiec[0]=1;
    for(int i=1;i<=5005;++i)
        jiec[i]=jiec[i-1]*ll(i)%ll(1e9+7);
    for(int i=0;i<=5005;++i)
        ij[i]=Int(1)/Int(jiec[i]);
    int T;si(T);
    lp(I,1,T){
        int n,q;
        si(n),si(q);
        static char buf[5010];
        sf("%s",buf);
        SuffixAutomaton<>sam;
        SuffixAutomaton<>::Pointer ptr=sam.Root();
        for(char*p=buf;*p;++p)
            ptr=sam.Append(ptr,*p-'a');
      //  vp(i,sam.Nodes())
         //       cout<<sam.Nodes()[i]->Count()<<" "<<sam.Nodes()[i]->Length()<<endl;
        sam.Build();
        //vp(i,sam.Nodes())
              //  cout<<sam.Nodes()[i]->Count()<<" "<<sam.Nodes()[i]->Length()<<endl;
        static Int ans[5010];
        lp(i,1,5005)
                ans[i]=Int(0);
        for(int k=1;k<=n;++k){
            vp(i,sam.Nodes()){
                ptr=sam.Nodes()[i];
                if(ptr->Count()>=k&&ptr->Parent()){
                     Int shuliang=ptr->Length()-ptr->Parent()->Length();
                     int c=ptr->Count();
                     Int t=shuliang* Int(jiec[c])*ij[k]*ij[c-k];
                     ans[k]+=t;
                }
            }
        }
        lp(i,1,q){
            int k;si(k);
            if(k>n)pi(0);
            else pi(int(ans[k].Value()));
            pf("\n");
        }
    }
    return 0;
}
