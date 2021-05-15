#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
char str[60010];int len;
namespace sam{
    int pr[120010],ln[120010],tr[120010][26],lst=1,nw=1;
    int vo[120010],lf[120010],ch[120010][26];
    void add(int c,int d){
        int p=lst,np=++nw;ln[np]=ln[p]+1;lst=np;vo[np]=d;lf[np]=d;
        for(;p&&!tr[p][c];p=pr[p])tr[p][c]=np;
        if(!p)pr[np]=1;
        else{
            int q=tr[p][c];
            if(ln[q]==ln[p]+1)pr[np]=q;
            else{
                int nq=++nw;ln[nq]=ln[p]+1;pr[nq]=pr[q];
                lp(i,0,25)tr[nq][i]=tr[q][i];
                pr[q]=pr[np]=nq;
                for(;p&&tr[p][c]==q;p=pr[p])tr[p][c]=nq;
            }
        }
    }
    int sa[60010],rk[60010];
    bool cmp(int x,int y){return ln[x]<ln[y];} 
    void bud(){
        static int tmp[120010];
        static int cc[60010];
        lp(i,1,nw)++cc[ln[i]];
        lp(i,1,len)cc[i]+=cc[i-1];
        lp(i,1,nw)tmp[cc[ln[i]]--]=i;
        rp(i,nw,1){
            int u=tmp[i];
            vo[pr[u]]=vo[u];
            ch[pr[u]][str[vo[u]-ln[pr[u]]]-'A']=u;
        }
    }
    void dfs(){
        stack<int>stk;stk.push(1);
        while(!stk.empty()){
            int u=stk.top();stk.pop();
            if(lf[u])sa[++sa[0]]=lf[u];
            rp(i,25,0)if(ch[u][i])stk.push(ch[u][i]);
        }
        lp(i,1,len)rk[sa[i]]=i;
    }
}
int main(){
    sf("%d",&len);
    lp(i,1,len){
        char tmp[11];sf("%s",tmp);
        str[i]=tmp[0];
    }
    lp(i,1,len)str[len+i]=str[len-i+1];len*=2;
    lp(i,1,len)sam::add(str[i]-'A',i);
    sam::bud();
    sam::dfs();
    int left=1,right=len/2;
    lp(i,1,len/2){
        if(sam::rk[len-left+1]<sam::rk[right])
            pf("%c",str[left]),++left;
        else
            pf("%c",str[right]),--right;
        if(i%80==0||i==len/2)pf("\n");
    }
    //ps;
    return 0; 
}
