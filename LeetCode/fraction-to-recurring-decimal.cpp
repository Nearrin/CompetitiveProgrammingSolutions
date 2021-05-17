class Solution {
public:
    #define int long long
    string fractionToDecimal(int p, int q) {
        string sign;
        if(p<0&&q>0)sign="-";
        if(p>0&&q<0)sign="-";
        p=abs(p),q=abs(q);
        string ans=sign+to_string(p/q)+".";
        p%=q;
        unordered_map<int,int>idx;
        string ans2;
        int myidx=-1;
        idx[p]=0;
        while(p){
            int tmp=(long long)p*10/q;
            p=(long long)p*10%q;
            ans2.push_back('0'+tmp);
            if(idx.count(p)){
                myidx=idx[p];
                break;
            }
            else{
                idx[p]=ans2.size();
            }
        }
        if(ans2.empty()){
            ans.pop_back();
            return ans;
        }
        if(myidx==-1)return ans+ans2;
        for(int i=0;i<ans2.size();++i){
            if(i==myidx)ans.push_back('(');
            ans.push_back(ans2[i]);
        }
        ans.push_back(')');
        return ans;
    }
    #undef int
};
