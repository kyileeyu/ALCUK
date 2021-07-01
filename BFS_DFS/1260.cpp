//BOJ 1260: DFS와 BFS

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
bool visited[1005];
vector<int> adj[1005];
queue<int> q;

void dfs(int now){
    visited[now] = 1;
    printf("%d ",now);
    for (int i=0; i<adj[now].size(); i++){
        int next = adj[now][i];
        if (!visited[next]) dfs(next);
    }
}

void bfs(int st){
    q.push(st);
    visited[st] = 1;

    while (!q.empty()){
        int now =q.front();
        q.pop();
        printf("%d ",now);
        for (int i=0; i<adj[now].size(); i++){
            int next = adj[now][i];
            if (!visited[next]){
                visited[next] = 1;
                q.push(next);
            }
        }
    }
}

int main(){
    int n,m,v;
    int x,y;

    scanf("%d %d %d",&n ,&m ,&v);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for(int i=1; i<=n; i++){
        sort(adj[i].begin(),adj[i].end());
    }
    dfs(v);
    printf("\n");
    memset(visited,0,sizeof(visited));
    bfs(v);
    printf("\n");

}

