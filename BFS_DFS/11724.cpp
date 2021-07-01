// BOJ 11724: 연결 요소의 개수

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

bool visited[1005];
vector<int> adj[1005];

void dfs(int now){
    visited[now] = 1;
    for (int i=0; i<adj[now].size(); i++){
        int next = adj[now][i];
        if (!visited[next]) dfs(next);
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n, &m);
    for(int i=0; i<m; i++){
        int x,y;
        scanf("%d %d",&x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    printf("%d\n",cnt);
    
}

