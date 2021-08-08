//  BOJ 22254: 공정 컨설턴트 호석
#include <iostream>
#include <queue>
using namespace std;
int arr[100005];

int main(){
    int n,x;
    cin >> n>> x;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int left=1,right=n,ans=0;
    while(left <=right){
        bool flag=true;
        int mid = (left+right)/2;//공정 개수
        priority_queue<int>pq;
        for(int i=0; i<mid; i++){
            pq.push(0);
        }
        for(int i=0; i<n; i++){
            int tmp = -pq.top();
            pq.pop();
            if( (tmp + arr[i]) > x){
                flag = false;
                break;
            }
            else pq.push(-(tmp + arr[i]));
        }
        if(flag){
            ans =mid;
            right= mid-1;
        }
        else left = mid+1;
    }
    cout << ans;
 
}
