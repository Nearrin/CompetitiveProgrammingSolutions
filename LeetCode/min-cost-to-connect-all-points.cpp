#include <bits/stdc++.h>
using namespace std;
namespace minimum_spanning_tree {
template <class T, class C = less<T>> struct minimum_spanning_tree {
    struct edge {
        T w;
        int u, v;
        int operator<(const edge &b) const { return C()(w, b.w); }
    };
    int n;
    vector<edge> egs;
    vector<int> pr;
    minimum_spanning_tree(int _n) : n(_n), pr(n + 1) {}
    void add(int u, int v, T w) {
        edge e;
        e.u = u;
        e.v = v;
        e.w = w;
        egs.push_back(e);
    }
    int fd(int x) { return x == pr[x] ? x : pr[x] = fd(pr[x]); }
    void lk(int x, int y) { pr[fd(x)] = y; }
    T run() {
        T sum = 0;
        sort(egs.begin(), egs.end());
        for (int i = 1; i <= n; ++i)
            pr[i] = i;
        for (int i = 0; i < egs.size(); ++i) {
            int u = egs[i].u, v = egs[i].v;
            T w = egs[i].w;
            if (fd(u) != fd(v))
                lk(u, v), sum += w;
        }
        return sum;
    }
};
} // namespace minimum_spanning_tree
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        minimum_spanning_tree::minimum_spanning_tree<int>tree(n);
        for(int i=0;i<points.size();++i){
            for(int j=i+1;j<points.size();++j){
                tree.add(i,j,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]));
            }
        }
        return tree.run();
    }
};
