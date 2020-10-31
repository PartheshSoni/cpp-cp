#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct dijkstra{
  int n;
  const ll INF = 4e18;
  vector<ll> dists;
  vector<int> parent;
  vector<bool> visited;
  vector<vector<pair<ll, int>>> graph;

  void init(int n){
    this->n = n;
    dists = vector<ll>(n);
    parent = vector<int>(n);
    visited = vector<bool>(n);
    graph = vector<vector<pair<ll, int>>>(n);
  }
  
  void edge(int u, int v, ll w){
    // Graph nodes
    graph[u].push_back(make_pair(w, v));
    graph[v].push_back(make_pair(w, u));
  }

  using ptype = pair<ll, int>;
  void run(int src){
    fill(visited.begin(), visited.end(), false);
    fill(parent.begin(), parent.end(), -1);
    fill(dists.begin(), dists.end(), INF);

    priority_queue<ptype, vector<ptype>, greater<ptype>> pq;
    dists[src] = 0;
    // Distance nodes, distance from the selected graphs.
    pq.push(make_pair(dists[src], src));
    while(!pq.empty()){
      ptype temp = pq.top();
      pq.pop();

      if(visited[temp.second])
        continue;
      
      visited[temp.second] = true;

      dists[temp.second] = min(dists[temp.second], temp.first);

      for(ptype node: graph[temp.second]){
        ll d = node.first + dists[temp.second];
        if(d < dists[node.second]){
          dists[node.second] = d;
          parent[node.second] = temp.second;
          pq.push(make_pair(d, node.second));
        }
      }
    }
  }
};