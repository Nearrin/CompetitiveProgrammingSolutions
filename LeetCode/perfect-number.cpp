class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(!num)return 0;
        int t=0;
        for(int i=1;i*i<=num;++i){
            if(num%i==0){
                t+=i;
                if(i!=num/i)
                    t+=num/i;
            }
        }
        return t==num*2;
    }
};
