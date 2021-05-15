#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int C[51][51],N;
int used[51][51],posnow;
void read_input(){
	scanf("%d",&N);
	for(int i = 1;i<=N;++i)
		for(int j = 1;j<=N;++j)
			scanf("%d",&C[i][j]);
	for(int i = 1;i<=N;++i)
		used[i][i] = 1;
}

int maxweist,maxweied;
void getmaxweistranded(){
	for(int i = 1;i<=N;++i)
		for(int j = 1;j<=N;++j)
		if(C[i][j]==N*(N-1))
			maxweist = i,maxweied = j;
}
int firstansst,firstansed;
void makemove(int x){
	used[posnow][x] = 1;
	posnow = x;
}
int maxweiedsecondmax;
void getmaxweiedsecondmax(){
	maxweiedsecondmax = -1;
	for(int i = 1;i<=N;++i)
		maxweiedsecondmax = max(maxweiedsecondmax,C[maxweied][i]);
}
bool checkcanmove(){
	for(int i = 1;i<=N;++i)
		if(!used[posnow][i])
		return true;
	return false;
}
int mymaxmove;
void getmaxmove(){
	int wei = -1;
	for(int i = 1;i<=N;++i)
		if(!used[posnow][i]){
			if(wei<C[posnow][i]){
				wei=C[posnow][i];
				mymaxmove = i;
			}
		}
}
namespace MAX{
	void run(){
		while(true){
			int mxto = -1,mxwei = -int(~0u>>1);
			for(int i = 1;i<=N;++i)
				if(!used[posnow][i]){

					int shou = C[posnow][i];
					int preposnow = posnow;
					makemove(i);
					if(checkcanmove()){
						getmaxmove();
						shou -= C[posnow][mymaxmove];
					}
					posnow = preposnow;
					used[posnow][i] = 0;
					if(shou>mxwei){
						mxwei = shou;
						mxto = i;
					}

				}
			cout<<posnow<<" "<<mxto<<endl;
			makemove(mxto);
			if(!checkcanmove())
				return;
			int u,v;
			cin>>u>>v;
			makemove(v);
			if(!checkcanmove())
				return;
		}
	}
}
namespace RANDOM{
	void run(){
		while(true){
			int mxto = -1,mxwei = -1;
			for(int i = 1;i<=N;++i)
				if(!used[posnow][i]){
					if(C[posnow][i]>mxwei){
						mxwei = C[posnow][i];
						mxto = i;
					}
				}
			cout<<posnow<<" "<<mxto<<endl;
			makemove(mxto);
			if(!checkcanmove())
				return;
			int u,v;
			cin>>u>>v;
			makemove(v);
			if(!checkcanmove())
				return;
		}
	}
}
int main(){
	read_input();
	getmaxweistranded();
	posnow = maxweist;
	cout<<maxweist<<" "<<maxweied<<endl;
	makemove(maxweied);
	getmaxweiedsecondmax();
	cin>>firstansst>>firstansed;
	makemove(firstansed);
	if(C[firstansst][firstansed]==maxweiedsecondmax){
		MAX::run();
	}
	else{
		RANDOM::run();
	}
	return 0;
}