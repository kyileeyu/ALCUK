//BOJ 7576: 토마토

#include <iostream>
#include <algorithm>
#include <queue>
#include <stdio.h> // scanf printf
#include <math.h> // max 쓰려귱
#define MAX 1000+1
using namespace std;


int n,m;
int box[MAX][MAX];
int dx[4] ={ 1,-1,0,0};
int dy[4] ={ 0,0,1,-1};
queue <pair <int, int> > q;

void bfs(){
    while(!q.empty()){
        
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //익은 토마토 꺼내기
        
        for(int i=0; i<4; i++){
            
            int nx = x+dx[i];
            int ny = y+dy[i];
            //상하좌우 토마토 익힐 좌표
            
            if( 0<=nx && nx < n && 0<=ny && ny < m){
                //토마토 좌표가 상자 안에 있는지 확인
                if( box[nx][ny] == 0){
                    //토마토가 아직 안익은앤지 확인
                    box[nx][ny] = box[x][y]+1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}


void isItRipe(){
    int day = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
                        
            if( box[i][j] == 0){
                printf("%d\n",-1);
                return;
            }
            day = max( box[i][j], day);
            
        }
    }
    printf("%d\n",day-1);
}

int main(){
    
    scanf("%d %d",&m,&n);
    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            
            scanf("%d",&box[i][j]);
            
            if(box[i][j] == 1){
                q.push(make_pair(i, j));
            }
        }
    }
    
    bfs();
    isItRipe();
}
