#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstdlib>
#include<set>
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
namespace trp{
    struct node{
        node(){}
        node(int a,int b){l=a;r=b;sum=0;ch[0]=ch[1]=0;}
        int l,r;ll sum;
        node*ch[2];
    };
    node buff[4000010],*bfs=buff;
    inline node*newnode(int l,int r){
        *bfs=node(l,r);
        return bfs++;
    }
    inline ll query(node*x,int k){
        if(!x)return 0;
        int m=(x->l+x->r)/2;
        if(k<=m)return query(x->ch[0],k);
        else return (x->ch[0]?x->ch[0]->sum:0)+query(x->ch[1],k);
    }
    inline void insert(node*x,int k,int v){
        if(x->l==x->r)x->sum+=v;
        else{
            int m=(x->l+x->r)/2;
            if(k<=m){
                if(!x->ch[0])x->ch[0]=newnode(x->l,m);
                insert(x->ch[0],k,v);
                x->sum+=v;
            }else{
                if(!x->ch[1])x->ch[1]=newnode(m+1,x->r);
                insert(x->ch[1],k,v);
                x->sum+=v;
            }
        }
    }
    inline void remove(node*x,int k,int v){
        if(x->l==x->r)x->sum-=v;
        else{
            int m=(x->l+x->r)/2;
            if(k<=m){
                remove(x->ch[0],k,v);
                x->sum-=v;
            }else{
                remove(x->ch[1],k,v);
                x->sum-=v;
            }
        }
    }
}
namespace seg{
    struct node{
        node(int a,int b){ch[0]=ch[1]=0;l=a;r=b;tp=trp::newnode(0,99999);}
        node*ch[2];int l,r;trp::node*tp;
    };
    inline node*build(int l,int r){
        node*ret=new node(l,r);
        if(l!=r){
            int m=(l+r)/2;
            ret->ch[0]=build(l,m);
            ret->ch[1]=build(m+1,r);
        }
        return ret;
    }
    inline void insert(node*x,int p,pair<int,int>v){
        trp::insert(x->tp,v.first,v.second);
        if(x->ch[0]){
            if(p<=x->ch[0]->r)insert(x->ch[0],p,v);
            else insert(x->ch[1],p,v);
        }
    }
    inline void remove(node*x,int p,pair<int,int>v){
        trp::remove(x->tp,v.first,v.second);
        if(x->ch[0]){
            if(p<=x->ch[0]->r)remove(x->ch[0],p,v);
            else remove(x->ch[1],p,v);
        }
    }
    inline ll query(node*x,int l,int r,int v){
        if(l<=x->l&&r>=x->r)return trp::query(x->tp,v);
        else{
            ll ret=0;
            if(l<=x->ch[0]->r)ret+=query(x->ch[0],l,r,v);
            if(r>x->ch[0]->r)ret+=query(x->ch[1],l,r,v);
            return ret;
        }
    }
}
namespace lisa{
    vector<int>data;
    inline void insert(int x){
        data.pb(x);
    }
    inline void build(){
        sort(data.begin(),data.end());
        data.erase(unique(data.begin(),data.end()),data.end());
    }
    inline int convert(int x){
        return lower_bound(data.begin(),data.end(),x)-data.begin()+1;
    }
}
int main(){
    static int a[100010],n,m;
    static set<int>p[200010];static char op1[100010];
    static int op2[100010],op3[100010];
    sf("%d",&n);lp(i,1,n)sf("%d",&a[i]),lisa::insert(a[i]);
    sf("%d",&m);lp(i,1,m){
        char op[11];sf("%s%d%d",op,&op2[i],&op3[i]);
        op1[i]=op[0];if(op[0]=='U')lisa::insert(op3[i]);
    }
    lisa::build();
    seg::node*rt=seg::build(1,n);
    lp(i,1,n){
        int t=lisa::convert(a[i]);
        if(p[t].empty())seg::insert(rt,i,mp(0,a[i]));
        else seg::insert(rt,i,mp(*p[t].rbegin(),a[i]));
        p[t].insert(i);
    }
    lp(i,1,m){
        if(op1[i]=='Q'){
            pf("%lld\n",seg::query(rt,op2[i],op3[i],op2[i]));
        }else{
            int x=op2[i],y=a[x],z=op3[i];
            set<int>&s1=p[lisa::convert(y)],&s2=p[lisa::convert(z)];
            set<int>::iterator it,ti;int tp;
            it=s1.lower_bound(x);
            if(it==s1.begin())seg::remove(rt,x,mp(tp=0,y));
            else seg::remove(rt,x,mp(tp=*(--it),y)),++it;
            ++it;
            if(it!=s1.end()){
                seg::remove(rt,*it,mp(x,a[*it]));
                seg::insert(rt,*it,mp(tp,a[*it]));
            }
            s1.erase(x);
            it=ti=s2.lower_bound(x);
            if(it==s2.begin())seg::insert(rt,x,mp(tp=0,z));
            else seg::insert(rt,x,mp(tp=*(--it),z));
            it=ti;
            if(it!=s2.end()){
                seg::remove(rt,*it,mp(tp,a[*it]));
                seg::insert(rt,*it,mp(x,a[*it]));
            }
            s2.insert(x);
            a[x]=z;
        }
    }
    //ps;
    return 0;
}
