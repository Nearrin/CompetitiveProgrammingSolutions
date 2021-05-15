#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int n,p,m,b;
double r[1010000];

int main(){
    int T;scanf("%d",&T);
    scanf("%d%d%d%d",&n,&p,&m,&b);
    scanf("%lf%lf%lf%lf",&r[1],&r[2],&r[3],&r[4]);
    long double c1=-1/r[1]+1/r[2];
    long double c2=-1/(r[1]*r[2]);
    long double C=-sqrt(c1/r[3]+c2)-3*c1;
    long double myr4=( (4*c1+C)*(4*c1+C)-c2 )/c1;
    if(fabs(myr4-1/r[4])>1e-12)
        C=sqrt(c1/r[3]+c2)-3*c1;
    long double sum = 0;
    for(int i = 1;i<=T;++i){
        n = ll(p)*ll(n)%m+b;
        if(n<=4)sum+=r[n];
        else{
            sum+=c1/( (n*c1+C)*(n*c1+C)-c2 );
        }
    }
    printf("%.6lf\n",double(sum));
    return 0;
}
