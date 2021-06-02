#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
    int t;
    string word;
    cin >> t;

    while(t--){
        cin >> word ;
        char w= word[word.length()-1];

        if(w=='a' || w=='o' || w=='u'){
            word+="s";

//            +s - a,o,u
//            +es - l,v,r
//            +as - t,w,
//            +os - i
//            y -> ios
//            -n,-ne ->anes
        }
        else if(w=='l' || w=='v' || w=='r')     word+="es";
        else if(w=='t' || w=='w')              word+="as";
        else if(w=='i')                        word+="os";
        else if(w=='y'){
            word.erase(word.length()-1);
            word+="ios";
        }
        else if(w=='n'){
            word.erase(word.length()-1);
            word+="anes";
        }
        else if(word[word.length()-2]=='n' && w=='e'){
            word.erase(word.length()-2,word.length()-1);
            word+="anes";
        }
        else{
            word +="us";
        }
        cout << word << "\n";

    }
}
