#include <iostream>
#include<utility>
#include<vector>
#include<cstdio>
using namespace std;
struct info{
    bool left_can_shoot_when_right_die;
    int left_shoot_time_when_right_die;
    int people_alive_when_right_die;

    bool left_can_shoot_when_right_live;
    int left_shoot_time_when_right_live;
    int people_alive_when_right_live;

    int l,r,right_shoot_time;
    int slowest_shooter;
    int slowest_shooter_time;
    inline void update(const info&a,const info&b){
        if(b.left_can_shoot_when_right_die){
            if(b.left_shoot_time_when_right_die>a.right_shoot_time){
                left_can_shoot_when_right_die=a.left_can_shoot_when_right_live;
                left_shoot_time_when_right_die=a.left_shoot_time_when_right_live;
                people_alive_when_right_die=b.people_alive_when_right_die+a.people_alive_when_right_live-1;
            }else{
                left_can_shoot_when_right_die=a.left_can_shoot_when_right_die;
                left_shoot_time_when_right_die=a.left_shoot_time_when_right_die;
                people_alive_when_right_die=b.people_alive_when_right_die+a.people_alive_when_right_die;
            }
        }else{
                left_can_shoot_when_right_die=a.left_can_shoot_when_right_live;
                left_shoot_time_when_right_die=a.left_shoot_time_when_right_live;
                people_alive_when_right_die=b.people_alive_when_right_die+a.people_alive_when_right_live;
        }


        if(b.left_can_shoot_when_right_live){
            if(b.left_shoot_time_when_right_live>a.right_shoot_time){
                left_can_shoot_when_right_live=a.left_can_shoot_when_right_live;
                left_shoot_time_when_right_live=a.left_shoot_time_when_right_live;
                people_alive_when_right_live=b.people_alive_when_right_live+a.people_alive_when_right_live-1;
            }else{
                left_can_shoot_when_right_live=a.left_can_shoot_when_right_die;
                left_shoot_time_when_right_live=a.left_shoot_time_when_right_die;
                people_alive_when_right_live=b.people_alive_when_right_live+a.people_alive_when_right_die;
            }
        }else{
                left_can_shoot_when_right_live=a.left_can_shoot_when_right_live;
                left_shoot_time_when_right_live=a.left_shoot_time_when_right_live;
                people_alive_when_right_live=b.people_alive_when_right_live+a.people_alive_when_right_live;
        }
        if(a.slowest_shooter_time>=b.slowest_shooter_time){
            slowest_shooter_time=a.slowest_shooter_time;
            slowest_shooter=a.slowest_shooter;
        }else{
            slowest_shooter_time=b.slowest_shooter_time;
            slowest_shooter=b.slowest_shooter;
        }
        l=a.l;
        r=b.r;
        right_shoot_time=b.right_shoot_time;
    }
};
    void printinfo(info ifo){
        return;
        cout<<"---------------------------------\n";
        cout<<ifo.l<<" "<<ifo.r<<endl;
        cout<<"lshoot time"<<ifo.right_shoot_time<<endl;
         cout<<"ifo.left_can_shoot_when_right_die"<<ifo.left_can_shoot_when_right_die<<endl;
   cout<<" ifo. left_shoot_time_when_right_die"<<ifo. left_shoot_time_when_right_die<<endl;
    cout<<" ifo. people_alive_when_right_di" <<ifo. people_alive_when_right_die<<endl;

    cout<<  " ifo.  left_can_shoot_when_right_live"<<ifo.  left_can_shoot_when_right_live<<endl;
    cout<<  "ifo. left_shoot_time_when_right_live " << ifo. left_shoot_time_when_right_live<<endl;
    cout<<  " ifo.  people_alive_when_right_live" <<ifo.  people_alive_when_right_live<<endl;
    cout<<"---------------------------------\n\n";
    }
struct segmenttree{
    int *a,n;
    struct node{
        node*lc,*rc;
        info ifo;
    }*root;
    void buildtree(node*x,int l,int r){
        x->ifo.l=l;
        x->ifo.r=r;
        x->ifo.right_shoot_time=a[r];
        if(l==r){
            x->ifo.left_can_shoot_when_right_die=false;
            x->ifo.left_shoot_time_when_right_die=-1;
            x->ifo.people_alive_when_right_die=0;
            x->ifo.left_can_shoot_when_right_live=true;
            x->ifo.left_shoot_time_when_right_live=a[r];
            x->ifo.people_alive_when_right_live=1;
            x->ifo.slowest_shooter=l;
            x->ifo.slowest_shooter_time=a[r];
        }else{
            x->lc=new node;
            x->rc=new node;
            int m=(l+r)/2;
            buildtree(x->lc,l,m);
            buildtree(x->rc,m+1,r);
            x->ifo.update(x->lc->ifo,x->rc->ifo);
        }
    }
    void change(node*x,int p,int v){
        if(x->ifo.l==x->ifo.r){
            x->ifo.left_shoot_time_when_right_live=v;
            x->ifo.slowest_shooter_time=v;
            x->ifo.right_shoot_time=v;
        }else{
            int m=(x->ifo.l+x->ifo.r)/2;
            if(p<=m){
                change(x->lc,p,v);
            }else
                change(x->rc,p,v);
            x->ifo.update(x->lc->ifo,x->rc->ifo);
           // x->ifo.right_shoot_time=x->rc->ifo.right_shoot_time;
        }
    }
    void query(node*x,vector<info*>&ifs,int l,int r){
        if(l==x->ifo.l&&r==x->ifo.r){
            ifs.push_back(&x->ifo);
        }else{
            int m=(x->ifo.l+x->ifo.r)/2;
            if(r<=m){
                query(x->lc,ifs,l,r);
            }else if(l>m){
                query(x->rc,ifs,l,r);
            }else{
                query(x->lc,ifs,l,m);
                query(x->rc,ifs,m+1,r);
            }
        }
    }

    void build(){

       //for(int i=1;i<=n;++i)
      //     cout<<a[i]<<" ";
    //   cout<<endl;
        root=new node;
        buildtree(root,1,n);
    }
    int curans;
    int calc(){
        //cout<<"hehe";
        int t=root->ifo.slowest_shooter;
        int l=t,r=t+n/2-1;
   //    cout<<l<<" "<<r<<endl;
        vector<info*>ifs;
        query(root,ifs,l,r);
        for(int i=0;i<ifs.size();++i)
            printinfo(*ifs[i]);
        info tmp=*ifs[0];
        for(int i=1;i<ifs.size();++i){
            info tmo2;
            tmo2.update(tmp,*ifs[i]);
            tmp=tmo2;
            printinfo(tmp);
        }
        if(tmp.left_can_shoot_when_right_live)
            return curans=(tmp.people_alive_when_right_live-1);
        else
            return curans=(tmp.people_alive_when_right_live);
    }
};
segmenttree trees[200010];int treecnt;
int treepos[200010];
int intreepos[200010];
int ans;
void modify(int p,int v){
    segmenttree&tr=trees[treepos[p]];
    int u=intreepos[p];
    ans-=tr.curans;
    tr.change(tr.root,u,v);
    tr.change(tr.root,u+tr.n/2,v);
    ans+=tr.calc();
}

int main()
{
    int n;static int p[200010],u[200010];
    static int vis[200010];
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
            int t;scanf("%d",&t);
        p[t]=i;
    }
    for(int i=1;i<=n;++i)
        scanf("%d",u+i);
    for(int i=1;i<=n;++i){
        if(vis[i])continue;
        int cirlen=0;
        static int num[200010];
        num[i]=++cirlen;
        static int vec[200010];
        int vlen=0;
        vec[++vlen]=i;
        vis[i]=1;
        for(int j=p[i];j!=i;j=p[j]){
            num[j]=++cirlen;
            vec[++vlen]=j;
            vis[j]=1;
        }
        ++treecnt;
        segmenttree&tr=trees[treecnt];
        tr.n=2*cirlen;
        tr.a=new int[2*cirlen+10];
        for(int j=1;j<=vlen;++j){
            tr.a[j]=u[vec[j]];
            tr.a[j+vlen]=u[vec[j]];
            treepos[vec[j]]=treecnt;
            intreepos[vec[j]]=j;
        }
        tr.build();
    }
    for(int i=1;i<=treecnt;++i)
        ans+=trees[i].calc();
    printf("%d\n",ans);
    int q;scanf("%d",&q);
    for(int i=1;i<=q;++i){
        int k,v;
        scanf("%d%d",&k,&v);
        modify(k,v);
        printf("%d\n",ans);
    }
    return 0;
}
/*
4
2 3 4 1
8 2 3 4
*/
