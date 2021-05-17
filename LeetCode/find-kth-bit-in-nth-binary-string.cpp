class Solution {
public:
    char findKthBit(int n, int k,int p=0) {
        if(n==1)return '0' +p;
        int d=(1<<(n-1))-1;
        if(k==d+1)return '1'-p;
        if(k<=d)return findKthBit(n-1,k,p);
        return findKthBit(n-1,d-(k-d-1)+1,1-p);
    }
};
