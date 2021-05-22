
//BOJ 1976: 여행가자

#include <iostream>
using namespace std;
int parent[205]={0,};
int plan[1005];

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

int isUnion(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b) return 0;
    else return 1;
    
}
int main(){

    int n,m,tmp;
    scanf("%d",&n);
    scanf("%d",&m);
    
    for(int i=1; i<=n;i++){
        parent[i]=i;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1; j<=n; j++){
            scanf("%d",&tmp);
            if(tmp ==1) merge(i,j);
        }
    }

    for(int i=0; i<m; i++) scanf("%d", &plan[i]);
    for(int i=0; i<m-1; i++){
        if(!isUnion(plan[i],plan[i+1])){
            printf("NO\n");
            return 0;
        };
        
    }
    printf("YES\n");
}

