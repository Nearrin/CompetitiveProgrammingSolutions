#include<algorithm>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<string>
#include<vector>
namespace OtherUtilities{
    template<typename value_type>
    bool Down(value_type&a,const value_type&b){if(a>b){a=b;return true;}return false;}
    template<typename value_type>
    bool Up(value_type&a,const value_type&b){if(a<b){a=b;return true;}return false;}
    template<typename value_type>
    inline std::string ToStr(const value_type&a){std::stringstream s;s<<a;std::string r;s>>r;return r;}
    template<typename value_type>
    inline value_type FromStr(const std::string&a){std::stringstream s;s<<a;value_type r;s>>r;return r;}
    template<typename value_type>
    inline value_type Abs(const value_type&a){return a<value_type(0)?-a:a;}
    inline void Read(int&a){
        char c;for(c=std::getchar();!std::isdigit(c)&&c!='-';c=std::getchar());bool flag=c=='-';if(flag)a=0;else a=c-'0';
        for(c=std::getchar();std::isdigit(c);c=std::getchar())a=a*10+c-'0';if(flag)a=-a;
    }
    inline void Read(unsigned&a){
        char c;for(c=std::getchar();!std::isdigit(c);c=std::getchar());a=c-'0';for(c=std::getchar();std::isdigit(c);c=std::getchar())a=a*10+c-'0';
    }
    inline void Read(long long&a){
        char c;for(c=std::getchar();!std::isdigit(c)&&c!='-';c=std::getchar());bool flag=c=='-';if(flag)a=0;else a=c-'0';
        for(c=std::getchar();std::isdigit(c);c=std::getchar())a=a*10+c-'0';if(flag)a=-a;
    }
    inline void Read(unsigned long long&a){
        char c;for(c=std::getchar();!std::isdigit(c);c=std::getchar());a=c-'0';for(c=std::getchar();std::isdigit(c);c=std::getchar())a=a*10+c-'0';
    }
    inline void Read(double&a){std::scanf("%lf",&a);}
    inline void Read(char*a){std::scanf("%s",a);}
    inline void Write(int a){
        if(a<0)a=-a,std::putchar('-');std::vector<char>t;do{t.push_back(a%10+'0');a/=10;}while(a!=0);
        for(std::vector<char>::const_reverse_iterator i=t.rbegin();i!=t.rend();++i)std::putchar(*i);
    }
    inline void Write(unsigned a){
        std::vector<char>t;do{t.push_back(a%10+'0');a/=10;}while(a!=0);for(std::vector<char>::const_reverse_iterator i=t.rbegin();i!=t.rend();++i)std::putchar(*i);
    }
    inline void Write(long long a){
        if(a<0)a=-a,std::putchar('-');std::vector<char>t;do{t.push_back(a%10+'0');a/=10;}while(a!=0);
        for(std::vector<char>::const_reverse_iterator i=t.rbegin();i!=t.rend();++i)std::putchar(*i);
    }
    inline void Write(unsigned long long a){
        std::vector<char>t;do{t.push_back(a%10+'0');a/=10;}while(a!=0);for(std::vector<char>::const_reverse_iterator i=t.rbegin();i!=t.rend();++i)std::putchar(*i);
    }
    inline void Write(const double&a,const int&b){std::printf(("%."+ToStr(b)+"lf").c_str(),a);}
    inline void Write(char*a){std::printf("%s",a);}
    inline void Input(const std::string&a){std::freopen(a.c_str(),"r",stdin);}
    inline void Output(const std::string&a){std::freopen(a.c_str(),"w",stdout);}
    template<typename value_type=double>
    struct Real{
        inline Real(const value_type&_value=0,const value_type&_precision=1e-8):value(_value),precision(_precision){}
        inline Real<value_type>&operator+=(const Real<value_type>&a){value+=a.value;return*this;}
        inline Real<value_type>&operator-=(const Real<value_type>&a){value-=a.value;return*this;}
        inline Real<value_type>&operator*=(const Real<value_type>&a){value*=a.value;return*this;}
        inline Real<value_type>&operator/=(const Real<value_type>&a){value/=a.value;return*this;}
        value_type value,precision;
    };
    template<typename value_type>
    inline Real<value_type>operator-(const Real<value_type>&a){return Real<value_type>(-a.value,a.precision);}
    template<typename value_type>
    inline Real<value_type>operator+(const Real<value_type>&a,const Real<value_type>&b){return Real<value_type>(a.value+b.value,a.precision);}
    template<typename value_type>
    inline Real<value_type>operator-(const Real<value_type>&a,const Real<value_type>&b){return Real<value_type>(a.value-b.value,a.precision);}
    template<typename value_type>
    inline Real<value_type>operator*(const Real<value_type>&a,const Real<value_type>&b){return Real<value_type>(a.value*b.value,a.precision);}
    template<typename value_type>
    inline Real<value_type>operator/(const Real<value_type>&a,const Real<value_type>&b){return Real<value_type>(a.value/b.value,a.precision);}
    template<typename value_type>
    inline bool operator<(const Real<value_type>&a,const Real<value_type>&b){return a.value<b.value-a.precision;}
    template<typename value_type>
    inline bool operator>(const Real<value_type>&a,const Real<value_type>&b){return a.value>b.value+a.precision;}
    template<typename value_type>
    inline bool operator!=(const Real<value_type>&a,const Real<value_type>&b){return a<b||a>b;}
    template<typename value_type>
    inline bool operator==(const Real<value_type>&a,const Real<value_type>&b){return !(a!=b);}
    template<typename value_type>
    inline void Read(Real<value_type>&a){Read(a.value);}
    template<typename value_type>
    inline void Write(const Real<value_type>&a,const int&b){Write(a.value,b);}
}
namespace NumberTheory{
    template<typename value_type>
    inline value_type GCD(const value_type&a,const value_type&b){return b==value_type(0)?a:GCD(b,a%b);}
    template<typename value_type>
    inline value_type ExGCD(const value_type&a,const value_type&b,value_type&x,value_type&y){
        if(b==value_type(0)){x=value_type(1);y=value_type(0);return a;}else{value_type t=ExGCD(b,a%b,y,x);y-=a/b*x;return t;}
    }
    template<typename value_type,typename pow_type>
    inline value_type Pow(value_type a,pow_type b){value_type r(1);for(;b!=pow_type(0);a*=a,b/=2)if(b%pow_type(2)==pow_type(1))r=r*a;return r;}
    template<typename value_type=long long>
    struct Integer{
        inline Integer(const value_type&_value=0,const value_type&_modular=1000000007):
        value(_value),modular(_modular){}
        inline Integer<value_type>&operator+=(const Integer<value_type>&a){value+=a.value;if(value>=modular)value-=modular;return*this;}
        inline Integer<value_type>&operator-=(const Integer<value_type>&a){value-=a.value;if(value<value_type(0))value+=modular;return*this;}
        inline Integer<value_type>&operator*=(const Integer<value_type>&a){value=value*a.value%modular;return*this;}
        inline Integer<value_type>&operator/=(const Integer<value_type>&a){
            value_type x,y;ExGCD(a.value,modular,x,y);x=x%a.modular;if(x<value_type(0))x+=a.modular;value=value*x%modular;return*this;
        }
        value_type value,modular;
    };
    template<typename value_type>
    inline Integer<value_type>operator-(const Integer<value_type>&a){
        value_type t=-a.value;if(t<value_type(0))t+=a.modular;return Integer<value_type>(t,a.modular);
    }
    template<typename value_type>
    inline Integer<value_type>operator+(const Integer<value_type>&a,const Integer<value_type>&b){
        value_type t=a.value+b.value;if(t>=a.modular)t-=a.modular;return Integer<value_type>(t,a.modular);
    }
    template<typename value_type>
    inline Integer<value_type>operator-(const Integer<value_type>&a,const Integer<value_type>&b){
        value_type t=a.value+b.value;if(t<value_type(0))t+=a.modular;return Integer<value_type>(t,a.modular);
    }
    template<typename value_type>
    inline Integer<value_type>operator*(const Integer<value_type>&a,const Integer<value_type>&b){
        return Integer<value_type>(a.value*b.value%a.modular,a.modular);
    }
    template<typename value_type>
    inline Integer<value_type>operator/(const Integer<value_type>&a,const Integer<value_type>&b){
        value_type x,y;ExGCD(b.value,a.modular,x,y);x=x%a.modular;if(x<value_type(0))x+=a.modular;return Integer<value_type>(a.value*x%a.modular,a.modular);
    }
    template<typename value_type>
    inline bool operator==(const Integer<value_type>&a,const Integer<value_type>&b){return a.value==b.value;}
    template<typename value_type>
    inline bool operator!=(const Integer<value_type>&a,const Integer<value_type>&b){return a.value!=b.value;}
    template<typename value_type>
    inline void Read(Integer<value_type>&a){Read(a.value);}
    template<typename value_type>
    inline void Write(const Integer<value_type>&a){Write(a.value);}
}
namespace DataStructures{
    template<typename value_type=int,typename cmp_type=std::less<value_type> >
    struct Heap{
        inline Heap():root(0),siz(0){}
        inline ~Heap(){clear(root);}
        struct node{inline node(const value_type&_value):value(_value),ch(0),br(0),pr(0){}value_type value;node*ch,*br,*pr;}*root;
        inline void merge(node*&x,node*y){if(!x)x=y;else if(y){if(cmp_type()(y->value,x->value))std::swap(x,y);y->br=x->ch;if(x->ch)x->ch->pr=y;y->pr=x;x->ch=y;}}
        inline void cut(node*&x,node*y){if(x==y)x=0;else{if(y==y->pr->ch)y->pr->ch=y->br;else y->pr->br=y->br;if(y->br)y->br->pr=y->pr;y->pr=y->br=0;}}
        inline node*split(node*x){
            std::vector<node*>t;for(node*i=x->ch;i;i=i->br)t.push_back(i);x->ch=0;node*r=0;
            for(typename std::vector<node*>::const_iterator i=t.begin();i!=t.end();++i)(*i)->pr=(*i)->br=0;
            for(typename std::vector<node*>::const_iterator i=t.begin();i+1<t.end();i+=2)merge(*i,*(i+1));
            for(typename std::vector<node*>::const_iterator i=t.begin();i<t.end();i+=2)merge(r,*i);return r;
        }
        inline void clear(node*x){if(x){clear(x->ch);clear(x->br);delete x;}}
        inline void Clear(){clear(root);root=0;siz=0;}
        inline node*Push(const value_type&a){node*r=new node(a);merge(root,r);++siz;return r;}
        inline void Erase(node*x){cut(root,x);merge(root,split(x));--siz;}
        inline const value_type&Top(){return root->value;}
        inline void Pop(){Erase(root);}
        inline void Merge(Heap<value_type,cmp_type>&a){merge(root,a.root);a.root=0;siz+=a.siz;a.siz=0;}
        inline void Modify(node*x,const value_type&v){if(cmp_type()(x->value,v))x->value=v,merge(root,split(x));else x->value=v,cut(root,x),merge(root,x);}
        inline int Size(){return siz;}
        inline bool Empty(){return !siz;}
        int siz;
    };
    template<typename key_type=int,typename value_type=int,typename cmp_type=std::less<key_type> >
    struct Map{
        inline Map():root(0){}
        inline~Map(){clear(root);}
        struct node{
            inline node(const key_type&_key,const value_type&_value):fix(std::rand()),siz(1),key(_key),value(_value),lc(0),rc(0){}
            node*lc,*rc;int fix,siz;key_type key;value_type value;
        }*root;
        inline void update(node*x){x->siz=1;if(x->lc)x->siz+=x->lc->siz;if(x->rc)x->siz+=x->rc->siz;}
        inline void rotate_l(node*&x){node*y=x->lc;x->lc=y->rc;y->rc=x;y->siz=x->siz;x->siz-=1+(y->lc?y->lc->siz:0);x=y;}
        inline void rotate_r(node*&x){node*y=x->rc;x->rc=y->lc;y->lc=x;y->siz=x->siz;x->siz-=1+(y->rc?y->rc->siz:0);x=y;}
        inline node*access(node*&x,const key_type&key){
            if(!x)return x=new node(key,value_type());
            if(cmp_type()(key,x->key)){node*r=access(x->lc,key);update(x);if(x->lc->fix<x->fix)rotate_l(x);return r;}
            if(cmp_type()(x->key,key)){node*r=access(x->rc,key);update(x);if(x->rc->fix<x->fix)rotate_r(x);return r;}
            return x;
        }
        inline int count(node*x,const key_type&key){
            if(!x)return 0;if(cmp_type()(key,x->key))return count(x->lc,key);if(cmp_type()(x->key,key))return count(x->rc,key);return 1;
        }
        inline void erase(node*&x,const key_type&key){
            if(cmp_type()(key,x->key))erase(x->lc,key),--x->siz;else if(cmp_type()(x->key,key))erase(x->rc,key),--x->siz;
            else if(!x->lc){node*t=x->rc;delete x;x=t;}else if(!x->rc){node*t=x->lc;delete x;x=t;
            }else if(x->lc->fix<x->rc->fix)rotate_l(x),erase(x->rc,key),--x->siz;else rotate_r(x),erase(x->lc,key),--x->siz;
        }
        inline node*select(node*x,const int&k){int t=x->lc?x->lc->siz:0;if(k<t)return select(x->lc,k);if(k==t)return x;return select(x->rc,k-(t+1));}
        inline int rank(node*x,const key_type&key){
            if(!x)return 0;if(cmp_type()(key,x->key))return rank(x->lc,key);if(cmp_type()(x->key,key))return(x->lc?x->lc->siz:0)+1+rank(x->rc,key);return (x->lc?x->lc->siz:0);
        }
        inline void clear(node*x){if(x){clear(x->lc);clear(x->rc);delete x;}}
        inline void Insert(const key_type&key,const value_type&value){access(root,key)->value=value;}
        inline void Erase(const key_type&key){erase(root,key);}
        inline value_type&operator[](const key_type&key){return access(root,key)->value;}
        inline node*Select(int k){return select(root,k);}
        inline int Count(const key_type&key){return count(root,key);}
        inline int Rank(const key_type&key){return rank(root,key);}
        inline void Clear(){clear(root);root=0;}
        inline node*Front(){return select(0);}
        inline node*Back(){return select(Size()-1);}
        inline int Size(){return root?root->siz:0;}
        inline bool Empty(){return !root;}
        inline node*LowerBound(const key_type&key){if(!root)return 0;int t=rank(key);if(t==root->size)return 0;return select(t);}
        inline node*UpperBound(const key_type&key){if(!root)return 0;int t=rank(key)+count(key);if(t==root->size)return 0;return select(t);}
        inline node*Next(node*x){int t=rank(x->key)+1;if(t==root->siz)return 0;return select(t);}
        inline node*Prec(node*x){int t=rank(x->key)-1;if(t<0)return 0;return select(t);}
    };
    struct UnionFindSet{
        inline UnionFindSet(const int&_vcnt):vcnt(_vcnt),parent(_vcnt),rank(_vcnt){for(int i=0;i<vcnt;++i)parent[i]=i;}
        inline int Find(const int&x){return x==parent[x]?x:parent[x]=Find(parent[x]);}
        inline void Merge(int x,int y){x=Find(x);y=Find(y);if(rank[x]>rank[y])parent[y]=x;else if(rank[x]<rank[y])parent[x]=y;else parent[x]=y,++rank[y];}
        inline int Size(){return vcnt;}
        int vcnt;std::vector<int>parent,rank;
    };
    template<typename data_type>
    struct Sequence{
        inline Sequence(const std::vector<data_type>&a):root(build(a,0,a.size()-1)){}
        inline~Sequence(){clear(root);}
        struct node{
            inline node(const int&_l,const int&_r,node*_lc,node*_rc,const data_type&_data):l(_l),r(_r),lc(_lc),rc(_rc),data(_data){}int l,r;data_type data;node*lc,*rc;
        }*root;
        inline void clear(node*x){if(x){clear(x->lc);clear(x->rc);delete x;}}
        inline void push_down(node*x){x->data.push_down(x->lc?&x->lc->data:0,x->rc?&x->rc->data:0);}
        inline void push_up(node*x){push_down(x->lc);push_down(x->rc);x->data.push_up(&x->lc->data,&x->rc->data);}
        inline node*build(const std::vector<data_type>&a,const int&l,const int&r){
            if(l==r)return new node(l,r,0,0,a[l]);else{int m=(l+r)>>1;node*ret=new node(l,r,build(a,l,m),build(a,m+1,r),data_type());push_up(ret);return ret;}
        }
        inline data_type query(node*x,const int&l,const int&r){
            push_down(x);if(x->l==l&&x->r==r)return x->data;int m=(x->l+x->r)>>1;if(r<=m)return query(x->lc,l,r);if(l>m)return query(x->rc,l,r);
            data_type ret,t1=query(x->lc,l,m),t2=query(x->rc,m+1,r);ret.push_up(&t1,&t2);return ret;
        }
        inline data_type Query(const int&l,const int&r){return query(root,l,r);}
        inline data_type Query(const int&l){return query(root,l,l);}
        inline void split(node*x,const int&l,const int&r,std::vector<data_type*>&a){
            push_down(x);if(x->l==l&&x->r==r){a.push_back(&x->data);return;}int m=(x->l+x->r)>>1;
            if(r<=m){split(x->lc,l,r,a);return;}if(l>m){split(x->rc,l,r,a);return;}split(x->lc,l,m,a);split(x->rc,m+1,r,a);
        }
        inline void refresh(node*x,const int&l,const int&r){
            if(x->l==l&&x->r==r)return;int m=(x->l+x->r)>>1;if(r<=m)refresh(x->lc,l,r);else if(l>m)refresh(x->rc,l,r);else refresh(x->lc,l,m),refresh(x->rc,m+1,r);push_up(x);
        }
        template<typename op_type>
        inline void Modify(const op_type&op,const int&l,const int&r){std::vector<data_type*>a;split(root,l,r,a);op.modify(a);refresh(root,l,r);}
        template<typename op_type>
        inline void Modify(const op_type&op,const int&l){std::vector<data_type*>a;split(root,l,l,a);op.modify(a[0]);refresh(root,l,l);}
    };
    template<typename data_type>
    struct DynamicSequence{
        inline DynamicSequence():root(0){}
        inline~DynamicSequence(){clear(root);}
        struct node{node(const data_type&_data):data(_data),siz(1),rev(false),fix(std::rand()){}node*lc,*rc;int siz,fix;bool rev;data_type data;}*root;
        inline void clear(node*x){if(x){clear(x->lc);clear(x->rc);delete x;}}
        inline void push_down(node*x){
            x->data.push_down(x->lc?&x->lc->data:0,x->rc?&x->rc->data:0);
            if(x->rev){x->data.reverse();if(x->lc)x->lc->rev=!x->lc->rev;if(x->rc)x->rc->rev=!x->rc->rev;swap(x->lc,x->rc);x->rev=false;}
        }
        inline void push_up(node*x){
            if(x->lc)push_down(x->lc);if(x->rc)push_down(x->rc);x->data.push_up(x->lc?&x->lc->data:0,x->rc?&x->rc->data:0);
            x->siz=1;if(x->lc)x->siz+=x->lc->siz;if(x->rc)x->siz+=x->rc->siz;
        }
        inline node*merge(node*x,node*y){
            if(!x)return y;if(!y)return x;push_down(x);push_down(y);if(x->fix<y->fix){x->rc=merge(x->rc,y);push_up(x);return x;}else{y->lc=merge(x,y->lc);push_up(y);return y;}
        }
        inline std::pair<node*,node*>split(node*x,const int&y){
            push_down(x);if(!x)return std::make_pair((node*)0,(node*)0);int t=x->lc?x->lc->siz:0;std::pair<node*,node*>r;
            if(t<y){r=split(x->rc,y-(t+1));x->rc=r.first;push_up(x);return std::make_pair(x,r.second);
            }else{r=split(x->lc,t);x->lc=r.second;push_up(x);return std::make_pair(r.first,x);}
        }
        inline void Clear(){clear(root);root=0;}
        inline int Size(){return root?root->siz:0;}
        inline void Insert(const data_type&a,const int&b){std::pair<node*,node*>t=split(root,b);root=merge(merge(t.first,new node(a)),t.second);}
        inline void Remove(const int&a,const int&b){std::pair<node*,node*>t1=split(root,a),t2=split(t1.second,b-a+1);clear(t2.first);root=merge(t1.first,t2.second);}
        inline void Remove(const int&a){Remove(a,a);}
        inline data_type Query(const int&a,const int&b){
            std::pair<node*,node*>t1=split(root,a),t2=split(t1.second,b-a+1);data_type r=t2.first.data;root=merge(merge(t1.first,t2.first),t2.second);return r;
        }
        inline data_type Query(const int&a){return Query(a,a);}
        template<typename op_type>
        inline void Modify(const op_type&op,const int&a,const int&b){
            std::pair<node*,node*>t1=split(root,a),t2=split(t1.second,b-a+1);op.modify(t2.first.data);root=merge(merge(t1.first,t2.first),t2.second);
        }
        template<typename op_type>
        inline void Modify(const op_type&op,const int&a){Modify(op,a,a);}
    };
    template<typename data_type>
    struct DynamicTree{
        DynamicTree(const std::vector<data_type>&a){for(typename std::vector<data_type>::const_iterator i=a.begin();i!=a.end();++i)ns.push_back(new node(*i));}
        struct node{inline node(const data_type&_data):lc(0),rc(0),pr(0),rev(false),data(_data){}node*lc,*rc,*pr;bool rev;data_type data;};
        std::vector<node*>ns;
        inline int direct(node*x){if(!x->pr)return 2;else if(x==x->pr->lc)return 0;else if(x==x->pr->rc)return 1;else return 2;}
        inline void push_down(node*x){
            x->data.push_down(x->lc?&x->lc->data:0,x->rc?&x->rc->data:0);
            if(x->rev){x->data.reverse();if(x->lc)x->lc->rev=!x->lc->rev;if(x->rc)x->rc->rev=!x->rc->rev;swap(x->lc,x->rc);x->rev=false;}
        }
        inline void push_up(node*x){if(x->lc)push_down(x->lc);if(x->rc)push_down(x->rc);x->data.push_up(x->lc?&x->lc->data:0,x->rc?&x->rc->data:0);}
        inline void setchd(node*x,node*y,int d){if(d==0)x->lc=y;else x->rc=y;if(y)y->pr=x;push_up(x);}
        inline void rotate(node*x){node*y=x->pr,*z=y->pr;int d1=direct(x),d2=direct(y);setchd(y,x->ch[!d1],d1);setchd(x,y,!d1);if(d2<2)setchd(z,x,d2);else x->pr=z;}
        inline void release(node*x){if(direct(x)<2)release(x->pr);push_down(x);}
        inline void splay(node*x){release(x);while(direct(x)<2){node*y=x->pr;if(direct(y)==2)rotate(x);else if(direct(x)==direct(y))rotate(y),rotate(x);else rotate(x),rotate(x);}}
        inline node*access(node*x){node*y=0;while(x){splay(x);setchd(x,y,1);y=x;x=x->pr;}return y;}
        inline void evert(node*x){access(x);splay(x);x->rev=1;}
        inline bool check(node*x,node*y){access(x);node*z=access(y);return z==access(x);}
        inline void link(node*x,node*y){evert(y);y->pr=x;}
        inline void cut(node*x,node*y){evert(x);access(y);splay(y);y->ch[0]=0;x->pr=0;}
        inline bool Check(const int&x,const int&y){return check(ns[x],ns[y]);}
        inline void Link(const int&x,const int&y){link(ns[x],ns[y]);}
        inline void Cut(const int&x,const int&y){Cut(ns[x],ns[y]);}
        inline data_type Query(const int&x,const int&y){evert(ns[x]);access(ns[y]);splay(ns[y]);return ns[y]->data;}
        inline data_type Query(const int&x){return Query(x,x);}
        template<typename op_type>
        inline void Modify(const op_type&op,const int&x,const int&y){evert(ns[x]);access(ns[y]);splay(ns[y]);op.modify(ns[y].data);}
        template<typename op_type>
        inline void Modify(const op_type&op,const int&x){Modify(op,x,x);}
    };
}
namespace GraphTheory{
    template<typename cost_type=int,typename cmp_type=std::less<cost_type> >
    struct ShortestPath{
        inline ShortestPath(const int&_vcnt,const int&_source):vcnt(_vcnt),source(_source),start(_vcnt),dist(_vcnt),can(_vcnt){}
        inline void AddEdge(const int&u,const int&v,const cost_type&w){start[u].push_back(std::make_pair(v,w));}
        struct cmp{inline bool operator()(const std::pair<cost_type,int>&a,const std::pair<cost_type,int>&b){return cmp_type()(b.first,a.first);}};
        inline std::pair<std::vector<cost_type>&,std::vector<bool>&>Run(){
            dist[source]=cost_type(0);can[source]=1;std::priority_queue<std::pair<cost_type,int>,std::vector<std::pair<cost_type,int> >,cmp>qu;
            qu.push(std::make_pair(cost_type(0),source));
            while(!qu.empty()){
                int u=qu.top().second;cost_type d=qu.top().first;qu.pop();if(d!=dist[u])continue;
                for(typename std::vector<std::pair<int,cost_type> >::const_iterator i=start[u].begin();i!=start[u].end();++i){
                    int v=i->first;cost_type w=i->second;if(!can[v]||cmp_type()(dist[u]+w,dist[v]))can[v]=true,dist[v]=dist[u]+w,qu.push(std::make_pair(dist[v],v));
                }
            }
            return std::pair<std::vector<cost_type>&,std::vector<bool>&>(dist,can);
        }
        std::vector<std::vector<std::pair<int,cost_type> > >start;std::vector<cost_type>dist;std::vector<bool>can;int vcnt,source;
    };
    template<typename cost_type=int,typename cmp_type=std::less<cost_type> >
    struct MinSpanningTree{
        inline MinSpanningTree(const int&_vcnt):vcnt(_vcnt){}
        inline void AddEdge(const int&u,const int&v,const cost_type&w){edges.push_back(std::make_pair(std::make_pair(u,v),w));}
        inline bool cmp(const std::pair<cost_type,std::pair<int,int> >&a,const std::pair<cost_type,std::pair<int,int> >&b){return cmp_type()(a.first,b.first);}
        inline std::pair<cost_type,std::vector<std::pair<cost_type,std::pair<int,int> > >&>Run(){
            cost_type r=cost_type(0);sort(edges.begin(),edges.end(),cmp);DataStructures::UnionFindSet dset(vcnt);
            for(typename std::vector<std::pair<cost_type,std::pair<int,int> > >::const_iterator i=edges.begin();i!=edges.end();++i){
                int u=i->second.first,v=i->second.second;cost_type w=i->first;if(dset.Find(u)!=dset.Find(v))r+=w,dset.Merge(u,v),result.push_back(edges[i]);
            }
            return std::pair<cost_type,std::vector<std::pair<cost_type,std::pair<int,int> > >&>(r,result);
        }
        int vcnt;std::vector<std::pair<cost_type,std::pair<int,int> > >edges,result;
    };
}
namespace LinearProgramming{
    template<typename flow_type=int>
    struct MaxFlow{
        inline MaxFlow(const int&_vcnt,const int&_source,const int&_sink,const flow_type&_all):
        start(_vcnt),dist(_vcnt),gap(_vcnt+1),vcnt(_vcnt),source(_source),sink(_sink),all(_all){gap[0]=vcnt;}
        struct edge{inline edge(const int&_v,const flow_type&_c):v(_v),c(_c){}int v;flow_type c;};
        inline void AddEdge(const int&u,const int&v,const flow_type&c){
            start[u].push_back(edges.size());edges.push_back(edge(v,c));
            start[v].push_back(edges.size());edges.push_back(edge(u,flow_type(0)));
        }
        inline flow_type dfs(const int&u,const flow_type&f){
            if(u==sink)return f;flow_type g=f;int mh=vcnt;
            for(typename std::vector<int>::const_iterator i=start[u].begin();i!=start[u].end();++i){
                edge&e=edges[*i],&ev=edges[(*i)^1];
                if(e.c!=flow_type(0)&&dist[u]==dist[e.v]+1){flow_type t=dfs(e.v,std::min(g,e.c));g-=t;e.c-=t;ev.c+=t;if(g==flow_type(0)||dist[source]==vcnt)return f-g;}
                if(e.c!=flow_type(0))OtherUtilities::Down(mh,dist[e.v]+1);
            }
            if(f==g){if(!--gap[dist[u]])dist[source]=vcnt;++gap[dist[u]=mh];}return f-g;
        }
        inline flow_type Run(){flow_type r=0;while(dist[source]!=vcnt&&all!=flow_type(0)){flow_type t=dfs(source,all);all-=t;r+=t;}return r;}
        std::vector<edge>edges;std::vector<std::vector<int> >start;std::vector<int>dist,gap;int vcnt,source,sink;flow_type all;
    };
    template<typename flow_type=int,typename cost_type=int,typename cmp_type=std::less<cost_type> >
    struct MinCostMaxFlow{
        inline MinCostMaxFlow(const int&_vcnt,const int&_source,const int&_sink,const flow_type&_all):
        start(_vcnt),dist(_vcnt),vis(_vcnt),vcnt(_vcnt),source(_source),sink(_sink),flow(flow_type(0)),cost(cost_type(0)),all(_all){}
        struct edge{inline edge(const int&_v,const flow_type&_c,const cost_type&_w):v(_v),c(_c),w(_w){}int v;flow_type c;cost_type w;};
        inline void AddEdge(const int&u,const int&v,const flow_type&c,const cost_type&w){
            start[u].push_back(edges.size());edges.push_back(edge(v,c,w));start[v].push_back(edges.size());edges.push_back(edge(u,flow_type(0),-w));
        }
        struct cmp{inline bool operator()(const std::pair<cost_type,int>&a, const std::pair<cost_type,int>&b){return cmp_type()(b.first,a.first);}};
        inline bool relabel(){
            GraphTheory::ShortestPath<cost_type,cmp_type>sp(vcnt,source);
            for(int u=0;u<vcnt;++u)
                for(typename std::vector<int>::const_iterator i=start[u].begin();i!=start[u].end();++i){const edge&e=edges[*i];if(e.c!=flow_type(0))sp.AddEdge(u,e.v,e.w);}
            std::pair<std::vector<cost_type>&,std::vector<bool>&>r=sp.Run();dist=r.first;return r.second[sink];
        }
        inline flow_type dfs(const int&u,const flow_type&f){
            if(u==sink)return f;flow_type g=f;vis[u]=true;
            for(typename std::vector<int>::const_iterator i=start[u].begin();i!=start[u].end();++i){
                edge&e=edges[*i],&ev=edges[(*i)^1];
                if(e.c!=flow_type(0)&&dist[e.v]==dist[u]+e.w&&!vis[e.v]){flow_type t=dfs(e.v,std::min(g,e.c));g-=t;e.c-=t;ev.c+=t;cost+=t*e.w;if(g==flow_type(0))return f;}
            }
            return f-g;
        }
        inline std::pair<flow_type,cost_type>Run(){
            while(all!=flow_type(0)&&relabel()){flow_type t;do{std::fill(vis.begin(),vis.end(),false);flow+=(t=dfs(source,all));all-=t;}while(t!=flow_type(0));}
            return std::make_pair(flow,cost);
        }
        std::vector<edge>edges;std::vector<std::vector<int> >start;std::vector<cost_type>dist;std::vector<bool>vis;int vcnt,source,sink;flow_type flow,all;cost_type cost;
    };
    struct MaxMatching{
        inline MaxMatching(const int&_xcnt,const int&_ycnt):
        xcnt(_xcnt),ycnt(_ycnt),result(_xcnt,-1),flow(_xcnt+_ycnt+2,_xcnt+_ycnt,_xcnt+_ycnt+1,std::max(_xcnt,_ycnt)){}
        inline void AddEdge(const int&x,const int&y){flow.AddEdge(x,y+xcnt,1);}
        inline std::pair<int,std::vector<int>&> Run(){
            for(int i=0;i<xcnt;++i)flow.AddEdge(xcnt+ycnt,i,1);for(int i=xcnt;i<xcnt+ycnt;++i)flow.AddEdge(i,xcnt+ycnt+1,1);int r=flow.Run();
            for(int i=0;i<xcnt;++i)
                for(std::vector<int>::const_iterator j=flow.start[i].begin();j!=flow.start[i].end();++j)
                    if(flow.edges[*j].v!=xcnt+ycnt&&!flow.edges[*j].c){result[i]=flow.edges[*j].v-xcnt;break;}
            return std::pair<int,std::vector<int>&>(r,result);
        }
        MaxFlow<>flow;int xcnt,ycnt;std::vector<int>result;
    };
    template<typename cost_type=int,typename cmp_type=std::less<cost_type> >
    struct MinCostMaxMatching{
        inline MinCostMaxMatching(const int&_xcnt,const int&_ycnt):
        xcnt(_xcnt),ycnt(_ycnt),result(_xcnt,-1),flow(_xcnt+_ycnt+2,_xcnt+_ycnt,_xcnt+_ycnt+1,std::max(_xcnt,_ycnt)){}
        inline void AddEdge(const int&x,const int&y,const cost_type&w){flow.AddEdge(x,y+xcnt,1,w);}
        inline std::pair<std::pair<int,cost_type>,std::vector<int>&>Run(){
            for(int i=0;i<xcnt;++i)flow.AddEdge(xcnt+ycnt,i,1,0);for(int i=xcnt;i<xcnt+ycnt;++i)flow.AddEdge(i,xcnt+ycnt+1,1,0);
            std::pair<int,cost_type> r=flow.run();
            for(int i=0;i<xcnt;++i)
                for(std::vector<int>::const_iterator j=flow.start[i].begin();j!=flow.start[i].end();++j)
                    if(flow.edges[*j].v!=xcnt+ycnt&&!flow.edges[*j].c){result[i]=flow.edges[*j].v-xcnt;break;}
            return std::pair<std::pair<int,cost_type>,std::vector<int>&>(r,result);
        }
        MinCostMaxFlow<int,cost_type,cmp_type>flow;int xcnt,ycnt;std::vector<int>result;
    };
    template<typename value_type=OtherUtilities::Real<> >
    struct Simplex{
        inline Simplex(const int&_n,const int&_m):n(_n),m(_m),p(0),a(_n+2,std::vector<value_type>(_m+2)){}
        inline void pivot(const int&l,const int&e){
            value_type t(-a[l][e]);a[l][e]=value_type(-1);std::vector<int>qu;for(int i=0;i<=m+1;++i)if(OtherUtilities::Abs(a[l][i]/=t)>value_type(0))qu.push_back(i);
            for(int i=0;i<=n+1;++i)
                if(i!=l&&OtherUtilities::Abs(a[i][e])>value_type(0)){
                    t=a[i][e];a[i][e]=value_type(0);for(std::vector<int>::const_iterator j=qu.begin();j!=qu.end();++j)a[i][*j]+=a[l][*j]*t;
                }
            if(-p==l)p=e;else if(p==e)p=-l;
        }
        inline bool opt(const int&d){
            while(true){
                int l=-1,e=-1;for(int i=1;i<=m+1;++i)if(a[d][i]>value_type(0)){e=i;break;}if(e==-1)return true;value_type t;
                for(int i=1;i<=n;++i)if(a[i][e]<value_type(0)&&(l==-1||a[i][0]/-a[i][e]<t))t=a[i][0]/-a[i][e],l=i;if(l==-1)return false;pivot(l,e);
            }
        }
        inline value_type&At(const int&x,const int&y){return a[x][y];}
        inline std::pair<value_type,bool>Run(){
            value_type t;int l=-1;for(int i=1;i<=n;++i)if(l==-1||a[i][0]<t)t=a[i][0],l=i;
            if(t<value_type(0)){
                for(int i=1;i<=n;++i)a[i][m+1]=value_type(1);a[n+1][m+1]=value_type(-1);p=m+1;pivot(l,m+1);
                if(!opt(n+1)||OtherUtilities::Abs(a[n+1][0])>value_type(0))return std::make_pair(a[0][0],false);
                if(p<0)for(int i=1;i<=m;++i)if(OtherUtilities::Abs(a[-p][i])>value_type(0)){pivot(-p,i);break;}for(int i=0;i<=n;++i)a[i][p]=value_type(0);
            }
            bool r=opt(0);return std::make_pair(a[0][0],r);
        }
        int n,m,p;std::vector<std::vector<value_type> >a;
    };
}
namespace NumericAlgorithms{
    template<typename value_type>
    inline void DiscreteFourierTransform(std::vector<std::complex<value_type> >&a,const int&n,const int&s){
        value_type pi=value_type(acos(-1.0));std::complex<value_type> im(value_type(0),value_type(1));
        for(int i=0;i<n;++i){int j=0;for(int k=0;(1<<k)<n;++k)j<<=1,j+=((i>>k)&1);if(i<j)swap(a[i],a[j]);}
        for(int i=1;(1<<i)<=n;++i){
            int m=(1<<i);std::complex<value_type> wm=exp(value_type(s)*im*value_type(2)*pi/value_type(m));
            for(int j=0;j<n;j+=m){
                std::complex<value_type> w(value_type(1),value_type(0));
                for(int k=0;k<(m>>1);++k){std::complex<value_type> u=a[j+k],v=w*a[j+k+(m>>1)];a[j+k]=u+v;a[j+k+(m>>1)]=u-v;w*=wm;}
            }
        }
    }

}
using namespace std;
using namespace OtherUtilities;
using namespace NumberTheory;
using namespace DataStructures;
using namespace LinearProgramming;
using namespace NumericAlgorithms;
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
ll n,k,a[200010],sum[200010],f[200010],ans,ansa,ansb;
int main(){
    Read(n);Read(k);
    lp(i,1,n)Read(a[i]);
    rp(i,n,1)sum[i]=sum[i+1]+a[i];
    f[n-k+1]=n-k+1;
    rp(i,n-k,1){
        if(sum[i]-sum[i+k]>=sum[f[i+1]]-sum[f[i+1]+k])
            f[i]=i;
        else
            f[i]=f[i+1];
    }
    lp(i,1,n-k-k+1){
        ll tmp=sum[i]-sum[i+k]+sum[f[i+k]]-sum[f[i+k]+k];
        if(tmp>ans){
            ans=tmp;
            ansa=i;
            ansb=f[i+k];
        }
    }
    Write(ansa);Write(" ");Write(ansb);Write("\n");
    //ps;
    return 0;
}