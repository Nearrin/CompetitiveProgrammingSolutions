#include<cstdio>
#include<complex>
#include<cmath>
#include<algorithm>
using namespace std;
typedef complex<double> cpx;
double pi=acos(-1.0);cpx im(0,1);
void fft(cpx*a,int n,int s){
    for(int i=0;i<n;++i){
        int j=0;for(int k=0;(1<<k)<n;++k)j<<=1,j+=((i>>k)&1);
        if(i<j)swap(a[i],a[j]);
    }
    for(int i=1;(1<<i)<=n;++i){
        int m=(1<<i);cpx wm=exp(double(s)*im*2.0*pi/double(m));
        for(int j=0;j<n;j+=m){
            cpx w=1;
            for(int k=0;k<m/2;++k){
                cpx u=a[j+k],v=w*a[j+k+m/2];
                a[j+k]=u+v;
                a[j+k+m/2]=u-v;
                w*=wm;
            }
        }
    }
}
int main(){
    int n;scanf("%d",&n);
    static double a[100010];
    for(int i=0;i<n;++i)
        scanf("%lf",a+i);
        
    int myn=1;while(myn<2*n)myn*=2;
    static cpx mya[300010];
    for(int i=0;i<n;++i)
        mya[i]=a[i];
    static cpx myb[300010];
    for(int i=1;i<n;++i)myb[i]=1/(double(i)*double(i));
    static cpx myc[300010];
    fft(mya,myn,1);
    fft(myb,myn,1);
    for(int i=0;i<myn;++i)
        myc[i]=mya[i]*myb[i];
    fft(myc,myn,-1);
    
    //for(int i=0;i<n;++i)printf("%lf\n",real(myc[i])/myn);
    
    reverse(a,a+n);
    
    int myn2=1;while(myn2<2*n)myn2*=2;
    static cpx mya2[300010];
    for(int i=0;i<n;++i)
        mya2[i]=a[i];
    static cpx myb2[300010];
    for(int i=1;i<n;++i)myb2[i]=1/(double(i)*double(i));
    static cpx myc2[300010];
    fft(mya2,myn2,1);
    fft(myb2,myn2,1);
    for(int i=0;i<myn2;++i)
        myc2[i]=mya2[i]*myb2[i];
    fft(myc2,myn2,-1);
    
    for(int i=0;i<n;++i)printf("%lf\n",real(myc[i])/myn-real(myc2[n-i-1])/myn2);
    //for(;;);
    return 0;
}
/*
5
4006373.885184
15375036.435759
1717456.469144
8514941.004912
1410681.345880

5
1
3
5
7
9
*/
