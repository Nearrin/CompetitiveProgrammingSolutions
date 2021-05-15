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
int n,m;vector<int>cnt(110);
void done(int&curid,int&curcnt,int idx){
	if(!curcnt)curid=idx,curcnt=1;
	else if(curid==idx)++curcnt;
	else --curcnt;
}
int calc(vector<int>cnt,int curid,int curcnt){
	sort(cnt.begin()+2,cnt.begin()+m+1);
	while(cnt[m]>0){
		rp(i,m,2){
			done(curid,curcnt,i);
			--cnt[i];
			if(cnt[i-1]<=cnt[i])break;
		}
	}
	lp(i,1,cnt[1])done(curid,curcnt,1);
	return curid==1?curcnt:0;
}
int main(){
	sf("%d%d",&n,&m);int curid=0,curcnt=0;
	lp(i,1,m)sf("%d",&cnt[i]);int ret=calc(cnt,curid,curcnt);
	if(ret==0){
		pf("NO\n");
	}else{
		pf("YES\n%d\n",ret);
		lp(i,1,n){
			int saveid=curid,savecnt=curcnt;
			lp(j,1,m){
				if(cnt[j]==0)continue;
				--cnt[j];
				done(curid,curcnt,j);
				if(calc(cnt,curid,curcnt)==ret){
					pf("%d\n",j);break;
				}
				++cnt[j];
				curid=saveid;
				curcnt=savecnt;
			}
		}
	}
	return 0;
}
