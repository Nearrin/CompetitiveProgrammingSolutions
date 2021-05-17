class Solution {
public:
    string largestTimeFromDigits(vector<int>& a) {
        sort(begin(a),end(a));
        set<string>ans;
        do{
            int h=(a[0]-0)*10+a[1]-0;
            int m=(a[2]-0)*10+a[3]-0;
            string tmp;
            tmp.push_back(a[0]+'0');
            tmp.push_back(a[1]+'0');
            tmp.push_back(':');
            tmp.push_back(a[2]+'0');
            tmp.push_back(a[3]+'0');
            if(h<=23&&m<=59)
                ans.insert(tmp);
        }while(next_permutation(begin(a),end(a)));
        if(ans.size()==0)return "";
        return *ans.rbegin();
    }
};
