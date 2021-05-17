class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<vector<int>>a(3);
        int s=0;
        for(auto v:digits){
            a[v%3].push_back(v);
            s=(s+v)%3;
        }
        for(int i=0;i<3;++i)sort(begin(a[i]),end(a[i])),reverse(begin(a[i]),end(a[i]));
        if(s==1){
            if(a[1].size()!=0){
                a[1].pop_back();
            }else if(a[2].size()>=2){
                a[2].pop_back();
                a[2].pop_back();
            }else{
                return "";
            }
        }else if(s==2){
            if(a[2].size()!=0){
                a[2].pop_back();
            }else if(a[1].size()>=2){
                 a[1].pop_back();
                a[1].pop_back();
            }else{
                return "";
            }
        }
        vector<int>b;
        for(int i=0;i<3;++i)for(auto v:a[i])b.push_back(v);
        sort(b.begin(),b.end());
        while(b.size()>1&&b.back()==0)b.pop_back();
        string st;
        for(auto i=b.rbegin();i!=b.rend();++i)st.push_back('0'+*i);
        return st;
    }
};
