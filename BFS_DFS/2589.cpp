//BOJ 2589: 보물섬

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <string.h>//memset 쓰려궁
using namespace std;
#define MAX 50+1
int n,m;
char map[MAX][MAX];
int arr[MAX][MAX]={0,};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
queue<pair<int, int>> q;

int bfs(int x,int y){
    int result = 0;
    memset(arr,0,sizeof(arr));
    
    q.push(make_pair(x, y));
    arr[x][y] =1;
    
    while(!q.empty()){
        
        int nextx = q.front().first;
        int nexty = q.front().second;
        q.pop();
        
        
        for(int i=0; i<4; i++){
            int nx = nextx + dx[i];
            int ny = nexty + dy[i];
            
            if( 0<=nx && nx<n && 0<=ny && ny<m){
                if( map[nx][ny] == 'L' && arr[nx][ny] ==0){
                    
                    q.push(make_pair(nx, ny));
                    arr[nx][ny] = arr[nextx][nexty]+1;
                    result = max(result, arr[nx][ny]);
                }
            }
        }
    }
    return result-1;
}

int main(){
    int day=0;
    
    scanf("%d %d",&n ,&m );
    for(int i=0; i<n; i++){
        scanf("%s",map[i]);
    }
    
    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if(map[i][j] == 'L'){
                day = max( day, bfs(i,j));
            }
        }
    }
    printf("%d\n",day);
    
}

