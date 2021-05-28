
// BOJ 1647: 도시 분할 계획

#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
priority_queue<pair<int, pair<int, int>>>pq;
int parent[100005];


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
    int n,m,wei=0,Mcost=0;
    cin >> n >> m;
    
    for(int i=1 ; i<=n; i++)    parent[i]=i;
    
    for(int i=0; i<m; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        pq.push({-c,{a,b}});
    }
    
    while(!pq.empty()){
        int u = find(pq.top().second.first);
        int v = find(pq.top().second.second);
        int cost = -pq.top().first;
        pq.pop();
        
        if(u==v)  continue;
        merge(u,v);
        Mcost = max(Mcost,cost);
        wei += cost;
        
    }
    cout << wei-Mcost<<"\n";
}
