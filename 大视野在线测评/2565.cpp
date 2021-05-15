#include<bits/stdc++.h>
#define lop(i,a,b) for(auto i=a;i<=b;++i)
#define rlp(i,a,b) for(auto i=a;i>=b;--i)
#define all(a) a.begin(),a.end()
#define sqr(a) ((a)*(a))
#define pub push_back
#define pob pop_back
#define mkp make_pair
#define scf scanf
#define ptf printf
#define inf (~0u>>1)
namespace CTL{}
using namespace CTL;
using namespace std;
typedef long long lli;
typedef unsigned long long ull;
typedef string str;
typedef vector<int> vei;
typedef vector<string> ves;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef set<int> sti;
typedef set<str> sts;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#ifndef PALINDROMIC_TREE
#define PALINDROMIC_TREE
#include<bits/stdc++.h>
namespace CTL{
    using namespace std;
    struct PalindromicTree{
        struct node{
            node(int m,node*f,int l):nxt(m),fail(f),cnt(0),len(l){}
            vector<node*>nxt;node*fail;int cnt,len;}*lst;
        int m,strl;vector<int>str;vector<node*>nds;
        PalindromicTree(int _m):m(_m),strl(0){
            node*n0=new node(m,0,-2),*n1=new node(m,n0,-1),*n2=new node(m,n1,0);
            fill(n0->nxt.begin(),n0->nxt.end(),n2);str.push_back(-1);lst=n1;}
        node*getf(node*x){
            while(x->fail&&str[strl-x->len-1]!=str[strl])x=x->fail;return x;}
        node*add(int c){
            str.push_back(c);++strl;node*p=getf(lst);
            if(!p->nxt[c]){
                node*np=(p->nxt[c]=new node(m,getf(p->fail)->nxt[c],p->len+2));
                nds.push_back(np);}
            ++(lst=p->nxt[c])->cnt;return lst;}
        void count(){for(int i=nds.size()-1;i>=0;--i)nds[i]->fail->cnt+=nds[i]->cnt;}};}
#endif
        int main(){
            static char s[100010];
            scanf("%s",s+1);
            int l=strlen(s+1);
            PalindromicTree*pt=new PalindromicTree(26),*rpt=new PalindromicTree(26);
            static int dp[100010],rdp[100010];
            for(int i=1;i<=l;++i)
                dp[i]=pt->add(s[i]-'a')->len;
            for(int i=l;i>=1;--i)
                rdp[i]=rpt->add(s[i]-'a')->len;
            int ans=0;
            for(int i=1;i<=l-1;++i)
                ans=max(ans,dp[i]+rdp[i+1]);
            printf("%d\n",ans);
            return 0;
        }
