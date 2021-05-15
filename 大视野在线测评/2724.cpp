#include<cstdio>
#include<algorithm>
#include<set>
#include<cmath>
#define sf scanf
#define pf printf
#define fr feopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int a[40010],n,org[40010],m;
void init(){
    sf("%d%d",&n,&m);
    lp(i,1,n)sf("%d",&a[i]);
}
void lisa(){//checked
    static int b[40010];
    lp(i,1,n)b[i]=a[i],org[i]=a[i];
    sort(b+1,b+n+1);
    int c=unique(b+1,b+n+1)-b-1;
    lp(i,1,n)a[i]=lower_bound(b+1,b+c+1,a[i])-b;
    //lp(i,1,n)pf("[%d]",a[i]);
}
struct block{
    int c[40010],k,k_bac;
    block(){fill(c+1,c+n+1,0);k=-1;}
    void save(){k_bac=k;}
    void load(){k=k_bac;}
    void add(int x){
        ++c[a[x]];
        if(k==-1||c[a[x]]>c[a[k]]||(c[a[x]]==c[a[k]]&&a[x]<a[k]))k=x;
    }
    void del(int x){
        --c[a[x]];
    }
}bks[41][41],tmp;
int bg[2010],ed[2010],bs;
int bel[40010];
void make(){//checked
    int siz=max(1,int(pow(double(n),2.0/3.0)));
    int re=0;
    lp(i,1,n){
        if(!re){
            ++bs,re=siz;
            bg[bs]=i;
        }else --re;
        bel[i]=bs;
        ed[bs]=i;
    }
    lp(i,1,bs)lp(j,i,bs){
        lp(k,bg[i],ed[j]){
            bks[i][j].add(k);
        }
        //pf("[%d]",org[bks[i][j].k]);
    }
    //lp(i,1,bs)pf("[%d,%d]",bg[i],ed[i]);pf("\n");
    //lp(i,1,n)pf("[%d]",bel[i]);
}
int query(int l,int r){
    if(bel[l]==bel[r]){
        tmp.save();
        lp(i,l,r)tmp.add(i);
        int t=org[tmp.k];
        lp(i,l,r)tmp.del(i);
        tmp.load();
        return t;
    }else{
        int ll=l,rr=r;
        while(bel[ll-1]==bel[ll])++ll;
        while(bel[rr+1]==bel[rr])--rr;
        int uu=bel[ll],ww=bel[rr];
        //pf("[%d,%d]",l,r);
        block&bk=uu>ww?tmp:bks[uu][ww];
        bk.save();
        lp(i,l,ll-1)bk.add(i);
        lp(i,rr+1,r)bk.add(i);
        int t=org[bk.k];
        lp(i,l,ll-1)bk.del(i);
        lp(i,rr+1,r)bk.del(i);
        bk.load();
        return t;
    }
}
void answ(){
    int lst=0;
    lp(i,1,m){
        int l,r;sf("%d%d",&l,&r);
        l=(l+lst-1)%n+1,r=(r+lst-1)%n+1;
        if(l>r)swap(l,r);
        pf("%d\n",lst=query(l,r));
    }
}
int main(){
    init();
    lisa();
    make();
    answ();
    //ps;
    return 0;
}
