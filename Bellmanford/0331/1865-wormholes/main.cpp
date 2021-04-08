//
//  main.cpp
//  03.31.2021
//
//  Created by 뜽효니 on 2021/03/31.
//

// 1865번 웜홀
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,w;
int s,e,t;

const int INF =1e9;

int main(){
    int TC;
    cin >> TC;
    
    while(TC--){
        
        scanf("%d %d %d",&n,&m,&w);
        
        typedef pair<int,int> p;
        vector <p> edge[501];
        for(int i=1; i<=n; i++){
            edge[i].clear();
        }
        
        for(int i=0; i<m; i++){
            scanf("%d %d %d",&s,&e,&t);
            edge[s].push_back({e,t});
            edge[e].push_back({s,t});
        }
        
        for(int i=0; i<w; i++){
            scanf("%d %d %d",&s,&e,&t);
            edge[s].push_back({e,-t});
        }
        
        int dist[501];
        fill(dist,dist+501,INF);
        dist[1]=0;
        bool cycle=false;

        
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n;i++){
                for(int j=0; j<edge[i].size(); j++){
                    
                    int n_vertex = edge[i][j].first;
                    int nextcost = edge[i][j].second;
                    
                    if ( dist[n_vertex] > dist[i] + nextcost){
                        dist[n_vertex] = dist[i] + nextcost;
                        if(k==n) cycle =true;
                    }
                }
            }
        }
        
        if(cycle) printf("YES\n");
        else printf("NO\n");
    }
}

