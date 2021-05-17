class Solution {
public:
    vector<string> expand(string S) {
        function<vector<string>(int)>f=[&](int i){
            if(i==S.size())
                return vector<string>(1);
            if(S[i]!='{'){
                auto t=f(i+1);
                for(auto&v:t)
                    v.push_back(S[i]);
                return t;
            }
            int j=i;
            vector<char>tmp;
            while(S[j]!='}'){
                if(S[j]!='{'&&S[j]!=',')
                    tmp.push_back(S[j]);++j;
            }
            sort(begin(tmp),end(tmp));
            auto tmp2=f(j+1);
            vector<string>ans;
            for(auto c:tmp)for(auto cc:tmp2){
                cc.push_back(c);
                ans.push_back(cc);
            }
            return ans;
        };
        auto ans=f(0);
        for(auto&v:ans)
            reverse(begin(v),end(v));
        return ans;
    }
};
