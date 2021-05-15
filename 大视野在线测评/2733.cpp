#ifndef MERGABLE_SEGMENT_TREE
#define MERGABLE_SEGMENT_TREE
#include<bits/stdc++.h>
namespace CTL{
    using namespace std;
    struct MergableSegmentTree{
        struct node{
            node(int a,int b):lc(0),rc(0),ct(0),lt(a),rt(b){}
            node*lc,*rc;int ct,lt,rt;}*root;
        MergableSegmentTree(int l,int r):root(new node(l,r)){}
        node*merge(node*u,node*v){
            if(!u)return v;if(!v)return u;u->ct+=v->ct;
            if(u->lt!=u->rt)u->lc=merge(u->lc,v->lc),u->rc=merge(u->rc,v->rc);
            delete v;return u;}
        void modify(int a,int d,node*u=0){
            if((u?0:(u=root)),u->lt!=u->rt){
                int m=(u->lt+u->rt)/2;
                if(a<=m)modify(a,d,u->lc?u->lc:(u->lc=new node(u->lt,m)));
                else modify(a,d,u->rc?u->rc:( u->rc=new node(m+1,u->rt)));}
            u->ct+=d;}
        int query(int k,node*u=0){
            if((u?0:(u=root)),u->lt==u->rt)return u->lt;
            else if(k<=(u->lc?u->lc->ct:0))return query(k,u->lc);
            else return query(k-(u->lc?u->lc->ct:0),u->rc);}
        int size(){return root->ct;}
        void merge(MergableSegmentTree&a){
            root=merge(root,a.root);
            a.root=new node(root->lt,root->rt);}};}
#endif
#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
namespace ufs{
    const int nmx=100000;
    int p[nmx+10];
    int fd(int u){return u==p[u]?u:p[u]=fd(p[u]);}
    int lk(int u,int v){p[fd(u)]=v;}
}
using namespace CTL;
MergableSegmentTree* nd[100010];
int mp[100010];
int main(){
    mp[0]=-1;
    int n,m;sf("%d%d",&n,&m);
    lp(i,1,n){
        int t;sf("%d",&t);
        nd[i]=new MergableSegmentTree(1,n);
        nd[i]->modify(t,1);
        ufs::p[i]=i;
        mp[t]=i;
    }
    lp(i,1,m){
        int a,b;sf("%d%d",&a,&b);
        if(ufs::fd(a)!=ufs::fd(b)){
            int d=ufs::fd(a),e=ufs::fd(b);
 nd[e]->merge(*nd[d]);
            ufs::lk(d,e);
        }
    }
    int q;sf("%d",&q);
    lp(i,1,q){
        char op[11];int a,b;
        sf("%s%d%d",op,&a,&b);
        if(op[0]=='Q'){
            int ans;
            if(b>=1&&b<=nd[ufs::fd(a)]->size())
                ans=nd[ufs::fd(a)]->query(b);
            else ans=0;
            pf("%d\n",mp[ans]);
        }
        else{
            if(ufs::fd(a)!=ufs::fd(b)){
                int d=ufs::fd(a),e=ufs::fd(b);
              nd[e]->merge(*nd[d]);
                ufs::lk(d,e);
            }
        }
    }
    //ps;
    return 0;
}
