#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int way[3][100010][5];//1up2down3left4right
struct node{
    node(int a,int b){l=a,r=b;lc=rc=0;lp(i,1,6)go[i]=0;}
    node*lc,*rc;int go[7],l,r;
};
node*build(int l,int r){
    node*x=new node(l,r);
    if(l!=r){
        int m=(l+r)/2;
        x->lc=build(l,m);
        x->rc=build(m+1,r);
    }else{
        x->go[3]=x->go[4]=1;
    }
    return x;
}
#define hehe(a,b) (x->lc->go[a]&&x->rc->go[b])
void upda(node*x){
    int m=x->lc->r;
    x->go[1]=((hehe(1,4)&&way[2][m][4])||(hehe(3,1)&&way[1][m][4]));
    x->go[2]=((hehe(4,2)&&way[2][m][4])||(hehe(2,3)&&way[1][m][4]));
    x->go[3]=((hehe(1,2)&&way[2][m][4])||(hehe(3,3)&&way[1][m][4]));
    x->go[4]=((hehe(4,4)&&way[2][m][4])||(hehe(2,1)&&way[1][m][4]));
    x->go[5]=(x->lc->go[5]||(x->rc->go[5]&&x->lc->go[3]&&x->lc->go[4]&&way[2][m][4]&&way[1][m][4]));
    x->go[6]=(x->rc->go[6]||(x->lc->go[6]&&x->rc->go[3]&&x->rc->go[4]&&way[2][m][4]&&way[1][m][4]));
}
void update(node*x,int p){
    if(x->l==x->r){
        x->go[1]=x->go[2]=x->go[5]=x->go[6]=way[1][x->l][2];
        x->go[3]=x->go[4]=1;
    }else{
        if(p<=x->lc->r)update(x->lc,p);
        else update(x->rc,p);
        upda(x);
    }
}
node*rt;
vector<node*>ans;
void query(node*x,int l,int r){
    //pf("[%d,%d]",l,r);
    if(l<=x->l&&r>=x->r)ans.push_back(x);
    else{
        int m=(x->l+x->r)/2;
        if(l<=m)query(x->lc,l,r);
        if(r>m)query(x->rc,l,r);
    }
}
node*get(int l,int r){
    ans.clear();
    query(rt,l,r);
    while(ans.size()>1){
        node*t=new node(0,0);
        t->lc=ans[ans.size()-2];t->rc=ans[ans.size()-1];
        t->l=t->lc->l;t->r=t->rc->r;
        upda(t);
        ans.pop_back();ans.pop_back();
        ans.push_back(t);
    }
    return ans.front();
}
void pnode(node*x){
    pf("[%d,%d:%d%d%d%d%d%d]\n",x->l,x->r,x->go[1],
            x->go[2],x->go[3],x->go[4],x->go[5],x->go[6]);
} 
void print(node*x){
    if(x){
        pf("[%d,%d:%d%d%d%d%d%d]\n",x->l,x->r,x->go[1],
            x->go[2],x->go[3],x->go[4],x->go[5],x->go[6]);
        print(x->lc);
        print(x->rc);
        if(x==rt)pf("\n");
    }
}
int main(){
    int n;sf("%d",&n);
    rt=build(1,n);
    while(true){
        char op[11];int u,v,w,x;
        sf("%s%d%d%d%d",op,&u,&v,&w,&x);
        if(op[0]=='O'){
            if(u==w){
                if(v>x)swap(v,x);
                way[u][v][4]=1;
                way[w][x][3]=1;
            }else{
                if(u>w)swap(u,w);
                way[u][v][2]=1;
                way[w][x][1]=1;
            }
            update(rt,v);
            update(rt,x);
        }else if(op[0]=='A'){
            int orz=0;
            int r1=u,c1=v,r2=w,c2=x;
            if(c1>c2)swap(c1,c2),swap(r1,r2);
            node*l=(c1-1)?get(1,c1-1):0,*m=get(c1,c2),*r=(c2==n)?0:get(c2+1,n);
            //pnode(l);pnode(m);pnode(r);
            if(r1==1&&r2==1){
                if(m->go[3])orz=1;
                if(l&&r&&way[1][c1][3]&&way[1][c2][4]&&l->go[6]&&r->go[5]&&
                    way[2][c1][3]&&way[2][c2][4]&&m->go[4])
                    orz=1;
                if(l&&way[1][c1][3]&&l->go[6]&&way[2][c1][3]&&m->go[2])
                    orz=1;
                if(r&&way[1][c2][4]&&r->go[5]&&way[2][c2][4]&&m->go[1])
                    orz=1;
            }else if(r1==2&&r2==2){
                if(m->go[4])orz=1;
                //pf("[%d]\n",orz);
                if(l&&r&&way[1][c1][3]&&way[1][c2][4]&&l->go[6]&&r->go[5]&&
                    way[2][c1][3]&&way[2][c2][4]&&m->go[3])
                    orz=1;
                //pf("[%d]\n",orz);
                if(l&&way[1][c1][3]&&l->go[6]&&way[2][c1][3]&&m->go[1])
                    orz=1;
                //pf("[%d]\n",orz);
                if(r&&way[1][c2][4]&&r->go[5]&&way[2][c2][4]&&m->go[2])
                    orz=1;
                //pf("[%d]\n",orz);
            }else if(r1==1&&r2==2){
                if(m->go[1])orz=1;
                if(l&&way[1][c1][3]&&way[2][c1][3]&&l->go[6]&&m->go[4])
                    orz=1;
                if(r&&way[1][c2][4]&&way[2][c2][4]&&r->go[5]&&m->go[3])
                    orz=1;
            }else{//r1=2,r2=1
                if(m->go[2])orz=1;
                if(l&&way[1][c1][3]&&way[2][c1][3]&&l->go[6]&&m->go[3])
                    orz=1;
                if(r&&way[1][c2][4]&&way[2][c2][4]&&r->go[5]&&m->go[4])
                    orz=1;
            }
            pf("%s\n",orz?"Y":"N");
        }else if(op[0]=='C'){
            if(u==w){
                if(v>x)swap(v,x);
                way[u][v][4]=0;
                way[w][x][3]=0;
            }else{
                if(u>w)swap(u,w);
                way[u][v][2]=0;
                way[w][x][1]=0;
            }
            update(rt,v);
            update(rt,x);
        }else break;
        //print(rt);
    }//ps;
    return 0;
}
