class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        sort(begin(A),end(A),[](int x,int y){return (x&1)<(y&1);});
        return A;
    }
};
