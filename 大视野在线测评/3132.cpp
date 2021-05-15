#include<cstdio>
#include<algorithm>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
int n,m;
struct bit{
    int d[2049][2049];
    void add(int x,int y,int t){
        for(int i=x;i<=n;i+=i&-i)
            for(int j=y;j<=m;j+=j&-j)
                d[i][j]+=t;
    }
    int ask(int x,int y){
        int r=0;
        for(int i=x;i;i-=i&-i)
            for(int j=y;j;j-=j&-j)
                r+=d[i][j];
        return r;
    }
}b1,b2,b3,b4;
int sum(int x,int y){
    return b1.ask(x,y)*(x+1)*(y+1)-b2.ask(x,y)*(x+1)-b3.ask(x,y)*(y+1)+b4.ask(x,y);
}
int main(){
    char op[11];
    sf("%s%d%d",op,&n,&m);
    while(sf("%s",op)!=EOF){
        if(op[0]=='L'){
            int x1,y1,x2,y2,t;
            sf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&t);
            b1.add(x1,y1,t);b1.add(x2+1,y1,-t);b1.add(x1,y2+1,-t);b1.add(x2+1,y2+1,t);
            b2.add(x1,y1,t*y1);b2.add(x2+1,y1,-t*y1);b2.add(x1,y2+1,-t*(y2+1));b2.add(x2+1,y2+1,t*(y2+1));
            b3.add(x1,y1,t*x1);b3.add(x2+1,y1,-t*(x2+1));b3.add(x1,y2+1,-t*x1);b3.add(x2+1,y2+1,t*(x2+1));
            b4.add(x1,y1,t*x1*y1);b4.add(x2+1,y1,-t*(x2+1)*y1);b4.add(x1,y2+1,-t*x1*(y2+1));b4.add(x2+1,y2+1,t*(x2+1)*(y2+1));
        }else{
            int x1,y1,x2,y2;
            sf("%d%d%d%d",&x1,&y1,&x2,&y2);
            pf("%d\n",sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1));
        }
    }
    //ps;
    return 0;
}
