#include<iostream>
 #include<cstdio>
 #include<cmath>
 #include<cstring>
 #include<algorithm>
 using namespace std;
 #define NMAX 200011
 struct node
 {
     int num,weight;
     node *next;
 };
 pair<int,int> d1[NMAX],d2[NMAX];
 node *graph[NMAX];
 node memo[2*NMAX];
 int size[NMAX],Q[NMAX],mark[NMAX];
 int n,m,ans=NMAX,top=0,root,sumsize,minsize,tot1,tot2;
 void add(int x,int y,int z)
 {
     node *p=&memo[top++];
     p->num=y; p->weight=z; p->next=graph[x]; graph[x]=p;
     p=&memo[top++];
     p->num=x; p->weight=z; p->next=graph[y]; graph[y]=p;
 }
 void get_root(int i,int fa)
 {
     int big=-1;
     size[i]=1;
     for(node *p=graph[i];p;p=p->next)
     if(p->num!=fa)
     {
         get_root(p->num,i);
         size[i]+=size[p->num];
         if(size[p->num]>big) big=size[p->num];
     }
     if(sumsize-size[i]>big) big=sumsize-size[i];
     if(big<minsize) minsize=big,root=i;
 }
 void get_dis(int i,pair<int,int> d[], int &tot)
 {
     int left,right,u;
     Q[left=right=1]=i;
     d[++tot].first=0; d[tot].second=0; mark[i]=tot;
     while(left<=right)
     {
         u=Q[left++];
         for(node *p=graph[u];p;p=p->next)
         if(mark[p->num]==0)
         {
             d[++tot].first=d[mark[u]].first+p->weight; d[tot].second=d[mark[u]].second+1;
             mark[p->num]=tot;
             Q[++right]=p->num;
         }
     }
     for(i=1;i<=right;i++) mark[Q[i]]=0;
 }
 
 void count(int x,node *mid)
 {
     node *mid_next=mid->next,*left=graph[x];
     tot2=tot1=0;
     mid->next=NULL; 
     get_dis(x,d1,tot1);
     sort(d1+2,d1+tot1+1);
     mid->next=mid_next; graph[x]=mid_next;
     get_dis(x,d2,tot2);
     sort(d2+2,d2+tot2+1);
     for(int i=1,j=tot2;i<=tot1;i++)
     {
         while(d1[i].first+d2[j].first>m&&j>0) j--;
         while(d1[i].first+d2[j].first==m)
         {
             if(ans>d1[i].second+d2[j].second) ans=d1[i].second+d2[j].second;
             if(j>0&&d2[j-1].first==d2[j].first) j--;
             else break;
         }
     }
     graph[x]=left;
 }
 
 void dfs(int i,int size_i)
 {
     if(size_i<=2) return ;
     sumsize=minsize=size_i;
     get_root(i,-1); i=root;
     get_root(i,-1);
     int sum=0;
     node *mid,*mid_next,*left=graph[i],*p;
     for(p=graph[i];p;p=p->next)
     {
         sum+=size[p->num];
         if(sum*2>=size_i-1||p->next->next==NULL) break;
     }
     mid=p;
     count(i,mid);
     mid_next=mid->next; mid->next=NULL;
     dfs(i,sum+1);
     mid->next=mid_next; graph[i]=mid_next;
     dfs(i,size_i-sum);
     graph[i]=left;
 }
 
 int main()
 {
     int x,y,z;
     scanf("%d%d",&n,&m);
     memset(mark,0,sizeof(mark));
     memset(graph,0,sizeof(graph));
     int i;
     for(i=1;i<n;i++)
     {
         scanf("%d%d%d",&x,&y,&z);
         add(x,y,z);
     }
     dfs(0,n);
     if(ans!=NMAX)
         printf("%d\n",ans);
     else
         printf("-1\n");
     return 0;
 }
