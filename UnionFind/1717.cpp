
//BOJ 1717: 집합의 표현
#include <iostream>
#include <string.h>
using namespace std;
int parent[1000001];
int find(int x){
    
    if(parent[x] == x )return x;
    return parent[x] =find(parent[x]);

}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return;
    parent[b] =a ;
}

string isUnion(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return "YES";
    else return "NO";
    
}
int main(){
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)    parent[i]=i;
    
    while(m--){
        int cmd,a,b;
        scanf("%d%d%d",&cmd,&a,&b);
        if(cmd ==0) merge(a,b);
        else cout << isUnion(a,b) << "\n";
    }
    
}
