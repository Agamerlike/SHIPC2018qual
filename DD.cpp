#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#include <functional>
typedef long long ll;


using namespace std;

typedef pair<ll,int> P;

class Edge
{
	public:
	ll cost;
	int from;
	int to;

	Edge(int n,ll c)
	{
		to=n;
		cost=c;
	}

	Edge(int f,int t,int c)
	{
		from=f;
		to=t;
		cost=c;
	}
};

vector<Edge> eng[100000];
vector<Edge> snug[100000];
ll endd[100000];
ll snud[100000];
ll zansnu[100000];//それぞれの料金所を経由したときの残スヌーク

void dijk(int s,ll d[],vector<Edge> g[])
{
	priority_queue<P,vector<P>,greater<P>> que;
	fill(d,d+100000,1e9-1);
	d[s]=0;
	que.push(P(0,s));
	while(!que.empty())
	{
		P p=que.top();
		que.pop();
		int v=p.second;
		if(d[v]<p.first)
			continue;
		for(int i=0;i<g[v].size();i++)
		{
			Edge e=g[v][i];
			if(d[e.to]>d[v]+e.cost)
			{
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}

int main()
{
	int n,m,s,t;
	P best;//最もスヌークが多くなるときに経由する両替所とコスト
	cin>>n>>m>>s>>t;
	s--;t--;
	for(int i=0;i<m;i++)
	{
		int u,v;
		ll a,b;
		cin>>u>>v>>a>>b;
		u--;v--;
		eng[u].push_back(Edge(v,a));
		eng[v].push_back(Edge(u,a));
		snug[u].push_back(Edge(v,b));
		snug[v].push_back(Edge(u,b));
	}

	dijk(s,endd,eng);//あらかじめ円のほうは最短路を求めておく
	dijk(t,snud,snug);//snuの方はゴールからの最短路を求めておく
	for(int i=0;i<n;i++)
	{
		zansnu[i]=1e15-(endd[i]+snud[i]);
	}

	for(int i=n-2;i>-1;i--)
	{
		zansnu[i]=max(zansnu[i],zansnu[i+1]);
	}
	
	for(int i=0;i<n;i++)
		cout<<zansnu[i]<<endl;
	return 0;
}