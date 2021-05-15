#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque> 
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int n,a,b;
int val[1010][1010],minx[1010][1010],maxx[1010][1010];
int miny[1010][1010],maxy[1010][1010]; 
int main(){
    sf("%d%d%d",&a,&b,&n);
    lp(i,1,a)lp(j,1,b)sf("%d",&val[i][j]);
    lp(i,1,a){
        deque<int>qu1,qu2;
        lp(j,1,b){
            while(!qu1.empty()&&val[i][qu1.back()]>=val[i][j])
                qu1.pop_back();
            qu1.push_back(j);
            while(qu1.front()<j-n+1)qu1.pop_front();
            minx[i][j]=val[i][qu1.front()];
            while(!qu2.empty()&&val[i][qu2.back()]<=val[i][j])
                qu2.pop_back();
            qu2.push_back(j);
            while(qu2.front()<j-n+1)qu2.pop_front();
            maxx[i][j]=val[i][qu2.front()];
        }
    }
    /*lp(i,1,a){
        lp(j,1,b)pf("[%d,%d]",minx[i][j],maxx[i][j]);
        pf("\n");
    }*/
    lp(j,1,b){
        deque<int>qu1,qu2;
        lp(i,1,a){
            while(!qu1.empty()&&minx[qu1.back()][j]>=minx[i][j])
                 qu1.pop_back();
            qu1.push_back(i);
            while(qu1.front()<i-n+1)qu1.pop_front();
            miny[i][j]=minx[qu1.front()][j];
            while(!qu2.empty()&&maxx[qu2.back()][j]<=maxx[i][j])
                 qu2.pop_back();
            qu2.push_back(i);
            while(qu2.front()<i-n+1)qu2.pop_front();
            maxy[i][j]=maxx[qu2.front()][j];
        } 
    }
    /*lp(i,1,a){
        lp(j,1,b)pf("[%d,%d]",miny[i][j],maxy[i][j]);
        pf("\n");
    }*/
    int ans=~0u>>1;
    lp(i,n,a)
        lp(j,n,b)
            ans=min(ans,maxy[i][j]-miny[i][j]);
    pf("%d\n",ans); 
    //ps;
    return 0;
}
