#include<cstdio>
#include<set>
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    long long i,k,s;
    long long ai,bi;
    cin>>i>>k>>s>>ai>>bi;
    long long neg=1;
   long long kmi=k-i;
    if(kmi<0){
        neg=-1;
        kmi=-kmi;
    }
    long long A=kmi/2,B=kmi%2;
    long long tmp=4*A*neg-s;
    double t1,t2;
    if(B){
        if(neg==1){
            long double tt=pow(2,tmp*1.0);
            t1=tt*2*sqrt(2.0);
            t2=tt*2*sqrt(6.0);
        }else{
           long  double tt=pow(2,tmp*1.0);
            t1=tt*sqrt(2.0)/8;
            t2=tt*sqrt(6.0)/8;
        }
    }else{
        t1=t2=pow(2,tmp*1.0);
    }
     long double q=t1*ai+t2*bi;
     cout<<setprecision(10)<<fixed;
     cout<<q<<endl;
    return 0;
}
