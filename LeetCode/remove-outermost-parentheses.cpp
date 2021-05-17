class Solution {
public:
    string removeOuterParentheses(string a) {
        string b;
        for(int i=0;i<a.size();++i)
        {
            int s=0;
            int j=i;
            while(true){
                s+=a[j]=='('?1:-1;
                if(!s)break;
                ++j;
            }
            b+=a.substr(i+1,j-i-1);
            i=j;
        }
        return b;
    }
};
