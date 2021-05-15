#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#include<utility>
#include<vector>
#include<queue>
#include<set>
struct hui{
    int d,a,b,id;
}hs[500010],h[21][500010];
int s[21];
struct node{
    node(int u,int v){
        id=u,a=v;
    }

    int id,a;
};
bool operator<(node a,node b){
    return a.a<b.a;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        hs[i].d=d;
        hs[i].a=a;
        hs[i].b=b;
        hs[i].id=i;
        ++s[d];
        h[d][s[d]]=hs[i];
    }
    for(int i=1;i<=m;++i){
        set<node>st;
        for(int j=1;j<=s[i];++j)
            st.insert(node(h[i][j].id,h[i][j].a));
        int ans1=-1,ans2=-1;
        for(int j=1;j<=s[i];++j){
            node tmp(0,h[i][j].b);
            set<node>::iterator it=st.upper_bound(tmp);
            if(it!=st.end()){
                ans1=h[i][j].id;
                ans2=it->id;
                break;
            }
        }
        if(ans1==-1)
            printf("NIE\n");
        else
            printf("TAK %d %d\n",ans1,ans2);
    }
    return 0;
}
