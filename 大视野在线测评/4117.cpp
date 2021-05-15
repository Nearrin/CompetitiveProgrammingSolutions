#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#include<utility>
#include<vector>
#include<queue>
int n;
double p[10];
typedef long long ll;
ll comb[110][110];
int main(){
    cin>>n;
    for(int i=1;i<=4;++i)
        cin>>p[i];
    comb[0][0]=1;
    for(int i=1;i<=100;++i)
        for(int j=0;j<=i;++j){
            if(j==0||j==i)
                comb[i][j]=1;
            else
                comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
        }
    vector<pair<double,ll > >vec;
    for(int n1=0;n1<=n;++n1)
        for(int n2=0;n2<=n;++n2)
            for(int n3=0;n3<=n;++n3)
                for(int n4=0;n4<=n;++n4){

                    if(n1+n2+n3+n4!=n)
                        continue;
                    ll cnt=comb[n][n1]*comb[n-n1][n2]*comb[n-n1-n2][n3];
                    double pro=1;
                    for(int i=1;i<=n1;++i)
                        pro*=p[1];
                    for(int i=1;i<=n2;++i)
                        pro*=p[2];
                    for(int i=1;i<=n3;++i)
                        pro*=p[3];
                    for(int i=1;i<=n4;++i)
                        pro*=p[4];
                    vec.push_back(make_pair(pro,cnt));
                }
    double ans=0;
    int del=0;
    /*while(true){
        ++del;
        double mi;
        int miindex=-1;
        for(int i=0;i<vec.size();++i)
            if(miindex==-1||vec[i].first<mi){
                miindex=i;
                mi=vec[i].first;
            }
        if(vec[miindex].second==1){
            if(vec.size()==1)
                break;
            double smi;
            int smiindex=-1;
            for(int i=0;i<vec.size();++i)
                if(i!=miindex&&(smiindex==-1||vec[i].first<smi)){
                    smiindex=i;
                    smi=vec[i].first;
                }
            --vec[miindex].second;
            --vec[smiindex].second;
            ans+=vec[miindex].first+vec[smiindex].first;
            vec.push_back(make_pair(vec[miindex].first+vec[smiindex].first,1));
        }else{
            ll tcnt=vec[miindex].second/2;
            ans+=vec[miindex].first*tcnt*2;
            vec[miindex].second-=tcnt*2;
            vec.push_back(make_pair(2*vec[miindex].first,tcnt));
        }
        while(true){
            int src=-1;
            for(int i=0;i<vec.size();++i)
                if(vec[i].second==0)
                    src=i;
            if(src==-1)
                break;
            vec.erase(vec.begin()+src);
        }
    }*/
    typedef pair<double,ll> ND;
    priority_queue<pair<double,ll>,vector<pair<double,ll> >,greater< pair<double,ll> > >qu;
    for(int i=0;i<vec.size();++i)
        qu.push(vec[i]);
    while(true){
        ++del;
        ND nd=qu.top();
        qu.pop();
        if(nd.second==1){
            if(qu.empty())
                break;
            ND nd2=qu.top();
            qu.pop();
            ans+=nd.first+nd2.first;
            --nd.second;
            --nd2.second;
            if(nd.second!=0)
                qu.push(nd);
            if(nd2.second!=0)
                qu.push(nd2);
            qu.push(make_pair(nd.first+nd2.first,1));
        }else{
            ll tcnt=nd.second/2;
            ans+=nd.first*tcnt*2;
            nd.second-=tcnt*2;
            if(nd.second!=0)
                qu.push(nd);
            qu.push(make_pair(2*nd.first,tcnt));
        }
    }
    printf("%.6lf\n",ans);
    //cout<<del<<endl;
    return 0;
}
