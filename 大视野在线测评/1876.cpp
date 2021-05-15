#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#define sf scanf
#define pf printf
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define ps system("pause");
using namespace std;
struct bign{
    int data[3010],size;
};
char tmp[10010];
void read(bign &a){
    sf("%s",tmp);
    int len=strlen(tmp);
    a.size=0;
    int j=len-4;
    lp(i,1,len/4){
        int t=0;
        lp(k,0,3)
            t*=10,t+=tmp[j+k]-'0';
        a.data[++a.size]=t;
        j-=4;
    }
    j+=4;
    int t=0;
    for(int k=0;k<j;++k)
        t*=10,t+=tmp[k]-'0';
    a.data[++a.size]=t;
}
void print(bign &a){
    pf("%d",a.data[a.size]);
    for(int i=a.size-1;i>0;--i)
        pf("%04d",a.data[i]);
    pf("\n");
}
bign A,B,C,T;
void div2(bign &a){
    for(int i=a.size;i>=0;--i){
        a.data[i-1]+=(a.data[i]&1)*10000;
        a.data[i]>>=1;
    }
    if(a.data[a.size]==0)--a.size;
}
void mul2(bign &a){
    a.data[a.size+1]=0;
    for(int i=1;i<=a.size;++i)a.data[i]*=2;
    for(int i=1;i<=a.size;++i){
        a.data[i+1]+=a.data[i]/10000;
        a.data[i]%=10000;
    }
    if(a.data[a.size+1]!=0)++a.size;
}
bool operator<(bign &a,bign &b){
    if(a.size!=b.size)return a.size<b.size;
    for(int i=a.size;i>0;--i)if(a.data[i]!=b.data[i])return a.data[i]<b.data[i];
    return false;
}
void mswap(bign &a,bign &b){
    if(a<b)swap(a,b);
}
void minu(bign &a,bign b){
    for(int i=b.size+1;i<=a.size;++i)
        b.data[i]=0;
    b.size=a.size;
    lp(i,1,b.size)b.data[i]=9999-b.data[i];
    ++b.data[1];
    T.size=a.size;
    T.data[1]=0;
    lp(i,1,T.size){
        T.data[i]+=a.data[i]+b.data[i];
        T.data[i+1]=T.data[i]/10000;
        T.data[i]%=10000;
    }
    while(T.size&&!T.data[T.size])--T.size;
}
void mul(bign &a,bign &b){
    T.size=a.size+b.size;
    lp(i,1,T.size)T.data[i]=0;
    lp(i,1,a.size)lp(j,1,b.size){
        T.data[i+j-1]+=a.data[i]*b.data[j];
        T.data[i+j]+=T.data[i+j-1]/10000;
        T.data[i+j-1]%=10000;
    }
    if(T.data[T.size]==0)--T.size;
} 
void gcd(){
    C.size=1;C.data[1]=1;
    while(B.size){
        if((A.data[1]&1)==0&&(B.data[1]&1)==0)
            div2(A),div2(B),mul2(C);
        else if((A.data[1]&1)==0)
            div2(A);
        else if((B.data[1]&1)==0)
            div2(B);
        else{
            mswap(A,B);
            minu(A,B);
            A=T;
            mswap(A,B);
        }
    }
    mul(A,C);
}
int main(){
    read(A);read(B);
    gcd();
    print(T);
    //ps;
    return 0;
}
