
//BOJ 10216: Count circle groups

#include <iostream>
#include <math.h>
using namespace std;
int group[3005][3];
int parent[3005];
int cnt;
int find(int x){
    if(x==parent[x]) return x;
    return parent[x]=find(parent[x]);
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return;
    else{
        parent[b] =a;
        cnt--;
    }
    
}
int isGroup(int a, int b){
    double dist =sqrt(pow((group[a][0]-group[b][0]),2) + pow((group[a][1]-group[b][1]),2));
    if( dist <= group[a][2]+group[b][2]) return 1;
    else return 0;
}

int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cnt = n;

        for(int i=1; i<=n; i++){
            parent[i]=i;
            scanf("%d %d %d",&group[i][0],&group[i][1],&group[i][2]);
        }
                
        for(int i=1; i<=n-1; i++){//연결되는지 확인
            for(int j=i+1; j<=n; j++ ){
                if(isGroup(i,j))  merge(i,j);
            }
        }
        cout << cnt << "\n";
    }
}
