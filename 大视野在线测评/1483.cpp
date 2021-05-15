#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
struct seg{
    seg(){}
    seg(int u,int v):l(u),r(v){}
    int l,r;
};
bool operator<(seg u,seg v){
    return u.l<v.r;
}
int n,m,a[100010],ans;
map<int,set<seg>*>mp;
int main(){
    sf("%d%d",&n,&m);
    lp(i,1,n)sf("%d",&a[i]);
    for(int i=1;i<=n;){
        int j=i;for(;j+1<=n&&a[i]==a[j+1];++j);
        if(!mp[a[i]])mp[a[i]]=new set<seg>();
        mp[a[i]]->insert(seg(i,j));
        i=j+1;++ans;
    }
    lp(i,1,m){
        int u,v,w;
        sf("%d",&u);
        if(u==1){
            sf("%d%d",&u,&v);
            if(u!=v){
                if(!mp[v])mp[v]=mp[u],mp[u]=0;
                else if(mp[u]){
                    set<seg>*su=mp[u],*sv=mp[v];
                    //if(su->size()>sv->size())swap(su,sv);
                    ans-=su->size()+sv->size();
                    for(set<seg>::iterator it=su->begin();it!=su->end();++it){
                        seg t=*it;
                        set<seg>::iterator r=sv->upper_bound(t),l;
                        if(r==sv->end()){
                            --r;
                            if(r->r+1==t.l){
                                t.l=r->l;
                                sv->erase(r);
                            }
                        }else if(r==sv->begin()){
                            if(r->l-1==t.r){
                                t.r=r->r;
                                sv->erase(r);
                            }
                        }else{
                            if(r->l-1==t.r){
                                t.r=r->r;
                                sv->erase(r);
                            }
                            l=sv->upper_bound(t);--l;
                            if(l->r+1==t.l){
                                t.l=l->l;
                                sv->erase(l);
                            }
                        }
                        sv->insert(t);
                    }
                    ans+=sv->size();
                    delete su;mp[u]=0;mp[v]=sv;
                }
            }
        }else{
            pf("%d\n",ans);
        }
    }
    //ps;
    return 0;
} 
