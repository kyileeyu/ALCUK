// BOJ 2805: 나무 자르기

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    int n,m,right=0,ans=0;
    cin >> n >> m;
    vector<int>v;
    
    for(int i=0; i<n;i++){
        int tree;
        cin >> tree;
        v.push_back(tree);
        right = max(right,tree);
    }
    int left=0,mid=0;
    while(left <= right){
        mid = (left+right)/2;//자를 미터
        long long cnt=0;
        for(int i=0; i<n;i++){
            if( mid!=0 && v[i]/mid > 0 ){//자를수 있다
                cnt +=v[i]-mid;
            }
        }
        if(cnt >= m){
            ans =mid;
            left = mid+1;
        }
        else right = mid-1;
        
    }
    cout << ans;
}
