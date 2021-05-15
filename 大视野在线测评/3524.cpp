#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
#include<utility>
#include<queue>
#include<bitset>
using namespace std;
struct node{
    node(){}
    node(node*ch0,node*ch1,int _cnt){ch[0]=ch0,ch[1]=ch1,cnt=_cnt;}
    node*ch[2];int cnt;
}*nds[500010];
node pour[10750010];
node*ptr=pour;
node*newnode(node*ch0,node*ch1,int _cnt){
    if(ptr>=pour+10500010)for(;;);
    *ptr=node(ch0,ch1,_cnt);
    return ptr++;
}
node*build(int l,int r){
    return newnode(0,0,0);
}
node*make(int l,int r,int v){
    if(l==r)return newnode(0,0,1);
    else{
        int m=(l+r)/2;
        if(v<=m)return newnode(make(l,m,v),0,1);
        else return newnode(0,make(m+1,r,v),1);
    }
}
node*add(node*x,int l,int r,int v){
    if(l==r){
        return newnode(0,0,x->cnt+1);
    }else{
        int m=(l+r)/2;
        if(v<=m){
            if(!x->ch[0])return newnode(make(l,m,v),x->ch[1],x->cnt+1);
            return newnode(add(x->ch[0],l,m,v),x->ch[1],x->cnt+1);
        }
        else{
            if(!x->ch[1])return newnode(x->ch[0],make(m+1,r,v),x->cnt+1);
            return newnode(x->ch[0],add(x->ch[1],m+1,r,v),x->cnt+1);
        }
    }
}
int C(node*x){
    if(!x)return 0;
    else return x->cnt;
}
int C0(node*x){
    if(!x)return 0;
    else return C(x->ch[0]);
}
int C1(node*x){
    if(!x)return 0;
    else return C(x->ch[1]);
}
node*CC0(node*x){
    if(!x)return 0;
    else return x->ch[0];
}
node*CC1(node*x){
    if(!x)return 0;
    else return x->ch[1];
}
int ask(node*x,node*y,int l,int r,int di){
    if(l==r){
        if(C(x)-C(y)>di)return l;
        else return 0;
    }else{
        int m=(l+r)/2;
        if(C0(x)-C0(y)>di)
            return ask(CC0(x),CC0(y),l,m,di);
        else if(C1(x)-C1(y)>di)
            return ask(CC1(x),CC1(y),m+1,r,di);
        else return 0;
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    nds[0]=build(1,n);
    for(int i=1;i<=n;++i){
        int t;scanf("%d",&t);
        nds[i]=add(nds[i-1],1,n,t);
    }
    for(int i=1;i<=m;++i){
        int l,r;scanf("%d%d",&l,&r);
        printf("%d\n",ask(nds[r],nds[l-1],1,n,(r-l+1)/2));
    }
    //for(;;);
    return 0;
} 
