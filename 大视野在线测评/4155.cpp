#include<queue>
#include<vector>
using namespace std;
template<class FLOW = int>struct MF{
	struct edge{
	public:
		int v;
		FLOW c,l;
		edge(int _v,FLOW _c):
			v(_v),c(_c),l(_c){
		}
	};
	vector<edge>edges;
	vector<vector<int> >start;
	vector<int>height,gap,cur,from;
	int n,source,sink;
	void label(){
		height[sink] = 0;
		queue<int>qu;
		qu.push(sink);
		while(!qu.empty()){
			int u = qu.front();
			qu.pop();
			for(int i = 0;i<start[u].size();++i){
				edge&e = edges[start[u][i]],&ev = edges[start[u][i]^1];
				if(ev.c>0&&height[e.v]==n){
					height[e.v] = height[u]+1;
					qu.push(e.v);
				}
			}
		}
		for(int i = 0;i<n;++i)
			++gap[height[i]];
	}
	FLOW augment(){
		FLOW f = 0;
		for(int u = sink;u!=source;u = edges[from[u]^1].v)
			if(f<=0||f>edges[from[u]].c)
			f = edges[from[u]].c;
		for(int u = sink;u!=source;u = edges[from[u]^1].v){
			edges[from[u]].c -= f;
			edges[from[u]^1].c += f;
		}
		return f;
	}
	MF(int _n,int _source,int _sink):
		start(_n),height(_n,_n),gap(_n+1),n(_n),
		cur(_n),from(_n),source(_source-1),sink(_sink-1){
	}
	void add(int u,int v,FLOW c){
		start[u-1].push_back(edges.size());
		edges.push_back(edge(v-1,c));
		start[v-1].push_back(edges.size());
		edges.push_back(edge(u-1,0));
	}
	FLOW run(){
		label();
		FLOW r = 0;
		int u = source;
		while(height[source]!=n){
			if(u==sink){
				r += augment();
				u = source;
			}
			bool flag = false;
			for(int i = cur[u];i<start[u].size();++i){
				edge&e = edges[start[u][i]];
				if(e.c>0&&height[u]==height[e.v]+1){
					flag = true;
					from[e.v] = start[u][i];
					u = e.v;
					break;
				}
			}
			if(!flag){
				int mh = n-1;
				for(int i = 0;i<start[u].size();++i){
					edge&e = edges[start[u][i]];
					if(e.c>0&&mh>height[e.v])
						mh = height[e.v];
				}
				if(!--gap[height[u]])
					break;
				++gap[height[u] = mh+1];
				cur[u] = 0;
				if(u!=source)
					u = edges[from[u]^1].v;
			}
		}
		return r;
	}
};
#include<iostream>
#include<bitset>
int main(){
	int t;cin>>t;
	while(t--){
		int n,m;
		static int d[1010];
		cin>>n>>m;
		MF<> mf(n,1,2);
		fill(d+1,d+n+1,0);
		for(int i = 1;i<=m;++i){
			int u,v;
			cin>>u>>v;
			mf.add(u,v,1);
			mf.add(v,u,1);
			++d[u];
			++d[v];
		}
		cout<<m-mf.run()<<" ";
		vector<bitset<40000> >f(n+1);
		f[2][d[1]] = 1;
		for(int i = 3;i<=n;++i)
			f[i] = ((f[i-1]<<d[i])|f[i-1]);
		int ans = ~0u>>1;
		for(int i = 0;i<40000;++i)
			if(f[n][i]){
				int t1 = i;
				int t2 = 2*m-i;
				if(t1<t2)swap(t1,t2);
				ans = min(ans,(t1-t2)/2);
			}
		cout<<ans<<endl;


	}
	return 0;
}
