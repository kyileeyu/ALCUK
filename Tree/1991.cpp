
//BOJ 1991: 트리순회

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <vector<char>> v(40);

void go(int s, int m){
    if(m == 0) printf("%c", s+64);
    if(v[s][0] != '.') go(v[s][0]-64, m);
    if(m == 1) printf("%c", s+64);
    if(v[s][1] != '.') go(v[s][1]-64, m);
    if(m == 2) printf("%c", s+64);
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        char node,left,right;
        scanf("%c %c %c", &node, &left, &right);
        v[node-64].push_back(left);
        v[node-64].push_back(right);
    }
    for(int i=0; i<3; i++){
        go(1,i);
        printf("\n");
    }
}
