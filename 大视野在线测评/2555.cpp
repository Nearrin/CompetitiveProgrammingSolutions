#include<bits/stdc++.h>
#define lop(i,a,b) for(int i=a;i<=int(b);++i)
#define rlp(i,a,b) for(int i=a;i>=b;--i)
#define vlp(i,a) for(int i=0;i<a.size();++i)
#define mcs int css;cin>>css;lop(csn,1,css)
#define fio ios::sync_with_stdio(0)
#define all(a) a.begin(),a.end()
#define pub push_back
#define pob pop_back
#define mkp make_pair
#define vec vector
#define scf scanf
#define ptf printf
namespace CTL{}
using namespace CTL;
using namespace std;
typedef long long lli;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldb;
typedef string str;
typedef pair<int,int> pii;



#ifndef SUFFIX_ARRAY
#define SUFFIX_ARRAY
#include<bits/stdc++.h>
namespace CTL{
    using namespace std;
    template<class T>struct SuffixArray{
        struct node{
            node*c[2],*p;T v;int f,s;double t;
            node(node*_p,T _v):
                f(rand()*1.0/RAND_MAX*1e9),
                p(_p),v(_v),s(1),t(5e8){c[0]=c[1]=0;}}*root;
        SuffixArray():root(new node(0,0)){}
        ~SuffixArray(){clear(root);}
        void relabel(node*x,double l,double r){
            x->t=(l+r)/2;if(x->c[0])relabel(x->c[0],l,x->t);
            if(x->c[1])relabel(x->c[1],x->t,r);}
        void update(node*x){
            x->s=1;for(int i=0;i<2;++i)if(x->c[i])x->s+=x->c[i]->s;}
        void rotate(node*&x,int d){
            node*y=x->c[d];x->c[d]=y->c[!d];y->c[!d]=x;
            y->s=x->s;update(x);x=y;}
        static int check(node*x,node*p,int v){
            if(x->v!=v)return x->v<v?1:0;double d=x->p->t-p->t;
            if(d<-1e-8)return 1;return d>1e-8?0:2;}
        node*insert(node*&x,node*p,int v,double l,double r){
            int d=check(x,p,v);if(d==2)return x;
            node*y;if(!x->c[d]){
                y=x->c[d]=new node(p,v);
                if(d)y->t=(x->t+r)/2;else y->t=(l+x->t)/2;
            }else y=insert(x->c[d],p,v,d?x->t:l,d?r:x->t);
            update(x);if(x->c[d]->f>x->f)
                rotate(x,d),relabel(x,l,r);return y;}
        void erase(node*&x,node*y){
            if(x==y){
                if(!x->c[0]){x=x->c[1];delete y;}
                else if(!x->c[1]){x=x->c[0];delete y;}
                else{
                    int d=x->c[0]->f<x->c[1]->f;
                    rotate(x,d);erase(x->c[!d],y);--x->s;}
            }else erase(x->c[x->t<y->t],y),--x->s;}
        bool check(node*x,T*y){
            for(++y;x->v==*y&&*y;x=x->p,++y);
            return x->v<*y;}
        int count(node*x,T*y){
            int r=0;while(x){
                if(check(x,y))
                    r+=(x->c[0]?x->c[0]->s:0)+1,x=x->c[1];
                else x=x->c[0];}
            return r;}
        void clear(node*x){
            if(!x)return;clear(x->c[0]);
            clear(x->c[1]);delete x;}
        node*insert(node*p,int v){
            return insert(root,p,v,0,1e9);}
        void erase(node*y){erase(root,y);}
        int count(T*y){
            T*t=y;while(*(t+1))++t;
            int r=-count(root,y);++*t;
            r+=count(root,y);--*t;return r;}};}
#endif



char st[3000010];int len,msk=0;
void getstr(){scf("%s",st+1);len=strlen(st+1);}
void demark(){
  // return;
    int t=msk;
    lop(i,1,len){
        msk=(msk*131+i-1)%len;
        swap(st[i],st[msk+1]);
    }
    msk=t;
}
int main(){
    int q;scf("%d",&q);
    SuffixArray<char> sbt;
    SuffixArray<char>::node*p=sbt.root;
    getstr();lop(i,1,len)
            p=sbt.insert(p,st[i]);
    lop(i,1,q){
        char op[110];scf("%s",op);getstr();demark();
        if(op[0]=='A'){
            lop(i,1,len){

                //SuffixArray<char>::node*tmp=p;
                             //  p=sbt.insert(p,st[i]);
                            //  sbt.erase(p);
                             //  p=tmp;
                               p=sbt.insert(p,st[i]);

            }
        }else{
            reverse(st+1,st+len+1);
            int ans=sbt.count(st);
            ptf("%d\n",ans);
            msk^=ans;
        }
    }
    //ps;
    return 0;
}
