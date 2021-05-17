class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        vector<int>l(a.size()),r(a.size());
        for(int i=0;i<a.size();++i)
            if(!i||a[i]>=a[i-1]&&l[i-1])
                l[i]=1;
        for(int i=a.size()-1;i>=0;--i)
            if(i+1==a.size()||a[i]<=a[i+1]&&r[i+1])
                r[i]=1;
        if(r[0]||r[1]||l[a.size()-2])
            return true;
        for(int i=1;i+1<a.size();++i)
            if(l[i-1]&&r[i+1]&&a[i-1]<=a[i+1])
                return true;
        return false;
    }
};
