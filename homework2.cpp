#include <iostream>

using namespace std;

int main(){
    
    int 1a = 1245; //part a: lexical error

    string b =; //part b: syntax error

    int c = "50.4"; //part c: static semantic error
    cout << c << endl;

    int d[5]; //part d: dynamic semantic error
    d[100] = 4; 
    cout << d[100] << endl;


    return 0;
}