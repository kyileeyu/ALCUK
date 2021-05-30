
// BOJ 10423: 전기가 부족해

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
priority_queue<pair<int, pair<int, int>>>pq;
int parent[1005],cnt=0;
vector<int>power;


int find(int x){
    if(parent[x]==x)return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return;
    cnt++;
    
    auto isPowerplant = find(power.begin(),power.end(),b);

    if(isPowerplant == power.end())  parent[b] =a;
    else parent[a] = b;
       
}
  
int main(){
    int n,m,k,wei=0;
    cin >> n >> m >> k;
    
    for(int i=1 ; i<=n; i++)    parent[i]=i;
    for(int i=0;i<k;i++){
        int p;
        scanf("%d",&p);
        power.push_back(p);
    }

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
        
        //발전소끼리 잇는지 확인
        if( find(power.begin(),power.end(),u) < power.end() &&
           find(power.begin(),power.end(),v) < power.end()){        //둘다발전소임
            continue;
        }
        if(u==v)  continue;
        merge(u,v);
        wei += cost;
        if(n-k == cnt) break;
        
    }
    cout << wei<<"\n";
}
    
    

