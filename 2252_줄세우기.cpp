//
//  main.cpp
//  Topological_Sort
//
//  Created by 뜽효니 on 2021/05/14.

//2252
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector <int> v[35000];
queue <int> q;
int len[100005];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        len[b]++;
    }

    for(int i=1; i<=n; i++){
        if(len[i] == 0)
            q.push(i);
    }
    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        printf("%d ",now);

        for(int i=0; i<v[now].size(); i++){
            int next = v[now][i];
            len[next]--;

            if(len[next]==0) q.push(next);
        }
    }
}
