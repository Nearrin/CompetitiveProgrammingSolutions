class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(int &v:A){
            v*=v;
        }
        sort(begin(A),end(A));
        return A;
    }
};
