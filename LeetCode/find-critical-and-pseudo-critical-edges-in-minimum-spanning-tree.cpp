template<class T=int,class C=less<T> >struct MinimumSpanningTree{
    struct edge{
        T w;
        int u,v;
        int idx;
        int operator<(const edge&b)const{
            return C()(w,b.w);
        }
    };
    int n;
    vector<edge>egs;
    vector<int>pr;
    MinimumSpanningTree(int _n):
        n(_n),pr(n+1){
    }
    void add(int u,int v,T w,int i){
        edge e;
        e.u=u;
        e.v=v;
        e.w=w;
        e.idx=i;
        egs.push_back(e);
    }
    int fd(int x){
        return x==pr[x]?x:pr[x]=fd(pr[x]);
    }
    void lk(int x,int y){
        pr[fd(x)]=y;
    }
    pair<set<int>,set<int>> run(int&cost){
        cost=0;
        sort(egs.begin(),egs.end());
        set<int>ans,tree;
        for(int i=1;i<=n;++i)
            pr[i]=i;
        for(int i=0;i<egs.size();++i){
            int j=i;
            while(j+1<egs.size()&&egs[j+1].w==egs[j].w)
                ++j;
            for(int k=i;k<=j;++k){
                int u=egs[k].u,v=egs[k].v;
                T w=egs[k].w;
                if(fd(u)!=fd(v))
                    ans.insert(egs[k].idx);
            }
            for(int k=i;k<=j;++k){
                int u=egs[k].u,v=egs[k].v;
                T w=egs[k].w;
                if(fd(u)!=fd(v))
                    lk(u,v),tree.insert(egs[k].idx),cost+=w;
            }
            i=j;
        }
        return make_pair(ans,tree);
    }
    int run(){
        int cost=0;
        sort(egs.begin(),egs.end());
        for(int i=1;i<=n;++i)
            pr[i]=i;
        for(int i=0;i<egs.size();++i){
            int j=i;
            while(j+1<egs.size()&&egs[j+1].w==egs[j].w)
                ++j;
            for(int k=i;k<=j;++k){
                int u=egs[k].u,v=egs[k].v;
                T w=egs[k].w;
                if(fd(u)!=fd(v))
                    lk(u,v),cost+=w;
            }
            i=j;
        }
        return cost;
    }
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& e) {
        MinimumSpanningTree t1(n);
        for(int i=0;i<e.size();++i)t1.add(e[i][0],e[i][1],e[i][2],i);
        int cost;
        auto t1_ans=t1.run(cost);
        auto some=t1_ans.second,sudo=t1_ans.first;
        set<int>cri;
        for(auto j:some){
            MinimumSpanningTree t(n);
            for(int i=0;i<e.size();++i)if(i!=j)t.add(e[i][0],e[i][1],e[i][2],i);
            int c2=t.run();
            if(c2!=cost)cri.insert(j);
        }
        vector<int>a,b;
        for(auto i:cri)a.push_back(i);
        for(auto i:sudo)if(!cri.count(i))b.push_back(i);
        return {a,b};
    }
};
