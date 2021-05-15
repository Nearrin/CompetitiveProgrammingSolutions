#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[100010];
int seg[100010*4];
void buildseg(int x,int l,int r){
	seg[x] = ~0u>>1;
	if(l!=r){
		int m = (l+r)/2;
		buildseg(x*2,l,m);
		buildseg(x*2+1,m+1,r);
	}
}
void cover(int x,int l,int r,int dl,int dr,int d){
	if(dl<=l&&dr>=r){
		seg[x] = min(seg[x],d);
	}
	else{
		int m = (l+r)/2;
		if(dr>m)
			cover(x*2+1,m+1,r,dl,dr,d);
		if(dl<=m)
			cover(x*2,l,m,dl,dr,d);
	}
}
int query(int x,int l,int r,int u){
	if(l==r)
		return seg[x];
	int m = (l+r)/2;
	if(u<=m)
		return min(query(x*2,l,m,u),seg[x]);
	return min(query(x*2+1,m+1,r,u),seg[x]);
}
static int price[100010];
static int value[100010];
ll dp[100010][510];
int main(){
//	ios::sync_with_stdio(false);
	int T;cin>>T;
	while(T--){
		int n,k,m;
		scanf("%d%d%d",&n,&k,&m);
		ll take = 0;
		for(int i = 1;i<=n;++i)
			scanf("%d",a+i),take+=a[i];
		buildseg(1,1,n);
		for(int i = 1;i<=m;++i){
			int l,r,c;
			scanf("%d%d%d",&l,&r,&c);
			cover(1,1,n,l,r,c);
		}
		for(int i = 1;i<=n;++i)
			price[i] = query(1,1,n,i),value[i]=-a[i];
		for(int i = 1;i<=n;++i)
			for(int j = 0;j<=k;++j){
				dp[i][j] = dp[i-1][j];
				if(price[i]<=j)
					dp[i][j] = max(dp[i][j],dp[i-1][j-price[i]]+value[i]);
			}
		ll ans = take+dp[n][k];
		printf("%lld\n",ans);

	}
	return 0;
}