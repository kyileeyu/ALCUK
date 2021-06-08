// BOJ 11265: 끝나지 않는 파티

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[505][505];

int main(){
    int n,m;
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n;j++){
                if(arr[i][j] > arr[i][k]+arr[k][j]){
                    arr[i][j] = arr[i][k]+arr[k][j];
                }
            }
        }
    }
    
    for(int i=0; i<m; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        
        if(arr[a][b]<=c){
            printf("Enjoy other party\n");
        }
        else printf("Stay here\n");
    }
    
}

