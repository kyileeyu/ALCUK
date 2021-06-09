//BOJ 1956: 운동

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF 987654321

int arr[401][401];
int v,e;

void floyd_warshall(){
    for(int k=1; k<=v; k++){
        for(int i=1; i<=v; i++){
            for(int j=1; j<=v; j++){
                if( arr[i][j] > arr[k][j] + arr[i][k]){
                    arr[i][j] = arr[k][j] + arr[i][k];
                }
            }
        }
    }
}
int main(){
    scanf("%d %d",&v,&e);
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v;j++ ){
            if(i==j)arr[i][j]=0;
            else arr[i][j]=INF;
        }
    }
    
    for(int i=0; i<e; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        arr[a][b]=c;
    }
    floyd_warshall();
    int sum=INF;
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            if(i!= j && arr[i][j]!=INF && arr[j][i]!=INF)
                sum = min(sum,arr[i][j]+arr[j][i]);
        }
    }
    
    if(sum ==INF)printf("-1\n");
    else printf("%d\n",sum);
        
    
}

