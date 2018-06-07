#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
void recurprint(int n,vector<int> &parent){
	if(n==1)return;
	n=parent[n];
	recurprint(n,parent);
	cout<<n<<" ";
}

int main() {
	// your code goes here
	int i,j,k,n,r,e,u,v,w;    
	cin>>n>>e;
	vector<vector<pair<int,int> > > vec(n+1);
	vector<int> dist(n+1,50000),parent(n+1),vis(n+1);
	
	for(i=0;i<e;i++){
		cin>>u>>v>>w;
	vec[u].push_back({v,w});
	}
	priority_queue<pp ,vector<pp>,greater<pp>> pq;
	pp p;
	dist[1]=0;
	
	pq.push({0,1});
	
		while(!pq.empty()){
		p=pq.top();
		int u=p.second;
		vis[u]=1;
		pq.pop();
		
		for(i=0;i<vec[u].size();i++){
			w=vec[u][i].second;
			v=vec[u][i].first;
		if(!vis[v] && w<dist[v]){
			dist[v]=w;
			pq.push({dist[v],v});
			parent[v]=u;
			}	
		}
	}
	for(i=1;i<n;i++){
		cout<<i+1<<" ->> "<<parent[i+1]<<"\n";
	}
	cout<<"PATH"<<"\n";
recurprint(n,parent);
cout<<n;
	return 0;
}
