#include<cstdio>
using namespace std;
int n,m,f;
char a[1010][1010];
int main(){
	scanf("%d%d%d",&n,&m,&f);
	for(int i=1;i<n;++i)
		a[i][1]='P';
	a[n][1]='G';
	if(m==2){
		for(int i=n;i>1;--i)
			a[i][2]='L';
		a[1][2]='D';
	}else{
		for(int i=1;i<=n;++i){
			if(i==1)a[i][2]='D';
			else if(i==n)a[i][2]='G';
			else if(i%2==0)a[i][2]='G';
			else a[i][2]='L';
			if(i==1)a[i][m]='D';
			else if(i==n)a[i][m]='L';
			else if(i%2==0)a[i][m]='L';
			else a[i][m]='D';
			for(int j=3;j<m;++j){
				if(i%2==1)
					a[i][j]='D';
				else
					a[i][j]='G';
			}
		}
		
	}
/*	for(int j=m;j>=1;--j){
		for(int i=1;i<=n;++i){
			putchar(a[i][j]);
		}
		putchar('\n');

	}
*/
	for(int i=1;i<=f;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x%2==1){
		
		a[x+2][y+3]='L';
		a[x][y+2]='P';
		a[x+1][y+2]='P';
		a[x+1][y-1]='L';
		}else if(y!=3){
			a[x+2][y-2]='L';
			a[x][y-1]='P';
			a[x+1][y-1]='P';
			a[x+1][y+2]='L';
		}else{
			a[x][1]='G';
        	a[x][2]='P';
        	a[x+1][2]='D';
        	a[x+1][y+2]='L';
		}
	}
	printf("TAK\n");
	int x=1,y=1;
	for(int i=1;i<=n*m-4*f;++i){
		putchar(a[x][y]);
		if(a[x][y]=='L')
			--x;
		else if(a[x][y]=='P')
			++x;
		else if(a[x][y]=='G')
			++y;
		else
			--y;
	}
	putchar('\n');
	return 0;
}
