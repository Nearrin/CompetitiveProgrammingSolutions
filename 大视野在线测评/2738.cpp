#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
struct query{
    int tp;//1:add 2:ask
    int x,y,va;
    int x1,y1,x2,y2,k,now,idx;
}qs[400010];int qz;
int ans[100010],as;
int n,q;
int lisa[400010],lisas;
void init(){
    sf("%d%d",&n,&q);
    lp(i,1,n)lp(j,1,n){
        ++qz;qs[qz].x=i;qs[qz].y=j;
        qs[qz].tp=1;
        sf("%d",&qs[qz].va);
        lisa[++lisas]=qs[qz].va;
    }
    sort(lisa+1,lisa+lisas+1);
    lisas=unique(lisa+1,lisa+lisas+1)-lisa-1;
    lp(i,1,qz)qs[i].va=lower_bound(lisa+1,lisa+lisas+1,qs[i].va)-lisa;
    lp(i,1,q){
        ++qz;sf("%d%d%d%d%d",&qs[qz].x1,&qs[qz].y1,
            &qs[qz].x2,&qs[qz].y2,&qs[qz].k);
        qs[qz].tp=2;
        qs[qz].now=0;qs[qz].idx=++as;
    }
}
void print(){
    lp(i,1,as)pf("%d\n",lisa[ans[i]]);
}
int db[510][510];
void add(int x,int y,int d){
    for(int i=x;i<=n;i+=i&-i)
        for(int j=y;j<=n;j+=j&-j)
            db[i][j]+=d;
}
int ask(int x,int y){
    int r=0;
    for(int i=x;i;i-=i&-i)
        for(int j=y;j;j-=j&-j)
            r+=db[i][j];
    return r;
}
void solve(int ql,int qr,int vl,int vr){
    if(ql>qr)return;
    if(vl==vr){
        lp(i,ql,qr)ans[qs[i].idx]=vl;
    }else{
        static int dlt[400010];
        int vm=vl+(vr-vl)/2;
        lp(i,ql,qr){
            if(qs[i].tp==1&&qs[i].va<=vm)add(qs[i].x,qs[i].y,1);
            else if(qs[i].tp==2)dlt[i]=ask(qs[i].x2,qs[i].y2)-ask(qs[i].x2,qs[i].y1-1)-
                ask(qs[i].x1-1,qs[i].y2)+ask(qs[i].x1-1,qs[i].y1-1);
        }
        lp(i,ql,qr){
            if(qs[i].tp==1&&qs[i].va<=vm)add(qs[i].x,qs[i].y,-1);
        }
        static query lq[400010],rq[400010];int lqs=0,rqs=0;
        lp(i,ql,qr){
            if(qs[i].tp==1){
                if(qs[i].va<=vm)lq[++lqs]=qs[i];
                else rq[++rqs]=qs[i];
            }else{
                if(qs[i].now+dlt[i]<=qs[i].k-1){
                    qs[i].now+=dlt[i];
                    rq[++rqs]=qs[i];
                }else lq[++lqs]=qs[i];
            }
        }
        lp(i,1,lqs)qs[ql+i-1]=lq[i];
        lp(i,1,rqs)qs[ql+lqs+i-1]=rq[i];
        solve(ql,ql+lqs-1,vl,vm);
        solve(ql+lqs,qr,vm+1,vr);
    }
}
int main(){
    init();
    solve(1,qz,1,lisas);
    print();
    //ps;
    return 0;
}
