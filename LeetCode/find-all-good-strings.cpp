template <class T> struct kmp_algorithm {
    kmp_algorithm(const T &_b) : b(_b), p(b.size(), -1),go(b.size(),vector<int>(256,-1)) {
        int j = 0;
        for (int i = 1; i < b.size(); ++i) {
            j = p[i - 1];
            for (; j != -1 && b[j + 1] != b[i]; j = p[j])
                ;
            p[i] = j + (b[j + 1] == b[i]);
        }
        for(int j=-1;j<int(b.size())-1;++j){
            for(char c='a';c<='z';++c){
                int nj=j;
                for (; nj != -1 && b[nj + 1] != c; nj = p[nj]);
                nj+=(b[nj+1]==c);
                if(nj+1!=b.size()){
                    //cout<<"go "<<j+1<<" "<<c<<" "<<nj+1<<endl;
                    go[j+1][c]=nj+1;
                }
            }
        }
    }
    auto run(const T &a) {
        vector<vector<int>>f(b.size(),vector<int>(a.size()+1));
        for(int i=0;i<=a.size();++i){
            for(int s=0;s<b.size();++s){
                if(i==0){
                    f[s][i]=1;
                }else{
                    for(char c='a';c<='z';++c){
                        if(go[s][c]!=-1){
                            f[s][i]+=f[go[s][c]][i-1];
                            f[s][i]%=int(1e9+7);
                        }
                    
                    }
                }
            }
        }
        int r=0;
        for(char c='a';c<a[0];++c){
            if(go[0][c]!=-1){
                r+=f[go[0][c]][a.size()-1];
                r%=int(1e9+7);
            }
        }
        for (int i = 0, j = -1; i < a.size(); ++i) {
            for (; j != -1 && b[j + 1] != a[i]; j = p[j])
                ;
            j += (b[j + 1] == a[i]);
            if(j+1==b.size()){
                break;
            }
            if(i+1==a.size()){
                r+=1;
                r%=int(1e9+7);
            }else{
                for(char c='a';c<a[i+1];++c){
                     if(go[j+1][c]!=-1){
                        r+=f[go[j+1][c]][a.size()-(i+1)-1];
                        r%=int(1e9+7);
                    }
                }
            }
        }
        return r;
    }
    T b;
    vector<int> p;
    vector<vector<int>>go;
};
int count(string a,string b){
    return kmp_algorithm(b).run(a);
}
class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        if(s1>s2)return 0;
        if(s1==string(n,'a'))return count(s2,evil);
        int i=n-1;
        while(s1[i]=='a')--i;
        --s1[i];
        for(int j=i+1;j<n;++j)s1[j]='z';
        int tmp=count(s2,evil)-count(s1,evil);
        if(tmp<0)tmp+=int(1e9+7);
        return tmp;
    }
};
