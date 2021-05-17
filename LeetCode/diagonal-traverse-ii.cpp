bool cmp(pair<int,int>a,pair<int,int>b){
    int sa=a.first+a.second,sb=b.first+b.second;
    if(sa!=sb)return sa<sb;
    return a.second<b.second;
}
bool cmp(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b){
    return cmp(a.first,b.first);
}
struct cp{
  bool operator()  (pair<pair<int,int>,int>a,pair<pair<int,int>,int>b){
      return cmp(a.first,b.first);
  }
};
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& a) {
        vector<pair<pair<int,int>,int>>b;
        for(int i=0;i<a.size();++i){
            for(int j=0;j<a[i].size();++j){
                b.push_back({{i,j},a[i][j]});
            }
        }
        sort(begin(b),end(b),cp());
        vector<int>c;
        for(auto t:b)c.push_back(t.second);
        return c;
    }
};
