#include<algorithm>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<functional>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<string>
#include<vector>
namespace CoreUtilities{
    template<typename val_t>bool MakeMax(val_t&a,const val_t&b){
        if(a<b){a=b;return true;}
        return false;}
    template<typename val_t>bool MakeMin(val_t&a,const val_t&b){
        if(a>b){a=b;return true;}
        return false;}
    template<typename val_t>inline std::string ToStr(const val_t&a){
        std::stringstream s;s<<a;
        std::string r;s>>r;
        return r;}
    template<typename val_t>inline val_t FromStr(const std::string&a){
        std::stringstream s;s<<a;
        val_t r;s>>r;
        return r;}
    template<typename val_t>inline val_t Abs(const val_t&a){
        return a<val_t(0)?-a:a;}
    inline void SetInput(const std::string&a){
        std::freopen(a.c_str(),"r",stdin);}
    inline void SetOutput(const std::string&a){
        std::freopen(a.c_str(),"w",stdout);}
    inline void Read(int&a){
        char c;
        for(c=std::getchar();!std::isdigit(c)&&c!='-';c=std::getchar());
        bool flag=c=='-';
        a=flag?0:c-'0';
        for(c=std::getchar();std::isdigit(c);c=std::getchar())
            a=a*10+c-'0';
        a*=flag?-1:1;
        std::ungetc(c,stdin);}
    inline void Read(unsigned&a){
        char c;
        for(c=std::getchar();!std::isdigit(c);c=std::getchar());
        a=c-'0';
        for(c=std::getchar();std::isdigit(c);c=std::getchar())
            a=a*10+c-'0';
        std::ungetc(c,stdin);}
    inline void Read(long long&a){
        char c;
        for(c=std::getchar();!std::isdigit(c)&&c!='-';c=std::getchar());
        bool flag=c=='-';
        a=flag?0:c-'0';
        for(c=std::getchar();std::isdigit(c);c=std::getchar())
            a=a*10+c-'0';
        a*=flag?-1:1;
        std::ungetc(c,stdin);}
    inline void Read(unsigned long long&a){
        char c;
        for(c=std::getchar();!std::isdigit(c);c=std::getchar());
        a=c-'0';
        for(c=std::getchar();std::isdigit(c);c=std::getchar())
            a=a*10+c-'0';
        std::ungetc(c,stdin);}
    inline void Read(double&a){
        std::scanf("%lf",&a);}
    inline void Read(char*a){
        std::scanf("%s",a);}
    inline void Read(char&a){
        for(a=std::getchar();a=='\n'||a==' ';a=std::getchar());}
    inline void Write(const int&a){
        int b=a;
        if(b<0)b=-b,std::putchar('-');
        std::vector<char>t;
        do{
            t.push_back(b%10+'0');
            b/=10;
        }while(b!=0);
        for(std::vector<char>::const_reverse_iterator i=t.rbegin();i!=t.rend();++i)
            std::putchar(*i);}
    inline void Write(const unsigned&a){
        unsigned b=a;
        std::vector<char>t;
        do{
            t.push_back(b%10+'0');
            b/=10;
        }while(b!=0);
        for(std::vector<char>::const_reverse_iterator i=t.rbegin();i!=t.rend();++i)
            std::putchar(*i);}
    inline void Write(const long long&a){
        long long b=a;
        if(b<0)b=-b,std::putchar('-');
        std::vector<char>t;
        do{
            t.push_back(b%10+'0');
            b/=10;
        }while(b!=0);
        for(std::vector<char>::const_reverse_iterator i=t.rbegin();i!=t.rend();++i)
            std::putchar(*i);}
    inline void Write(const unsigned long long&a){
        unsigned long long b=a;
        std::vector<char>t;
        do{
            t.push_back(b%10+'0');
            b/=10;
        }while(b!=0);
        for(std::vector<char>::const_reverse_iterator i=t.rbegin();i!=t.rend();++i)
            std::putchar(*i);}
    inline void Write(const double&a,const int&b){
        std::printf(("%."+ToStr(b)+"lf").c_str(),a);}
    inline void Write(const char*a){
        std::printf("%s",a);}
    inline void Write(const char&a){
        std::putchar(a);}
    template<typename val_t=double,long long eps=100000000>struct Real{
        inline Real(const val_t&_val=0):
        val(_val){}
        inline Real<val_t,eps>&operator+=(const Real<val_t,eps>&a){
            val+=a.val;
            return*this;}
        inline Real<val_t,eps>&operator-=(const Real<val_t,eps>&a){
            val-=a.val;
            return*this;}
        inline Real<val_t,eps>&operator*=(const Real<val_t,eps>&a){
            val*=a.val;
            return*this;}
        inline Real<val_t,eps>&operator/=(const Real<val_t,eps>&a){
            val/=a.val;
            return*this;}
        val_t val;};
    template<typename val_t,long long eps>inline Real<val_t,eps>operator-(const Real<val_t,eps>&a){
        return Real<val_t,eps>(-a.val);}
    template<typename val_t,long long eps>inline Real<val_t,eps>operator+(const Real<val_t,eps>&a,const Real<val_t,eps>&b){
        return Real<val_t,eps>(a.val+b.val);}
    template<typename val_t,long long eps>inline Real<val_t,eps>operator-(const Real<val_t,eps>&a,const Real<val_t,eps>&b){
        return Real<val_t,eps>(a.val-b.val);}
    template<typename val_t,long long eps>inline Real<val_t,eps>operator*(const Real<val_t,eps>&a,const Real<val_t,eps>&b){
        return Real<val_t,eps>(a.val*b.val);}
    template<typename val_t,long long eps>inline Real<val_t,eps>operator/(const Real<val_t,eps>&a,const Real<val_t,eps>&b){
        return Real<val_t,eps>(a.val/b.val);}
    template<typename val_t,long long eps>inline bool operator<(const Real<val_t,eps>&a,const Real<val_t,eps>&b){
        return a.val<b.val-val_t(1)/val_t(eps);}
    template<typename val_t,long long eps>inline bool operator>(const Real<val_t,eps>&a,const Real<val_t,eps>&b){
        return a.val>b.val+val_t(1)/val_t(eps);}
    template<typename val_t,long long eps>inline bool operator!=(const Real<val_t,eps>&a,const Real<val_t,eps>&b){
        return a<b||a>b;}
    template<typename val_t,long long eps>inline bool operator==(const Real<val_t,eps>&a,const Real<val_t,eps>&b){
        return!(a!=b);}
    template<typename val_t,long long eps>inline void Read(Real<val_t,eps>&a){
        Read(a.val);}
    template<typename val_t,long long eps>inline void Write(const Real<val_t,eps>&a,const int&b){
        Write(a.val,b);}}
namespace NumberTheory{
    template<typename val_t>inline val_t GCD(const val_t&a,const val_t&b){
        return b==val_t(0)?a:GCD(b,a%b);}
    template<typename val_t>inline val_t ExGCD(const val_t&a,const val_t&b,val_t&x,val_t&y){
        if(b==val_t(0)){
            x=val_t(1);
            y=val_t(0);
            return a;
        }else{
            val_t t=ExGCD(b,a%b,y,x);
            y-=a/b*x;
            return t;}}
    template<typename val_t,typename pow_t>inline val_t Pow(val_t a,pow_t b){
        val_t r(1);
        for(;b!=pow_t(0);a*=a,b/=2)
            if(b%pow_t(2)==pow_t(1))
                r=r*a;
        return r;}
    template<typename val_t,typename pow_t>inline val_t PowMod(val_t a,pow_t b,pow_t c){
        val_t r(1);
        for(;b!=pow_t(0);a*=a,a%=c,b/=2)
            if(b%pow_t(2)==pow_t(1))
                r=r*a%c;
        return r;}
    template<typename val_t=long long,val_t mod=val_t(1000000007)>struct Int{
        inline Int(const val_t&_val=0):
        val(_val){}
        inline Int<val_t,mod>&operator+=(const Int<val_t,mod>&a){
            val+=a.val;
            if(val>=mod)
                val-=mod;
            return*this;}
        inline Int<val_t,mod>&operator-=(const Int<val_t,mod>&a){
            val-=a.val;
            if(val<val_t(0))
                val+=mod;
            return*this;}
        inline Int<val_t,mod>&operator*=(const Int<val_t,mod>&a){
            val=val*a.val%mod;
            return*this;}
        inline Int<val_t,mod>&operator/=(const Int<val_t,mod>&a){
            val_t x,y;
            ExGCD(a.val,mod,x,y);
            x=x%mod;
            if(x<val_t(0))
                x+=mod;
            val=val*x%mod;
            return*this;}
        val_t val;};
    template<typename val_t,val_t mod>inline Int<val_t,mod>operator-(const Int<val_t,mod>&a){
        val_t t=-a.val;
        if(t<val_t(0))
            t+=mod;
        return Int<val_t,mod>(t);}
    template<typename val_t,val_t mod>inline Int<val_t,mod>operator+(const Int<val_t,mod>&a,const Int<val_t,mod>&b){
        val_t t=a.val+b.val;
        if(t>=mod)
            t-=mod;
        return Int<val_t,mod>(t);}
    template<typename val_t,val_t mod>inline Int<val_t,mod>operator-(const Int<val_t,mod>&a,const Int<val_t,mod>&b){
        val_t t=a.val+b.val;
        if(t<val_t(0))
            t+=mod;
        return Int<val_t,mod>(t);}
    template<typename val_t,val_t mod>inline Int<val_t,mod>operator*(const Int<val_t,mod>&a,const Int<val_t,mod>&b){
        return Int<val_t,mod>(a.val*b.val%mod);}
    template<typename val_t,val_t mod>inline Int<val_t,mod>operator/(const Int<val_t,mod>&a,const Int<val_t,mod>&b){
        val_t x,y;
        ExGCD(b.val,mod,x,y);
        x=x%mod;
        if(x<val_t(0))
            x+=mod;
        return Int<val_t,mod>(a.val*x%mod);}
    template<typename val_t,val_t mod>inline bool operator==(const Int<val_t,mod>&a,const Int<val_t,mod>&b){
        return a.val==b.val;}
    template<typename val_t,val_t mod>inline bool operator!=(const Int<val_t,mod>&a,const Int<val_t,mod>&b){
        return a.val!=b.val;}
    template<typename val_t,val_t mod>inline void Read(Int<val_t,mod>&a){
        CoreUtilities::Read(a.val);}
    template<typename val_t,val_t mod>inline void Write(const Int<val_t,mod>&a){
        CoreUtilities::Write(a.val);}}
namespace DataStructures{
    template<typename val_t=int,typename cmp_t=std::less<val_t> >struct Heap{
        inline Heap():
        root(0),siz(0){}
        inline ~Heap(){
            clear(root);}
        struct node{
            inline node(const val_t&_val):
            val(_val),ch(0),br(0),pr(0){}
            val_t val;
            node*ch,*br,*pr;}*root;
        inline void merge(node*&x,node*y){
            if(!x)
                x=y;
            else if(y){
                if(cmp_t()(y->val,x->val))
                    std::swap(x,y);
                y->br=x->ch;
                if(x->ch)
                    x->ch->pr=y;
                y->pr=x;
                x->ch=y;}}
        inline void cut(node*&x,node*y){
            if(x==y)
                x=0;
            else{
                if(y==y->pr->ch)
                    y->pr->ch=y->br;
                else
                    y->pr->br=y->br;
                if(y->br)
                    y->br->pr=y->pr;
                y->pr=y->br=0;}}
        inline node*split(node*x){
            std::vector<node*>t;
            for(node*i=x->ch;i;i=i->br)
                t.push_back(i);
            x->ch=0;
            node*r=0;
            for(typename std::vector<node*>::const_iterator i=t.begin();i!=t.end();++i)
                (*i)->pr=(*i)->br=0;
            for(typename std::vector<node*>::const_iterator i=t.begin();i+1<t.end();i+=2)
                merge(*i,*(i+1));
            for(typename std::vector<node*>::const_iterator i=t.begin();i<t.end();i+=2)
                merge(r,*i);
            return r;}
        inline void clear(node*x){
            if(x){
                clear(x->ch);
                clear(x->br);
                delete x;}}
        inline void Clear(){
            clear(root);
            root=0;
            siz=0;}
        inline node*Push(const val_t&a){
            node*r=new node(a);
            merge(root,r);
            ++siz;
            return r;}
        inline void Erase(node*x){
            cut(root,x);
            merge(root,split(x));
            --siz;}
        inline const val_t&Top(){
            return root->val;}
        inline void Pop(){
            Erase(root);}
        inline void Merge(Heap<val_t,cmp_t>&a){
            merge(root,a.root);
            a.root=0;
            siz+=a.siz;
            a.siz=0;}
        inline void Modify(node*x,const val_t&v){
            if(cmp_t()(x->val,v)){
                x->val=v;
                merge(root,split(x));
            }else{
                x->val=v;
                cut(root,x);
                merge(root,x);}}
        inline int Size(){
            return siz;}
        inline bool Empty(){
            return !siz;}
        int siz;};
    template<typename key_t=int,typename val_t=int,typename cmp_t=std::less<key_t> >struct Map{
        inline Map():
        root(0){}
        inline~Map(){
            clear(root);}
        struct node{
            inline node(const key_t&_key,const val_t&_val):
            fix(std::rand()),siz(1),key(_key),val(_val),lc(0),rc(0){}
            node*lc,*rc;
            int fix,siz;
            key_t key;
            val_t val;}*root;
        inline void update(node*x){
            x->siz=1;
            if(x->lc)
                x->siz+=x->lc->siz;
            if(x->rc)
                x->siz+=x->rc->siz;}
        inline void rotate_l(node*&x){
            node*y=x->lc;
            x->lc=y->rc;
            y->rc=x;
            y->siz=x->siz;
            x->siz-=1+(y->lc?y->lc->siz:0);
            x=y;}
        inline void rotate_r(node*&x){
            node*y=x->rc;
            x->rc=y->lc;
            y->lc=x;
            y->siz=x->siz;
            x->siz-=1+(y->rc?y->rc->siz:0);
            x=y;}
        inline node*access(node*&x,const key_t&key){
            if(!x)
                return x=new node(key,val_t());
            if(cmp_t()(key,x->key)){
                node*r=access(x->lc,key);
                update(x);
                if(x->lc->fix<x->fix)
                    rotate_l(x);
                return r;}
            if(cmp_t()(x->key,key)){
                node*r=access(x->rc,key);
                update(x);
                if(x->rc->fix<x->fix)
                    rotate_r(x);
                return r;}
            return x;}
        inline bool exist(node*x,const key_t&key){
            if(!x)
                return false;
            if(cmp_t()(key,x->key))
                return exist(x->lc,key);
            if(cmp_t()(x->key,key))
                return exist(x->rc,key);
            return true;}
        inline void erase(node*&x,const key_t&key){
            if(cmp_t()(key,x->key)){
                erase(x->lc,key);
                --x->siz;
            }else if(cmp_t()(x->key,key)){
                erase(x->rc,key);
                --x->siz;
            }else if(!x->lc){
                node*t=x->rc;
                delete x;
                x=t;
            }else if(!x->rc){
                node*t=x->lc;
                delete x;
                x=t;
            }else if(x->lc->fix<x->rc->fix){
                rotate_l(x);
                erase(x->rc,key);
                --x->siz;
            }else{
                rotate_r(x);
                erase(x->lc,key);
                --x->siz;}}
        inline node*select(node*x,const int&k){
            int t=x->lc?x->lc->siz:0;
            if(k<t)
                return select(x->lc,k);
            if(k==t)
                return x;
            return select(x->rc,k-(t+1));}
        inline int rank(node*x,const key_t&key){
            if(!x)
                return 0;
            if(cmp_t()(key,x->key))
                return rank(x->lc,key);
            if(cmp_t()(x->key,key))
                return(x->lc?x->lc->siz:0)+1+rank(x->rc,key);
            return (x->lc?x->lc->siz:0);}
        inline void clear(node*x){
            if(x){
                clear(x->lc);
                clear(x->rc);
                delete x;}}
        inline void Insert(const key_t&key,const val_t&val){
            access(root,key)->val=val;}
        inline void Erase(const key_t&key){
            erase(root,key);}
        inline val_t&operator[](const key_t&key){
            return access(root,key)->val;}
        inline node*Select(int k){
            return select(root,k);}
        inline bool Exist(const key_t&key){
            return exist(root,key);}
        inline int Rank(const key_t&key){
            return rank(root,key);}
        inline void Clear(){
            clear(root);
            root=0;}
        inline node*Front(){
            return select(0);}
        inline node*Back(){
            return select(Size()-1);}
        inline int Size(){
            return root?root->siz:0;}
        inline bool Empty(){
            return !root;}
        inline node*LowerBound(const key_t&key){
            if(!root)
                return 0;
            int t=rank(key);
            if(t==root->size)
                return 0;
            return select(t);}
        inline node*UpperBound(const key_t&key){
            if(!root)
                return 0;
            int t=rank(key)+exist(key);
            if(t==root->size)
                return 0;
            return select(t);}
        inline node*Next(node*x){
            int t=rank(x->key)+1;
            if(t==root->siz)
                return 0;
            return select(t);}
        inline node*Prec(node*x){
            int t=rank(x->key)-1;
            if(t<0)
                return 0;
            return select(t);}};
    template<typename val_t=int,typename cmp_t=std::less<val_t> >struct Set{
        inline Set():
        root(0){}
        inline~Set(){
            clear(root);}
        struct node{
            inline node(const val_t&_val):
            fix(std::rand()),siz(1),val(_val),lc(0),rc(0){}
            node*lc,*rc;
            int fix,siz;
            val_t val;}*root;
        inline void rotate_l(node*&x){
            node*y=x->lc;
            x->lc=y->rc;
            y->rc=x;
            y->siz=x->siz;
            x->siz-=1+(y->lc?y->lc->siz:0);
            x=y;}
        inline void rotate_r(node*&x){
            node*y=x->rc;
            x->rc=y->lc;
            y->lc=x;
            y->siz=x->siz;
            x->siz-=1+(y->rc?y->rc->siz:0);
            x=y;}
        inline void insert(node*&x,const val_t&val){
            if(!x)
                x=new node(val);
            else if(cmp_t()(val,x->val)){
                insert(x->lc,val);
                ++x->siz;
                if(x->lc->fix<x->fix)
                    rotate_l(x);
            }else{
                insert(x->rc,val);
                ++x->siz;
                if(x->rc->fix<x->fix)
                    rotate_r(x);}}
        inline void erase(node*&x,const val_t&val){
            if(cmp_t()(val,x->val)){
                erase(x->lc,val);
                --x->siz;
            }else if(cmp_t()(x->val,val)){
                erase(x->rc,val);
                --x->siz;
            }else if(!x->lc){
                node*t=x->rc;
                delete x;
                x=t;
            }else if(!x->rc){
                node*t=x->lc;
                delete x;
                x=t;
            }else if(x->lc->fix<x->rc->fix){
                rotate_l(x);
                erase(x->rc,val);
                --x->siz;
            }else{
                rotate_r(x);
                erase(x->lc,val);
                --x->siz;}}
        inline bool exist(node*x,const val_t&val){
            if(!x)
                return false;
            if(cmp_t()(val,x->val))
                return exist(x->lc,val);
            if(cmp_t()(x->val,val))
                return exist(x->rc,val);
            return true;}
        inline val_t select(node*x,const int&k){
            int t=x->lc?x->lc->siz:0;
            if(k<t)
                return select(x->lc,k);
            if(k==t)
                return x->val;
            return select(x->rc,k-(t+1));}
        inline void clear(node*x){
            if(x){
                clear(x->lc);
                clear(x->rc);
                delete x;}}
        inline void Insert(const val_t&val){
            insert(root,val);}
        inline bool Exit(const val_t&val){
            return exist(root,val);}
        inline val_t Select(const int&k){
            return select(root,k);}
        inline void Erase(const val_t&val){
            erase(root,val);}
        inline val_t Front(){
            return select(0);}
        inline val_t Back(){
            return select(Size()-1);}
        inline int Size(){
            return root?root->siz:0;}
        inline bool Empty(){
            return !root;}};
    struct UnionFindSet{
        inline UnionFindSet(const int&_vcnt):
        vcnt(_vcnt),prt(_vcnt),rnk(_vcnt){
            for(int i=0;i<vcnt;++i)
                prt[i]=i;}
        inline int Find(const int&x){
            return x==prt[x]?x:prt[x]=Find(prt[x]);}
        inline void Merge(int x,int y){
            x=Find(x);
            y=Find(y);
            if(rnk[x]>rnk[y])
                prt[y]=x;
            else if(rnk[x]<rnk[y])
                prt[x]=y;
            else{
                prt[x]=y;
                ++rnk[y];}}
        inline int Size(){
            return vcnt;}
        int vcnt;
        std::vector<int>prt,rnk;};
    template<typename dat_t>struct Sequence{
        inline Sequence(const std::vector<dat_t>&a):
        root(build(a.begin(),a.end(),a.begin())){}
        inline~Sequence(){
            clear(root);}
        struct node{
            inline node(const int&_l,const int&_r,node*_lc,node*_rc,const dat_t&_dat):
            l(_l),r(_r),lc(_lc),rc(_rc),dat(_dat){}
            int l,r;
            dat_t dat;
            node*lc,*rc;}*root;
        inline void clear(node*x){
            if(x){
                clear(x->lc);
                clear(x->rc);
                delete x;}}
        inline void push_down(node*x){
            x->dat.push_down(x->lc?&x->lc->dat:0,x->rc?&x->rc->dat:0);}
        inline void push_up(node*x){
            push_down(x->lc);
            push_down(x->rc);
            x->dat.push_up(&x->lc->dat,&x->rc->dat);}
        template<typename iter_t>inline node*build(const iter_t&a,const iter_t&b,const iter_t&c){
            if(a+1==b)return new node(a-c,a-c,0,0,*a);
            else{
                iter_t m=a+(b-a-1)/2;
                node*ret=new node(a-c,b-c-1,build(a,m+1,c),build(m+1,b,c),dat_t());
                push_up(ret);
                return ret;}}
        inline dat_t query(node*x,const int&l,const int&r){
            push_down(x);
            if(x->l==l&&x->r==r)
                return x->dat;
            int m=(x->l+x->r)>>1;
            if(r<=m)
                return query(x->lc,l,r);
            if(l>m)
                return query(x->rc,l,r);
            dat_t t1=query(x->lc,l,m),t2=query(x->rc,m+1,r),ret=t1;
            ret.push_up(&t1,&t2);
            return ret;}
        inline dat_t Query(const int&l,const int&r){
            return query(root,l,r);}
        inline dat_t Query(const int&l){
            return query(root,l,l);}
        inline void split(node*x,const int&l,const int&r,std::vector<dat_t*>&a){
            push_down(x);
            if(x->l==l&&x->r==r){
                a.push_back(&x->dat);
                return;}
            int m=(x->l+x->r)>>1;
            if(r<=m){
                split(x->lc,l,r,a);
                return;}
            if(l>m){
                split(x->rc,l,r,a);
                return;}
            split(x->lc,l,m,a);
            split(x->rc,m+1,r,a);}
        inline void refresh(node*x,const int&l,const int&r){
            if(x->l==l&&x->r==r)
                return;
            int m=(x->l+x->r)>>1;
            if(r<=m)
                refresh(x->lc,l,r);
            else if(l>m)
                refresh(x->rc,l,r);
            else{
                refresh(x->lc,l,m);
                refresh(x->rc,m+1,r);}
            push_up(x);}
        template<typename op_t>inline void Modify(const op_t&op,const int&l,const int&r){
            std::vector<dat_t*>a;
            split(root,l,r,a);
            op.modify(a);
            refresh(root,l,r);
        }
        template<typename op_t>inline void Modify(const op_t&op,const int&l){
            std::vector<dat_t*>a;
            split(root,l,l,a);
            op.modify(a[0]);
            refresh(root,l,l);}};
    template<typename dat_t>struct DynamicSequence{
        inline DynamicSequence():
        root(0){}
        inline~DynamicSequence(){
            clear(root);}
        struct node{
            node(const dat_t&_dat):
                dat(_dat),siz(1),rev(false),fix(std::rand()){}
            node*lc,*rc;
            int siz,fix;
            bool rev;
            dat_t dat;}*root;
        inline void clear(node*x){
            if(x){
                clear(x->lc);
                clear(x->rc);
                delete x;}}
        inline void push_down(node*x){
            x->dat.push_down(x->lc?&x->lc->dat:0,x->rc?&x->rc->dat:0);
            if(x->rev){
                x->dat.reverse();
                if(x->lc)
                    x->lc->rev=!x->lc->rev;
                if(x->rc)
                    x->rc->rev=!x->rc->rev;
                swap(x->lc,x->rc);
                x->rev=false;}}
        inline void push_up(node*x){
            if(x->lc)
                push_down(x->lc);
            if(x->rc)
                push_down(x->rc);
            x->dat.push_up(x->lc?&x->lc->dat:0,x->rc?&x->rc->dat:0);
            x->siz=1;
            if(x->lc)
                x->siz+=x->lc->siz;
            if(x->rc)
                x->siz+=x->rc->siz;}
        inline node*merge(node*x,node*y){
            if(!x)
                return y;
            if(!y)
                return x;
            push_down(x);
            push_down(y);
            if(x->fix<y->fix){
                x->rc=merge(x->rc,y);
                push_up(x);
                return x;
            }else{
                y->lc=merge(x,y->lc);
                push_up(y);
                return y;}}
        inline std::pair<node*,node*>split(node*x,const int&y){
            push_down(x);
            if(!x)
                return std::make_pair((node*)0,(node*)0);
            int t=x->lc?x->lc->siz:0;
            std::pair<node*,node*>r;
            if(t<y){
                r=split(x->rc,y-(t+1));
                x->rc=r.first;
                push_up(x);
                return std::make_pair(x,r.second);
            }else{
                r=split(x->lc,t);
                x->lc=r.second;
                push_up(x);
                return std::make_pair(r.first,x);}}
        inline void Clear(){
            clear(root);
            root=0;}
        inline int Size(){
            return root?root->siz:0;}
        inline void Insert(const dat_t&a,const int&b){
            std::pair<node*,node*>t=split(root,b);
            root=merge(merge(t.first,new node(a)),t.second);}
        inline void Remove(const int&a,const int&b){
            std::pair<node*,node*>t1=split(root,a),t2=split(t1.second,b-a+1);
            clear(t2.first);
            root=merge(t1.first,t2.second);}
        inline void Remove(const int&a){
            Remove(a,a);}
        inline dat_t Query(const int&a,const int&b){
            std::pair<node*,node*>t1=split(root,a),t2=split(t1.second,b-a+1);
            dat_t r=t2.first.dat;
            root=merge(merge(t1.first,t2.first),t2.second);
            return r;}
        inline dat_t Query(const int&a){
            return Query(a,a);}
        template<typename op_t>inline void Modify(const op_t&op,const int&a,const int&b){
            std::pair<node*,node*>t1=split(root,a),t2=split(t1.second,b-a+1);
            op.modify(t2.first.dat);
            root=merge(merge(t1.first,t2.first),t2.second);}
        template<typename op_t>inline void Modify(const op_t&op,const int&a){
            Modify(op,a,a);}};
    template<typename dat_t>struct DynamicTree{
        inline DynamicTree(const std::vector<dat_t>&a):
        ns(a.begin(),a.end()){}
        struct node{
            inline node(const dat_t&_dat):
            pr(0),rev(false),dat(_dat){
                ch[0]=ch[1]=0;}
            node*ch[2],*pr;
            bool rev;
            dat_t dat;};
        std::vector<node>ns;
        inline int direct(node*x){
            if(!x->pr)return 2;
            else if(x==x->pr->ch[0])return 0;
            else if(x==x->pr->ch[1])return 1;
            else return 2;}
        inline void push_down(node*x){
            x->dat.push_down(x->ch[0]?&x->ch[0]->dat:0,x->ch[1]?&x->ch[1]->dat:0);
            if(x->rev){
                x->dat.reverse();
                for(int i=0;i<2;++i)
                    if(x->ch[i])
                        x->ch[i]->rev=!x->ch[i]->rev;
                swap(x->ch[0],x->ch[1]);
                x->rev=false;}}
        inline void push_up(node*x){
            for(int i=0;i<2;++i)
                if(x->ch[i])
                    push_down(x->ch[i]);
            x->dat.push_up(x->ch[0]?&x->ch[0]->dat:0,x->ch[1]?&x->ch[1]->dat:0);}
        inline void setchd(node*x,node*y,int d){
            x->ch[d]=y;
            if(y)
                y->pr=x;
            push_up(x);}
        inline void rotate(node*x){
            node*y=x->pr,*z=y->pr;
            int d1=direct(x),d2=direct(y);
            setchd(y,x->ch[!d1],d1);
            setchd(x,y,!d1);
            if(d2<2)
                setchd(z,x,d2);
            else
                x->pr=z;}
        inline void release(node*x){
            if(direct(x)<2)
                release(x->pr);
            push_down(x);}
        inline void splay(node*x){
            release(x);
            while(direct(x)<2){
                node*y=x->pr;
                if(direct(y)==2)
                    rotate(x);
                else if(direct(x)==direct(y)){
                    rotate(y);
                    rotate(x);
                }else{
                    rotate(x);
                    rotate(x);}}}
        inline node*access(node*x){
            node*y=0;
            while(x){
                splay(x);
                setchd(x,y,1);
                y=x;
                x=x->pr;}
            return y;}
        inline void evert(node*x){
            access(x);
            splay(x);
            x->rev=1;}
        inline bool check(node*x,node*y){
            access(x);
            node*z=access(y);
            return z==access(x);}
        inline void link(node*x,node*y){
            evert(y);
            y->pr=x;}
        inline void cut(node*x,node*y){
            evert(x);
            access(y);
            splay(y);
            y->lc=0;
            x->pr=0;}
        inline bool Check(const int&x,const int&y){
            return check(&ns[x],&ns[y]);}
        inline void Link(const int&x,const int&y){
            link(&ns[x],&ns[y]);}
        inline void Cut(const int&x,const int&y){
            Cut(&ns[x],&ns[y]);}
        inline dat_t Query(const int&x,const int&y){
            evert(&ns[x]);
            access(&ns[y]);
            splay(&ns[y]);
            return ns[y].dat;}
        inline dat_t Query(const int&x){
            splay(&ns[x]);
            return ns[x].dat;}
        template<typename op_t>inline void Modify(const op_t&op,const int&x,const int&y){
            evert(&ns[x]);
            access(&ns[y]);
            splay(&ns[y]);
            op.modify(&ns[y].dat);}
        template<typename op_t>inline void Modify(const op_t&op,const int&x){
            splay(&ns[x]);
            op.modify(&ns[x].dat);
            push_up(&ns[x]);}
        inline int LCA(const int&x,const int&y,const int&z){
            evert(&ns[z]);
            access(&ns[x]);
            return access(&ns[y])-&ns[0];}};
    template<typename val_t>struct Discretization{
        void add(const val_t&v){
            a.push_back(v);}
        void build(){
            std::sort(a.begin(),a.end());
            a.erase(std::unique(a.begin(),a.end()),a.end());}
        int ask(const val_t&v){
            return std::lower_bound(a.begin(),a.end(),v)-a.begin();}
        std::vector<val_t>a;};}
namespace GraphTheory{
    template<typename cst_t=int,typename cmp_t=std::less<cst_t> >struct ShortestPath{
        inline ShortestPath(const int&_vcnt,const int&_src):
        vcnt(_vcnt),src(_src),start(_vcnt),dist(_vcnt),can(_vcnt){}
        inline void AddEdge(const int&u,const int&v,const cst_t&w){
            start[u].push_back(std::make_pair(v,w));}
        struct cmp{
            inline bool operator()(const std::pair<cst_t,int>&a,const std::pair<cst_t,int>&b){
                return cmp_t()(b.first,a.first);}};
        inline void Run(){
            dist[src]=cst_t(0);
            can[src]=1;
            std::priority_queue<std::pair<cst_t,int>,std::vector<std::pair<cst_t,int> >,cmp>qu;
            qu.push(std::make_pair(cst_t(0),src));
            while(!qu.empty()){
                int u=qu.top().second;
                cst_t d=qu.top().first;
                qu.pop();
                if(d!=dist[u])continue;
                for(typename std::vector<std::pair<int,cst_t> >::const_iterator i=start[u].begin();i!=start[u].end();++i){
                    int v=i->first;
                    cst_t w=i->second;
                    if(!can[v]||cmp_t()(dist[u]+w,dist[v])){
                        can[v]=true,dist[v]=dist[u]+w;
                        qu.push(std::make_pair(dist[v],v));}}}}
        std::vector<std::vector<std::pair<int,cst_t> > >start;
        std::vector<cst_t>dist;
        std::vector<bool>can;
        int vcnt,src;};
    template<typename cst_t=int,typename cmp_t=std::less<cst_t> >struct MinSpanningTree{
        inline MinSpanningTree(const int&_vcnt):
        vcnt(_vcnt){}
        inline void AddEdge(const int&u,const int&v,const cst_t&w){
            edges.push_back(std::make_pair(std::make_pair(u,v),w));}
        inline bool cmp(const std::pair<cst_t,std::pair<int,int> >&a,const std::pair<cst_t,std::pair<int,int> >&b){
            return cmp_t()(a.first,b.first);}
        inline cst_t Run(){
            cst_t r=cst_t(0);
            sort(edges.begin(),edges.end(),cmp);
            DataStructures::UnionFindSet dset(vcnt);
            for(typename std::vector<std::pair<cst_t,std::pair<int,int> > >::const_iterator i=edges.begin();i!=edges.end();++i){
                int u=i->second.first,v=i->second.second;
                cst_t w=i->first;
                if(dset.Find(u)!=dset.Find(v)){
                    r+=w,dset.Merge(u,v);
                    res.push_back(edges[i]);}}
            return r;}
        int vcnt;
        std::vector<std::pair<cst_t,std::pair<int,int> > >edges,res;};}
namespace LinearProgramming{
    template<typename flow_t=int>struct MaxFlow{
        inline MaxFlow(const int&_vcnt,const int&_src,const int&_snk,const flow_t&_all):
        start(_vcnt),dist(_vcnt),gap(_vcnt+1),vcnt(_vcnt),src(_src),snk(_snk),all(_all){
            gap[0]=vcnt;}
        struct edge{
            inline edge(const int&_v,const flow_t&_c):
            v(_v),c(_c){}
            int v;
            flow_t c;};
        inline void AddEdge(const int&u,const int&v,const flow_t&c){
            start[u].push_back(edges.size());
            edges.push_back(edge(v,c));
            start[v].push_back(edges.size());
            edges.push_back(edge(u,flow_t(0)));}
        inline flow_t dfs(const int&u,const flow_t&f){
            if(u==snk)return f;
            flow_t g=f;
            int mh=vcnt;
            for(typename std::vector<int>::const_iterator i=start[u].begin();i!=start[u].end();++i){
                edge&e=edges[*i],&ev=edges[(*i)^1];
                if(e.c!=flow_t(0)&&dist[u]==dist[e.v]+1){
                    flow_t t=dfs(e.v,std::min(g,e.c));
                    g-=t;
                    e.c-=t;
                    ev.c+=t;
                    if(g==flow_t(0)||dist[src]==vcnt)
                        return f-g;}
                if(e.c!=flow_t(0))
                    CoreUtilities::MakeMax(mh,dist[e.v]+1);}
            if(f==g){
                if(!--gap[dist[u]])
                    dist[src]=vcnt;
                ++gap[dist[u]=mh];}
            return f-g;}
        inline flow_t Run(){
            flow_t r=0;
            while(dist[src]!=vcnt&&all!=flow_t(0)){
                flow_t t=dfs(src,all);
                all-=t;
                r+=t;}
            return r;}
        std::vector<edge>edges;
        std::vector<std::vector<int> >start;
        std::vector<int>dist,gap;
        int vcnt,src,snk;
        flow_t all;};
    template<typename flow_t=int,typename cst_t=int,typename cmp_t=std::less<cst_t> >struct MinCostMaxFlow{
        inline MinCostMaxFlow(const int&_vcnt,const int&_src,const int&_snk,const flow_t&_all):
        start(_vcnt),dist(_vcnt),vis(_vcnt),vcnt(_vcnt),src(_src),snk(_snk),flow(flow_t(0)),cst(cst_t(0)),all(_all){}
        struct edge{
            inline edge(const int&_v,const flow_t&_c,const cst_t&_w):
            v(_v),c(_c),w(_w){}int v;
            flow_t c;
            cst_t w;};
        inline void AddEdge(const int&u,const int&v,const flow_t&c,const cst_t&w){
            start[u].push_back(edges.size());
            edges.push_back(edge(v,c,w));
            start[v].push_back(edges.size());
            edges.push_back(edge(u,flow_t(0),-w));}
        struct cmp{
            inline bool operator()(const std::pair<cst_t,int>&a,const std::pair<cst_t,int>&b){
                return cmp_t()(b.first,a.first);}};
        inline bool relabel(){
            GraphTheory::ShortestPath<cst_t,cmp_t>sp(vcnt,src);
            for(int u=0;u<vcnt;++u)
                for(typename std::vector<int>::const_iterator i=start[u].begin();i!=start[u].end();++i){
                    const edge&e=edges[*i];
                    if(e.c!=flow_t(0))
                        sp.AddEdge(u,e.v,e.w);}
            sp.Run();
            dist=sp.dist;
            return sp.can[snk];}
        inline flow_t dfs(const int&u,const flow_t&f){
            if(u==snk)return f;
            flow_t g=f;
            vis[u]=true;
            for(typename std::vector<int>::const_iterator i=start[u].begin();i!=start[u].end();++i){
                edge&e=edges[*i],&ev=edges[(*i)^1];
                if(e.c!=flow_t(0)&&dist[e.v]==dist[u]+e.w&&!vis[e.v]){
                    flow_t t=dfs(e.v,std::min(g,e.c));
                    g-=t;
                    e.c-=t;
                    ev.c+=t;
                    cst+=t*e.w;
                    if(g==flow_t(0))return f;}}
            return f-g;}
        inline std::pair<flow_t,cst_t>Run(){
            while(all!=flow_t(0)&&relabel()){
                flow_t t;
                do{
                    std::fill(vis.begin(),vis.end(),false);
                    flow+=(t=dfs(src,all));
                    all-=t;
                }while(t!=flow_t(0));}
            return std::make_pair(flow,cst);}
        std::vector<edge>edges;
        std::vector<std::vector<int> >start;
        std::vector<cst_t>dist;
        std::vector<bool>vis;
        int vcnt,src,snk;
        flow_t flow,all;
        cst_t cst;};
    struct MaxMatching{
        inline MaxMatching(const int&_xcnt,const int&_ycnt):
        xcnt(_xcnt),ycnt(_ycnt),res(_xcnt,-1),flow(_xcnt+_ycnt+2,_xcnt+_ycnt,_xcnt+_ycnt+1,std::max(_xcnt,_ycnt)){}
        inline void AddEdge(const int&x,const int&y){
            flow.AddEdge(x,y+xcnt,1);}
        inline int Run(){
            for(int i=0;i<xcnt;++i)
                flow.AddEdge(xcnt+ycnt,i,1);
            for(int i=xcnt;i<xcnt+ycnt;++i)
                flow.AddEdge(i,xcnt+ycnt+1,1);
            int r=flow.Run();
            for(int i=0;i<xcnt;++i)
                for(std::vector<int>::const_iterator j=flow.start[i].begin();j!=flow.start[i].end();++j)
                    if(flow.edges[*j].v!=xcnt+ycnt&&!flow.edges[*j].c){
                        res[i]=flow.edges[*j].v-xcnt;
                        break;}
                return r;}
        MaxFlow<>flow;
        int xcnt,ycnt;
        std::vector<int>res;};
    template<typename cst_t=int,typename cmp_t=std::less<cst_t> >struct MinCostMaxMatching{
        inline MinCostMaxMatching(const int&_xcnt,const int&_ycnt):
        xcnt(_xcnt),ycnt(_ycnt),res(_xcnt,-1),flow(_xcnt+_ycnt+2,_xcnt+_ycnt,_xcnt+_ycnt+1,std::max(_xcnt,_ycnt)){}
        inline void AddEdge(const int&x,const int&y,const cst_t&w){
            flow.AddEdge(x,y+xcnt,1,w);}
        inline std::pair<int,cst_t>Run(){
            for(int i=0;i<xcnt;++i)
                flow.AddEdge(xcnt+ycnt,i,1,0);
            for(int i=xcnt;i<xcnt+ycnt;++i)
                flow.AddEdge(i,xcnt+ycnt+1,1,0);
            std::pair<int,cst_t> r=flow.run();
            for(int i=0;i<xcnt;++i)
                for(std::vector<int>::const_iterator j=flow.start[i].begin();j!=flow.start[i].end();++j)
                    if(flow.edges[*j].v!=xcnt+ycnt&&!flow.edges[*j].c){
                        res[i]=flow.edges[*j].v-xcnt;
                        break;}
            return r;}
        MinCostMaxFlow<int,cst_t,cmp_t>flow;
        int xcnt,ycnt;
        std::vector<int>res;};
    template<typename val_t=CoreUtilities::Real<> >struct Simplex{
        inline Simplex(const int&_n,const int&_m):
        n(_n),m(_m),p(0),a(_n+2,std::vector<val_t>(_m+2)){}
        inline void pivot(const int&l,const int&e){
            val_t t(-a[l][e]);
            a[l][e]=val_t(-1);
            std::vector<int>qu;
            for(int i=0;i<=m+1;++i)
                if(CoreUtilities::Abs(a[l][i]/=t)>val_t(0))
                    qu.push_back(i);
            for(int i=0;i<=n+1;++i)
                if(i!=l&&CoreUtilities::Abs(a[i][e])>val_t(0)){
                    t=a[i][e];
                    a[i][e]=val_t(0);
                    for(std::vector<int>::const_iterator j=qu.begin();j!=qu.end();++j)
                        a[i][*j]+=a[l][*j]*t;}
                if(-p==l)
                    p=e;
                else if(p==e)
                    p=-l;}
        inline bool opt(const int&d){
            while(true){
                int l=-1,e=-1;
                for(int i=1;i<=m+1;++i)
                    if(a[d][i]>val_t(0)){
                        e=i;
                        break;}
                    if(e==-1)return true;
                    val_t t;
                    for(int i=1;i<=n;++i)
                        if(a[i][e]<val_t(0)&&(l==-1||a[i][0]/-a[i][e]<t))
                            t=a[i][0]/-a[i][e],l=i;
                    if(l==-1)return false;
                    pivot(l,e);}}
        inline val_t&At(const int&x,const int&y){
            return a[x][y];}
        inline bool Run(){
            val_t t;
            int l=-1;
            for(int i=1;i<=n;++i)
                if(l==-1||a[i][0]<t)
                    t=a[i][0],l=i;
            if(t<val_t(0)){
                for(int i=1;i<=n;++i)a[i][m+1]=val_t(1);
                a[n+1][m+1]=val_t(-1);
                p=m+1;
                pivot(l,m+1);
                if(!opt(n+1)||CoreUtilities::Abs(a[n+1][0])>val_t(0))
                    return false;
                if(p<0)
                    for(int i=1;i<=m;++i)
                        if(CoreUtilities::Abs(a[-p][i])>val_t(0)){
                            pivot(-p,i);
                            break;}
                        for(int i=0;i<=n;++i)
                            a[i][p]=val_t(0);}
            return opt(0);}
        int n,m,p;
        std::vector<std::vector<val_t> >a;};}
namespace NumericAlgorithms{
    template<typename val_t>inline void DiscreteFourierTransform(std::vector<std::complex<val_t> >&a,const int&n,const int&s){
        val_t pi=val_t(acos(-1.0));
        std::complex<val_t>im(val_t(0),val_t(1));
        for(int i=0;i<n;++i){
            int j=0;
            for(int k=0;(1<<k)<n;++k)
                j<<=1,j+=((i>>k)&1);
            if(i<j)
                swap(a[i],a[j]);}
        for(int i=1;(1<<i)<=n;++i){
            int m=(1<<i);
            std::complex<val_t> wm=exp(val_t(s)*im*val_t(2)*pi/val_t(m));
            for(int j=0;j<n;j+=m){
                std::complex<val_t> w(val_t(1),val_t(0));
                for(int k=0;k<(m>>1);++k){
                    std::complex<val_t> u=a[j+k],v=w*a[j+k+(m>>1)];
                    a[j+k]=u+v;
                    a[j+k+(m>>1)]=u-v;
                    w*=wm;}}}}}
namespace ComputationalGeometry{
    template<typename val_t=CoreUtilities::Real<> >struct Point2D{
        inline Point2D(const val_t&_x,const val_t&_y):
        x(_x),y(_y){}
        val_t x,y;
        inline Point2D<val_t>&operator+=(const Point2D<val_t>&a){
            x+=a.x;
            y+=a.y;
            return*this;}
        inline Point2D<val_t>&operator-=(const Point2D<val_t>&a){
            x-=a.x;
            y-=a.y;
            return*this;}};
    template<typename val_t>inline Point2D<val_t>operator-(const Point2D<val_t>&a){
        return Point2D<val_t>(-a.x,-a.y);}
    template<typename val_t>inline Point2D<val_t>operator+(const Point2D<val_t>&a,const Point2D<val_t>&b){
        return Point2D<val_t>(a.x+b.x,a.y+b.y);}
    template<typename val_t>inline Point2D<val_t>operator-(const Point2D<val_t>&a,const Point2D<val_t>&b){
        return Point2D<val_t>(a.x-b.x,a.y-b.y);}
    template<typename val_t>inline val_t det(const Point2D<val_t>&a,const Point2D<val_t>&b){
        return a.x*b.y-b.x*a.y;}
    template<typename val_t>inline val_t dot(const Point2D<val_t>&a,const Point2D<val_t>&b){
        return a.x*b.x+a.y*b.y;}}
namespace StringAlgorithms{}
using namespace std;
using namespace CoreUtilities;
using namespace NumberTheory;
using namespace DataStructures;
using namespace LinearProgramming;
using namespace NumericAlgorithms;
using namespace ComputationalGeometry;
using namespace StringAlgorithms;
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,a) for(int i=0;i<int(a.size());++i)
#define wp(i,a) for(int i=int(a.size())-1;i>=0;--i)
typedef long long ll;
int main(){
    ll n,x=1;Read(n);
    while(n%x==0)x*=3;
    Write(n/x+1);Write('\n');
    //ps;
    return 0;
}