//  BOJ 2230: 수 고르기
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int arr[100005];

int main(){
    int n,m;
    cin >> n>> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    
    int left=0,right=1,ans=2000000000;
    if(m==0){
        cout << 0;
        return 0;
    }
    while(right <n){

        int diff = arr[right] - arr[left];
        if(diff >= m){
            ans = min(ans,diff);
            left++;
        }
        else right++;
    }
    cout << ans <<"\n";
    
}
