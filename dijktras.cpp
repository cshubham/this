#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;


int main() {
	// your code goes here
	int i,j,k,n,r,e,u,v,w;    
	cin>>n>>e;
	vector<vector<pair<int,int> > > vec(n+1);
	vector<int> dist(n+1,50000);
	
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
		pq.pop();
		
		for(i=0;i<vec[u].size();i++){
			w=vec[u][i].second;
			v=vec[u][i].first;
		if(dist[u]+w<dist[v]){
			dist[v]=dist[u]+w;
			pq.push({dist[v],v});
			}	
		}
	}
	for(i=0;i<n;i++){
		cout<<i+1<<" -> "<<dist[i+1]<<"\n";
	}
	return 0;
}
