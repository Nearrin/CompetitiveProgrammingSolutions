#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;


#include<algorithm>
using namespace std;
const int N=300010,M=26;
struct PT{
    int n,m,nxt[N+3][M],fail[N+3],cnt[N+3],hei[N+3],len[N+3],str[N+1],strl,lst,nds;
    PT(int _n,int _m):
        n(_n),m(_m),strl(0),lst(1),nds(0){
        newnode(-2);
        fill(nxt[0],nxt[0]+M,2);
        newnode(-1);
        fail[1]=0;
        newnode(0);
        fail[2]=1;
        str[0]=-1;
    }
    int newnode(int _l){
        fill(nxt[nds],nxt[nds]+M,-1);
        cnt[nds]=0;
        hei[nds]=0;
        len[nds]=_l;
        return nds++;
    }
    int getfail(int x){
        while(x&&str[strl-len[x]-1]!=str[strl])
            x=fail[x];
        return x;
    }
    void add(int c){
        str[++strl]=c;
        int p=getfail(lst);
        if(nxt[p][c]==-1){
            int np=newnode(len[p]+2);
            fail[np]=nxt[getfail(fail[p])][c];
            nxt[p][c]=np;
            hei[np]=hei[fail[np]]+1;
        }
        ++cnt[lst=nxt[p][c]];
    }
    void count(){
        for(int i=nds-1;i>=1;--i)
            cnt[fail[i]]+=cnt[i];
    }
};

int main(){
    static char s[300010];
    scanf("%s",s+1);
    int l=strlen(s+1);
    PT*pt=new PT(l,26);
    for(int i=1;i<=l;++i)
        pt->add(s[i]-'a');
    pt->count();
    long long ans=0;
    for(int i=3;i<=pt->nds;++i){
        ans=max(ans,((long long)pt->cnt[i])*pt->len[i]);
    }
    cout<<ans<<endl;
    return 0;
}
