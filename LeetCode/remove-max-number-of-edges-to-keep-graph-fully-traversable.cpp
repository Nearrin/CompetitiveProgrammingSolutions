#include <bits/stdc++.h>
using namespace std;
namespace union_find_set {
struct statistic;
template <class T = statistic> struct union_find_set {
    int n;
    vector<int> p, r;
    union_find_set(int _n) : n(_n), p(n), r(n) {
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }
    int find(int x) { return  p[x]==x?x:p[x]=find(p[x]);}
    void link(int x, int y) {
        p[find(x)]=y;
    }
};
} // namespace union_find_set
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int numboth=0;
        union_find_set::union_find_set<>f1(n);
        for(auto e:edges){
            if(e[0]==3&&f1.find(e[1]-1)!=f1.find(e[2]-1)){
                f1.link(e[1]-1,e[2]-1);
                ++numboth;
            }
        }
        auto f2=f1;
        int cnt1=0;
         for(auto e:edges){
            if(e[0]==1&&f1.find(e[1]-1)!=f1.find(e[2]-1)){
                f1.link(e[1]-1,e[2]-1);
                ++cnt1;
            }
        }
        if(cnt1+numboth!=n-1)return -1;
        int cnt2=0;
         for(auto e:edges){
            if(e[0]==2&&f2.find(e[1]-1)!=f2.find(e[2]-1)){
                f2.link(e[1]-1,e[2]-1);
                ++cnt2;
            }
        }
        if(cnt2+numboth!=n-1)return -1;
        return edges.size()-numboth-cnt1-cnt2;
    }
};
