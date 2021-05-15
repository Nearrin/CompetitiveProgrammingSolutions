#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	int T;cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		static double p[21][10010];
		static int haszero[21];
		for(int i = 1;i<=n;++i)
			haszero[i] = 0;
		int zeronum = 0;
		for(int i = 1;i<=n;++i){
			for(int j = 1;j<=m;++j){
				cin>>p[i][j];
				if(fabs(p[i][j])<1e-8)
					haszero[i] = 1;
			}
			zeronum += haszero[i];
		}
		if(zeronum==n||haszero[1]){
			printf("%.6lf\n",0.0);
		}
		else{
			static double u[21];
			double sum = 0;
			for(int i = 1;i<=n;++i){
				u[i] = 1;
				for(int j = 1;j<=m;++j)
					u[i] *= p[i][j]/p[1][j];
				sum += u[i];
			}
			printf("%.6lf\n",1/sum);
		}
	}
	return 0;
}