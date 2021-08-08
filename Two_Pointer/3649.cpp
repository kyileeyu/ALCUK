// BOJ 3649: 로봇 프로젝트

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(); cout.tie();

    int x,n;
    while(cin >> x){//입력이 있을 때만 실행
        x *= 10000000;//나노미터로 변경
        cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin >>v[i];
        }
        
        sort(v.begin(),v.end());
        int left=0, right=n-1,sum=0;
        
        while(left < right){
            sum = v[left] + v[right];
            if(sum >x) right--;
            else if(sum <x) left++;
            else break;
        }
        if( sum==x ){
            cout << "yes " << v[left] << " " << v[right] << "\n";
        }
        else cout << "danger\n" ;
    }
    return 0;
}
