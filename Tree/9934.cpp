
// BOJ 9934: 완전 이진 트리

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int visited[1025], tree[1025],k;

void setlevel(int le,int ri, int lev){
    int mid = (le+ri) / 2;
    tree[lev] = visited[mid];
    
    if( le == mid || ri == mid ) return;
    setlevel(le,mid-1,lev*2);
    setlevel(mid+1,ri,lev*2+1);
    return;
}

int main(){

    cin >> k;
    for(int i=1; i<pow(2,k); i++){
        scanf("%d",&visited[i]);
    }
    
    setlevel(1, 1<<k,1);
    
    int lv =2;
    for(int i=1; i<pow(2,k); i++){
        if( i == lv){
            printf("\n");
            lv *= 2;
        }
        printf("%d ",tree[i]);
    }
    
}
