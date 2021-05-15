#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,v) for(int i=0;i<v.size();++i)
#define wp(i,v) for(int i=int(v.size()-1);i>=0;--i)
typedef long long ll;
using namespace std;
#include<cstring>
#include<tr1/unordered_map>
#include<map>
char str[500010];
namespace sam{
    const int N=500000*2+10;
    map<int,int> tr[N];
    int ln[N],pr[N],nw=1,lst=1,is[N],po[N];
    void add(int c,int u){
        int p=lst,np=++nw;ln[np]=ln[p]+1;lst=np;is[np]=1;po[np]=u;
        for(;p&&!tr[p][c];p=pr[p])tr[p][c]=np;
        if(!p)pr[np]=1;
        else{
            int q=tr[p][c];
            if(ln[q]==ln[p]+1)pr[np]=q;
            else{
                int nq=++nw;ln[nq]=ln[p]+1;pr[nq]=pr[q];
                tr[nq]=tr[q];
                pr[np]=pr[q]=nq;
                for(;p&&tr[p][c]==q;p=pr[p])tr[p][c]=nq;
            }
        }
    }
    int ch[N][26];
    int cnt[N];ll sum[N];
    ll calc(){
        ll ret=0;
        static int tmp[N],ccc[N];
        lp(i,1,nw)++ccc[ln[i]];
        lp(i,1,nw)ccc[i]+=ccc[i-1];
        lp(i,1,nw)tmp[ccc[ln[i]]--]=i;
        rp(i,nw,1){
            int u=tmp[i];
            po[pr[u]]=po[u];
            ch[pr[u]][str[po[u]-ln[pr[u]]]-'a']=u;
            cnt[u]+=is[u];
            cnt[pr[u]]+=cnt[u];
            sum[pr[u]]+=sum[u]+ll(ln[u]-ln[pr[u]])*cnt[u];
        }
        lp(i,1,nw){
            static ll tsum[26],tcnt[26];
            lp(j,0,25)if(ch[i][j]){
                tcnt[j]=cnt[ch[i][j]];
                tsum[j]=sum[ch[i][j]]+ll(ln[ch[i][j]]-ln[i])*cnt[ch[i][j]];
            }else tcnt[j]=tsum[j]=0;
            static ll tsump[26],tcntp[26];
            lp(j,0,25)tsump[j]=tcntp[j]=0;
            tsump[0]=tsum[0];
            tcntp[0]=tcnt[0];
            lp(j,1,25)tsump[j]+=tsump[j-1]+tsum[j],tcntp[j]+=tcntp[j-1]+tcnt[j];
            ll del=0;
            lp(j,1,25){
                del+=tsum[j]*tcntp[j-1]+tsump[j-1]*tcnt[j];
            }
            if(is[i]){
                del+=sum[i];
            }
            ret+=del;
        }
        return ret;
    }
}
int main(){
    gets(str+1);int len=strlen(str+1);
    reverse(str+1,str+len+1);
    lp(i,1,len)sam::add(str[i]-'a',i);
    pf("%lld\n",sam::calc());
    return 0;
}
