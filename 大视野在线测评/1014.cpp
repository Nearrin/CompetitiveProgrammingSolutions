#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstdlib>
#include<cstring>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
using namespace std;
typedef long long ll;
ll p=1000000007,q=26;
ll pw[100010];
namespace treap{
    struct node{
        node(){}
        node(char c){siz=1;ch[0]=ch[1]=0;val=c;hs=c-'a';fix=rand();}
        node*ch[2];char val;ll hs;int siz,fix;
    };
    node buff[100010],*bfs=buff;
    node*newnode(char v){
        *bfs=node(v);
        return bfs++;
    }
    inline void update(node*x){
        x->siz=1;
        if(x->ch[0])x->siz+=x->ch[0]->siz;
        if(x->ch[1])x->siz+=x->ch[1]->siz;
        x->hs=x->val-'a';
        if(x->ch[0])x->hs=(x->hs+x->ch[0]->hs*q)%p;
        if(x->ch[1])x->hs=(x->hs*pw[x->ch[1]->siz]+x->ch[1]->hs)%p;
    }
    inline void rotate(node*&x,int d){
        node*y=x->ch[d];
        x->ch[d]=y->ch[!d];
        y->ch[!d]=x;
        y->siz=x->siz;y->hs=x->hs;
        update(x);
        x=y;
    }
    inline void insert(node*&x,int k,char v){
        if(!x)x=new node(v);
        else{
            int t=x->ch[0]?x->ch[0]->siz:0;
            if(k<=t){
                insert(x->ch[0],k,v);
                update(x);
                if(x->ch[0]->fix<x->fix)rotate(x,0);
            }else {
                insert(x->ch[1],k-(t+1),v);
                update(x);
                if(x->ch[1]->fix<x->fix)rotate(x,1);
            }
        }
    }
    inline void modify(node*x,int k,char v){
        int t=x->ch[0]?x->ch[0]->siz:0;
        if(k<=t)modify(x->ch[0],k,v);
        else if(k>t+1)modify(x->ch[1],k-(t+1),v);
        else x->val=v;
        update(x);
    }
    inline ll query(node*x,int l,int r){
    	if(l==1&&r==x->siz)return x->hs;
        int t=x->ch[0]?x->ch[0]->siz:0;
        if(r<=t)return query(x->ch[0],l,r);
        else if(l>t+1)return query(x->ch[1],l-(t+1),r-(t+1));
        else if(l==t+1&&r==t+1)return x->val-'a';
        else if(l==t+1)return ((x->val-'a')*pw[r-(t+1)]+query(x->ch[1],1,r-(t+1)))%p;
        else if(r==t+1)return (query(x->ch[0],l,t)*q+(x->val-'a'))%p;
        else{
            ll t1=query(x->ch[0],l,t);
            t1=(t1*q+x->val-'a')%p;
            r=r-(t+1);
            t1=(t1*pw[r]+query(x->ch[1],1,r))%p;
            return t1;
        }
    }
    int lcp(node*x,int a,int b){
        int len=x->siz;
        int lft=0,rht=min(len-a,len-b);
        if(query(x,a,a)!=query(x,b,b))return 0;
        if(query(x,a,a+rht)==query(x,b,b+rht))return rht+1;
        while(lft+1<rht){
            int mid=(lft+rht)/2;
            if(query(x,a,a+mid)==query(x,b,b+mid))
                lft=mid;
            else
                rht=mid;
        }
        return lft+1;
    }
    void print(node*x,int d){
    	if(x){
    		print(x->ch[0],d+1);
    		lp(i,1,d*4)pf(" ");pf("[%lld,%d]\n",x->hs,x->siz);
    		print(x->ch[1],d+1);
    	}
    }
}
int main(){
    pw[0]=1;lp(i,1,100005)pw[i]=pw[i-1]*q%p;
    static char str[100010];
    sf("%s",str+1);treap::node*rt=0;int len=strlen(str+1);
    lp(i,1,len)treap::insert(rt,i-1,str[i]);
    int m;sf("%d",&m);
    lp(i,1,m){
        char op[11];sf("%s",op);
        if(op[0]=='Q'){
            int x,y;sf("%d%d",&x,&y);
            pf("%d\n",treap::lcp(rt,x,y));
        }else if(op[0]=='R'){
            int x;char v[11];sf("%d%s",&x,v);
            treap::modify(rt,x,v[0]);
        }else{
            int x;char v[11];sf("%d%s",&x,v);
            treap::insert(rt,x,v[0]);
        }
    }
    return 0;
}
