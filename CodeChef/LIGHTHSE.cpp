#include<cstdio>
#include<set>
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
//int x[110],y[110],n;
//enum T{NE,WN,WS,SE,NONE} dir[110];
//vector<vector<T> >sols;
//void print(T t){
//    switch(t){
//    case NE:cout<<"1";break;
//        case WN:cout<<"2";break;
//        case WS:cout<<"3";break;
//        case SE:cout<<"4";break;
//    case NONE:cout<<0;
//    }
//}

//int nowbest=~0u>>1;
//void init(){
//    nowbest=~0u>>1;
//    sols.clear();

//}

//void dfs(int i,int ans){
//    if(i==n+1){

//        for(int j=1;j<=n;++j){
//            int fd=0;

//            for(int k=1;k<=n;++k){
//                if(fd)break;
//                if(dir[j]!=NONE){fd=1;break;}
//                if(dir[k]==NONE){continue;}
//                else if(dir[k]==NE){
//                    if(x[j]>=x[k]&&y[j]>=y[k])
//                        fd=1;
//                } else if(dir[k]==WN){
//                    if(x[j]<=x[k]&&y[j]>=y[k])
//                        fd=1;
//                } else if(dir[k]==WS){
//                    if(x[j]<=x[k]&&y[j]<=y[k])
//                        fd=1;
//                } else if(dir[k]==SE){
//                    if(x[j]>=x[k]&&y[j]<=y[k])
//                        fd=1;
//                }
//            }

//            if(!fd)return;
//        }

//        if(ans==nowbest){
//            vector<T>tmp;
//            for(int j=1;j<=n;++j)
//                tmp.push_back(dir[j]);
//            sols.push_back(tmp);
//        }else if(ans<nowbest){
//            sols.clear();
//            vector<T>tmp;
//            for(int j=1;j<=n;++j)
//                tmp.push_back(dir[j]);
//            sols.push_back(tmp);
//            nowbest=ans;
//        }
//    }else if(ans>nowbest){

//    }else{
//        dir[i]=NE;
//        dfs(i+1,ans+1);

//        dir[i]=WN;
//        dfs(i+1,ans+1);

//     //   dir[i]=WS;
//     //   dfs(i+1,ans+1);

//    //    dir[i]=SE;
//      //  dfs(i+1,ans+1);

//        dir[i]=NONE;
//        dfs(i+1,ans);
//    }
//}
//static int x[100010],y[100010];
//void bf(){
//    srand(time(0));
//    //cin>>n;
//    n=rand()%50+1;
//    while(true){
//        for(int i=1;i<=n;++i){
//            x[i]=rand()%21-10;
//            y[i]=rand()%21-10;
//        }
//        int fail=0;
//        for(int i=1;i<=n;++i)
//            for(int j=1;j<i;++j)
//                if(x[i]==x[j]&&y[i]==y[j])
//                    fail=1;
//        if(!fail)break;
//    }
//  //  for(int i=1;i<=n;++i)
//     //   printf("(%d,%d)\n",x[i],y[i]);
//    dfs(1,0);
//    cout<<endl;
//    cout<<nowbest<<endl<<endl;
//    if(nowbest>2){
//        for(;;);
//    }

//    return;
//    for(int i=0;i<sols.size();++i){
//        for(int j=0;j<sols[i].size();++j){
//            print(sols[i][j]);
//            //cout<<" ";
//        }
//        cout<<endl;

//    }getchar();
//}
static int x[100010],y[100010];
bool cmp(int a,int b){
    return x[a]<x[b];
}


static int bx[10000],by[10000];

int main(){
  //   while(true){
   //     init();
//    bf();
//    }
  //  freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int T;
  scanf("%d",&T);
   // T=~0u>>1;
    while(T--){
        int n;scanf("%d",&n);

        int xmax=-(~0u>>1),xmin=-xmax;
        int ymax=xmax,ymin=xmin;
//        {
//            while(true){
//                    for(int i=1;i<=n;++i){
//                        bx[i]=rand()%21-10;
//                        by[i]=rand()%21-10;
//                    }
//                    int fail=0;
//                    for(int i=1;i<=n;++i)
//                        for(int j=1;j<i;++j)
//                            if(bx[i]==bx[j]&&by[i]==by[j])
//                                fail=1;
//                    if(!fail)break;
//                }


//        }
        for(int i=1;i<=n;++i){
            scanf("%d%d",&x[i],&y[i]);
           // x[i]=bx[i],y[i]=by[i];
            xmax=max(xmax,x[i]);
            xmin=min(xmin,x[i]);
            ymax=max(ymax,y[i]);
            ymin=min(ymin,y[i]);
        }
        int can1=0;

        for(int i=1;i<=n;++i){
            int fail=0;
            if(x[i]!=xmax&&x[i]!=xmin)
                fail=1;
            if(y[i]!=ymax&&y[i]!=ymin)
                fail=1;
            if(!fail)
                can1=i;
        }
        if(can1){
            printf("1\n%d ",can1);
            if(y[can1]==ymin)
                printf("N");
            else printf("S");
            if(x[can1]==xmin)
                printf("E")
                        ;else printf("W");
            printf("\n");
        }
        else{
            printf("2\n");
            vector<int>hasymin;
            for(int i=1;i<=n;++i)
                if(y[i]==ymin)
                    hasymin.push_back(i);
            int ans11=-1,ans12=-1,ans21=-1,ans22=-1;
            sort(hasymin.begin(),hasymin.end(),cmp);
            if(hasymin.size()!=1){
                int p1=hasymin.front();
                int p2=hasymin.back();
                ans11=p1;
                ans12=1;
                ans21=p2;
                ans22=2;
                printf("%d N%c\n",ans11,ans12==1?'E':'W');
                printf("%d N%c\n",ans21,ans22==1?'E':'W');
            }else{
                int p=hasymin.front();
                //p鏈濆乏
                int xmin2=~0u>>1,ymin2=~0u>>1;
                for(int i=1;i<=n;++i){
                    if(i==p)continue;
                    if(x[i]<=x[p])continue;
                    xmin2=min(xmin2,x[i]);
                    ymin2=min(ymin2,y[i]);
                }
                for(int i=1;i<=n;++i){
                    if(i==p)continue;
                    if(x[i]<=xmin2&&y[i]<=ymin2){
                        ans11=p;
                        ans12=2;
                        ans21=i;
                        ans22=1;
                    }
                }


                //p鏈濆彸
                int xmax3=-(~0u>>1),ymin3=~0u>>1;
                for(int i=1;i<=n;++i){
                    if(i==p)continue;
                    if(x[i]>=x[p])continue;
                    xmax3=max(xmax3,x[i]);
                    ymin3=min(ymin3,y[i]);
                }
                for(int i=1;i<=n;++i){
                    if(i==p)continue;
                    if(x[i]>=xmax3&&y[i]<=ymin3){
                        ans11=p;
                        ans12=1;
                        ans21=i;
                        ans22=2;
                    }
                }

                if(ans12==2){
                    swap(ans11,ans21);
                    swap(ans12,ans22);
                }

                printf("%d N%c\n",ans11,ans12==1?'E':'W');
                printf("%d N%c\n",ans21,ans22==1?'E':'W');

//                if(ans11==-1){

//                    for(int i=1;i<=n;++i)
//                        printf("(%d,%d)\n",x[i],y[i]);
//                    cout<<endl;
//                    cout<<"oops\n";
//                }



//                int fail=0;

//                for(int i=1;i<=n;++i){
//                    int cv=0;
//                    if(x[i]>=x[ans11]&&y[i]>=y[ans11])
//                        cv=1;
//                    if(x[i]<=x[ans21]&&y[i]>=y[ans21])
//                        cv=1;
//                    if(!cv)fail=1;
//                }

//                if(fail){
//                     cout<<"oops\n";
//                }

            }
        }
    }
    return 0;
}
/*
 *
 *
 *
 4
 9 3
 2 -5
 10 -2
 -2 2
*/