#include<iostream>
#include<algorithm>
#include<iomanip>
#include<unordered_set>
#include<vector>
using namespace std;
typedef long long ll;
int n,q;
void sub1(){
    vector<int>a;
    for(int i=1;i<=n;++i){
        int t;scanf("%d",&t);
        a.push_back(t);
    }
    unordered_set<int>st;
    for(int i=1;i<=q;++i){
        int t;scanf("%d",&t);
        if(t==1){
            int l,r;scanf("%d%d",&l,&r);
            --l,--r;
                ll c1=a[l];
                ll c2=0;
                ll c3=0;
                st.insert(a[l]);
                for(int j=l+1;j<=r;++j){
                    if(st.count(a[j]))continue;
                    st.insert(a[j]);
                    c3=(c3+c2*a[j])%ll(1e9+7);
                    c2=(c2+c1*a[j])%ll(1e9+7);
                    c1=(c1+a[j])%ll(1e9+7);
                }
                for(int j=l;j<=r;++j){
                    st.erase(a[j]);
                }
                printf("%d\n",int(c3));
        }else if(t==2){
            int x,y;scanf("%d%d",&x,&y);
            a[x-1]=y;
        }else if(t==3){
            int x;scanf("%d",&x);
            a.erase(a.begin()+x-1);
        }else if(t==4){
            int z,y;scanf("%d%d",&z,&y);
            a.insert(a.begin()+z,y);
        }else if(t==5){
            int l,r;scanf("%d%d",&l,&r);
            --l,--r;
            for(int j=l;j<=r;++j){
                st.insert(a[j]);
            }
            printf("%d\n",st.size());
            for(int j=l;j<=r;++j){
                st.erase(a[j]);
            }
        }
    }
}
int t1[100010],t2[100010],t3[100010],has[10],a[100010];
namespace s2{
    int sum[100010*4];
    void update(int x,int l,int r){
        sum[x]=sum[x*2]+sum[x*2+1];
    }
    void change(int x,int l,int r,int p,int q){
        if(l==r){
            sum[x]=q;
        }else{
            int m=(l+r)/2;
            if(p<=m)change(x*2,l,m,p,q);
            else change(x*2+1,m+1,r,p,q);
            update(x,l,r);
        }
    }
    int getsum(int x,int l,int r,int u,int v){
        if(u<=l&&v>=r)return sum[x];
        int ret=0;
        int m=(l+r)/2;
        if(u<=m)
            ret+=getsum(x*2,l,m,u,v);
        if(v>m)
            ret+=getsum(x*2+1,m+1,r,u,v);
        return ret;
    }
    vector<int>lft[100010];
    vector<int>idx[100010];
    int ans[100010];
}
#include<map>
void sub2(){
    static int pre[100010];
    map<int,int>mp;
    for(int i=1;i<=n;++i)
        pre[i]=mp[a[i]],mp[a[i]]=i;
    for(int i=1;i<=q;++i)
        s2::lft[t3[i]].push_back(t2[i]),
                s2::idx[t3[i]].push_back(i);
    for(int i=1;i<=n;++i){
        if(pre[i])s2::change(1,1,n,pre[i],0);
        s2::change(1,1,n,i,1);
        for(int j=0;j<s2::lft[i].size();++j){
            int lf=s2::lft[i][j],id=s2::idx[i][j];
            s2::ans[id]=s2::getsum(1,1,n,lf,i);
        }
    }
    for(int i=1;i<=q;++i)
        printf("%d\n",s2::ans[i]);
}
/*
9 5
1 3 3 1 2 3 5 2 6
5 1 1
5 1 5
5 1 7
5 1 9
5 2 3


*/
namespace s3{
    struct info{
        info(){
            s1=s2=s3=0;
        }
        ll s1,s2,s3;
    }seg[100010*4];
    info merge(info a,info b){
        info c;
        c.s1=a.s1+b.s1;c.s1%=ll(1e9+7);
        c.s2=a.s2+b.s2+a.s1*b.s1;c.s2%=ll(1e9+7);
        c.s3=a.s3+b.s3+a.s1*b.s2+a.s2*b.s1;c.s3%=ll(1e9+7);
        return c;
    }

    void update(int x,int l,int r){
        seg[x]=merge(seg[x*2],seg[x*2+1]);
    }
    void change(int x,int l,int r,int p,int q){
        if(l==r){
            seg[x].s1=q;
            seg[x].s2=0;
            seg[x].s3=0;
        }else{
            int m=(l+r)/2;
            if(p<=m)change(x*2,l,m,p,q);
            else change(x*2+1,m+1,r,p,q);
            update(x,l,r);
        }
    }
    info getsum(int x,int l,int r,int u,int v){
        if(u<=l&&v>=r)return seg[x];
        info ret;
        int m=(l+r)/2;
        if(u<=m)
            ret=merge(getsum(x*2,l,m,u,v),ret);
        if(v>m)
             ret=merge(getsum(x*2+1,m+1,r,u,v),ret);
        return ret;
    }
    vector<int>lft[100010];
    vector<int>idx[100010];
    int ans[100010];
}
void sub3(){
    static int pre[100010];
    map<int,int>mp;
    for(int i=1;i<=n;++i)
        pre[i]=mp[a[i]],mp[a[i]]=i;
    for(int i=1;i<=q;++i)
        s3::lft[t3[i]].push_back(t2[i]),
                s3::idx[t3[i]].push_back(i);
    for(int i=1;i<=n;++i){
        if(pre[i])s3::change(1,1,n,pre[i],0);
        s3::change(1,1,n,i,a[i]);
        for(int j=0;j<s3::lft[i].size();++j){
            int lf=s3::lft[i][j],id=s3::idx[i][j];
            s3::ans[id]=s3::getsum(1,1,n,lf,i).s3;
        }
    }
    for(int i=1;i<=q;++i)
        printf("%d\n",s3::ans[i]);
}
/*
9 5
1 3 3 1 2 3 5 2 6
1 1 1
1 1 5
1 1 7
1 1 9
1 2 3
*/
#include<cmath>
namespace s4{
    vector<int>lisa;
    int k,bcnt,bbg[100010],bed[100010];
    int bsum[410][100010*2];int valmx;
    int bel[100010];
    int bans[410][410];
    int isend[100010];
    void run(){
        k=sqrt(n*1.0);
        bcnt=(n+k-1)/k;
        for(int i=1;i<=bcnt;++i){
            bbg[i]=(i-1)*k+1,bed[i]=min(i*k,n);
            isend[bed[i]]=i;
          //  printf("[%d,%d]\n",bbg[i],bed[i]);
        }

        //离散化
        for(int i=1;i<=n;++i)
            lisa.push_back(a[i]);
        for(int i=1;i<=q;++i)
            if(t1[i]==2)
                lisa.push_back(t3[i]);
        sort(lisa.begin(),lisa.end());
        lisa.erase(unique(lisa.begin(),lisa.end()),lisa.end());
        valmx=lisa.size();
        for(int i=1;i<=n;++i){
            a[i]=lower_bound(lisa.begin(),lisa.end(),a[i])-lisa.begin()+1;
            //cout<<a[i]<<" ";
        }
      //  cout<<endl;
        for(int i=1;i<=q;++i)
            if(t1[i]==2){
                t3[i]=lower_bound(lisa.begin(),lisa.end(),t3[i])-lisa.begin()+1;
                //cout<<"2 "<<t2[i]<<" "<<t3[i]<<endl;
            }
        //



        //bsum
        static int tmp1[100010*2];
        for(int i=1;i<=bcnt;++i){
            for(int j=bbg[i];j<=bed[i];++j){
                ++tmp1[a[j]];
                bel[j]=i;
            }
            for(int j=1;j<=valmx;++j)
                bsum[i][j]=tmp1[j];
        }

        //bans
        static int tmm[100010*2];
        for(int i=1;i<=bcnt;++i){
            for(int j=1;j<=valmx;++j)
                tmm[j]=0;
            int ans=0;
            for(int j=1;j<=n;++j){
                if(!tmm[a[j]]){
                    ++ans;
                    tmm[a[j]]=1;
                }
                if(isend[j])
                    bans[i][isend[j]]=ans;
            }
        }

//        for(int i=1;i<=n;++i)cout<<a[i]<<" ";cout<<endl;
//        for(int i=1;i<=q;++i){
//            cout<<t1[i]<<" "<<t2[i]<<" "<<t3[i]<<endl;
//        }


        for(int i=1;i<=q;++i){
            if(t1[i]==2){
                for(int j=(t2[i]+k-1)/k;j<=bcnt;++j){
                    bsum[j][a[t2[i]]]--;
                    bsum[j][t3[i]]++;
                }
                a[t2[i]]=t3[i];
            }else{
                int l=t2[i],r=t3[i];
                if(bel[r]-bel[l]<=1){
                    static int tmp2[100010*2];
                    int ans=0;
                    for(int j=l;j<=r;++j){
                        if(!tmp2[a[j]])
                            ++ans;
                        tmp2[a[j]]=1;
                    }
                    printf("%d\n",ans);
                    for(int j=l;j<=r;++j){
                        tmp2[a[j]]=0;
                    }
                }else{
                    int bl=bel[l]+1,br=bel[r]-1;
                    static int tmp2[100010*2];
                    int ans=bans[bl][br];
                  //  cout<<"["<<ans<<endl;
                    for(int j=l;bel[j]==bel[l];++j){
                        if(bsum[br][a[j]]-bsum[bl-1][a[j]]==0){
                            if(!tmp2[a[j]]){
                                tmp2[a[j]]=1;
                                ++ans;
                            }
                        }
                    }
                  //  cout<<"["<<ans<<endl;
                    for(int j=r;bel[j]==bel[r];--j){
                        if(bsum[br][a[j]]-bsum[bl-1][a[j]]==0){
                            if(!tmp2[a[j]]){
                                tmp2[a[j]]=1;
                                ++ans;
                            }
                        }
                    }
                    printf("%d\n",ans);
                    for(int j=l;bel[j]==bel[l];++j){

                                tmp2[a[j]]=0;

                    }
                    for(int j=r;bel[j]==bel[r];--j){

                                tmp2[a[j]]=0;

                    }
                }
            }
        }
    }
}
/*
10 7
1 3 3 1 2 3 5 2 6 3
5 1 1
5 1 5
5 1 7
2 3 5
5 1 9
2 1 2
5 2 3

10 3
1 3 3 1 2 3 5 2 6 3
5 1 1
5 1 5
5 1 7

*/
void sub4(){
    s4::run();
}
void sub5(){

}
void sub6(){

}
void sub7(){

}
void sub8(){

}
bool  s1s=1;
int main(){
    scanf("%d%d",&n,&q);
    if(ll(n)*ll(q)<=2*ll(1e7)&&s1s)
        sub1();
    else{
        for(int i=1;i<=n;++i)scanf("%d",a+i);
        for(int i=1;i<=q;++i){
            scanf("%d",t1+i);
            if(t1[i]==3)scanf("%d",t2+i);
            else scanf("%d%d",t2+i,t3+i);
            has[t1[i]]=1;
        }
        if(has[1]+has[2]+has[3]+has[4]==0){
            sub2();
        }else if(has[5]+has[2]+has[3]+has[4]==0){
            sub3();//cout<<"3";
        }else if(has[1]+has[3]+has[4]==0){
            sub4();
        }else if(has[3]+has[4]==0){
            sub5();
        }else if(has[1]+has[5]==0){
            sub6();
        }else if(n<=50000&&q<=50000){
            sub7();
        }else{
            sub8();
        }
    }
    return 0;
}
