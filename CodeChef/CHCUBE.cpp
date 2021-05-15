#include<iostream>
#include<string>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		string tmp[11];
		for(int i = 1;i<=6;++i)
			cin>>tmp[i];
		int ff = 0;
		for(int i = 1;i<=2;++i)
			for(int j = 3;j<=4;++j)
			for(int k = 5;k<=6;++k)
			if(tmp[i]==tmp[j]&&tmp[j]==tmp[k])
			++ff;
		if(ff)cout<<"YES"<<endl;
		else cout<<"NO\n";
	}
	return 0;
}