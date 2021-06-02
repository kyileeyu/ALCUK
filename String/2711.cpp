
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int main(){
    int t,Index;
    char str[85];
    string ans="";
    scanf("%d",&t);
    
    while(t--){
        scanf("%d",&Index);
        getchar();
        scanf("%s",str);
        
        string ans ="";
        for(int i=0;i<strlen(str);i++){
            if(i+1==Index)continue;
            ans +=str[i];
        }
        
        printf("%s\n", ans.c_str());
    }
}

