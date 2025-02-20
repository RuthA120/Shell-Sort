#include <iostream>
using namespace std;

// Print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void shellSort(int array[], int n) {
    int hlist[] = {5,3, 1};  // Custom gap sequence
    int hsize = sizeof(hlist) / sizeof(hlist[0]);  // Get size of hlist

    for (int k = 0; k < hsize; k++) {  // Iterate over hlist
        int h = hlist[k];  // Current gap value
        int comparisons = 0; // Counter for comparisons

        for (int i = h; i < n; i++) {  // Start from index h
            int temp = array[i];
            int j;
            for (j = i; j >= h && array[j - h] > temp; j -= h) {
                array[j] = array[j - h];
                comparisons++;  // Count each comparison
            }
            array[j] = temp;
        }

        cout << "Gap: " << h << " | Comparisons: " << comparisons << endl;
        printArray(array, n);
    }
}

// Driver code
int main() {
    int data[] = {9, 7, 11, 1, 4, 20, 5, 16, 2, 28, 3, -1, 17, 0, 8, 6};
    int size = sizeof(data) / sizeof(data[0]);
    shellSort(data, size);
    cout << "Sorted array: \n";
    printArray(data, size);
}
