#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
ll cnt(ll x,ll d){
	ll r = 0;
	while(x%d==0){
		x /= d;
		++r;
	}
	return r;
}
int main(){
	ios::sync_with_stdio(false);
	int n;cin>>n;
	for(int i = 1;i<=n;++i){
		ll t;
		cin>>t;
		ll c2 = cnt(t,2),c5 = cnt(t,5);
		while(c5>c2){
			t *= 4;
			c2 += 2;
		}
		cout<<t<<endl;
	}

	return 0;
}