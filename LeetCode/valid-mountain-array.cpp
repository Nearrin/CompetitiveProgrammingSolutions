class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3)return false;
        int i=0;
        while(i+1<A.size()&&A[i+1]>A[i])++i;
        int j=A.size()-1;
        while(j&&A[j-1]>A[j])--j;
        return i==j&&i&&i!=A.size()-1;
    }
};
