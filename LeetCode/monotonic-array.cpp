class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int t=0;
        for(int i=1;i<A.size();++i)
            if(A[i]>A[i-1])t=1;
        if(!t)return 1;
        reverse(begin(A),end(A));
           t=0;
        for(int i=1;i<A.size();++i)
            if(A[i]>A[i-1])t=1;
        if(!t)return 1;
        return 0;
    }
};
