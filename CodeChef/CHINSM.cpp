#include<algorithm>
#include<deque>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
#define N 100000
int a[N+10],b[N+10],n,k,l;
vector<int>p[N+10],u[N+10];
int f(int x){
    int r=0;
    for(int i=1;i<=x;++i)
        for(int j=1;j<=i;++j)
            if(i%j==0)
                ++r;
    return r;
}
int main(){
    //cout<<f(100000)<<endl;//1166750
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        p[a[i]].push_back(i);;
        u[a[i]].push_back(0);
        l=max(l,a[i]);
    }
    for(int y=k+1;y<=l;++y){
        for(int t=0;t*y+k<=l;++t){
            int x=t*y+k;
            for(int i=0;i<p[x].size();++i){
                int j=upper_bound(p[y].begin(),p[y].end(),p[x][i])-p[y].begin();
                if(j!=p[y].size())
                    u[y][j]=max(u[y][j],p[x][i]);
            }
        }
        for(int i=0;i<p[y].size();++i){
            if(i)
                u[y][i]=max(u[y][i],u[y][i-1]);
            b[p[y][i]]=u[y][i];
        }
    }
    //for(int i=1;i<=n;++i)
        //cout<<b[i]<<endl;
    long long ans=0;
    deque<int>qub(1,n),qup(1,n+1);
    for(int i=n;i>=1;--i){
        int j=lower_bound(qub.begin(),qub.end(),i)-qub.begin();
        ans+=qup[j]-i;
        //cout<<i<<" "<<qup[j]-1<<endl;
        while(qub.front()<=b[i]){
            qub.pop_front();
            qup.pop_front();
        }
        qub.push_front(b[i]);
        qup.push_front(i);
    }
    cout<<ans<<endl;
    return 0;
}
/*
8 0
4 6 2 3 1 2 3 2

3 2
5 3 1
*/
