#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	int T;cin>>T;
	while(T--){
		ll n,k;
		cin>>n>>k;
		static ll a[100010];
		for(int i = 1;i<=n;++i)
			cin>>a[i];
		ll nowuse = 0;
		++nowuse;
		ll nowwehave = k;
		for(int i = 1;i<=n;++i){
			if(nowwehave>a[i]){
				nowwehave -= a[i];
				--nowwehave;
				if(nowwehave==0){
					++nowuse;
					nowwehave = k;
				}
			}
			else if(nowwehave==a[i]){
				++nowuse;
				nowwehave = k;
			}
			else{
				a[i] -= nowwehave;
				nowuse += a[i]/k;
				a[i] %= k;
				if(a[i]==0){
					++nowuse;
					nowwehave = k;
				}
				else{
					++nowuse;
					nowwehave = k;
					nowwehave -= a[i];
					--nowwehave;
					if(nowwehave==0){
						++nowuse;
						nowwehave = k;
					}
				}
			}
		}
		if(nowwehave==k)
			--nowuse;
		cout<<nowuse<<endl;
	}
	return 0;
}