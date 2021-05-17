class Solution {
public:
    string entityParser(string text) {
        string ans;
        for(int i=0;i<text.size();++i){
            if(text[i]!='&'){
                ans.push_back(text[i]);
            }else{
                int j=i+1;
                string t;
                t.push_back(text[i]);
                while(j!=text.size()&&j-i+1<10&&text[j]!=';'){
                    t.push_back(text[j]);
                    ++j;
                }
                if(j==text.size()||text[j]!=';'){
                    ans.push_back(text[i]);
                }else{
                    t.push_back(';');
                    i=j;
                    if(t=="&quot;")
                        ans.push_back('"');
                     else if(t=="&apos;")
                        ans.push_back('\'');
                     else if(t=="&amp;")ans.push_back('&');
                     else if(t=="&gt;")ans.push_back('>');
                     else if(t=="&lt;")ans.push_back('<');
                     else if(t=="&frasl;")ans.push_back('/');
                    else{
                        for(auto cc:t)ans.push_back(cc);
                    }
                       
                }
            }
        }
       return ans;
    }
};
