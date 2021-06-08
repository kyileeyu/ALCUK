//BOJ 14938: 서강 그라운드


#include <iostream>
#include <algorithm>
#include <math.h>
#define INF 987654321
using namespace std;
int arr[105][105];
int item[105];
int n,m,r,ans;

void floyd_warshall(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(arr[i][j] > arr[k][j] + arr[i][k])
                    arr[i][j] = arr[k][j] + arr[i][k];
            }
        }
    }
}

int main(){
    cin >> n >> m >> r;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) arr[i][j]=0;
            else arr[i][j]=INF;
        }
    }
    
    for(int i=1; i<=n; i++){
        scanf("%d",&item[i]);
    }
    for(int i=0; i<r; i++){
        int a,b,l;
        scanf("%d %d %d",&a,&b,&l);
        arr[a][b]=l;
        arr[b][a]=l;
    }
    
    
    floyd_warshall();
    
    for(int i=1; i<=n; i++){
        int tmp=item[i];
        for(int j=1; j<=n; j++){
            if(i!= j && m>=arr[i][j]) tmp+=item[j];
        }
        ans = max(tmp,ans);
    }
    printf("%d\n",ans);
}


