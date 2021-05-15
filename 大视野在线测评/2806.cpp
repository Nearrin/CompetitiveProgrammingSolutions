#include<cstdio>
#include<algorithm>
#include<deque>
#include<cmath>
#define sf scanf
#define pf printf
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
namespace sam{
    int tr[1100010][3],pr[1100010],ln[1100010],nw=1,lst=1;
    void add(int c){
        int p=lst,np=++nw;ln[np]=ln[p]+1;lst=np;
        for(;p&&!tr[p][c];p=pr[p])tr[p][c]=np;
        if(!p)pr[np]=1;
        else{
            int q=tr[p][c];
            if(ln[p]+1==ln[q])pr[np]=q;
            else{
                int nq=++nw;ln[nq]=ln[p]+1;pr[nq]=pr[q];
                copy(tr[q],tr[q]+3,tr[nq]);
                pr[np]=pr[q]=nq;
                for(;p&&tr[p][c]==q;p=pr[p])tr[p][c]=nq;
            }
        }
    }
};
int n,m,len;
char tmp[1100010];
int f[1100010],d[1100010];
int check(int l){
    deque<int> qu;
    lp(i,1,len){
        if(i-l>=0){
            while(!qu.empty()&&f[qu.back()]-qu.back()<=f[i-l]-(i-l))qu.pop_back();
            qu.push_back(i-l);
        }
        while(!qu.empty()&&qu.front()<i-d[i])qu.pop_front();
        f[i]=f[i-1];
        if(!qu.empty())f[i]=max(f[i],i+f[qu.front()]-qu.front());
    }
    return double(f[len])/len>=0.9-1e-10;
}
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,m){
        sf("%s",tmp);
        for(int j=0;tmp[j];++j)
            sam::add(tmp[j]-'0');
        sam::add(2);
    }
    lp(i,1,n){
        sf("%s",tmp+1);
        len=1;while(tmp[len+1])++len;
        int ty=0,now=1;
        lp(i,1,len){
            int c=tmp[i]-'0';
            if(!sam::tr[now][c]){
                while(now&&!sam::tr[now][c])now=sam::pr[now];
                if(!now)now=1,ty=0;
                else ty=sam::ln[now]+1,now=sam::tr[now][c];
            }else now=sam::tr[now][c],++ty;
            d[i]=ty;
        }
        if(!check(1))pf("0\n");
        else{
            int l=1,r=len+1;
            while(l+1<r){
                int m=(l+r)/2;
                if(check(m))l=m;
                else r=m;
            }
            pf("%d\n",l);
        }
    }
    //ps;
    return 0;
}
