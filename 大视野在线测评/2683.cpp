#include<iostream>

#include<cstdio>



#include<algorithm>
using namespace std;
const int N=500000;
struct BIT{
    int n,a[N+1];
    BIT(int _n):
        n(_n){
        fill(a+1,a+n+1,0);
    }
    void add(int i,int d){
        for(;i<=n;i+=i&-i)
            a[i]+=d;
    }
    int ask(int i){
        int r=0;
        for(;i;i-=i&-i)
            r+=a[i];
        return r;
    }
};
struct data{
    char typ;

    int x,y,delta;
        int id,t;

};
bool operator<(data a,data b){
    return a.x<b.x;
}

int n;
data ds[200000*4+10];
int dss;
int ans[200000+10];
int qid;
BIT*bit;
void work(int dsl,int dsr){
    if(dsl==dsr){
        return;
    }else{
        int dsm=(dsl+dsr)/2;
        work(dsl,dsm);
        work(dsm+1,dsr);
        static data op[200000*4+10];
        int ops=0;
        static data qu[200000*4+10];
        int qus=0;
        for(int i=dsl;i<=dsm;++i)
            if(ds[i].typ=='A')
                op[++ops]=ds[i];
        for(int i=dsm+1;i<=dsr;++i)
            if(ds[i].typ=='Q')
                qu[++qus]=ds[i];
        sort(op+1,op+ops+1);
        sort(qu+1,qu+qus+1);
        int ptr=1;
        for(int i=1;i<=qus;++i){
            while(ptr<=ops&&op[ptr].x<=qu[i].x){
                bit->add(op[ptr].y,op[ptr].delta);
                ++ptr;
            }
            ans[qu[i].id]+=qu[i].t*bit->ask(qu[i].y);
        }
        ptr=1;
        for(int i=1;i<=qus;++i){
            while(ptr<=ops&&op[ptr].x<=qu[i].x){
                bit->add(op[ptr].y,-op[ptr].delta);
                ++ptr;
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    bit=new BIT(n);
    for(int i=1;;++i){
        int t;scanf("%d",&t);
        data tmp;
        if(t==1){
            int x,y,d;
            scanf("%d%d%d",&x,&y,&d);
            tmp.typ='A';
            tmp.x=x;
            tmp.y=y;
            tmp.delta=d;
            ds[++dss]=tmp;
        }else if(t==2){
            ++qid;
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            tmp.typ='Q';
            tmp.x=x2;
            tmp.y=y2;
            tmp.t=1;
            tmp.id=qid;
             ds[++dss]=tmp;

             if(x1!=1){
                 tmp.typ='Q';
                 tmp.x=x1-1;
                 tmp.y=y2;
                 tmp.t=-1;
                 tmp.id=qid;
                  ds[++dss]=tmp;
             }
             if(y1!=1){
                 tmp.typ='Q';
                 tmp.x=x2;
                 tmp.y=y1-1;
                 tmp.t=-1;
                 tmp.id=qid;
                  ds[++dss]=tmp;
             }
             if(x1!=1&&y1!=1){
                 tmp.typ='Q';
                 tmp.x=x1-1;
                 tmp.y=y1-1;
                 tmp.t=1;
                 tmp.id=qid;
                  ds[++dss]=tmp;
             }
        }else{
            break;
        }
    }
    work(1,dss);
    for(int i=1;i<=qid;++i)
        printf("%d\n",ans[i]);
    return 0;
}
/*

16
1 2 3 3
2 1 1 3 3
1 2 2 2
2 2 2 3 4
1 2 3 3
2 1 1 3 3
1 2 2 2
2 2 2 3 4
1 2 3 3
2 1 1 3 3
1 2 2 2
2 2 2 3 4
1 2 3 3
2 1 1 3 3
1 2 2 2
2 2 2 3 4
*/
