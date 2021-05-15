#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
struct task{
    int dur,dle;
}tasks[150010];int n;
struct cmp1{bool operator()(task a,task b){return a.dle<b.dle;}};
struct cmp2{bool operator()(task a,task b){return a.dur<b.dur;}};
vector<vector<int>*>tmp;
int main(){
    lp(i,0,30000)tmp.push_back(new vector<int>(400)); 
    lp(i,0,tmp.size()-1)delete tmp[i];
    sf("%d",&n);
    lp(i,1,n)sf("%d%d",&tasks[i].dur,&tasks[i].dle);
    sort(tasks+1,tasks+n+1,cmp1());
    priority_queue<task,vector<task>,cmp2>qu;int now=0;
    lp(i,1,n){
        if(now+tasks[i].dur<=tasks[i].dle)now+=tasks[i].dur,qu.push(tasks[i]);
        else if(!qu.empty()&&qu.top().dur>tasks[i].dur)now+=-qu.top().dur+tasks[i].dur,qu.pop(),qu.push(tasks[i]);
    }
    pf("%d\n",qu.size());//ps;
    return 0;
}
