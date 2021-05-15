#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#include<utility>
#include<vector>
#include<queue>
#include<set>

typedef long long ll;
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll egcd(ll a,ll b,ll&x,ll&y){
    if(!b){
        x=1;
        y=0;
        return a;
    }else{
        ll d=egcd(b,a%b,y,x);
        y-=a/b*x;
        return d;
    }
}

bool calc(int n,int p,int q){
    return n%p<q&&n%p%(p-q)==0;
}



int main(){
    int t;cin>>t;
    while(t--){
        int p,q,n;
        scanf("%d%d%d",&p,&q,&n);
        int d=gcd(p,q);
        if(n%d){
            puts("R");
            continue;
        }
        p/=d;
        q/=d;
        n/=d;
        if(p==q)puts("E");
        else if(p>q){
            if(n<p)puts("P");
            else puts(calc(n,p,q)?"E":"P");
        }
        else{
            if(n<p){
                if(n+p<q)puts("E");
                else puts(calc(n+p,q,p)?"P":"E");
            }
                else puts("E");

        }
    }
    return 0;
}
