class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1)return "";
        int cnta=0;
        for(int i=0;i<palindrome.size();++i)if(palindrome[i]=='a')++cnta;
        if(cnta+1==palindrome.size()&&palindrome[palindrome.size()/2]!='a'){
             palindrome[palindrome.size()-1]='b';
            return palindrome;
        }
        if(cnta!=palindrome.size()){
            for(int i=0;i<palindrome.size();++i)if(palindrome[i]!='a'){palindrome[i]='a';break;}
            return palindrome;
        }else{
            
            palindrome[palindrome.size()-1]='b';
            return palindrome;
        }
    }
};
