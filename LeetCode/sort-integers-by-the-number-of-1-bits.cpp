int cnt(int v){
    if(v==0)return 0;
    return cnt(v/2)+v%2;
}
bool cmp(int x,int y){
    if(cnt(x)!=cnt(y))
        return cnt(x)<cnt(y);
    return x<y;
}
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};
