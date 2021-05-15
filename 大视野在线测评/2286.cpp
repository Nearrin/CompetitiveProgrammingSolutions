#include<iostream>
#include<cstdio>
using namespace std;
 const int N=250000,L=18;
#include<bits/stdc++.h>
using namespace std;
struct VirtualTree{
    vector<int>we[N+1];int mi[N+1][L+1];
    vector<int>vwe[N+1];



    int n,l;vector<vector<int> >to,vto,up;
    vector<int>lst,dp,dfn,edf,imp;
    VirtualTree(int _n):
        n(_n),l(ceil(log2(n)+1e-8)),to(n+1),vto(n+1),
        up(n+1,vector<int>(l+1)),dp(n+1),dfn(n+1),edf(n+1),imp(n+1){}
    void add(int u,int v,int w){
        to[u].push_back(v);
        to[v].push_back(u);
        we[u].push_back(w);
        we[v].push_back(w);
    }
    void vadd(int u,int v,int w){
        vto[u].push_back(v);

        vwe[u].push_back(w);



       //cout<<u<<" "<<v<<" "<<w<<endl;
    }
    int lca(int u,int v){
        if(dp[u]<dp[v])
            swap(u,v);
        for(int i=0;i<=l;++i)
            if(((dp[u]-dp[v])>>i)&1)
                u=up[u][i];
        if(u==v)
            return u;
        for(int i=l;i>=0;--i)
            if(up[u][i]!=up[v][i])
                u=up[u][i],v=up[v][i];
        return up[u][0];
    }
    int mlca(int u,int v){
        int ans=~0u>>1;
        if(dp[u]<dp[v])
            swap(u,v);
        for(int i=0;i<=l;++i)
            if(((dp[u]-dp[v])>>i)&1)
                ans=min(ans,mi[u][i]),u=up[u][i];
        if(u==v)
            return ans;
        for(int i=l;i>=0;--i)
            if(up[u][i]!=up[v][i])
                ans=min(ans,mi[u][i]),ans=min(ans,mi[v][i]),u=up[u][i],v=up[v][i];
        return ans;
    }
    void dfs(int u){
        dfn[u]=++dfn[0];
        for(int i=1;i<=l;++i){
            up[u][i]=up[up[u][i-1]][i-1];
            mi[u][i]=min(mi[u][i-1],mi[up[u][i-1]][i-1]);
        }

        for(int i=0;i<to[u].size();++i){
            int v=to[u][i];
            if(v!=up[u][0]){
                up[v][0]=u;
                mi[v][0]=we[u][i];
                dp[v]=dp[u]+1;
                dfs(v);
            }
        }
        edf[u]=dfn[0];
    }
    void build(){
        fill(mi[0],mi[0]+l+1,~0u>>1);
        mi[1][0]=~0u>>1;
        dfs(1);
    }
    void run(int*a,int m){
        for(int i=0;i<lst.size();++i){
            imp[lst[i]]=0;
            vto[lst[i]].clear();
            vwe[lst[i]].clear();
        }
        lst.clear();
        static pair<int,int>b[N+1];
        for(int i=1;i<=m;++i){
            imp[a[i]]=1;
            b[i]=make_pair(dfn[a[i]],a[i]);
        }
        sort(b+1,b+m+1);
        vector<int>st;
        st.push_back(1);
        lst.push_back(1);
        for(int i=1;i<=m;++i){
            int u=b[i].second,v=st.back();
            if(u==1)
                continue;
            if(dfn[u]<=edf[v])
                st.push_back(u);
            else{
                int w=lca(u,v);
            //  cout<<w<<endl;
                while(st.size()>=2&&dp[st[st.size()-2]]>=dp[w]){
                    vadd(st[st.size()-2],*st.rbegin(),mlca(*st.rbegin(),st[st.size()-2]));
                    lst.push_back(*st.rbegin());
                    st.pop_back();
                }
                if(st.size()>=2&&w!=st[st.size()-1]){
                    vadd(w,*st.rbegin(),mlca(w,*st.rbegin()));
                    lst.push_back(*st.rbegin());
                    st.pop_back();
                    st.push_back(w);
                }
                st.push_back(u);
            }
            //cout<<"stack:";
            //for(int j=0;j<st.size();++j)
            //  cout<<st[j]<<" ";
            //  cout<<endl;
        }
        while(st.size()>=2){
            vadd(st[st.size()-2],*st.rbegin(),mlca(*st.rbegin(),st[st.size()-2]));
            lst.push_back(*st.rbegin());
            st.pop_back();
        }
    }
};
VirtualTree*vt;
long long treedp(int u){
    long long ans=0;
    for(int i=0;i<vt->vto[u].size();++i){
        int v=vt->vto[u][i];
        int w=vt->vwe[u][i];
    //  cout<<"("<<u<<" "<<v<<" "<<w<<")"<<endl;
        if(vt->imp[v]){
            ans+=vt->vwe[u][i];
        }else{
            ans+=min((long long)vt->vwe[u][i],treedp(v));
        }
    }
    return ans;
}
int main(){
    int n;scanf("%d",&n);
    vt=new VirtualTree(n);
    for(int i=1;i<=n-1;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        vt->add(u,v,w);
    }
    vt->build();
    int m;scanf("%d",&m);
    static int a[250010];
    for(int i=1;i<=m;++i){
        int k;scanf("%d",&k);
        for(int j=1;j<=k;++j)
            scanf("%d",&a[j]);
        vt->run(a,k);
    //  for(int j=0;j<vt->lst.size();++j)
        //  cout<<vt->lst[j]<<endl;
    //  printf("-----------\n");
        printf("%lld\n",treedp(1));
    }
    //cout<<vt->lca(10,6)<<endl;
    return  0;
}
/*
10
1 5 13
1 9 6
2 1 19
2 4 8
2 3 91
5 6 8
7 5 4
7 8 31
10 7 9
3
2 10 6
4 5 7 8 3
3 9 4 6
*/
