#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>
#include<cstring>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
char str[500010];int len;
unsigned pw[500010],hs[500010],p=29;
unsigned get(int l,int r){return hs[r]-hs[l-1]*pw[r-l+1];}
bool cmp(int a,int b){
    int d=min(len*2-a,len*2-b);
    if(get(a,a+d)==get(b,b+d))return a>b;
    if(str[a]!=str[b])return str[a]<str[b];
    int l=0,r=d;
    while(l+1<r){
        int m=((l+r)>>1);
        if(get(a,a+m)==get(b,b+m))
            l=m;
        else r=m;
        //pf("[%d,%d]",l,r);
    }
    return str[a+r]<str[b+r];
}
int tmp[500010];
int main(){
    sf("%s",str+1);len=strlen(str+1);
    lp(i,len+1,len+len)str[i]=str[i-len];
    pw[0]=1;lp(i,1,len+len)pw[i]=pw[i-1]*p;
    lp(i,1,len+len)hs[i]=hs[i-1]*p+unsigned(str[i]);
    lp(i,1,len+len)tmp[i]=i;
    //pf("[%d]",cmp(4,1));ps;
    sort(tmp+1,tmp+len+len+1,cmp);
    lp(i,1,len+len){
        if(tmp[i]<=len){
            //pf("[%d]",tmp[i]);
            pf("%c",str[tmp[i]+len-1]);
        }
    }
    pf("\n");
    //ps;
    return 0;
}
