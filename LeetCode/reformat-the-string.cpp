class Solution {
public:
    string reformat(string s) {
        string a,b;
        for(auto c:s)if(c>='0'&&c<='9')a.push_back(c);
        else b.push_back(c);
        if(a.size()<b.size())swap(a,b);
        if(a.size()==b.size()||a.size()==b.size()+1){
            string tmp;
            while(a.size()||b.size()){
                if(a.size()){
                    tmp.push_back(a.back());
                    a.pop_back();
                }
                if(b.size()){
                    tmp.push_back(b.back());
                    b.pop_back();
                }
            }
            return tmp;
        }else return "";
    }
};
