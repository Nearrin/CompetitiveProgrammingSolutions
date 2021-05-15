#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
static char N[1210];int NL;
int ans=0;
namespace acm{
    const int L=2000,M=10;const char W='0';
    int ch[L+10][M+10],fa[L+10],tg[L+10],nw=1;
    void insert(char*s){
        int u=1;for(;*s;++s){
            if(!ch[u][*s-W])ch[u][*s-W]=++nw;
            u=ch[u][*s-W];
        }
        ++tg[u];
    }
    void build(){
        queue<int>qu;
        for(int i=0;i<M;++i)
            if(!ch[1][i])ch[1][i]=1;
            else fa[ch[1][i]]=1,qu.push(ch[1][i]);
        while(!qu.empty()){
            int u=qu.front();qu.pop();
            if(tg[fa[u]])tg[u]=1;//!
            for(int i=0;i<M;++i)
                if(!ch[u][i])ch[u][i]=ch[fa[u]][i];
                else fa[ch[u][i]]=ch[fa[u]][i],qu.push(ch[u][i]);
        }
    }
    void test(){
        while(true){
            static char s[1010];
            scanf("%s",s);
            int ty=1;
            char*pt=s;
            for(int u=1;*pt;++pt){
                u=ch[u][*pt-'0'];
                if(tg[u])ty=0;
            }
            if(ty==1)printf("No\n");
            else printf("Yes\n");
        }
    }
    int dp[1210][1510];
    void rundp(){
        for(int i=1;i<=nw;++i)
            dp[0][i]=(tg[i]==1?0:1);
        for(int i=1;i<=1205;++i){
            for(int j=1;j<=nw;++j){
                if(tg[j])continue;
                for(int k=0;k<M;++k){
                    dp[i][j]+=dp[i-1][ch[j][k]];
                    dp[i][j]%=1000000007;
                }
            }
        }
    }
    void run_same(){
        int u=1;
        for(int i=1;i<=NL;++i){
            u=ch[u][N[i]-'0'];
            if(tg[u])return;
        }
        ++ans;
        ans%=1000000007;
    }
    void run_short(){
        for(int i=1;i<NL;++i){
            for(int w=1;w<M;++w){
                ans+=dp[i-1][ch[1][w]];
                ans%=1000000007;
            }
        }
    }
    void run_other(){
        int u=1;
        for(int i=1;i<=NL;++i){
            for(int w=0;w<N[i]-'0';++w){
                if(i==1&&w==0)continue;
                ans+=dp[NL-i][ch[u][w]];
                ans%=1000000007;
            }
            u=ch[u][N[i]-'0'];
            if(tg[u])return;
        }
    }
}
int main(){
    scanf("%s",N+1);NL=strlen(N+1);
    int m;scanf("%d",&m);
    for(int i=1;i<=m;++i){
        static char S[1510];
        scanf("%s",S+1);
        acm::insert(S+1);
    }
    acm::build();
    //acm::test();
    acm::rundp();
    acm::run_same();
    //printf("%d\n",ans);
    acm::run_short();
    //printf("%d\n",ans);
    acm::run_other();
    printf("%d\n",ans);
    //for(;;);
    return 0;
}
