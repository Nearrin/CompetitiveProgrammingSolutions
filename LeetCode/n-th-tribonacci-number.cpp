class Solution {
public:
    int tribonacci(int n) {
        vector<int>p(100);
        p[1]=p[2]=1;
        for(int i=3;i<=n;++i)p[i]=p[i-1]+p[i-2]+p[i-3];
        return p[n];
    }
};
