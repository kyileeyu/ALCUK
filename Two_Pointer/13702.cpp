// BOJ 13702: 이상한 술집

#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n,k;
    long long right=0,ans=0;
    cin >> n >> k;
    long long arr[10005];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        right =max(right, arr[i]);
    }
    long long left=0;
    while(left <= right){
        long long mid =(left+right)/2;
        long long cnt =0;
        for(int i=0; i<n; i++){
            cnt += arr[i]/mid;
        }
        
        if( cnt <k) right = mid-1;
        else{
            left = mid+1;
            ans =mid;
        }
    }
    cout << ans;
}
