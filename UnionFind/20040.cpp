
//BOJ 20040: 사이클게임

#include <iostream>
using namespace std;

int parent[500005]={0,};

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

int isCycle(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return 1;
    else return 0;
    
}
int main(){

    int n,m;
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        parent[i]=i;
    }
    
    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        
        
        if(isCycle(a, b)){
            printf("%d\n",i+1);
            return 0;
        }
        else merge(a,b);
        
    }
    printf("0\n");
}

