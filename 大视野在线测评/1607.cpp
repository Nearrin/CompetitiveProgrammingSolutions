#include<iostream>
#include<cstdio>
using namespace std;
int n,a[100010],ans[1000010];
int cnt[1000010];
int has[1000010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),has[a[i]]++;
	for(int i=1;i<=1000000;++i)
		if(has[i])
		for(int j=i;j<=1000000;j+=i)
			cnt[j]+=has[i];
	for(int i=1;i<=n;++i)
		printf("%d\n",cnt[a[i]]-1);
	//	for(;;);
	return 0;
}
