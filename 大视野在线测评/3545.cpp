#include<cstdio>
#include<complex>
#include<cmath>
#include<algorithm>
using namespace std;
namespace seg{
    struct node{
        node(int _l,int _r):
            l(_l),r(_r),s(0){
                ch[0]=ch[1]=0;}
        int l,r,s;
        node*ch[2];
    };
    void update(node*x){
        x->s=0;
        if(x->ch[0])x->s+=x->ch[0]->s;
        if(x->ch[1])x->s+=x->ch[1]->s;
    }
    void insert(node*x,int h){
        if(x->l==x->r){
            x->s=1;
        }else{
            int m=x->l+(x->r-x->l)/2;
            if(h<=m){
                if(!x->ch[0])x->ch[0]=new node(x->l,m);
                insert(x->ch[0],h);
                update(x);
            }else{
                if(!x->ch[1])x->ch[1]=new node(m+1,x->r);
                insert(x->ch[1],h);
                update(x); 
            }
        }
    }
    void insert2(node*x,int h){
        if(x->l==x->r){
            --x->s;
        }else{
            int m=x->l+(x->r-x->l)/2;
            if(h<=m){
                insert2(x->ch[0],h);
                update(x);
            }else{
                insert2(x->ch[1],h);
                update(x); 
            }
        }
    }
    node*merge(node*x,node*y){
        if(!x)return y;
        if(!y)return x;
        x->s+=y->s;
        if(x->l!=x->r){
            x->ch[0]=merge(x->ch[0],y->ch[0]);
            x->ch[1]=merge(x->ch[1],y->ch[1]);
        }
        delete y;
        return x;
    }
    int query(node*x,int k){
        //printf("[%d,%d,%d]\n",x->l,x->r,k);
        if(x->s<k||k<1)return -1;
        if(x->l==x->r)return x->l;
        int t=x->ch[1]?x->ch[1]->s:0;
        if(k<=t)return query(x->ch[1],k);
        else return query(x->ch[0],k-t);
    }
}
namespace ufs{
    int prt[100010];
    int fd(int x){return x==prt[x]?x:prt[x]=fd(prt[x]);}
    void link(int x,int y){prt[fd(y)]=x;}
}
struct edge{
    int u,v,w;
};
bool cmp1(edge a,edge b){
    return a.w<b.w;
}
struct ques{
  int v,x,k,idx;  
};
bool cmp2(ques a,ques b){
    return a.x<b.x;
}
int main(){
    //freopen("p3.out","r",stdin);
    int n,m,q;scanf("%d%d%d",&n,&m,&q);
    static seg::node*nds[100010];
    static int hei[100010];
    for(int i=1;i<=n;++i){
        int h;scanf("%d",&h);
        nds[i]=new seg::node(0,1000000000);
        seg::insert(nds[i],h);
        ufs::prt[i]=i;
        hei[i]=h;
    }
    static edge egs[500010];
    for(int i=1;i<=m;++i)
        scanf("%d%d%d",&egs[i].u,&egs[i].v,&egs[i].w);
    sort(egs+1,egs+m+1,cmp1);
    static ques qs[500010];
    for(int i=1;i<=q;++i){
        scanf("%d%d%d",&qs[i].v,&qs[i].x,&qs[i].k);
        qs[i].idx=i;
    }
    sort(qs+1,qs+q+1,cmp2);
    static int ans[500010];int pt=1;
    for(int i=1;i<=q;++i){
        while(pt<=m&&egs[pt].w<=qs[i].x){
            int u=egs[pt].u;
            int v=egs[pt].v;
            int w=egs[pt].w;
            if(ufs::fd(u)!=ufs::fd(v)){
                seg::node*tmp=seg::merge(nds[ufs::fd(u)],nds[ufs::fd(v)]);
                ufs::link(u,v);
                nds[ufs::fd(u)]=tmp;
            }
            ++pt;
        }
        //for(;;);
        ans[qs[i].idx]=seg::query(nds[ufs::fd(qs[i].v)],qs[i].k);
        //for(;;);
    }
    for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
    //for(;;);
    return 0;
}
