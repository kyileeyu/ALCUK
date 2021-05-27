
// BOJ 1197: 최소 스패닝 트리

#include <iostream>
#include <queue>
using namespace std;
int parent[10005];
priority_queue<pair<int,pair<int,int>>>pq;


int find(int x){
    if(parent[x]==x)return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return;
    parent[b] =a;
}

int main(){
    
    int V,e,wei=0;
    cin >> V>>e;
    
    for(int i=1; i<=V; i++) parent[i]=i;

    for(int i=0; i<e; i++){
        int a,b,c;                              //가중치,두정점
        scanf("%d%d%d",&a,&b,&c);
        pq.push({-c,{a,b}});
    }
    
    while(!pq.empty()){
        int u = find(pq.top().second.first);
        int v = find(pq.top().second.second);
        int cost = -pq.top().first;
        pq.pop();
        if(u==v)continue;
        merge(u,v);
        wei += cost;
        
    }
    cout << wei<<"\n";
}
