#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int ans[10010],as;
struct ques{
    int tp,va,id;
    int lt,rt,kh,wh,now;
}qs[30010];int qz;
int n;
//1:add 2:del 3:ask
void init(){
    static int a[10010];
    int m;sf("%d%d",&n,&m);
    lp(i,1,n){
        sf("%d",&qs[++qz].va);
        a[i]=qs[qz].va;
        qs[qz].tp=1;qs[qz].id=i;
    }
    lp(i,1,m){
        char op[11];sf("%s",op);
        if(op[0]=='C'){
            int u,v;sf("%d%d",&u,&v);
            ++qz;qs[qz].tp=2;qs[qz].va=a[u];qs[qz].id=u;
            ++qz;qs[qz].tp=1;qs[qz].va=v;qs[qz].id=u;
            a[u]=v;
        }else{
            int u,v,w;sf("%d%d%d",&u,&v,&w);
            ++qz;qs[qz].tp=3;qs[qz].lt=u;
            qs[qz].rt=v;qs[qz].kh=w;qs[qz].wh=++as;
            qs[qz].now=0;
        }
    }
}
void print(){
    lp(i,1,as)pf("%d\n",ans[i]);
}
int db[10010];
void add(int i,int d){
    for(;i<=n;i+=i&-i)db[i]+=d;
}
int ask(int i){
    int r=0;
    for(;i;i-=i&-i)r+=db[i];
    return r;
}
void solve(int ql,int qr,int vl,int vr){
    if(ql>qr)return;
    static ques tmp1[30010],tmp3[30010];
    static int tmp2[30010];
    if(vl==vr){
        lp(i,ql,qr)if(qs[i].tp==3)
            ans[qs[i].wh]=vl;
    }else{
        int vm=vl+(vr-vl)/2;
        lp(i,ql,qr){
            if(qs[i].tp==1&&qs[i].va<=vm)
                add(qs[i].id,1);
            else if(qs[i].tp==2&&qs[i].va<=vm)
                add(qs[i].id,-1);
            else if(qs[i].tp==3)tmp2[i]=ask(qs[i].rt)-ask(qs[i].lt-1);
        }
        lp(i,ql,qr){
            if(qs[i].tp==1&&qs[i].va<=vm)
                add(qs[i].id,-1);
            else if(qs[i].tp==2&&qs[i].va<=vm)
                add(qs[i].id,1);
        }
        int t1=0,t3=0;
        lp(i,ql,qr)
            if(qs[i].tp==3){
                if(qs[i].now+tmp2[i]<=qs[i].kh-1){
                    qs[i].now+=tmp2[i];
                    tmp3[++t3]=qs[i];
                }else
                    tmp1[++t1]=qs[i];
            }else{
                if(qs[i].va<=vm)
                    tmp1[++t1]=qs[i];
                else
                    tmp3[++t3]=qs[i];
            }
        lp(i,1,t1)qs[ql+i-1]=tmp1[i];
        lp(i,1,t3)qs[ql+t1+i-1]=tmp3[i];
        solve(ql,ql+t1-1,vl,vm);
        solve(ql+t1,qr,vm+1,vr);
    }
}
int main(){
    init();
    solve(1,qz,0,~0u>>1);
    print();
    //ps;
    return 0;
}
