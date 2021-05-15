#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<string>
#include<iostream>
#include<cstring> 
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef vector<int> num;
num give(){
    num a;static char t[110];sf("%s",t+1);int l=strlen(t+1);
    reverse(t+1,t+l+1);
    lp(i,1,l)
        a.push_back(t[i]-'0');
    return a;
}
num mul(num a,num b){
    num c(a.size()+b.size(),0);
    lp(i,0,int(a.size()-1))
        lp(j,0,int(b.size()-1))
            c[i+j]+=a[i]*b[j];
    lp(i,0,int(c.size()-2))
        c[i+1]+=c[i]/10,
        c[i]%=10;
    while(c.size()>1&&!c.back())c.pop_back();
    return c; 
}
void prit(num a){
    reverse(a.begin(),a.end());
    for(int i=0;i<a.size();++i)pf("%d",a[i]);
}
int main(){
    num a=give();num b=give();
    num c=mul(a,b);
    prit(c);pf("\n");
    //ps;
    return 0; 
} 
