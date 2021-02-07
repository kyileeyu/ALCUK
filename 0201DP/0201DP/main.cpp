//
//  main.cpp
//  0201DP
//
//  Created by 뜽효니 on 2021/02/01.
//

#include <iostream>
#include <algorithm>

using namespace std;
//1,2,3더하기
int sum[15]={0,1,2,4,};
int cnt(int n){
    if(0<=n && n<=3) return sum[n];
    else if(sum[n]) return sum[n];
    else{
        return sum[n]=cnt(n-1)+cnt(n-2)+cnt(n-3);
    }
}

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d", &n);
        cout<< cnt(n)<<"\n";
    }
}


//fibo2
//int fibo[50]={0,1,};
//
//int dp(int n){
//    if(n==0 || n==1)    return n;
//    if(fibo[n]) return fibo[n];
//    else return fibo[n]= dp(n-1)+dp(n-2);
//}
//
//int main(){
//    int t,n;
//    cin >> t;
//    while(t--){
//        scanf("%d",&n);
//        if(n==0)    printf("%d %d\n",1,0);
//        else if(n==1)    printf("%d %d\n",0,1);
//        else    printf("%d %d\n", dp(n-1), dp(n));
//    }
//}//테케 한번에 쭉 넣을때 엔터같은경우는 실전에서 괜찮을수도 있음!

