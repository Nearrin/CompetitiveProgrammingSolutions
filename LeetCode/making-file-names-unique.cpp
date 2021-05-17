template <class A, class B> B conv(const A &a, B b = B()) {
    stringstream s;
    s << a, s >> b;
    return b;
}
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        map<string,int>m;
        unordered_set<string>n;
        vector<string>ans;
        for(auto t:names){
            if(!n.count(t)){
                n.insert(t);
                ans.push_back(t);
            }else{
                if(!m.count(t))m[t]=1;
                int i;
                for(i=m[t];n.count(t+"("+conv<int,string>(i)+")");++i){
                }
                m[t]=i;
                string tt=t+"("+conv<int,string>(i)+")";
                n.insert(tt);
                ans.push_back(tt);
            }
        }
        return ans;
    }
};
