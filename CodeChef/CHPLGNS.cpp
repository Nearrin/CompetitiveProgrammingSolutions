#include<algorithm>
#include<cctype>
#include<climits>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>
#define sf scanf
#define si(a)scanf("%d",&a)
#define pf printf
#define pi(a)printf("%d",a)
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b)for(int i=a;i<=int(b);++i)
#define rp(i,a,b)for(int i=int(a);i>=b;--i)
#define vp(i,a)for(int i=0;i<int(a.size());++i)
#define wp(i,a)for(int i=int(a.size())-1;i>=0;--i)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
template<class VAL>class TwoDimensionalPoint{
private:
    VAL x,y;
public:
    inline TwoDimensionalPoint(const VAL&_x,const VAL&_y):
        x(_x),y(_y){
    }
    inline TwoDimensionalPoint<VAL>&operator=(const TwoDimensionalPoint<VAL>&a){
        x=a.x;
        y=a.y;
        return*this;
    }
    inline TwoDimensionalPoint<VAL>operator+(const TwoDimensionalPoint<VAL>&a){
        return TwoDimensionalPoint(x+a.x,y+a.y);
    }
    inline TwoDimensionalPoint<VAL>operator-(const TwoDimensionalPoint<VAL>&a){
        return TwoDimensionalPoint(x-a.x,y-a.y);
    }
    inline VAL Dot(const TwoDimensionalPoint<VAL>&a)const{
        return x*a.x+y*a.y;
    }
    inline VAL Det(const TwoDimensionalPoint<VAL>&a)const{
        return x*a.y-a.x*y;
    }
};
template<class VAL>inline VAL Dot(const TwoDimensionalPoint<VAL>&a,const TwoDimensionalPoint<VAL>&b){
    return a.Dot(b);
}
template<class VAL>inline VAL Det(const TwoDimensionalPoint<VAL>&a,const TwoDimensionalPoint<VAL>&b){
    return a.Det(b);
}
int main(){
    int T;si(T);
    lp(I,1,T){
        int N;
        si(N);
        vector<pair<long double,int> >hehe;
        lp(i,1,N){
            int m;si(m);
            vector<TwoDimensionalPoint<long double> >pts;
            lp(j,1,m){
                int x,y;
                si(x),si(y);
                pts.push_back(TwoDimensionalPoint<long double>(x,y));
            }
            long double are=0;
            vp(j,pts){
                are+=Det(pts[j],pts[(j+1)%m]);
            }
            if(are<0)are*=-1;
            hehe.push_back(mp(are,i));
        }
        sort(hehe.begin(),hehe.end());
        static int ans[100010];
        vp(i,hehe)
                ans[hehe[i].second]=i;
        lp(i,1,N)
                pf("%d%c",ans[i],i==N?'\n':' ');
    }
    return 0;
}
