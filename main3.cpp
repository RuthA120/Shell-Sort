#include <iostream>

using namespace std;

int main(){

    int p = 2;
    int hlist[2] = {3,1};

    int N = 16;
    int A[16] = {9,7,11,1,4,20,5,16,2,28,3,-1,-17,0,8,6};

    for(int k=1; k<p; k++){
        int h = hlist[k];
        for(int j=2; j<N; j++){
            int i = j;
            while((i>h)&&(A[i-h] > A[i])){
                swap(A[i], A[i-h]);
                i = i - h;
            }
        }
    }

    for(int i=0; i<N; i++){
        cout << A[i] << endl;
    }


    return 0;
}