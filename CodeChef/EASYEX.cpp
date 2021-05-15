#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
typedef long long ll;
ll M = 2003;
ll pow(ll a,ll b){
	ll r = 1;
	while(b){
		if(b&1)r = r*a%M;
		a = a*a%M;
		b >>= 1;
	}
	return r;
}
ll inv(ll a){
	return pow(a,M-2);
}
ll calc(ll N,ll K,ll L){
	if(N<L)
		return 0;
	ll t1 = inv(pow(K,L));
	ll t2 = 1;
	for(int n = 0;n<=L-1;++n)
		t2 = t2*(N-n)%M;
	return t1*t2%M;
}
int main(){
	int T;cin>>T;
	while(T--){
		ll N,K,L,F;
		cin>>N>>K>>L>>F;
		cout<<calc(N,K,L)<<endl;
	}
	return 0;
}