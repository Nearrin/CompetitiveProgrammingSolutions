#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
#include<utility>
#include<queue>
using namespace std;
namespace sam{
    const int N=100000,L=2;
    int pr[N*2+10],ln[N*2+10],tr[N*2+10][L+10],nw;
    int ct[N*2+10],ps[N*2+10];
    int make(){++nw;return nw;}
    void init(){nw=0;make();}
    int add(int c,int p){
        if(tr[p][c]){
            int q=tr[p][c];
            if(ln[q]==ln[p]+1)return q;
            else{
                int np=make();ln[np]=ln[p]+1;pr[np]=pr[q];
                copy(tr[q],tr[q]+L,tr[np]);pr[q]=np;
                for(;p&&tr[p][c]==q;p=pr[p])tr[p][c]=np;
                return np;
            }
        }else{
            int np=make();ln[np]=ln[p]+1;
            for(;p&&!tr[p][c];p=pr[p])tr[p][c]=np;
            if(!p)pr[np]=1;
            else{
                int q=tr[p][c];
                if(ln[q]==ln[p]+1)pr[np]=q;
                else{
                    int nq=make();ln[nq]=ln[p]+1;pr[nq]=pr[q];
                    copy(tr[q],tr[q]+L,tr[nq]);pr[q]=pr[np]=nq;
                    for(;p&&tr[p][c]==q;p=pr[p])tr[p][c]=nq;
                }
            }
            return np;
        }
    }
    bool cmp(int x,int y){return ln[x]>ln[y];}
    int ch[10010][2];
    void dfs(int u){
        for(int i=0;i<2;++i){
            if(ch[u][i]&&ct[ch[u][i]]>1){
                for(int j=1;j<=ln[ch[u][i]]-ln[u];++j)
                    printf("%d\n",ct[ch[u][i]]);
                dfs(ch[u][i]);
            }
        }
    }
    void run(){
        int len;static char str[3010];
        scanf("%d%s",&len,str+1);
        reverse(str+1,str+len+1);
        init();int myu=1;int couter=1;
        for(char*p=str+1;*p;++p)
            myu=add(*p-'0',myu),ct[myu]=1,ps[myu]=couter++;
        static int buff[10010];
        for(int i=1;i<=nw;++i)buff[i]=i;
        sort(buff+1,buff+nw+1,cmp);
        for(int i=1;i<=nw;++i){
            int u=buff[i];
            ct[pr[u]]+=ct[u];
            ps[pr[u]]=ps[u];
            char c=str[ps[u]-ln[pr[u]]]-'0';
            ch[pr[u]][c]=u;
        }
        dfs(1);
    }
}
int main(){
    sam::run();
    //for(;;);
    return 0;
} 
