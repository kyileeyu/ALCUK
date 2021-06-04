#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


int main(){
    int n;
    scanf("%d",&n);

    int arr[50005];
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2; i<=n; i++ ){
        arr[i] = arr[i-1] + 1;
        for(int j=2; j*j <= i; j++){
            arr[i] = min(arr[i], 1 + arr[i-j*j]);
        }
    }
    
    printf("%d\n",arr[n]);
}
