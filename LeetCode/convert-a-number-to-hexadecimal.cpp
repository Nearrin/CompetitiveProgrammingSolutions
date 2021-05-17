class Solution {
public:
    string toHex(int num) {
        string ans;
        for(int i=7;i>=0;--i){
            int t=num>>(4*i);
            t&=15;
            if(i==0||t||ans.size())ans.push_back(t<10?'0'+t:'a'+t-10);
        }
        return ans;
    }
};
