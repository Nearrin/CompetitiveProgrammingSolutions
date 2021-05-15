#ifndef K_DIMENSIONAL_TREE
#define K_DIMENSIONAL_TREE
#include<bits/stdc++.h>
namespace CTL{
    using namespace std;
    struct KDimensionalTree{
        struct node{
            node(int x0,int x1,int d):color(1),cover(0),dir(d){
                ch[0]=ch[1]=0;x[0]=mi[0]=mx[0]=x0;x[1]=mi[1]=mx[1]=x1;}
            node*ch[2];int x[2],mi[2],mx[2],color,cover,dir;}*root;
        KDimensionalTree(pair<int,int>*a,int n){root=build(a,1,n,0);}
        static int direct;static int cmp(pair<int,int>a,pair<int,int>b){
            if(direct)return make_pair(a.second,a.first)<make_pair(b.second,b.first);
            return a<b;}
        node*build(pair<int,int>*a,int l,int r,int d){
            int m=(r+l)/2;direct=d;nth_element(a+l,a+m,a+r+1,cmp);
            node*p=new node((a+m)->first,(a+m)->second,d);
            if(l!=m)p->ch[0]=build(a,l,m-1,!d);if(r!=m)p->ch[1]=build(a,m+1,r,!d);
            for(int i=0;i<2;++i)for(int j=0;j<2;++j)if(p->ch[j])
                p->mi[i]=min(p->mi[i],p->ch[j]->mi[i]),
                p->mx[i]=max(p->mx[i],p->ch[j]->mx[i]);
            return p;}
        void down(node*a){
            if(a->cover){
                for(int i=0;i<2;++i)if(a->ch[i])a->ch[i]->cover=a->cover;
                a->color=a->cover;a->cover=0;}}
        void modify(node*a,int mi0,int mx0,int mi1,int mx1,int c){
            if(mi0>a->mx[0]||mx0<a->mi[0]||mi1>a->mx[1]||mx1<a->mi[1])return;
            if(mi0<=a->mi[0]&&mx0>=a->mx[0]&&mi1<=a->mi[1]&&mx1>=a->mx[1]){
                a->cover=c;return;}
            down(a);if(mi0<=a->x[0]&&mx0>=a->x[0]&&mi1<=a->x[1]&&mx1>=a->x[1])a->color=c;
            for(int i=0;i<2;++i)if(a->ch[i])modify(a->ch[i],mi0,mx0,mi1,mx1,c);}
        void modify(int mi0,int mx0,int mi1,int mx1,int c){modify(root,mi0,mx0,mi1,mx1,c);}
        int query(node*a,int x0,int x1){
            down(a);if(x0==a->x[0]&&x1==a->x[1])return a->color;
            direct=a->dir;if(cmp(make_pair(x0,x1),make_pair(a->x[0],a->x[1])))
                return query(a->ch[0],x0,x1);
            else return query(a->ch[1],x0,x1);}
        int query(int x0,int x1){return query(root,x0,x1);}};
    int KDimensionalTree::direct=0;}
#endif

#include<bits/stdc++.h>
#define lop(i,a,b) for(int i=a;i<=int(b);++i)
#define rlp(i,a,b) for(int i=a;i>=b;--i)
#define vlp(i,a) for(int i=0;i<a.size();++i)
#define all(a) a.begin(),a.end()
#define sqr(a) ((a)*(a))
#define pub push_back
#define pob pop_back
#define mkp make_pair
#define scf scanf
#define ptf printf
#define inf (~0u>>1)
namespace CTL{}
using namespace CTL;
using namespace std;
typedef long long lli;
typedef unsigned long long ull;
typedef string str;
typedef vector<int> vei;
typedef vector<string> ves;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef set<int> sti;
typedef set<str> sts;
typedef pair<int,int> pii;
typedef vector<pii> vii;
vector<int>to[100010];
int nw;
int bg[100010],ed[100010],dep[100010];
void dfs(int u,int d){
    dep[u]=d;
    bg[u]=++nw;
    lop(i,0,to[u].size()-1){
        dfs(to[u][i],d+1);
    }
    ed[u]=nw;
}
pii pts[100010];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n,c,q;
        cin>>n>>c>>q;
        for(int i=1;i<=n;++i)
            to[i].clear();
        for(int i=2;i<=n;++i){
            int f;scanf("%d",&f);
            to[f].push_back(i);
        }
        nw=0;
        dfs(1,1);
        lop(i,1,n)pts[i].first=dep[i],pts[i].second=bg[i];
        KDimensionalTree kdtree(pts,n);
        lli P=1e9+7,A=0;
        lop(i,1,q){
            int a,l;scf("%d%d%d",&a,&l,&c);
            int ans;
            if(c==0)
                ans=kdtree.query(dep[a],bg[a]);
            else
                kdtree.modify(dep[a],dep[a]+l,bg[a],ed[a],c),ans=0;
            A=(A+lli(i)*ans)%P;
        }
        cout<<A<<endl;
    }
    return 0;
}
/*
1
4 3 2
1 2 2
2 1 3
2 0 0
*/
