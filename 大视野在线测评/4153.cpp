#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
ll M=1e9+7;
void move(ll&ans,map<pair<int,int>,int >&mp,int x,int y){
    ll t=mp[make_pair(x,y)];
    t=t*(t-1)/2;
    ans-=t;
    --mp[make_pair(x,y)];
    t=mp[make_pair(x,y)];
    t=t*(t-1)/2;
    ans+=t;
}
void add(ll&ans,map<pair<int,int>,int >&mp,int x,int y){
    ll t=mp[make_pair(x,y)];
    t=t*(t-1)/2;
    ans-=t;
    ++mp[make_pair(x,y)];
    t=mp[make_pair(x,y)];
    t=t*(t-1)/2;
    ans+=t;
}
#define BIG 1000010
int main(){
    int T;scanf("%d",&T);
    for(int I=1;I<=T;++I){
        int n,q;
        ll allans=0;
        scanf("%d%d",&n,&q);
        static int belman[BIG],belwo[BIG];
        for(int i=1;i<=n;++i)
            belman[i]=belwo[i]=i;
        static vector<int>lstman[BIG],lstwo[BIG];
        for(int i=1;i<=n;++i)
            lstman[i].clear(),lstman[i].push_back(i),lstwo[i]=lstman[i];
        map<pair<int,int>,int >mp;
        ll ans=0;
        for(int i=1;i<=n;++i)
            mp[make_pair(i,i)]=1;
        for(int i=1;i<=q;++i){
            int t,a,b;
            scanf("%d%d%d",&t,&a,&b);
            if(t==1){
                if(belman[a]==belman[b])goto ok;
                if(lstman[belman[a]].size()>lstman[belman[b]].size()){
                    swap(a,b);
                }
                int originmancolor=belman[a];
                int tobemancolor=belman[b];
                for(int j=0;j<lstman[originmancolor].size();++j){
                    int couple=lstman[originmancolor][j];
                    int x=originmancolor,y=belwo[couple];
                    move(ans,mp,x,y);
                    add(ans,mp,tobemancolor,y);
                    belman[couple]=belman[b];
                    lstman[tobemancolor].push_back(couple);
                }
                lstman[originmancolor].clear();
            }else{
                if(belwo[a]==belwo[b])goto ok;
                if(lstwo[belwo[a]].size()>lstwo[belwo[b]].size()){
                    swap(a,b);
                }
                int originwocolor=belwo[a];
                int tobewocolor=belwo[b];
                for(int j=0;j<lstwo[originwocolor].size();++j){
                    int couple=lstwo[originwocolor][j];
                    int x=belman[couple],y=originwocolor;
                    move(ans,mp,x,y);
                    add(ans,mp,x,tobewocolor);
                    belwo[couple]=belwo[b];
                    lstwo[tobewocolor].push_back(couple);
                }
                lstwo[originwocolor].clear();
            }
            ok:
            allans+=ans*i%M;
            allans%=M;
        }
        printf("%d\n",int(allans));
    }
    return 0;
}
