#include<cstdio>
#include<algorithm>
using namespace std;
int isp[10000010],pri[10000010],mui[10000010],ggg[10000010];
void precalc(){
    mui[1]=1;ggg[1]=0;
    for(int i=2;i<=10000000;++i){
        if(!isp[i]){
            pri[++pri[0]]=i;
            mui[i]=-1;
            ggg[i]=1;
        }
        for(int j=1;j<=pri[0]&&(long long)(pri[j])*i<=10000000;++j){
            isp[i*pri[j]]=1;
            if(i%pri[j]==0){
                mui[i*pri[j]]=0;
                ggg[i*pri[j]]=mui[i];
                break;
            }else{
                mui[i*pri[j]]=-mui[i];
                ggg[i*pri[j]]=mui[i]-ggg[i];
            }
        }
    }
    for(int i=1;i<=10000000;++i)
        ggg[i]+=ggg[i-1];
}
int main(){
    precalc();
    int T;scanf("%d",&T);
    for(int i=1;i<=T;++i){
        int n,m;scanf("%d%d",&n,&m);
        long long ans=0;
        if(n>m)swap(n,m);
        for(int i=1;i<=n;++i){
            int nxt=min(n/(n/i),m/(m/i));
            ans+=(long long)((n/i))*(m/i)*(ggg[nxt]-ggg[i-1]);
            i=nxt;
        }
        printf("%lld\n",ans);
    } 
    //for(;;);
    return 0;
} 
