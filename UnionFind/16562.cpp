

//BOJ 16562: 친구비

#include <iostream>
#include <math.h>
using namespace std;

int fee[10005] = {0,};
int friends[10005] = {0,};
long long minfee = 0;

int find(int x){
    
    if(friends[x] == x )return x;
    return friends[x] =find(friends[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    fee[a]=min(fee[a],fee[b]);
    fee[b]=0;
    if(a==b) return;
    friends[b] =a ;

}


int main(){

    int n,m,k;
    cin >> n >> m >> k;
    
    for(int i=1; i<=n; i++){
        friends[i]=i;
        scanf("%d",&fee[i]);
    }
    
    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        merge(a,b);
        
    }
    for(int i=1; i<=n; i++){
        minfee += fee[i];
    }
    
    if(minfee <=k) printf("%lld\n",minfee);
    else printf("Oh no\n");
}
