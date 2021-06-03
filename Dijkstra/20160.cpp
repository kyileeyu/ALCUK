#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
typedef long long ll;
using namespace std;
ll V,E;
const ll INF = 1e15;
typedef pair<long long, long long> pll;
vector<vector<pair<int,int>>> road;

vector <ll> dijkstra(ll prev, ll node){
    vector <ll> dist(V+1, INF);
    dist[node] = prev;
    
    priority_queue <pll> pq;
    pq.push(make_pair(-dist[node],node));
    
    while (!pq.empty()) {
        ll cost = -pq.top().first;
        ll here = pq.top().second;
        pq.pop();
        
        if(dist[here] < cost) continue;
        
        for(int i=0; i<road[here].size(); i++){
            ll next = road[here][i].first;
            ll next_cost = road[here][i].second;
            
            if(dist[next] > dist[here]+next_cost){
                dist[next] = dist[here] + next_cost ;
                pq.push(make_pair(-dist[next], next));
            }
                
        }
        
    }
    return dist;
}

int main(){
    
    cin >> V >> E;
    road.resize(V+1);
    for(int i=0; i<E; i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        road[u].push_back({v,w});
        road[v].push_back({u,w});
    }
    pll node[10] = { {0,0},};
    ll prev_dist, prev_node;
    for(int i=0; i<10; i++){
        cin >> node[i].first;
    
        if(!i){
            prev_dist =0;
            prev_node = node[i].first;
            continue;
        }
        vector <ll> dist = dijkstra(prev_dist, prev_node);
        if(dist[node[i].first] != INF){
            prev_dist = dist[node[i].first];
            prev_node = node[i].first;
        }
        node[i].second = dist[node[i].first];
    }
    
    ll start,ansNode = V+1;
    scanf("%lld",&start);
    
    vector <ll> ansDist = dijkstra(0,start);
    for (int i=0; i<10; i++){
        if(node[i].second == INF) continue;
        if(node[i].second >= ansDist[node[i].first]){
            ansNode = min(node[i].first,ansNode);
        }
    }
    if(ansNode == V+1) printf("-1\n");
    else printf("%lld\n",ansNode);
    
}

