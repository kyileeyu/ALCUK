//BOJ 1719: 택배
#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
int n,m;
int arr[201][201];
int dist[201][201];
void floyd_warshall(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if( arr[i][j] > arr[k][j] + arr[i][k]){
                    arr[i][j] = arr[k][j] + arr[i][k];
                    dist[i][j]=dist[i][k];
                }
            }
        }
    }
}
int main(){
    cin >> n>>m;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            arr[i][j]=INF;
        }
    }
    
    for(int i=0; i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        arr[a][b]=c;
        arr[b][a]=c;
        dist[a][b]=b;
        dist[b][a]=a;
    }
    
    floyd_warshall();
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) printf("- ");
            else printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
}

