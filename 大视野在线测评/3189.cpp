#include<cstdio>
#include<algorithm>
#include<set>
#include<utility>
#include<vector>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int n,k,m;
struct tree{
    set<pair<int,int> >node[1010*4];
    void add(int x,int l,int r,int b,int e,pair<int,int>t){
        if(l==b&&r==e)node[x].insert(t);
        else{
            int m=(l+r)/2;
            if(e<=m)add(x*2,l,m,b,e,t);
            else if(b>m)add(x*2+1,m+1,r,b,e,t);
            else add(x*2,l,m,b,m,t),add(x*2+1,m+1,r,m+1,e,t);
        }
    }
    void rem(int x,int l,int r,int b,int e,pair<int,int>t){
        if(l==b&&r==e)node[x].erase(t);
        else{
            int m=(l+r)/2;
            if(e<=m)rem(x*2,l,m,b,e,t);
            else if(b>m)rem(x*2+1,m+1,r,b,e,t);
            else rem(x*2,l,m,b,m,t),rem(x*2+1,m+1,r,m+1,e,t);
        }
    }
    pair<int,int>ask(int x,int l,int r,int p){
        pair<int,int>t=node[x].empty()?make_pair(0,1):*node[x].rbegin();
        if(l!=r){
            int m=(l+r)/2;
            if(p<=m)t=max(t,ask(x*2,l,m,p));
            else t=max(t,ask(x*2+1,m+1,r,p));
        }
        return t;
    } 
}odd,even;
struct query{
    int tp;//1 paint 2 save 3 load
    int id;
    int tm,x1,y1,x2,y2,cl;
};
vector<query>q1,toadd[2010],torem[1010]; 
int main(){
    sf("%d%d%d",&n,&k,&m);int nw=0;
    lp(i,1,m){
        char op[11];
        sf("%s",op+1);
        if(op[1]=='P'){
            query t;t.tp=1;t.tm=i;
            sf("%d%d%d%d%d",&t.cl,&t.x1,&t.y1,&t.x2,&t.y2);
            ++t.x1;++t.x2;++t.y1;++t.y2;
            q1.push_back(t);
        }else if(op[1]=='S'){
            query t;t.tp=2;t.id=++nw;
            q1.push_back(t);
        }else{
            query t;t.tp=3;sf("%d",&t.id);
            q1.push_back(t);
        }
    }
    rp(i,int(q1.size()-1),0){
        if(q1[i].tp==1){
            toadd[q1[i].x1].push_back(q1[i]);
            torem[q1[i].x2+1].push_back(q1[i]);
        }
        else if(q1[i].tp==3){
            int j=i-1;
            while(q1[j].tp!=2||q1[j].id!=q1[i].id)--j;
            i=j;
        }
    }
    lp(i,1,n){
        lp(j,0,int(torem[i].size()-1))
            if((torem[i][j].x1+torem[i][j].y1)&1)
                odd.rem(1,1,n,torem[i][j].y1,torem[i][j].y2,make_pair(torem[i][j].tm,torem[i][j].cl));
            else
                even.rem(1,1,n,torem[i][j].y1,torem[i][j].y2,make_pair(torem[i][j].tm,torem[i][j].cl));
        lp(j,0,int(toadd[i].size()-1)){
            if((toadd[i][j].x1+toadd[i][j].y1)&1)
                odd.add(1,1,n,toadd[i][j].y1,toadd[i][j].y2,make_pair(toadd[i][j].tm,toadd[i][j].cl));
            else
                even.add(1,1,n,toadd[i][j].y1,toadd[i][j].y2,make_pair(toadd[i][j].tm,toadd[i][j].cl));
        }
        lp(j,1,n){
            if((i+j)&1)pf("%d ",odd.ask(1,1,n,j).second);
            else pf("%d ",even.ask(1,1,n,j).second);
        }
        pf("\n"); 
    }
    //ps;
    return 0; 
}
