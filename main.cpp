#include <iostream>

using namespace std;

int main(){

    int N = 5;
    int A[5] = {5,2,9,6,7};

    int j = N-1;
    while(j >= 1){
        if(A[N] < A[j]){
            swap(A[N], A[j]);
        }
        j--;
    }

    for(int i=0; i<N; i++){
        cout << A[i] << endl;
    }


    return 0;
}