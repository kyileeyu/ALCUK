
//11279 최대힙

#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;
int main(){
    int n,x;
    cin>> n;
    while(n--){
        
        scanf("%d",&x);
        if(x==0){
            if(pq.empty())  printf("0\n");
            else{
                printf("%d\n",pq.top());
                pq.pop();
            }
        }
        else pq.push(x);
    }
}
