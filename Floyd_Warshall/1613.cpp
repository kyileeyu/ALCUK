//BOJ 1613: 역사

#include <iostream>
#include <algorithm>
using namespace std;

int arr[401][401];
int N,K,a,b;

void floyd_warshall(){
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if( arr[k][j]==-1 && arr[i][k]==-1){
                    arr[i][j] = -1;
                    arr[j][i] = 1;
                }
            }
        }
    }
}
int main(){
    
    cin >> N >> K;

    
    for(int i=0; i<K;i++){
        scanf("%d %d", &a, &b);
        arr[a][b]=-1;
        arr[b][a]=1;
    }
    
    floyd_warshall();
    
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d", &a, &b);
        printf("%d\n",arr[a][b]);
    }
    return 0;
}
