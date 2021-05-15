#include<cstdio>
#include<algorithm>
#include<vector> 
#include<cstring>
#include<queue>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
vector<char>gob;
vector<int>usa;
namespace acm{
    int ch[1000010][26],fa[1000010],cnt[1000010],nw=1;
    char tmp[1000010];
    vector<int>vfs;
    void ins(){
        sf("%s",tmp+1);
        int len=strlen(tmp+1);int u=1;
        for(int i=1;i<=len;++i){
            gob.push_back(tmp[i]-'a');
            if(!ch[u][tmp[i]-'a'])
                ch[u][tmp[i]-'a']=++nw;
            u=ch[u][tmp[i]-'a'];
        }
        gob.push_back(60);
        usa.push_back(u);
    }
    void bud(){
        queue<int>qu;
        lp(i,0,25)if(!ch[1][i])ch[1][i]=1;
        else fa[ch[1][i]]=1,qu.push(ch[1][i]);
        while(!qu.empty()){
            int u=qu.front();qu.pop();vfs.push_back(u);
            lp(i,0,25)if(!ch[u][i])ch[u][i]=ch[fa[u]][i];
            else{
                fa[ch[u][i]]=ch[fa[u]][i];
                qu.push(ch[u][i]);
            }
        }
    }
    void run(){
        for(int i=0,u=1;i<gob.size();++i){
            if(gob[i]==60){u=1;continue;}
            u=ch[u][gob[i]];
            ++cnt[u];
        }
        //lp(i,1,nw)pf("[%d]",cnt[i]);pf("\n");
        rp(i,int(vfs.size()-1),0){
            int u=vfs[i];
            cnt[fa[u]]+=cnt[u];
        }
        //lp(i,1,nw)pf("[%d]",cnt[i]);
        lp(i,0,int(usa.size()-1))
            pf("%d\n",cnt[usa[i]]);
    }
}
int main(){
    int n;sf("%d",&n);
    lp(i,1,n)acm::ins();
    acm::bud();
    acm::run();
    //ps;
    return 0; 
} 
