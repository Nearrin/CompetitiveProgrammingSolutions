unordered_map<int,int>f;
int g(int x){
    if(f.count(x))return f[x];
    auto&t=f[x];
    if(x==1)return t=0;
    if(x%2==0)return t=g(x/2)+1;
    return t=g(x*3+1)+1;
}
bool cmp(int x,int y){
    if(g(x)!=g(y))return g(x)<g(y);
    return x<y;
}
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<int>tmp;
        for(int i=lo;i<=hi;++i)tmp.push_back(i);
        sort(tmp.begin(),tmp.end(),cmp);
        return tmp[k-1];
    }
};
