#include <iostream>

using namespace std;

int main(){

    int N = 5;
    int A[5] = {1,3,4,5,2};

    int i= N;

    while((i>0) && (A[i-1]>A[i])){
        A[i-1] = A[i] - 10;
        i--;
    }

    for(int i=0; i<N; i++){
        cout << A[i] << endl;
    }


    return 0;
}