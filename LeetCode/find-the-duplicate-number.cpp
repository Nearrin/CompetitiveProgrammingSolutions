class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int x=0,y=0;
        do{
            x=a[x],y=a[a[y]];
        }while(x!=y);
        x=0;
        while(x!=y){
            x=a[x],y=a[y];
        }
        return x;
    }
};
