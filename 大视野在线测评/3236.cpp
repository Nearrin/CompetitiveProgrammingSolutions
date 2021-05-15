#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
typedef long long ll;
using namespace std;
#include<map>
namespace input{
	int n,m,a[1000010],l[1000010],r[1000010],u[1000010],v[1000010];
	void init(){
		sf("%d%d",&n,&m);
		lp(i,1,n)sf("%d",&a[i]);
		lp(i,1,m)sf("%d%d%d%d",&l[i],&r[i],&u[i],&v[i]);
	}
}
namespace treap{
    struct node{
        node(int a){
            ch[0]=ch[1]=0;
            vl=a;sz=1;fx=rand();
        }
        node*ch[2];
        int vl,sz,fx;
    };
    void update(node*x){
        x->sz=1;
        lp(i,0,1)if(x->ch[i])x->sz+=x->ch[i]->sz;
    }
    void rotate(node*&x,int d){
        node*y=x->ch[d];
        x->ch[d]=y->ch[!d];
        y->ch[!d]=x;
        update(x);update(y);x=y;
    }
    void insert(node*&x,int v){
        if(!x)x=new node(v);
        else{
            if(v<x->vl){
                insert(x->ch[0],v);
                update(x);
                if(x->ch[0]->fx<x->fx)
                    rotate(x,0);
            }else{
                insert(x->ch[1],v);
                update(x);
                if(x->ch[1]->fx<x->fx)
                    rotate(x,1);
            }
        }
    }
    void remove(node*&x,int v){
        if(x->vl==v){
            if(!x->ch[0])x=x->ch[1];
            else if(!x->ch[1])x=x->ch[0];
            else if(x->ch[0]->fx<x->ch[1]->fx)
                rotate(x,0),remove(x->ch[1],v),update(x);
            else
                rotate(x,1),remove(x->ch[0],v),update(x);
        }else{
            remove(x->ch[v>x->vl],v),update(x);
        }
    }
    int lesseq(node*x,int v){
        if(!x)return 0;
        else if(x->vl<=v)return (x->ch[0]?x->ch[0]->sz:0)+1+lesseq(x->ch[1],v);
        else return lesseq(x->ch[0],v);
    }
}
namespace segment{
    struct node{
        node(int a,int b){
            ch[0]=ch[1]=0;
            tp=0;l=a;r=b;
        }
        node*ch[2];treap::node*tp;int l,r;
    };
    node*build(int l,int r){
        node*x=new node(l,r);
        if(l!=r){
            int m=(l+r)/2;
            x->ch[0]=build(l,m);
            x->ch[1]=build(m+1,r);
        }
        return x;
    }
    void insert(node*x,int p,int v){
        treap::insert(x->tp,v);
        if(x->l!=x->r){
            if(p<=x->ch[0]->r)
                insert(x->ch[0],p,v);
            else
                insert(x->ch[1],p,v);
        }
    }
    void remove(node*x,int p,int v){
        treap::remove(x->tp,v);
        if(x->l!=x->r){
            if(p<=x->ch[0]->r)
                remove(x->ch[0],p,v);
            else
                remove(x->ch[1],p,v);
        }
    }
    int lesseq(node*x,int b,int e,int v){
       if(b<=x->l&&e>=x->r)return treap::lesseq(x->tp,v);
       else{
            int ret=0;
            if(b<=x->ch[0]->r)ret+=lesseq(x->ch[0],b,e,v);
            if(e>x->ch[0]->r)ret+=lesseq(x->ch[1],b,e,v);
            return ret;
       }
    }
    int count(node*x,int b,int e,int u,int v){
    	return lesseq(x,b,e,v)-lesseq(x,b,e,u-1);
    }
}
namespace subtask1{
	int ans[1000010];
	void solve(){
		segment::node*rt=segment::build(1,input::n);
		lp(i,1,input::n)segment::insert(rt,i,input::a[i]);
		lp(i,1,input::m)ans[i]=segment::count(rt,input::l[i],input::r[i],input::u[i],input::v[i]);
	}
}
namespace subtask2{
	map<int,int>top;
	int pr[1000010];
	struct query{
		int idx,l,r,u,v;
	};
	int ans[1000010];
	vector<query>qs[1000010];
	void solve(){
		lp(i,1,input::n){
			pr[i]=top[input::a[i]];
			top[input::a[i]]=i;
		}
		lp(i,1,input::m){
			query t;t.idx=i;
			t.l=input::l[i];
			t.r=input::r[i];
			t.u=input::u[i];
			t.v=input::v[i];
			qs[t.r].pb(t);
		}
		segment::node*rt=segment::build(1,input::n);
		lp(i,1,input::n){
			segment::insert(rt,i,input::a[i]);
			if(pr[i])segment::remove(rt,pr[i],input::a[i]);
			vp(j,qs[i]){
				ans[qs[i][j].idx]=segment::count(rt,qs[i][j].l,qs[i][j].r,qs[i][j].u,qs[i][j].v);
			}
		}
	}
}
int main(){
	input::init();
	subtask1::solve();
	subtask2::solve();
	lp(i,1,input::m)pf("%d %d\n",subtask1::ans[i],subtask2::ans[i]);
	return 0;
}
