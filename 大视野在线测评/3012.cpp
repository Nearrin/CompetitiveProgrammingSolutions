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
#include<map>
#include<queue>
int n;char tmp[300010];
vector<char>str[30010];
int can[30010];
struct node{
	node(){fill(ch,ch+26,(node*)0);id=0;}
	node*ch[26];int id;
}*rt=new node();
namespace graph{
	map<int,int>to[26];
	void add(int u,int v){
		++to[u][v];
	}
	void rem(int u,int v){
		--to[u][v];
	}
	bool chk(){
		queue<int>qu;
		static int ind[26];
		lp(i,0,25)ind[i]=0;
		lp(i,0,25)for(map<int,int>::iterator it=to[i].begin();it!=to[i].end();++it)
			if(it->second)
				++ind[it->first];
		lp(i,0,25)if(ind[i]==0)qu.push(i);
		int cnt=0;
		while(!qu.empty()){
			int u=qu.front();qu.pop();++cnt;
			for(map<int,int>::iterator it=to[u].begin();it!=to[u].end();++it)
				if(it->second)
					if(!--ind[it->first])qu.push(it->first);
		}
		return cnt==26;
	}
}
void dfs(node*x){
	if(x->id){can[x->id]=1;return;}
	lp(i,0,25)if(x->ch[i]){
		lp(j,0,25)if(j!=i&&x->ch[j])graph::add(j,i);
		if(graph::chk())dfs(x->ch[i]);
		lp(j,0,25)if(j!=i&&x->ch[j])graph::rem(j,i);
	}
}
int main(){
	sf("%d",&n);
	lp(i,1,n){
		sf("%s",tmp);
		for(int j=0;tmp[j];++j)
			str[i].pb(tmp[j]);
		node*t=rt;
		for(int j=0;tmp[j];++j){
			if(!t->ch[tmp[j]-'a'])t->ch[tmp[j]-'a']=new node();
			t=t->ch[tmp[j]-'a'];
		}
		t->id=i;
	}
	dfs(rt);
	int ans=0;
	lp(i,1,n)ans+=can[i];
	pf("%d\n",ans);
	lp(i,1,n)if(can[i]){
		vp(j,str[i])pf("%c",str[i][j]);pf("\n");
	}
	return 0;
}
