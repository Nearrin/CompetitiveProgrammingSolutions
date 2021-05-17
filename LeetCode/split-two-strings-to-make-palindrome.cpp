int center(const string&a){
    int n=a.size();
    if(n%2==0){
        int ans=0;
        int l=n/2-1;
        int r=n/2;
        while(r<n){
            if(a[l]==a[r]){
                ans+=2;
                --l,++r;
            }else break;
        }
        return ans;
    }else{
         int ans=1;
        int l=n/2-1;
        int r=n/2+1;
        while(r<n){
            if(a[l]==a[r]){
                ans+=2;
                --l,++r;
            }else break;
        }
        return ans;
    }
}
bool check(const string& a, const string& b){
    int l1=0;
    int n=a.size();
    for(int i=0;i<a.size();++i){
        if(a[i]==b[n-i-1]){
            l1=i+1;
        }else break;
    }
    return l1*2+max(center(a),center(b))>=n;
}
class Solution {
public:
    bool checkPalindromeFormation(const string& a, const string& b) {
        return check(a,b)||check(b,a);
    }
};
