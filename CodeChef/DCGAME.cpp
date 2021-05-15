#include<iostream>
#include<algorithm>
#include<iomanip>
#include<unordered_map>
using namespace std;
typedef long long ll;
ll cnt[1000010];//cnt[i]琛ㄧず 鏈€澶у€煎皬浜庣瓑浜巄[i]鐨勫瓙娈电殑鏁伴噺
pair<int,int>c[1000010];
bool cmp(const pair<int,int>&x,const pair<int,int>&y){
    return x.first<y.first;
}
ll now=0;
int prt[1000010],len[1000010],rnk[1000010];
int fd(int x){
    return x==prt[x]?x:prt[x]=fd(prt[x]);
}
ll f(ll x){
    return x*(x+1)/2;
}

void link(int x,int y){
    x=fd(x);
    y=fd(y);
    now-=f(len[x]);
    now-=f(len[y]);
    if(true){
        ++rnk[x];
        prt[y]=x;
        len[x]+=len[y];
        now+=f(len[x]);
    }else if(rnk[x]>rnk[y]){
        prt[y]=x;
        len[x]+=len[y];
        now+=f(len[x]);
    }else{
        swap(x,y);
        prt[y]=x;
        len[x]+=len[y];
        now+=f(len[x]);
    }
}

int main(){
    static int n,m,a[1000010],b[1000010],bn;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        b[i]=a[i];
        c[i].first=a[i];
        c[i].second=i;
    }
    sort(b+1,b+n+1);
    bn=unique(b+1,b+n+1)-b-1;
    sort(c+1,c+n+1,cmp);
    for(int i=1;i<=n;++i){
        int j=i;
        while(j+1<=n&&c[j+1].first==c[j].first)++j;



        for(int k=i;k<=j;++k){
            int tmp=c[k].second;
            prt[tmp]=tmp;
            len[tmp]=1;
            ++now;
            if(tmp!=1&&prt[tmp-1])
                link(tmp-1,tmp);
            if(tmp!=n&&prt[tmp+1])
                link(tmp+1,tmp);
        }
         int idx=lower_bound(b+1,b+bn+1,c[i].first)-b;
         cnt[idx]=now;
        i=j;
    }
 
    //for(int i=1;i<=bn;++i)
       // cout<<b[i]<<" "<<cnt[i]-bcnt[i]<<" "<<bcnt[i]<<endl;
    ll all=ll(n)*(n+1)/2;
    for(int i=1;i<=m;++i){
           char t1[10];int t2;char t3[10];
           scanf("%s%d%s",t1,&t2,t3);
           ll tmp;
           if(t1[0]=='='){
                int ppp=lower_bound(b+1,b+bn+1,t2)-b;
                if(ppp==bn+1)
                    tmp=0;
                else if(b[ppp]!=t2) {
                    tmp=0;
                }else{
                    tmp=cnt[ppp]-cnt[ppp-1];
                }
           }else if(t1[0]=='<'){
               int ppp=lower_bound(b+1,b+bn+1,t2)-b;
               if(ppp==bn+1)
                   tmp=cnt[bn];
               else {
                   --ppp;
                    tmp=cnt[ppp];
               }
           }else{
                int ppp=upper_bound(b+1,b+bn+1,t2)-b;
                if(ppp==bn+1)
                    tmp=0;
                else {
                    --ppp;
                     tmp=all-cnt[ppp];
                }
           }
           //cout<<tmp<<endl;
           if(tmp%2==1){
               printf("%s",t3);
           }else if(t3[0]=='D')
               putchar('C');
           else putchar('D');
       }
       putchar('\n');
       return 0;
   }
/*
50 100
4 1 3 1 2 1 3 3 3 4 5 6 2 3 45 12 433 1 3 4 124 11 2 1 2 3 4 5 6 7 1 3 5 0 1 9 1 1 7 3 8 1 3 4 2 1 3 5 4 1
*/