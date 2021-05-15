#include<cstdio>
#include<set>
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
struct node{
    node* ch[2];
}nds[31*4*100000+10];
node*root;
int pp;
node*newnode(){
    node*r=nds+pp;
    ++pp;
    r->ch[0]=r->ch[1]=0;
    return r;
}
void init(){
    pp=0;
    root=nds+pp;
    ++pp;
    root->ch[0]=root->ch[1]=0;
}

void insert(int v){
    node*x=root;
    for(int i=31;i>=1;--i){
        int hehe=((v>>(i-1))&1);
        if(!x->ch[hehe])
            x->ch[hehe]=newnode();
        x=x->ch[hehe];
    }
}

int query(int v){
    int r=0;
    node*x=root;
    for(int i=31;i>=1;--i){
        int hehe=((v>>(i-1))&1);
        if(x->ch[!hehe]){
            x=x->ch[!hehe];
            r+=(1<<(i-1));
        }else{
            x=x->ch[hehe];
        }
    }
    return r;
}

int main(){
    int n;static int a[400010];
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    static int mx[400010],mxr[400010];
    init();
    insert(0);
    for(int i=1,sum=0;i<=n;++i){
        mx[i]=query(sum^a[i]);
        //cout<<i<<":"<<mx[i]<<endl;
        sum^=a[i];
        insert(sum);
        if(i!=1)mx[i]=max(mx[i],mx[i-1]);
        //cout<<i<<":"<<mx[i]<<endl;
    }
    init();
    insert(0);
    for(int i=n,sum=0;i>=1;--i){
        mxr[i]=query(sum^a[i]);
        sum^=a[i];
        insert(sum);
        if(i!=n)mxr[i]=max(mxr[i],mxr[i+1]);
    }
    long long ans=0;
    for(int i=1;i<n;++i){
        long long t1=mx[i],t2=mxr[i+1];
        if(t1+t2>ans)
            ans=t1+t2;

    }
    cout<<ans<<endl;
    return 0;
}
