struct rabin_karp_algorithm{
    rabin_karp_algorithm(const string&s):n(s.size()),h(0){
        for(int i=0;i<n;++i){
            h=(long long)h*26%1073741789+(s[i]-'a');
            if(h>=1073741789)h-=1073741789;
        }
    }
    rabin_karp_algorithm(int n_,int h_):n(n_),h(h_){}
    static int power(int x){
        while(p.size()<=x)
            p.push_back((long long)p.back()*26%1073741789);
        return p[x];
    }
    int n,h;
    static vector<int>p;
};
vector<int>rabin_karp_algorithm::p(1,1);
rabin_karp_algorithm operator+(const rabin_karp_algorithm&a,const rabin_karp_algorithm&b){
    return rabin_karp_algorithm(a.n+b.n,((long long)a.h*rabin_karp_algorithm::power(b.n)+b.h)%1073741789);    
}
bool operator==(const rabin_karp_algorithm&a,const rabin_karp_algorithm&b){
    return a.h==b.h;
}
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<rabin_karp_algorithm>p,n;
        for(auto s:words){
            p.push_back(rabin_karp_algorithm(s));
            reverse(begin(s),end(s));
            n.push_back(rabin_karp_algorithm(s));
        }
       vector<vector<int>> ans;
        for(int i=0;i<words.size();++i){
            for(int j=0;j<words.size();++j){
                if(words[j].size()&&words[i].size()&&words[i][0]!=words[j].back())continue;
                if(i!=j)
                if(p[i]+p[j]==n[j]+n[i]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
