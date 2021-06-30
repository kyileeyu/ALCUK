//BOJ 7569: 

#include <iostream>
#include <algorithm>
#include <queue>
#include <stdio.h> // scanf printf
#include <math.h> // max 쓰려귱
#define MAX 100+1
using namespace std;


int n,m,h;
int box[MAX][MAX][MAX];
int dx[6] ={ 1,-1,0,0,0,0};
int dy[6] ={ 0,0,1,-1,0,0};
int dz[6] ={ 0,0,0,0,1,-1};
queue <pair<pair <int, int>,int>> q;

void bfs(){
    while(!q.empty()){
        
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();
        //익은 토마토 꺼내기
        
        for(int i=0; i<6; i++){
            
            int nx = x+dx[i];
            int ny = y+dy[i];
            int nz = z+dz[i];
            //상하좌우 토마토 익힐 좌표
            
            if( 0<=nx && nx < n && 0<=ny && ny < m && 0<=nz && nz<h){
                //토마토 좌표가 상자 안에 있는지 확인
                if( box[nx][ny][nz] == 0){
                    //토마토가 아직 안익은앤지 확인
                    box[nx][ny][nz] = box[x][y][z]+1;
                    q.push(make_pair(make_pair(nx, ny),nz));
                }
            }
        }
    }
}


void isItRipe(){
    int day = 0;
    for(int k=0; k<h;k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                            
                if( box[i][j][k] == 0){
                    printf("%d\n",-1);
                    return;
                }
                day = max( box[i][j][k], day);
                
            }
        }
    }
    printf("%d\n",day-1);
}

int main(){
    
    scanf("%d %d %d",&m,&n,&h);
    for(int k=0; k<h; k++){
        for (int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                scanf("%d",&box[i][j][k]);
                
                if(box[i][j][k] == 1){
                    q.push(make_pair(make_pair(i, j),k));
                }
            }
        }
    }
    
    bfs();
    isItRipe();
}

