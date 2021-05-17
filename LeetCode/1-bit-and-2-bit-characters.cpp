class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int last=0;
        for(int i=0;i<bits.size();++i){
            if(bits[i]==0)last=1;
            else last=0,++i;
        }
        return last;
    }
};
